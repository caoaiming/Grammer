#include <iostream>

using namespace std;
/* static_cast 运算符
 * static_cast<<#type#>>(<#expression#>)
 *       要求： 类型 与 参数 必须是继承关系或者就是同一个类本身
 */

class ParentClass
{
public:
    virtual void process() {}
};

class SubClass : public ParentClass
{
    
};

class MyClass
{
    
};

int main(int ac, char **av)
{
    ParentClass *parentClass = new SubClass();
    SubClass *psubClass = static_cast<SubClass*>(parentClass);
                        /* 子类与父类的关系 */
    /*------------------------------------------------------*/
    MyClass *myClass = new MyClass();
    //SubClass *psubClass1 = static_cast<SubClass*>(myClass);
                /* 出错，两个类没有继承关系或是它本身那个类 */
    return 0;
}
