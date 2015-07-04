#include <iostream>

using namespace std;

void inline fun(int a, int b)
{
    cout << a+b << endl;
    cout << a-b << endl;
}

int main(int ac, const char **av)
{
    //inline: 函数调用比较多，并不复杂，而且空间占用不多, 降低寻址开销；
    //会将函数代码放置到调用处
    //缺点：占用内存了，每调用一次，复制一次，要求调用点多，代码尽可能短；
    fun(3, 5);
    
    return 0;
}
