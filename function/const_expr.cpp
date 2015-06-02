#include <iostream>

using namespace std;

constexpr int fac(int n)
{
    //cout << "xyz" << endl; //不可以出现不能转换为常量的语句
    return (n > 1)? fac(n-1) * n : 1;
}

int main(int ac, char **av)
{
    //可在编译时生成常量的函数
    //1.constexpr :前提是这个函数可以被常量化
    //2.带有关键字constexpr函数不可以定义函数原型，编译器无法确定能不能转换

    int jc = fac(10); //参数值是常量的时候才会转换.编译时,变为:jc = 3628800

    cout << jc << endl;

    return 0;
}
