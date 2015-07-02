#include <iostream>

using namespace std;
/*
     Lambda表达式类型

function()类：

     如何声明一个Lambda表达式的类型。可以使其像系统提供的那样传入函数对象或         
                                                     Lambda表达式
 
eg:
     replace(<#_ForwardIterator __first#>, <#_ForwardIterator __last#>, <#const _Tp &__old_value#>, <#const _Tp &__new_value#>)
         
     find(<#_InputIterator __first#>, <#_InputIterator __last#>, <#const _Tp &__value_#>)
*/

int output(int n)
{
    return n % 7 == 0;
}

/* 要求传入bool返回值,只有一个int类型的参数的Lambda表达式或函数对象*/
int outInts(int n, function<bool (int)> func)
{
    int count = 0;
    srand((unsigned)time(0));
    
    for(int i = 0; i < n; i++) {
        int value = rand();
        
        if(func(value)) {
            cout << value << endl;
            count++;
        }//end if
    }//end for
    
    cout << endl;
    return count;
}

int main(int ac, char **av)
{
    /* 1. 传入Lambda表达式 */
    cout << outInts(20, [](int n){return n % 3 == 0;}) << endl;
    
    /* 2. 传入函数对象 */
    cout << outInts(20, output) << endl;
    
    return 0;
}
