#include <iostream>

using namespace std;
//成员变量的初始化顺序
class MyClass {
public:
    int code1;
    int code2;
//    MyClass() : code1(30), code2(code1-20)  //code1 = 30, code2 = 9
    MyClass() : code2(30), code1(code2) // code1 = 32767, code2 = 30;
    {
        cout << "code1 = " << code1 << "  code2 = " << code2 << endl;
    }//初始化顺序与定义顺序一致，不会应为位置而发生改变
};


int main(int ac, char **av)
{
    MyClass class1;

    return 0;
}
