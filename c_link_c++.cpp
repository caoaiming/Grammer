#include <iostream>

using namespace std;

extern "C" int sum(int a, int b)
{
    return a+b;
}

extern "C++" int csum(int a, int b)
{
    return a+b;
}

int main(int ac, char **av)
{
    //语言链接性（本质上是指定c++编译器链接时查找函数实现）
    //C语言：一个函数对应一个名称 process(int) _process
    //c++语言：一个函数对应多个名称（重载）process(int) _process_i
    //                                process(int  , float) _process_i_f
    //extern "C"  void process(int) ;  C必须大写
    //extern "C++" void process(int);  C必须大写
    //extern void process(int); //默认C++规则
    //
    int value = sum(1, 1);

    cout << value << endl;


    return 0;
}
