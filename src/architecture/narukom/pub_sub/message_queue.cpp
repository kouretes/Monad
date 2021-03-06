/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "message_queue.h"
#include "../tools/XML.h"

 
using std::map;
using std::string;

MessageQueue::MessageQueue() : Thread(false), type_string("topic")
{
	boost::unique_lock<Mutex> sub_lock(sub_mutex);
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
    this->publishers_buf = new map<string,MessageBuffer*>();
    this->subscribers_buf = new map<string,MessageBuffer*>();
    this->topic_tree = new TopicTree<string,MessageBuffer>();
    create_tree(topic_tree, string("topic_tree.xml"));
		condition_variable_period = boost::posix_time::millisec(5);


}

MessageQueue::MessageQueue(string configuration_file)  : Thread(false), type_string("topic")
{
	boost::unique_lock<Mutex> sub_lock(sub_mutex);
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
    this->publishers_buf = new map<string,MessageBuffer*>();
    this->subscribers_buf = new map<string,MessageBuffer*>();
    this->topic_tree = new TopicTree<string,MessageBuffer>();
    create_tree(topic_tree, configuration_file);
		condition_variable_period = boost::posix_time::millisec(5);

}

MessageQueue::MessageQueue(const char* configuration_file)  : Thread(false), type_string("topic")
{
		boost::unique_lock<Mutex> sub_lock(sub_mutex);
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
    this->publishers_buf = new map<string,MessageBuffer*>();
    this->subscribers_buf = new map<string,MessageBuffer*>();
    this->topic_tree = new TopicTree<string,MessageBuffer>();
    create_tree(topic_tree, string(configuration_file));
		condition_variable_period = boost::posix_time::millisec(5);
}

void MessageQueue::create_tree(TopicTree<string,MessageBuffer>* tree,const  string& file_name)
{
    string parent = "";
    string topic;
    XML configFile(file_name);
    if (!configFile.IsLoadedSuccessfully())
    {
        cout << "Could not load file Default tree created" << file_name << endl;
        topic_tree->add_topic(string("global"));
        topic_tree->add_topic_under(string("global"),string("motion"));
        topic_tree->add_topic_under(string("global"),string("sensors"));
        topic_tree->add_topic_under(string("global"),string("vision"));
        topic_tree->add_topic_under(string("global"),string("behavior"));
        topic_tree->add_topic_under(string("global"),string("localization"));
        topic_tree->add_topic_under(string("global"),string("communication"));
        topic_tree->add_topic_under(string("global"),string("obstacle"));
        topic_tree->add_topic_under(string("motion"),string("score"));
        return;
    }
    cout << "File: " << file_name << " Loaded " << endl;
    const string tree_str("tree");
    std::vector<XMLNode<std::string,std::string,std::string> > trees = configFile.QueryElement<std::string,std::string,std::string>(tree_str,NULL);

    for (std::vector<XMLNode<std::string,std::string,std::string> >::iterator it = trees.begin(); it != trees.end(); it++)
    {
        cout << "inside for " << endl;
        std::vector<XMLNode<std::string,std::string,std::string> > nodes;
        nodes = configFile.QueryElement(string("node"),&(*it));
        for (unsigned int j =0; j < nodes.size(); j++)
        {
            string parent = nodes[j].attrb["parent"];
            if (parent == "none" || parent == "")
            {
                cout << "topic tree " << nodes[j].value << endl;
                topic_tree->add_topic(nodes[j].value);
            }
            else
            {
                cout << "topic tree under " << parent << " " << nodes[j].value << endl;
                topic_tree->add_topic_under(parent,nodes[j].value);
            }
        }

    }

}


bool MessageQueue::add_topic(const std::string& new_topic)
{

		boost::unique_lock<Mutex> tree_lock(tree_mutex);
		bool result = topic_tree->add_topic(new_topic);
		return result;
}

bool MessageQueue::add_topic(const char* new_topic)
{

	boost::unique_lock<Mutex> tree_lock(tree_mutex);
	bool result;
  std::string tmp_topic(new_topic);
  result =  this->add_topic(tmp_topic);
	return result;
}

