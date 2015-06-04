#include <iostream>

using namespace std;

class MyClass {
public:
    static int code;

    static string getName()
    {
        return "Bill Graters.";
    }
    static int getCode();
};

int MyClass::code = 20;
int MyClass::getCode()
{
    return code;
}

int main(int ac, char **av)
{
    //类中静态成员方法:
    //静态方法与静态数据一样，虽然在类中声明，却不存在于类中，而是在外部
    cout << MyClass::getName() << endl;
    cout << MyClass::getCode() << endl;

    return 0;
}

