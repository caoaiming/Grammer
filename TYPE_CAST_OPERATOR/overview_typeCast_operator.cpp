#include <iostream>

using namespace std;
/*  类型转换操作符(运算符)概述
 
  1. dynamic_cast<<#type#>>(<#expression#>);
     :可以进行任何类型转换，功能最强大，比较灵活.
 
  2. const_cast<<#type#>>(<#expression#>);
     :type 和 expression 类型必须相同，但是可以将一个声明为常量的变量
       转换为非常量，暗示可以去掉或加上 const或valatite.
       valatite:功能比较多，可以访问一片内存的映射
 
  3. static_cast<<#type#>>(<#expression#>);
    :type必须可隐式转换为expression，即：type是expression的派生类或者
      类本身
 
  4. reinterpret_cast<<#type#>>(<#expression#>);
    :进行特殊类型转换，eg: 将一个long 类型转换为 指针类型（*）
     这在C语言中是可以直接进行转换的。
 */

int main(int ac, char **av)
{
    return 0;
}
