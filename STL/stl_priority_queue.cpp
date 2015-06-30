#include <iostream>
#include <queue>

using namespace std;
/*
    永远获得最大值的容器队列容器类：priority_queue
                                          ————队首存放的永远是最大值.
     1.只能获得最大元素值,没有front, back方法
 */

int main(int ac, char **av)
{
    priority_queue<int> p;
    
    p.push(10);
    p.push(20);
    p.push(30);
    
    cout << p.top() << endl;
    
    p.pop();
    cout << p.top() << endl;

    return 0;
}