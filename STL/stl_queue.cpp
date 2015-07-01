#include <iostream>
#include <queue>

using namespace std;
/*
    列表容器类： queue
*/

int main(int ac, char **av)
{
    queue<int> q; /*不能像list那样初始化({1, 2, 3, ,4...}),错误的 */
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    /* 获得队首元素值 */
    cout << "队首元素 : = " << q.front() << endl;

    /* 获得队尾元素值 */
    cout << "队尾元素 : = " << q.back() << endl;
    cout << "-------------------------------------" << endl;
    
    q.pop();
    cout << "队首元素 : = " << q.front() << endl;
    cout << "队尾元素 : = " << q.back() << endl;

    cout << "对列尺寸 ： = " << q.size() << endl;
    cout << "队列是不是为空： ";
    cout << (q.empty() ? "true" : "false") << endl;
    
    return 0;
}
