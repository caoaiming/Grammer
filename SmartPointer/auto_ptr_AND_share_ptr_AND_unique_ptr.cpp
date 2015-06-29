#include <iostream>

using namespace std;
/*
      几个智能指针的区别以及应用场景:
      auto_ptr  :
      share_ptr :
      unique_ptr:
 */

void process1()
{
    auto_ptr<string> str1(new string("hello world!"));
    auto_ptr<string> str2;
    
    str2 = str1; /*所有权转移：*/
    //cout << *str1 << endl; <引发抛出异常>
    cout << *str2 << endl;

    //如果有两个智能指针指向同一片内存，在释放时引发问题.
    
    /*解决办法: 1.深度复制，连智能指针指向的对象一起复制过来.
               2.所有权：对于一个特定对象，同时只能有一个智能指针拥有它，
                如果发生赋值操作，则所有权转移.
     NOTE: 如果此处换成unique_ptr则直接编译器报错，不允许这样做，没法运行
               3.引用智能指针计数器：一个特定对象可以被多个智能指针引用
    智能指针维护一个智能指针计数器，如果一个某个指针过期，则计数器减1，直到
    计数器减为0,才会释放.
     */
}

void process2()
{
    unique_ptr<string> str1(new string("hello world!"));
    unique_ptr<string> str2;
    //str2 = str1;  //不允许，直接在编译时就有编译器报错.
    cout << *str2 << endl;
}

void process3()
{
    shared_ptr<string> str1(new string("hello world!"));
    shared_ptr<string> str2;
    str2 = str1;//这样，当前计数器为2,变为0时，才会释放.
    cout << *str2 << endl;
}


int main(int ac, char **av)
{
    //process1();
    process3();
    return 0;
}