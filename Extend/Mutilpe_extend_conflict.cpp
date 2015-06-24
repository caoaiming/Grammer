#include <iostream>

using namespace std;
//多继承与父类方法冲突
class ParentClass1
{
protected:
    virtual void show()
    {
        cout << "ParentClass1" << endl;
    }
};
class ParentClass2
{
protected:
    virtual void show()
    {
        cout << "ParentClass2" << endl;
    }
};

class SubClass : public ParentClass1, public ParentClass2
{
public:
    /*
    void show()
    {
        cout << "SubClass" << endl;
    }
     */
    void show1()
    {
        ParentClass1::show();
    }
    void show2()
    {
        ParentClass2::show();
    }
    
};

int main(int ac,char **av)
{
    //SubClass  class1;
    //class1.show();在多个父类中发现show方法。
    //class1.show();在当前类中实现时会调用当前类的show（）方法
    //这样可以避免冲突.
    /*  ParentClass1 * class2 = new SubClass();
        class2->show();
    */
    return 0;
}