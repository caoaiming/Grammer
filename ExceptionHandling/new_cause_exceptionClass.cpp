#include <iostream>
#include <new>

using namespace std;
/* 由new产生的异常（bad_alloc）<分配空间过大,导致失败> */

struct Big
{
    double array[30000000000];
};

int main(int ac, char **av)
{
    Big *big;
    try {
        big = new Big[1000000];//太大，异常退出，不给执行的机会
    
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