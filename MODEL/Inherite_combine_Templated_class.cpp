#include <iostream>

using namespace std;

template <class T>
class TemplateClass
{
private:
    T mValue;
public:
    TemplateClass(T& value)
    {
        mValue = value;
    }
    T& getValue()
    {
        return mValue;
    }
};

template <class T>
class MyClass1 : public TemplateClass<T>
{
public:
    MyClass1(T& value) : TemplateClass<T>(value)
    {
        cout << "MyClass1" << endl;
    }
};

template <typename T> // <=>template <class T>
class MyClass2
{
public:
    TemplateClass<T> *p;
    MyClass2(T &value)
    {
        p = new TemplateClass<T>(value);
    }
    ~MyClass2()
    {
        delete p;
    }
};

int main(int ac, char **av)
{
    string s = "hello!";
    MyClass1<string> myClass1(s);
    cout << myClass1.getValue() << endl;
    
    long n = 1234;
    MyClass2<long> myClass2(n);
    cout << myClass2.p->getValue() << endl;
}