bool MessageQueue::add_topic_under(const std::string& parent,const std::string& new_topic)
{
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
	bool result = topic_tree->add_topic_under(parent,new_topic);
	return result;
}

bool MessageQueue::add_topic_under(const char* parent,const char* new_topic)
{
	boost::unique_lock<Mutex> tree_lock(tree_mutex);
  std::string tmp_parent(parent);
  std::string tmp_topic(new_topic);
  bool result =  topic_tree->add_topic_under(tmp_parent,tmp_topic);
	return result;
}

bool MessageQueue::remove_topic(const std::string& old_topic)
{
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
  bool result =  topic_tree->delete_topic(old_topic);
	return result;
}
bool MessageQueue::remove_topic(const char* old_topic)
{
	
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
	 std::string tmp_old_topic(old_topic);
  bool result =  topic_tree->delete_topic(tmp_old_topic);
	return result;
}


void MessageQueue::remove_publisher(Publisher* pub)
{
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
    cout << "Remove Publisher" << endl;
    string pub_name = pub->getName();
    map<string,MessageBuffer*>::iterator it = publishers_buf->find(pub_name);
    if (it != publishers_buf->end() )
        publishers_buf->erase(it);
}
void MessageQueue::remove_subscriber(Subscriber* sub)
{
boost::unique_lock<Mutex> sub_lock(sub_mutex);
		
	cout << "Remove Subscriber" << endl;
    string sub_name = sub->getName();
    map<string,MessageBuffer*>::iterator it = subscribers_buf->find(sub_name);
    if (it != subscribers_buf->end() )
        subscribers_buf->erase(it);
    
}

MessageBuffer* MessageQueue::add_publisher(Publisher* pub)//{return NULL;}//TODO};
{
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
		
    string owner_name = pub->getName();

    map<string,MessageBuffer*>::iterator it = publishers_buf->find(owner_name);
    if (it != publishers_buf->end() )
        return it->second;

    MessageBuffer* new_msg_buf = new MessageBuffer ( owner_name,&cond_lock, &cond);
    pub->setQueue(this);
    publishers_buf->insert ( std::make_pair<std::string,MessageBuffer*> ( owner_name,new_msg_buf ) );
    pub->setBuffer(new_msg_buf);
    return new_msg_buf;

}

MessageBuffer* MessageQueue::add_publisher(Publisher* pub , MessageBuffer* buf)
{
	boost::unique_lock<Mutex> pub_lock(pub_mutex);
		
  if(pub != 0 && buf !=0)
  {
    pub->setQueue(this);
    publishers_buf->insert(std::make_pair<std::string,MessageBuffer*> ( pub->getName(),buf ));
    return buf;
  }
  cout << " Either buffer or Publisher is null " << endl;
  return 0;
  
}


MessageBuffer* MessageQueue::add_subscriber ( Subscriber* sub ) //{return NULL;} //TODO};
{
    boost::unique_lock<Mutex> sub_lock(pub_mutex);
		string owner_name = sub->getName();

    map<string,MessageBuffer*>::iterator it = subscribers_buf->find(owner_name);
    if (it != subscribers_buf->end() )
        return it->second;

    MessageBuffer* new_msg_buf = new MessageBuffer ( owner_name,&cond_lock,&cond );
    sub->setQueue(this);
    subscribers_buf->insert ( std::make_pair<std::string,MessageBuffer*> ( owner_name,new_msg_buf ) );
    sub->setBuffer(new_msg_buf);
    return new_msg_buf;


}
MessageBuffer* MessageQueue::add_subscriber(Subscriber* sub, MessageBuffer* buf )
{
boost::unique_lock<Mutex> sub_lock(sub_mutex);
		
	if(sub != 0 && buf !=0)
  {
    sub->setQueue(this);
    subscribers_buf->insert(std::make_pair<std::string,MessageBuffer*> ( sub->getName(),buf ));
    return buf;
  }
  cout << " Either buffer or Subscriber is null " << endl;
  return 0;

}

