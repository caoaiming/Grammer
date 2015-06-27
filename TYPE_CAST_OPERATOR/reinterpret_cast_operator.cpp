#include <iostream>

using namespace std;
/*
 *reinterpret_cast 类型转换运算符
 *reinterpret_cast<<#type#>>(<#expression#>)
 *
 *     功能： 将一些基本类型变为指针类型
 */
class MyClass
{
public:
    virtual void process()
    {
        cout << "MyClass" << endl;
    }
};


int main(int ac, char **av)
{
    MyClass myClass;
    cout << "myClass Address(Hex) = " << &myClass << endl;
    cout << "-------------------------------------------" <<endl;

    long myClass_Address = reinterpret_cast<long>(&myClass);
    cout << "myClass Address(Dec) = " << myClass_Address << endl;
    cout << "myClass Address(Dec) = 0x"<<hex<<myClass_Address<<endl;                        /* 十六进制转换 */
    
    cout << "-------------------------------------------" <<endl;
    MyClass *pMyClass = reinterpret_cast<MyClass*>(myClass_Address);
    pMyClass->process();
    return 0;
}
