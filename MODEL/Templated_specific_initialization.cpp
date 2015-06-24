#include <iostream>
using namespace std;

//模板类得显示具体化。
//如果比较字符指针，可以使用strcmp()函数.

template <typename T>
class Compare
{
private:
    T mValue1;
    T mValue2;
public:
    Compare(T &value1, T & value2):mValue1(value1),mValue2(value2)
    {};
    int _compare()
    {
        if(mValue1 > mValue2)
            return 1;
        else if(mValue1 < mValue2)
            return -1;
        else
            return 0;
    }
};

class MyClass
{
private:
    int mValue;
public:
    MyClass(int value)
    {
        mValue = value;
    }
    virtual bool operator < (MyClass& myclass)
    {
        return mValue < myclass.mValue;
    }
    virtual bool operator > (MyClass& myclass)
    {
        return mValue > myclass.mValue;
    }
};

//模板类显示具体化
//1.阻止编译器为这个类生成相应的模板，使用我们自己定义的
template<> class Compare<const char*>//指定具体的参数
{
private:
    const char *mValue1;
    const char *mValue2;
public:
    Compare(const char *value1, const char *value2)
    {
        mValue1 = value1;
        mValue2 = value2;
    }
    
    int str_compare()
    {
        return strcmp(mValue1, mValue2);
    }
};

int main(int ac, char **av)
{
    int n1 = 20, n2 = 30;
    Compare<int> ss(n1,n2);//-1

    cout << ss._compare() << endl;
    
    MyClass s1(30), s2(20);
    Compare<MyClass> compareMyClass(s1, s2);
    
    cout << compareMyClass._compare() << endl;
    
    const char *c1 = "w";
    const char *c2 = "h";

    Compare<const char*> compareCharp(c1, c2);
    //其实是在按地址大小来比较，所以与'w'\'h'的ASCII码没关系
    //cout << compareCharp._compare() << endl;
    cout << compareCharp.str_compare() << endl;
    
    return 0;
}
