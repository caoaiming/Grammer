#include <iostream>

using namespace std;

/*【友元函数】 : 是类的好朋友，可以访问类中的私有成员.
 *1.在类（结构体）中需要定义友元函数的原型（前面加friend);
 *2.friend只能在友元函数的原型加，不能在友元函数的实现部分加.
 *3.尽管友元函数原型在类定义中，但不能像调用类成员方法一样，他本质是个函数.
 */

class MyClass
{
private:
    int mValue;
public:
    MyClass(int value) {mValue = value;}

    void print() {cout << mValue << endl;}
    
    MyClass operator*(int right)
    {//缺陷：左边必须是class类,右边任意，但是乘法应该满足交换律才合理....
     // MyClass * xxxxx, 只能通过函数了...
        return MyClass(mValue * right);
    }

    friend MyClass operator*(int, MyClass);
};
#if 0
MyClass operator*(int left, MyClass right)
{
//    return MYClass(left * right.mValue);  错误：mValue私有成员，不可以访问
      return right * left;  
}
#endif

MyClass operator*(int left, MyClass right)
{
    return left * right.mValue;//此时可以访问.
}

int main(int ac, char **av)
{
    //MyClass result = 20 * MyClass(30);// = MyClass(30) * 20;
    //cout << result.mValue  << endl; 问题来了：私有成员，不让访问...

    MyClass result = 20 * MyClass(30);
    result.print();

    return 0;
}
