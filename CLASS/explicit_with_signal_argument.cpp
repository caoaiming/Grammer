#include <iostream>

using namespace std;

class Integer {
private:
    int mCode;
public:
//  Integer(int value)
    explicit Integer(int value)//这样一来就不允许Integer n = 20,这种隐式调用
    {
        mCode = value;
    }
    int getValue()
    {
        return mCode;
    }
};

int main(int ac, char **av)
{
//    Integer n = 20; // <===>  Integer n = Integer(20);
//隐式调用，只有一个参数，可以这样初始化, 编译器允许这样来，他自己做转换.
    Integer n = Integer(30);
    cout << n.getValue() << endl;

    return 0;
}
