#include <iostream>

using namespace std;

//类型转换（数值与对象之间的转换）
//operator typename() {...}
//1.转换函数必须是方法
//2.转换函数不能有返回值
//3.转换函数不能有参数
class Myclass {
private:
    int mValue;
    double mDvalue;
public:
    Myclass(int value)
    {
        mValue = value;
    }
    Myclass(double num)
    {
        mDvalue = num;
    }
    operator int();
    operator double()
    {
        return mDvalue;
    }
};

Myclass::operator int() //默认自带返回值，不需要指定
{
    return mValue;
}

int main(int ac, char **av)
{    
    int n = 33;

    Myclass myClass(30);//将int类型的值转换为Myclass对象
    int value = myClass;//将对象转换为数值
    cout << value << endl;

    Myclass myClass1(30.12345);
    double value1 = myClass1;
    cout << value1 << endl;

    return 0;
}
