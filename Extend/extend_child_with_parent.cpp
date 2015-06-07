#include<iostream>

using namespace std;

class ParentClass
{
private:
    int mCode = 10;
public:
    int getCode()
    {
        return mCode;
    }
    ParentClass(int code)
    {
        cout << "父类带参构造方法" << endl;
        mCode = code;
    }
};

class MyChild : public ParentClass {
private:
    string Name;
public:
    MyChild() : ParentClass(345)
    {
        cout << "子类无参构造方法" << endl;
        Name = "Bill";
    }
    MyChild(int code) : ParentClass(code), Name("xiao ming zi !")
    {
        cout << "子类带参构造方法" << endl;
    }
    string getName()
    {
        return Name;
    }
};

int main(int ac, char **av)
{
    MyChild myClass = MyChild();
    cout << myClass.getCode() << endl;
    cout << myClass.getName() << endl;

    cout << "--------------------------------------" << endl;
    MyChild *pClass2 = new MyChild(99999);
    cout << pClass2->getCode() << endl;
    cout << pClass2->getName() << endl;

    return 0;
}
