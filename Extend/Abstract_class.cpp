#include <iostream>

using namespace std;

//抽象函数与纯虚函数
//在Java中，拥有抽象方法的类称为抽象类,功能一致，要求子类必须实现父类
//的抽象方法或纯虚方法,实现多态,其实在C++中，virtual关键字没有强制要
//子类去实现父类虚方法，所以纯虚函数的出现是为了强制.

//*************************************************************************
//*注意：一旦在类中使用了纯虚函数或虚函数，就不能创建实例，必须声明为指针.*
//*************************************************************************
class ParentClass
{
    public:
        virtual void process()
        {
            cout << "ParentClass.process" << endl;
        }
        virtual void process1() = 0;  //声明为纯虚函数，必须去实现
};

class MyClass : ParentClass
{
     public:
        void process()
        {
            cout << "MyClass.process" << endl;
        }
        void process1()
        {
            cout << "MyClass.process1" << endl;
        }

};

int main(int ac, char **av)
{
    MyClass  *pMyClass = new MyClass();
    pMyClass->process();

    delete pMyClass;
    return 0;
}
