#include <iostream>

using namespace std;
/*返回错误码和abort函数,不足之处：
 *   1.使用条件语句挨个判断
 *   2.当异常条件非常多，可能无法枚举所有的异常，或者忘了
 */

int factorial(int n)
{
    if(n < 0) {
        //return -1;
        cout << "n不能小于0" << endl;
        abort();
    }
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(int ac, char **av)
{
    int n = -10;
    int result = factorial(n);
    
    if(result > 0)
        cout << "n! = " << result << endl;
    else if(result == -1)
        cout << "n不能小于0" << endl;
    
    return 0;
}