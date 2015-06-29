#include <iostream>

using namespace std;
/*
     智能指针(C++ 98)的基本用法
 
     1.创建指针
     2.联动释放，变量本身以及他所指向的空间，一起释放,不需要人为干预.
     C++98 : auto_ptr 模板类
     C++11 : shared_ptr 、 unique_ptr（细化）
     在函数中：当我们的变量被释放时，他所指向的空间也一起回收。
 */
class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass对象被创建." << endl;
    }
    ~MyClass()
    {
        cout << "MyClass现象被销毁." << endl;
    }
    
    string getName()
    {
        return "bill";
    }
};

void  process1()
{
    auto myClass = new MyClass();
    cout << myClass->getName() << endl;
    /*如果前面抛出异常，那么就不会执行到该条释放语句，仍然是不完美的.*/
    if (true) {
        throw "出错了";
    }
    delete myClass;
}

void process2()
{
    auto_ptr<MyClass> myClass1(new MyClass());/*托管给智能指针*/
    
    cout << myClass1->getName() << endl;
}

void process3()
{
    shared_ptr<MyClass> myClass2(new MyClass());
    cout << myClass2->getName() << endl;
}

int main(int ac, char **av)
{
    //process1();
    //process2();
    process3();
    return 0;
}