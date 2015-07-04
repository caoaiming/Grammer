#include <iostream>

using namespace std;
//public可以在类的外部访问，可以在类的内部访问，也可以在子类中访问
//private只能在当前类内部访问
//protected在类的外部和private权限一样，不可以访问
//在子类中和public一样，可以访问父类的public、protected.

class ParentClass
{
    private:
        int code1 = 20;
    protected:
        int code2 = 30;
    public:
        int getCode1()
        {
            return code1;
        }
};

class SubClass : public ParentClass
{
    public: 
        int getCode2()
        {
            return code2;
        }
};

int main(int ac, char **av)
{
    SubClass subClass;
    cout << subClass.getCode2() << endl;
    cout << subClass.getCode1() << endl;
    //cout << subClass.code1 << endl;  //不允许
    //cout << subClass.code2 << endl;  //不允许
    
    return 0;
}
