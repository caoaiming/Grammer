#include <iostream>

using namespace std;

void fun1(int a, int b)
{
    a = a + b;
}
void fun2(int* a, int b)
{
    *a = *a + b;
}

void fun3(int &a, int b)//由编译器换为指针
{
    a = a + b;
}

int main(int ac, char **av)
{
    //引用类型的函数参数：在调用时，由编译器换为指针, 只用传递实际数值即可

    int a1 = 10;
    int b1 = 20;

    fun1(a1, b1); //无法返回
    cout << "a1 = " << a1  << endl;

    fun2(&a1, b1);
    cout << "a1 = " << a1  << endl;

    fun3(a1, b1);
    cout << "a1 = " << a1  << endl;

    return 0;
}
