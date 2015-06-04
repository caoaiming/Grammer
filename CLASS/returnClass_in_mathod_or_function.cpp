#include <iostream>

using namespace std;
//方法或函数如何返回对象:
// 1.直接返回对象
// 2.返回对象引用
// 3.返回对象指针
//具体返回什么看实际需要,考虑移动设备没有虚拟内存，资源紧张...
class MyClass 
{
public:
    int code = 20;
    MyClass(const MyClass& myClass)//复制构造方法
    {
        code = myClass.code;
        cout << "MyClass(const MyClass& myClass)" << endl;
    }
    MyClass()
    {
    
    }
};

MyClass mul2(MyClass myClass)
{
    myClass.code = myClass.code * 2;
    return myClass;
}
MyClass New_mul2(MyClass &myClass)
{
    myClass.code = myClass.code * 3;
    return myClass;
}

MyClass& New2_mul2(MyClass &myClass)
{
    myClass.code = myClass.code * 3;
    return myClass;
}
//错误例子：
//    MyClass& New2_mul2(MyClass myClass)
//    {
//        myClass.code = myClass.code * 3;
//        return myClass;
//    }函数内部是局部变量，返回引用没有意义.返回后就会释放,造成悬空指针引用
//     是栈变量量，应该返回对象，返回对象系用会自动调用复制构造方法.
int main(int ac, char **av)
{
    MyClass myClass1;

    MyClass myClass2 = mul2(myClass1);//总共2次调用.且效率低下
    //第1次调用：作为参数发生拷贝,调用复制构造方法
    //第2次调用：作为返回值返回时赋值给myClass2发生拷贝,函数栈局部则会释放
    cout << myClass2.code << endl;
    cout <<"----------------------------------------" << endl;

    MyClass myClass3 = New_mul2(myClass1);
    cout << myClass3.code << endl;//总共一次调用:发生在赋值时发生的拷贝.

    cout <<"----------------------------------------" << endl;
    MyClass myClass4 = New2_mul2(myClass1);
    cout << myClass4.code << endl;//总共一次调用,都是对myClass1的引用.
                                  //虽然返回一个引用，但是由于myClass4
                                  //是一个实例，所以赋值时还是发生调用了.
    cout <<"----------------------------------------" << endl;
    MyClass &myClass5= New2_mul2(myClass1);
    cout << myClass5.code << endl;//没有发生任何调用,都是对myClass1的引用.
                                  //指向同一个对象.赋值给了另一个指针
                                  //其实myClass5是一个指针了。
    return 0;
}
