#include <iostream>

using namespace std;

class MyClass
{
private:
    int mValue = 0;
public:
    MyClass(int value) 
    { 
        mValue = value;
    }
         /*复制构造方法*/
    MyClass(const MyClass& myClass);

    void setValue(int value)
    {
        mValue = value;
    }

    int getValue()
    {
        return mValue;
    }
};
/*自己定制的复制构造方法：*/
MyClass::MyClass(const MyClass& myClass)
{
    mValue = myClass.mValue * 2;
    cout << myClass.mValue << endl;
}

int main(int ac, char **av)
{
    //复制构造方法
    //             默认复制构造方法：所有的内容全部拷贝,可自己定制
    MyClass myClass(20);
    MyClass newClass = myClass; //此处发生内存拷贝，是一份复制品
    cout << newClass.getValue() << endl;

    cout << "---------------------------------------" << endl;
    //4种触发条件:
    
    //情况1：
    MyClass myClass1(10);
    MyClass newClass1(myClass1);

    //情况2：
    MyClass myClass2(30);
    MyClass newClass2 = myClass2;

    //情况3：
    MyClass myClass3(50);
    MyClass newClass3 = MyClass(myClass3);

    //情况4：
    MyClass myClass4(70);
    MyClass *pMyClass4 = new MyClass(myClass4);

    delete pMyClass4;
    return 0;
}
