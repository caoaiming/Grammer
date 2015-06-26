#include <iostream>

using namespace std;
//内嵌类:存在的意义是该类与其他类都没有关系，于是将其封装成内嵌类，
//禁止其他人访问。

class MyClass
{
public:
    class InnerClass
    {
    private:
        int mCode = 100;
    public:
        int getCode();
        void setCode(int code)
        {
            mCode = code;
        }
    };
    //内嵌类不能在所属类中定义,下面这种方法是错误的：
    //InnerClass::getCode()
    InnerClass *getInnerClass()
    {
        return new InnerClass();
    }

};

//正确格式如下：
int MyClass::InnerClass::getCode()
{
    return mCode;
}

int main(int ac, char **av)
{
    MyClass::InnerClass innerClass;
    innerClass.setCode(200);
    cout << innerClass.getCode() << endl;

    cout << "---------------------------------------------------" << endl;

    MyClass myClass;
    cout << myClass.getInnerClass()->getCode() << endl;

    return 0;
}
