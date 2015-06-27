#include <iostream>
#include <new>

using namespace std;
/* 阻止new抛出异常 C++开关提供开关，<nothrow> 决定是否让new抛出异常*/
/* 如果失败，直接返回空指针 */

struct Big
{
    double array[30000000000];
};

int main(int ac, char **av)
{
    Big *big;
    try {
        big = new(nothrow) Big[1000000];//nothrow关键字阻止抛出异常
        if(big == nullptr)
        {
            cout << "分配内存空间失败，直接返回空指针<nullptr>"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    catch (bad_alloc &ba)
    {
        cout << "下面是错误信息" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    delete [] big; //万一在其他大内存机器上申请成功了，记得释放.
    
    return 0;
}