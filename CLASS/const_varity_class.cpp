#include <iostream>

using namespace std;

class Calendar
{
private:
      const int months = 12;
//    float values[months]; 12只是占位符，系统并没有真正将这个值赋给
//    months，这只是类的声明，再没有实例化之前， months并不存在
//    不会申请空间,只有在定义并实例化后才会存在12,不确定数组多大
//    需要实际的值, 不知到类要多大的空间。
//    方法一：
      enum{months1 = 12};  //12的一个别名,会做替换。
      static const int months2 = 12; //独立于这个类，位于堆区，全局变量
public:
    void method()
    {
        cout << months << endl;
    }
};

int main(int ac, char **av)
{

    Calendar ss;
    ss.method();

    return 0;
}
