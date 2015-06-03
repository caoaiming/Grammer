#include <iostream>

using namespace std;

// 友元函数与 << 操作符重载(左移)

class MyClass
{
private:
    int mValue;
public:
    MyClass(int value)
    {
        mValue =  value;
    }
    //friend void operator<<(ostream &os, MyClass &myClass);
    friend ostream& operator<<(ostream &os, MyClass &myClass);
};

ostream& operator<<(ostream &os, MyClass &myClass)
{
    os << myClass.mValue; //这样作，就必须是友元函数
}

int main(int ac, char **av)
{
    MyClass myClass(99);

//    正确:         cout << myClass;  

//    cout << myClass << "abc";
//    错误：(cout << myClass)之后没返回值，导致后边接不上.没法调用
//          系统默认的(ostream &a, ostream &b)继续往后走，所以需要返回值;
    cout << myClass << "  is ok." << endl;

    return 0;
}
