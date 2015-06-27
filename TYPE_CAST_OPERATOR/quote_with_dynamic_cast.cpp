#include <iostream>

using namespace std;
/* dynamic_cast 与引用类型的转换(通常需要try ..catch包围)
 *   NOTE: dynamic_cast的参数必须是 <引用类型> 的值
 *   失败原因：
             1.待转换的类与要转的类型确实没有关系（比如不是继承关系）
             2.待转换的类型参数不是引用类型
 *
 */
class ParentClass
{
public:
    virtual void process()
    {
        cout << "parentclass" << endl;
    }
};

class SubClass : public ParentClass
{
public:
    virtual void process()
    {
        cout << "subclass" << endl;
    }
};

class MyClass
{
public:
    virtual void process()
    {
        cout << "myclass" << endl;
    }
};

int main(int ac, char **av)
{
    //ParentClass parentClass = SubClass();
    //SubClass &subClass = dynamic_cast<SubClass&>(parentClass);
    /*理论是可以的，但是运行时抛出了异常*/
    cout << "----------------------------------------" << endl;
    /*dynamic_cast的参数必须是 <引用类型> 的值*/
    SubClass subClass1;
    ParentClass &parentClass = subClass1;
    SubClass &subClass2 = dynamic_cast<SubClass&>(parentClass);
    subClass2.process();
    cout << "----------------------------------------" << endl;

    MyClass  myClass1;
    MyClass  &myClass2 = myClass1;
    try {
        SubClass &subClass3 = dynamic_cast<SubClass&>(myClass2);
           /*两个类没有派生关系，转换失败，抛出异常*/
    } catch(exception &e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
