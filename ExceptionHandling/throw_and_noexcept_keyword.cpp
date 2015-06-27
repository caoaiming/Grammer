#include <iostream>

using namespace std;
/*
   throw与noexcept
一、  noexcept: 禁止抛出异常（默认），后可跟一个bool判断：
      noexcept (false)  : 可以抛出异常
      noexcept (true)   : 不允许抛出异常
 
二、 throw:指定函数或方法抛出指定的异常（C98中加入的，不建议在C++11中使用）
   
 NOTE:尽量不要用，目前论坛存在两种争论:
 *      1.应该： 应为这样在函数或方法后面，有利于编译器优化
 *      2.反对： 每定义一个都要指定抛出的类型，比较麻烦,如果内部调用了
                其他的方法，他们抛出了别的异常，一层一层嵌套，不好...
 *
 */
class ExceptionClassA
{
    
};

class ExceptionClassB
{
    
};
/*由于C++是运行时检测，不像Java的编译时检测，
 *所以抛出的这两个类型没有人捕获时也不会报错
 *另外，我们限定了抛出的类型，除此之外的类型不会捕获，即便有捕获
 *的类型catch语句，也不执行捕获.
 */
void process1() throw(ExceptionClassA, ExceptionClassB)
{
    //throw "出错了";
    throw  ExceptionClassA();
}
          /*不能抛出任何的异常*/
//*void process2() noexcept (false / true)

 /*这里bool值可以是一个表达式,必须是常量表达式,这么写其实不对
  *只不果短路运算使系统没有继续向后扫描，没发现 n < 100不是常量表达式*/
template <class T>
void process2(int n) noexcept (sizeof(T) < 4 && n < 100)
{
    throw "Hello World!"; /*不能抛出，这里出错*/
}

int main(int ac, char **av)
{
    try {
        process1();
    } catch (const char *s) {
        cout << s << endl;
    }
    catch(ExceptionClassA &a)
    {
        cout << "ExceptionCLassA" << endl;
    }
    try {
        //process2<char>();     //不允许
        process2<int>(99);      //允许
        //process2<short>(100);   //这种情况报错原因： &&是短路运算，
                                //因为前边成立，后便也需判断，但是
                                //要求必须是一个常量，而我们是个变量
    
    } catch (const char *s) {
        cout << s << endl;
    }
    return 0;
}