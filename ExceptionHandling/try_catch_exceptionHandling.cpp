#include <iostream>

using namespace std;
/*引发异常与捕捉异常（throw、try、...catch）
 *    1.引发异常
 *    2.将可能产生异常的代码用try...catch括起来
 *    3.在catch中处理异常
 *
 *   优点： 不需要对factorial的返回值进行判断，如果发生异常，直接
 *         通过 throw 跳到 catch 处理中
 *
 */

int factorial(int n)
{
    if(n < 0)
    {
        //throw "n不能小于0";
        throw string("n 不能小于0 ");
    }
    
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

void process()
{
    try {  /* 类似于goto的功能，一旦出错，直接跳到catch语句中 */
        int n = -10;
        int jc = factorial(n);
        cout << n << "!= " << jc << endl;
    }
    //catch (const char* s) { /*接受异常的表达式变量*/
    catch (string s) {        /*类型需要对应       */
        cout << s << endl;
    }
}

int main(int ac, char **av)
{
    
    process();
    
    return 0;
}