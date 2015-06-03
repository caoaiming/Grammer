#include <iostream>

#if 0
    操作符重载的限制：
        <1>.重载后的操作数至少有一个是用户自定义义类型，
            为了防止用户重载基本类型的操作符号.
        <2>.不能改变操作符本身的特性，例如：不能将二元操作符，
            变成一元或者三元操作符.
        <3>.不能修改操作符本身的优先级.
        <4>.不能创建新的操作符.
        <5>.并不是所有的操作符都可以重载，例如sizeof 、指针(*)、
            ? :(三目运算符)、等...
        <6>.大多数可以重载的操作符都可以使用成员方法和非成员方法（函数形式）
          重载，但是 赋值: =  ,函数调用： ()，下标运算符: [],
          通过指针 访问成员:-> 只能通过方法成员重载.
#endif
using namespace std;

struct Mystruct {
    int value = 20;
};

/* Error
int operator+(int left, int right)
{
    return left - right;  //怕你这样胡整，那就乱套了
}
*/

int operator+(int left, struct Mystruct &myStruct)
{
    return left + myStruct.value;
}
/*----------------------------------------------------------------------*/
struct NEWstruct {
    int value = 10;
    int operator%(int v)  //直接内联了，而且参数只允许有一个.
    {
        return value % v;
    }
    void operator=(int v)//一些只能存在于方法中的操作符.
    {
        value = v;
    }
};
/*或者:（也可以在函数中,参数只能有两个)
 *  int operator%(NEWstruct &new_struct, int v)
 *  {
 *      return new_struct.value % v;
 *  }
 */

/*此函数不可以这样定义,因为"="操作符只能在方法成员中，不能在函数里。
 *
 * void operator=(NEWstruct &new_struct, int v)
 * {
 *    new_struct.value = v;
 * }
 */

int main(int ac, char **av)
{
    int a = 1 + 2;
/*--------------------------------<<1>>------------------------------
 *  
 *  int operator+(int left, Mystruct myStruct)
 *  int x = 1 + Mystruct();   Mystruct()是常量 value = 0编译器赋值为0,
 *
 *-----------------------------------------------------------------------*/
 
//    int operator+(int left, Mystruct &myStruct) //引用必须是变量，不能是
//    常量，因为只是个别名.增加一个引用。
    Mystruct mystruct;
    int x = 1 + mystruct;
    cout << "x = "  << x << endl;   

//---------------------------------<<2>>-------------------------------
    NEWstruct new_struct;
    
    cout << new_struct % 3 << endl;

//---------------------------------<<3>>-------------------------------
//不允许修改优先级：先加减、取余, 后加减。

/*---------------------------------<<4>>-------------------------------
 *不允许创建新的操作符号，因为没法定义优先级.苹果的switch语言允许这样：
 *int a = myStruct +&^%$ 4;  可以自己定制，缺点：可读性差.
 */


//---------------------------------<<6>>-------------------------------
    new_struct = 9999;
    cout << new_struct.value  << endl;
    
    
    return 0;
}
