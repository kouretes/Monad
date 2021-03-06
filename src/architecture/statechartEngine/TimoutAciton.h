#ifndef TIMOUTACITON_H
#define TIMOUTACITON_H 1

#include "IAction.h"

#include "messages/timeout.pb.h"

namespace statechart_engine {

    class TimeoutWorker: public IExecutable {

        public:

           void Set( Blackboard* blk, std::string& var, Statechart* s );

           int Execute();

      private:

           Blackboard* _blk;
           std::string _var;
           Statechart* _s;
    };

    class TimeoutAction: public IAction {

        public:

          TimeoutAction ( std::string var, int timeout_ms );

          virtual int Execute();

          virtual void UserInit();

        private:

          std::string _var;
          int _timeout_ms;

          TimeoutWorker _twork;

          TimeoutMsg _msg;
          Tuple _tpl;

    };

}

#endif // TIMOUTACITON_H
