#include <iostream>

using namespace std;
/*共同的友元函数
 *             :一个函数要同时访问多个类的私有成员，
 *做法：1. 将这个函数作为一个类的成员方法，然后将这个方法设为其他类的友元方法
 *     2. 设这个函数为多个类的友元函数（简单一点）.
 *
 */

class MyClass1;
class Myclass2;//提前声明一下

//第1种方法 《友元方法所属类必须是第一个》
class MyClass3
{
private:
    double mDot = 20.1;
public:
    void   test(MyClass1 &c1, Myclass2 &c2, MyClass3 &c3);
    
};


class MyClass1
{
private:
    string mName = "Bill torwads";
    friend void process(MyClass1 &c1, Myclass2 &c2);
                                   //Myclass2找不到，要提前声明
    friend void MyClass3::test(MyClass1 &c1, Myclass2 &c2, MyClass3 &c3);
};

class Myclass2
{
private:
    int mCode = 12;
    friend void process(MyClass1 &c1, Myclass2 &c2);
public:
    friend void MyClass3::test(MyClass1 &c1, Myclass2 &c2, MyClass3 &c3);
};


void MyClass3::test(MyClass1 &c1, Myclass2 &c2, MyClass3 &c3)
{
    cout << "c1.mName = " << c1.mName << endl;
    cout << "c2.mCode = " << c2.mCode << endl;
    cout << "c3.mDot = "  << c3.mDot  << endl;
}

void process(MyClass1 &c1, Myclass2 &c2)
{
    c1.mName = "Bill Gates";
    c2.mCode = 200;
    cout << "c1.mName = " << c1.mName << endl;
    cout << "c2.mCode = " << c2.mCode << endl;
}

int main(int ac, char **av)
{
    MyClass1 c1;
    Myclass2 c2;
    MyClass3 c3;
    
    process(c1, c2);        /* 第2种方法测试结果 */
    cout << "-----------------------------------------" << endl;
    c3.test(c1, c2, c3);    /* 第1种方法测试结果 */
    return 0;
}
