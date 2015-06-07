#include <iostream>
using namespace std;
//面向对象的三个特点：
//1.封装
//2.继承
//3.多态

class baseClass {
protected:
    int mCode = 20;
public:
    int getCode();
};

int baseClass::getCode()
{
    return mCode;
}

class MyClass : public baseClass
{
public:
    void setCode(int code);
};
void MyClass::setCode(int code)
{
    mCode = code;
}

int main(int ac, char **av)
{
    MyClass myClass1;
    cout << myClass1.getCode() << endl;
    myClass1.setCode(432);
    cout << myClass1.getCode() << endl;

    return 0;
}
