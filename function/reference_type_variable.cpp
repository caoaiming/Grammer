#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    //引用类型的变量：小名->同一个地址，两个人引用,一改都改
    //必须初始化，初始化的值不能是数值

    int value1 = 100;
    int &value2 = value1; //类型要一致

    cout << "value1 = "  << value1 << endl;
    cout << "value2 = "  << value2 << endl;

    value2 = 300;

    cout << "value1 = "  << value1 << endl;
    cout << "value2 = "  << value2 << endl;
    cout << &value1 << "=" << &value2 << endl;

    int *p = &value2;

    cout << *p  << "   address: " <<  p << endl;

    return 0;
}
