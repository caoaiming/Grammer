#include <iostream>
#include <boost/thread.hpp>

using namespace boost::this_thread;
using namespace boost::posix_time;

using namespace std;
/*
    线程中断
*/

void thread()
{
    try {//异常发生在线程挂起时(就能抽出空儿来检测信号)被信号打断.
        for(int i = 0; i < 6; i++) {
            sleep(seconds(1));
            cout << i << endl;
        }
    } catch (boost::thread_interrupted&) {
        cout << "线程已经被中断..."  << endl;
    }
}

int main(int ac, char **av)
{
    boost::thread t(thread);
    sleep(seconds(3));
    
    t.interrupt(); //中断信号
    t.join();
    
    return 0;
}
