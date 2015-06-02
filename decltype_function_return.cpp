#include <iostream>

using namespace std;

int fun1(int x)
{
    return x+x;
}
#if 0
auto fun2(int x) //如何推断，没法推断,错误！
{
    return x+x;
}
#endif
auto fun2(int x) ->int //正确，但是没有意义！
{
    return x+x;
}
#if 0
template <typename T1, typename T2>
void fun3(T1 x, T2 y)
{
    auto sum = x + y;
}
#endif

#if 0
template <typename T1, typename T2>
decltype(x+y) fun3(T1 x, T2 y) //错误，c++编译器从左向右扫描，此时x,y还没有定义,搞不定类型
{
    return x + y;
}
#endif

template <typename T1, typename T2>
auto fun3(T1 x, T2 y)  -> decltype(x+y)//用auto作为占位符，知道此处有返回值，然后在符号表里占位，扫到后边可以知道
                                       //将符号表内容写入         
{
    return x + y;
}


int main(int ac, char *av[])
{
    auto n = 20;
    auto sum = fun3(3,4);//编译器遇到这个调用会转化为 int (int x, int y) { return x+y;},然后处理.

    cout << sum << endl;

    return 0;
}
