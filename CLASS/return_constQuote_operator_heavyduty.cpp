#include <iostream>

using namespace std;

class MyClass {
public:
    int code;
    MyClass(int code)
    {
        this->code = code;
    }

    const MyClass& operator+(MyClass &myClass);
/*
    MyClass(const MyClass& myClass)
    {
        code = myClass.code;
        cout << "const MyClass& myClass" << endl;
    }
*/
};

const MyClass& MyClass::operator+(MyClass &myClass)
{
    myClass.code = code + myClass.code;
    return myClass;
}

int main(int ac, char **av)
{
    MyClass myClass1(20);
    MyClass myClass2(30);
    MyClass myClass3 = myClass1 + myClass2;

    cout << myClass3.code << endl;
#if 0
    如果返回常量引用时，就不可以这样用了,因为myClass2不可以改变
    myClass1 + myClass2 = myClass3;//没有意义，做个例子看操作符重载实质
    cout << "class1 ->" << myClass1.code << endl;
    cout << "class2 ->" << myClass2.code << endl;//发生改变，因为myClass2
    cout << "class3 ->" << myClass3.code << endl;//是参数.返回的也是他的
                                                 //引用
#endif
    return 0;
}