bool MessageQueue::subscribe ( const char* topic, Subscriber* sub,int where )
{
    string tmp_topic = string (topic);
    return subscribe(tmp_topic,sub,where);
}
bool MessageQueue::subscribe (const  std::string& topic, Subscriber* sub,int where )
{
	boost::unique_lock<Mutex> sub_lock(sub_mutex);

		boost::unique_lock<Mutex> tree_lock(tree_mutex);
    string owner = sub->getName();
    bool result;
    std::list<MessageBuffer*> * already_subscribed = topic_tree->message_arrived(topic);
		if(already_subscribed != 0)
			for(std::list<MessageBuffer*>::iterator it = already_subscribed->begin(); it != already_subscribed->end(); it++)
			{
				if((*it)->getOwner() == sub->getBuffer()->getOwner() )
					return true;
			}
    std::map<std::string,MessageBuffer*>::iterator sub_it = subscribers_buf->find ( owner );
    
    if ( sub_it != subscribers_buf->end() )
    {
    
        MessageBuffer* subscriber = sub_it->second;
        result =  topic_tree->subscribe ( topic,subscriber,where );
    
        return result;
        //        return true;
    }
    else
    {
        cout << "Subscriber was not added in message queue\nAutomatically added" << endl;
				sub_lock.unlock();
        this->add_subscriber(sub);
				sub_lock.lock();
        result =  topic_tree->subscribe ( topic,sub->getBuffer(),where );
    
        return result;


    }
    return false;
}


bool MessageQueue::unsubscribe (const std::string& from_topic, Subscriber*  sub   )
{
	boost::unique_lock<Mutex> sub_lock(sub_mutex);
		
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
    bool result;
    
    cout << "!MessageQueue unsubscribe!" << endl;
    result =  topic_tree->unsubscribe( from_topic,sub->getBuffer() );
    
    return result;
}
 bool MessageQueue::unsubscribe(const char* from_topic, Subscriber* sub )
 {
	 boost::unique_lock<Mutex> sub_lock(sub_mutex);
	boost::unique_lock<Mutex> tree_lock(tree_mutex);
   std::string tmp_from_topic(from_topic);
   return unsubscribe(tmp_from_topic,sub);
 }

void MessageQueue::process_queued_msg()
{
		boost::unique_lock<Mutex> sub_lock(sub_mutex);
		boost::unique_lock<Mutex> pub_lock(pub_mutex);
		boost::unique_lock<Mutex> tree_lock(tree_mutex);
	bool new_messages_to_deliver = false;
   if (publishers_buf->size() > 0 )
    {
// 				cout << "publishers size > 0 " << endl;
        for(map<string,MessageBuffer*>::iterator it = publishers_buf->begin(); it != publishers_buf->end(); it++)
        {
            if (it->second->size() < 1 )
            {
// 							cout << "no messages in the buffer of " << it->first << endl;

                continue;
            }
						
            Tuple* cur = it->second->remove_head();
//   						cout << "deliver " << cur->get_type() << " from " << cur->get_publisher() << " topic  " << cur->get_topic() << " Buffer size: " << it->first.size() << endl;
            while (cur != 0)
            {
							  new_messages_to_deliver = true;
                
                list<MessageBuffer*>* alist =  topic_tree->message_arrived(cur->get_topic());
                
								if(alist != 0)
								{
									for ( list<MessageBuffer*>::iterator buf_it = alist->begin(); buf_it != alist->end(); buf_it++)
									{
										
											if ((*buf_it)->getOwner() == cur->get_publisher() );
											else
											{
//   													cout << "Delivering to " << (*buf_it)->getOwner()<< " the " << cur->get_type() << " size: " << (*buf_it)->size() << endl;
													(*buf_it)->add(cur);
											}
									}
								}
								else
								{
// 									cout << "empty list of receivers " << endl;
								}
								delete cur;
                cur = it->second->remove_head();
                if (cur == 0)
                    break;
            }
        }
    }
    if(!new_messages_to_deliver)
    {
      
      boost::unique_lock<Mutex>  lock(cond_lock);
			sub_lock.unlock();
			pub_lock.unlock();
			tree_lock.unlock();
			
			cond.timed_wait<boost::unique_lock<Mutex>,boost::posix_time::time_duration >(lock,condition_variable_period);
    }
    
    
    

}


//void MessageQueue::finalize_queue(){}
int MessageQueue::Execute()
{
//   cout << "Starting Thread Main" << endl;
  process_queued_msg();
  return 0;
}
