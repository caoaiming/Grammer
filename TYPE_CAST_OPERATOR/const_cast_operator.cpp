#include <iostream>

using namespace std;
/*  const_cast 操作符 使用方法
    const_cast<<#type#>>(<#expression#>)
 */

class MyClass1
{
    virtual void process() {}
};

class MyClass2
{
    
};

int main(int ac, char **av)
{
    MyClass1 *pMyClass1_1 = new MyClass1();
    
    const MyClass1 *pMyClass1_2 = const_cast<MyClass1*>(pMyClass1_1); /* 增加const属性 */
    
    MyClass1 *pMyClass1_3 = const_cast<MyClass1*>(pMyClass1_2);
                       /* 去掉const属性 */
    /*--------------------------------------------------------*/
    
    //MyClass2 *pMyClass2 = const_cast<MyClass2*>(pMyClass1_2);
                       /* 出错， 类型不一致 */
    MyClass2 *pMyClass2 = dynamic_cast<MyClass2*>(pMyClass1_1);
                       /* 需要一个虚方法 */
    
    /*---------------------对 "引用" 用法--------------------*/
    
    MyClass1 myClass1_1;
    MyClass1 &myClass1_2 = myClass1_1;
    const MyClass1 myClass1_3=const_cast<MyClass1&>(myClass1_2);
                        /* 类型仍然要一致 */
    
    return 0;
}
