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

#include "fast.h"



int Fast::Execute()
{
// 	cout << "fast run" << endl;
 sleep(10);
    int c = counter.counter();
    counter.set_counter(++c);
    counter.set_topic("bar");
    counter.set_timeout(10);
    publish(&counter,"global",3000000);
    usleep(30000);
    if (c == 800)
        Thread::StopThread();
    return 0;
}


