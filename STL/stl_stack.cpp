#include <iostream>
#include <stack>

using namespace std;
/*
    栈容器类：stack <FILO,先入后出>
*/

int main(int ac, char **av)
{
    stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "栈顶元素：= " << s.top() << endl;
    s.pop();
    cout << "栈顶元素：= " << s.top() << endl;
    
    cout << "栈尺寸是：= "<<s.size() << endl;
    cout << "栈是不是为空？ = "<<(s.empty()? "true" : "false")<<endl;
    
    return 0;
}
