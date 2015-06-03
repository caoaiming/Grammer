#include <iostream>

using namespace std;

class MyClass {
public:
//    static int value = 10; //静态成员存储在类外边,在声明时已经分配了内存
                             //空间，必须在类外边初始化，如果此时就初始化
                             //类并没有被分配内存空间，，与定义不符合
                             //类中静态变量初始化必须在.cpp文件中，不能在
                             //类的声明所处的头文件中，理由是外部初始化只能
                             //有一次，如果放在头文件里，将会使每个引用
                             //此头文件的.cpp里包含此定义语句，在宏展开时
                             //发生了重复定义.
                             //且初始化方法为：
                             // int MyClass::value = 100;
    static int value;
    static const int max = 1234; //这初始化了，外边就不能在初始化了
                              //同理，外边初始化了，里边就不可以初始化了
//    static const int max;   //如果只作声明，外边必须初始化，因为是常量嘛.
                              //但是只能初始化一次,也就是不能在多个.cpp文件
                              //里重复定义（初始化）.
    MyClass();
    MyClass(int num)
    {
        value = num;
    }
    int getValue()
    {
        return value;
    }
};

MyClass::MyClass()
{
    value = 200;//第二种初始化方法.
}
int MyClass::value = 100; //第一种初始化方法
//const int MyClass::max = 1234; //这也可以初始化，不用强调static了.
                                 //前提是类中有声明

/*类中的静态变量：
 *1.  static变量不能直接在class中初始化
 *2.  static变量不能在头文件中初始化
 *3.  static变量可以在cpp文件中初始化，但初始化时不要再指定static.
 *4.  static变量可以在类的构造方法中初始化
 *5   static以及const 只能在一个.cpp文件里定义，不可重复定义,构造方法里可以
               多重构造不同的值，但是每一次构造都会改变这个<全局变量>
               以最新更改为准.
 *  例外： 类中的静态常量（整型或枚举型）可以在类中声明时就初始化，也可以在
 *         cpp文件中初始化.
 * */

int main(int ac, char **av)
{
    cout << MyClass::value  << endl; //= 100 ，外部初始化
    cout << MyClass::max << endl;

    MyClass class1;
    cout << MyClass::value  << endl; // = 200,构造方法初始化,将此值更新为200
    cout << class1.getValue() << endl;
    
    MyClass class2(33);  //其实无论是全局static,还是局部staic都在堆区，
                         //无论谁作更改，都以最新改动的这次为准.以下是证明
    cout << MyClass::value << endl;  // = 33
    cout << "Class1 value = " << class1.getValue() << endl;  // = 33
    cout << "Class2 value = " << class2.getValue() << endl;  // = 33
    
    MyClass::value = 1999;  //可以多处修改.
    cout << MyClass::value << endl;

    return 0;
}
