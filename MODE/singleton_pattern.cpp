#include <iostream>

using namespace std;
//单间模式：(singleton)只允许定义一个类，唯一一个。
//1. 不能使用new创建对象,也不能直接定义类变量
//2. 至少需提供一个静态方法，用于返回唯一的对象实例

class SingletonClass {
private:
    static SingletonClass* instance;
    SingletonClass()
    {
    }
public:
    static SingletonClass* getInstance()
    {
        if(instance == nullptr)//只能使用一次，下一次不为空后，进不去。
        {
            instance = new SingletonClass();
        }
        return instance; 
    }
    string getName()
    {
        return "Bill";
    }
};
SingletonClass* SingletonClass::instance = nullptr;
int main(int ac, char **av)
{
    SingletonClass* instance1 = SingletonClass::getInstance();
    cout << instance1->getName() << endl;

    return 0;
}
