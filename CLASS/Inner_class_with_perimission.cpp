#include <iostream>

using namespace std;
/*
 嵌套类的访问权限：
 private  :只有宿主类知道嵌套类的存在，嵌套类对于外部（包括宿主类外部和宿主类
            的派生类）都是隐藏的
 
 protected:只有宿主类知道嵌套类的存在，嵌套类对于外部（包括宿主类外部和宿主类的
            派生类）都是隐藏的，但是子类可以继承嵌套类.
 
 public   :无论哪里都可以访问，访问权限没有限制
 
 */

class MyClass
{
private:
    class InnerClass1
    {
    public:
        int code = 100;
    };
protected:
    class InnerClass2
    {
    public:
        int code = 200;
    };
public:
    class InnerClass3
    {
    public:
        int code = 300;
    };
    
    InnerClass1 *getInnerClass1()
    {
        return new InnerClass1();
    }
};

class SubClass : public MyClass
{
public:
    InnerClass2* getInnerClass2()
    {
        return new InnerClass2();
    }
    
    InnerClass3* getInnerClass3()
    {
        return new InnerClass3();
    }
};

int main(int ac, char **av)
{
    //MyClass::InnerClass1 class1;   /* 出错，私有禁止访问     */
    //MyClass::InnerClass2 class2;   /* 出错，受保护禁止访问   */
    //MyClass::InnerClass3 class3;   /* 正确，可以访问,public */
    MyClass myClass;
    
    //myClass::InnerClass1 *innerClass1 =myClass.getInnerClass1();
    /*不能用宿主类来单独声明这个内嵌类变量，总之不可访问*/
    cout << myClass.getInnerClass1()->code << endl;
    cout << "--------------------------------------------" << endl;
    
    SubClass subClass;
    cout << subClass.getInnerClass2()->code << endl;
    cout << "-------------------------------------------" << endl;
    
    SubClass::InnerClass3 *innerClass3 = subClass.getInnerClass3();
    cout  << innerClass3->code << endl;
    
    return 0;
}