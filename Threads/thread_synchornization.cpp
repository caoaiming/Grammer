#include <iostream>
#include <boost/thread.hpp>

using namespace std;
/*
    线程同步
*/

boost::mutex m;
void wait(int seconds)
{
    boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void thread()
{
    for(int i  = 0; i < 5; i++) {
        wait(1);
        m.lock();
        cout << "Thread" << boost::this_thread::get_id() << ":" << i << endl;
        m.unlock();
    }
}

int main(int ac, char **av)
{
    boost::thread t1(thread);
    boost::thread t2(thread);
    
    t1.join();
    t2.join();

    return 0;
}
