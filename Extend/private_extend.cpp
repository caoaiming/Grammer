#include <iostream>
using namespace std;

class ParentClass {
private:
    int mCode = 10;
public:
    int getCode()
    {
        return mCode;
    }
};

class ParentClass1 {
private:
    int mCode1 = 20;
public:
    int getCode1()
    {
        return mCode1;
    }
};

//C++的多继承，为数不多的几种语言才支持
//如果是公有继承，则父类的所有公有方法和公有数据都可以访问
//如果是私有继承，则父类中public成员变成protectd,所有public成员只能在子类中
//访问，不能在外部访问.所以应该在子类中流方法去访问.
//
class SubClass : private ParentClass ,private ParentClass1 {
public:
    int code = getCode();//留个接口去访问父类的public方法.
    ParentClass& getParentClass()//尽量返回引用或指针，
                                 //否则会调用i对象中的复制构造方法
    {
        return *this;//对象本身
    }
};


int main(int ac, char **av)
{
    SubClass subClass;
    //cout << subClass.getCode() << endl;//错误，不能在外部访问，只能在子类
    //内部去访问.
    cout << subClass.code << endl;
    cout << subClass.getParentClass().getCode() << endl;
    //返回对象本身，因此可以直接访问他自己的getCode()方法.

    return 0;
}
