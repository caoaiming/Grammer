#include <iostream>

using namespace std;

class Myclass {
private:
    int Value;
public:
    int  getValue();
    void setValue(int num)
    {
        Value = num;
    }
    Myclass(int value);
    Myclass operator+(Myclass aa);
    Myclass operator-(Myclass bb);
};

int Myclass::getValue()
{
    return Value;
}
#if 0
void MyClass::setValue(int num)
{
    Value = num;
}
#endif
Myclass::Myclass(int value)
{
    this->Value = value;
}


Myclass Myclass::operator+(Myclass aa)
{
    Myclass myClass(0);
//  myClass.Value = myClass1.Value + myClass2.Value;
    myClass.Value = Value + aa.Value;
    cout << "Value = " << Value << endl; //Value是myClass1的.
//  myclass1是调用者， myClass2是参数, myClass是当作返回值了.

    return myClass;
}

/*********************************************************************
 *        类的操作符重载,是发生在类的内部，可以访问一切私有成员      *   
 *********************************************************************/
Myclass Myclass::operator-(Myclass bb)
{
    Myclass myClass(1);
//  myClass4.Value = Value + bb.Value; //== 50,
//  重点看运算，与函数所带符号无关
    myClass.Value = Value - bb.Value; //== -10
    cout << "Value = " << Value << endl;

    return myClass;
}

/*********************************************************************
 *      函数的操作符重载,是发生在类的外部，不可以访问一切私有成员    *   
 *********************************************************************/
Myclass operator*(Myclass &left, Myclass &right)
{
    Myclass myClass(0);
    //不可以直接访问私有成员，需要setValue()方法.
    myClass.setValue(left.getValue() * right.getValue());

    return myClass;
}

int main(int ac, char **av)
{

    Myclass myClass1(20);
    Myclass myClass2(30);
    Myclass myClass3(40);
//操作符重载：
//    myClass1 + myClass2 ==>  myClass1.operator+(myClass2) {this}
//    Myclass myClass4 = myClass1 + myClass2;
//    Myclass myClass5 = myClass1 - myClass2;
      Myclass myClass6 = myClass1 + myClass2 - myClass3;
//--> ( myClass1.operator+( myClass2 )).operator-( myClass3 );
//    验证得到的计算方过程，已经证明.

//    cout << myClass4.getValue() << endl;
//    cout << myClass5.getValue() << endl;

      cout << myClass6.getValue() << endl;
      
      Myclass myClass7 = myClass1 * myClass2;
      cout << myClass7.getValue() << endl;

      Myclass myClass8 = myClass1 - myClass2 * myClass3;
      cout << myClass8.getValue() << endl;

     return 0;
}
