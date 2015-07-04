#include <iostream>
#include <boost/thread.hpp>

using namespace std;
/*
     线程基础
*/

void run1()
{
    for(int i = 0; i < 5; i++) {
        boost::this_thread::sleep(boost::posix_time::seconds(1));
        cout << i << endl;
    }
}

void run2()
{
    for(int i = 6; i < 10; i++) {
        boost::this_thread::sleep(boost::posix_time::seconds(0.5));
        cout << i << endl;
    }
}

int main(int ac, char **av)
{
    boost::thread t1(run1);
    boost::thread t2(run2);
    
    t1.join();
    t2.join();
    
    cout << "OK!" << endl;
    
    return 0;
}
