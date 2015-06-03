#include <iostream>

using namespace std;

struct Mystruct
{
    int code;
    string name;
};

class MyClass{
private:
    int code;
    string name;
public:
    MyClass();
    MyClass(int code);
    MyClass(string name);
    MyClass(int code, string name);
};

MyClass::MyClass()
{
    cout << "This is no value method!" << endl;
}

MyClass::MyClass(int code)
{
    this->code = code;
    cout << "This->code = " << this->code << endl;
}

MyClass::MyClass(string name)
{
    this->name = name;
    cout << "This->name = " << this->name << endl;
}

MyClass::MyClass(int code, string name)
{
    this->code = code;
    this->name = name;

    cout << this->code << "   " << this->name << endl;
}

int main(int ac, char **av)
{
    Mystruct mystruct = {20, "Mike"};
/*结构体的默认域是公有属性(public)，程
 *序会将所有成员变量作为默认的构造函数参数
 */
    cout << mystruct.code << "<STRUCT>"  << mystruct.name << endl;
/*类的默认域属性是私有属性(private),程序不能直接用{}初始化，public则可以
 *定义一个对象时会自动调用构造方法，如果自己定义了构造方法，则系统不会再
 *自动生成构造方法
 */
//    MyClass class1;
//    MyClass class2 = {10};
//    MyClass class3 = {"Caming"};
//    MyClass class4 = {11, "Casheng"};
    MyClass myclas1;
    
    return 0;
}
