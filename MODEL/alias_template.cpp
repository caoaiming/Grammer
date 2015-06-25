#include <iostream>
#include <array>

using namespace std;
//模板别名: 解决模板名字比较长，或者参数比较多的情况
//传统方法： C语言的typedef, 缺点是类型定死，长度也可能定死，导致不灵活
//C++11新提供的using, 保持类型不定,既可以使用与模板，也可以使用于非模板

typedef array<int , 20> Arrayi;
typedef array<double, 10> Arrayd;

template <class T> //指定模板的类型参数
using arr = array<T, 20>;

//using使用于非模板,与typedef功能一样
typedef const char *pc1; //常量指针
using pc2 = const char*; //pc1 <=> pc2

int main(int ac, char **av)
{
    Arrayi a1;
    Arrayd a2;
    
    array<double, 20> a;
    
    arr<double> a3;
    arr<char>   a4;
    a3[0] = 12.1;
    cout << a3[0] << endl;
    return 0;
}
