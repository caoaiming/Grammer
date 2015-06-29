#include <iostream>

using namespace std;
/* unique_ptr 与 临时右值
 */

unique_ptr<string> getString()
{
    unique_ptr<string> str(new string("女神"));
    return str;//无法使用，返回后立即释放.
}

int main(int ac, char **av)
{
    unique_ptr<string> str1(new string("超人"));
    //unique_ptr<string> str2 = str1;  /* 不能增加引用 */
    /*C++编译器规定，如果在某个作用域内，检测到左侧是智能指针而右侧是永久的
     *（当前作用域内）,则报错。 如果将str1的控制权交给str2，
     *str1变为空,则在以后误使用str1，会引发问题.好在，unique_str不允许.
     */
    unique_ptr<string> str3 = getString();//右侧是个临时值.
    cout << *str3 << endl;
    
    return 0;
}
