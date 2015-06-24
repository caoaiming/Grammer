#include <iostream>

using namespace std;
//多继承与共同基类
/*
 一个子类继承了多个父类，多个父类又有共同的基类，这样的话会怎么样？
 
 */
class baseClass
{
private:
    int mVlaue1;
public:
    baseClass(int value1)
    {
        mVlaue1 = value1;
        cout <<" baseClass "<< endl;
    }
};

class ParentClass1 : virtual public baseClass
{
private:
    int mValue2;
public:
    ParentClass1(int value2) : baseClass(value2)
    {
        mValue2 = value2;
        cout << "ParentClass1" << endl;
    }
};

class ParentClass2 : public virtual baseClass
{
private:
    int mValue3;
public:
    ParentClass2(int value3) : baseClass(value3)
    {
        mValue3 = value3;
        cout << "ParentClass2" << endl;

    }
};

class SubClass : public ParentClass1, public ParentClass2
{
private:
    int mValue;
public://通过不同的路径调用了两次baseClass的构造方法
#if 0
    SubClass(int value) : ParentClass1(value) ,ParentClass2(value)
    {
        mValue = value;
        cout << "SubClass" << endl;
    }
    //即使对baseClass是虚继承，C++只选择其中一个来做处理，但是初始化两个都会做，
#endif
    //如果向下面这样做的话，ParentClass1和ParentClass2后面的
    //对baseClass构造方法的显示调用就会忽略。。。。
    SubClass(int value) : baseClass(value), ParentClass1(value) ,ParentClass2(value)
    {
        mValue = value;
        cout << "SubClass" << endl;
    }
};

int main(int ac, char **av)
{
//虚基类或者虚继承，c++为多继承设计的。virtual
    SubClass* subClass = new SubClass(20);
    //baseClass *base = (ParentClass2 *)subClass;
    baseClass *base = subClass;//由编译器自动指定一个
    return 0;
}
