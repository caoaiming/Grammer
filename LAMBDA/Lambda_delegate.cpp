#include <iostream>

using namespace std;
/*
        将Lambda表达式作为委托（Delegate）
 
        委托：二传，在Lambda表达式内部调用其他对象的方法，这么做的原因与
             Lambda表达式的类型有关.
 
        总结： 除了使用Lambda表达式，没有其他方法能做到调用Unit类中的方法
              除非重新写个函数，功能一模一样,或者将方法声明为全局static

*/
class Unit
{
public:
    void static process(int n) /*const*/
    {
        cout << n << endl;
    }
};

class MyClass
{
public:
    void method(function<void (int)> func)
    {
        srand((unsigned)time(0));
        func(rand());
    }
};

int main(int ac, char **av)
{
    Unit unit;
    MyClass myClass;
#if 0
    /*报错： method的参数不是普通变量，而是一个类的成员方法，不允许这样用*/
    //myClass.method(unit.process);
    
    /* 解决方法 1. 将process() 变成静态的方法（与全局函数一样，都是全局的*/
    myClass.method(unit.process);//此时可以调用
    
#endif
    /*
        产生新问题：如果么某个类不可见，它内部的方法又不是static全局的，就
                  无法调用了？
             解决：可以使用Lambda表达式解决，直接使用已经定义好的类
                  也可以使用函数对象，但是又要重新写这段代码，麻烦.
     */
    
    //注意：Lambda表达式对访问外部变量有限制,需要在[]里使用  &、= 符号
    myClass.method([&](int n){unit.process(n);});
    
    //注意：如果使用 = 号，最好将方法声明为const，因为如果编译器觉得你会修改
    //     里边的值,就要报错,编译器不是万能的，这个是否报错，不确定.
    myClass.method([=](int n){unit.process(n);});
    
    //这样也可以
    myClass.method([unit](int n)mutable{unit.process(n);});


    return 0;
}
