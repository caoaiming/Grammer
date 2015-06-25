#include <iostream>

using namespace std;

/*模板类与友元
 *1.  非模板友元
 *                :普通函数，并没有使用到参数
 *2.  使用类模板类型参数的友元
 *                ：模板类至少一个类型参数，我们的友元函数也使用类模板的
 *                  一样类型参数
 *3.  使用自己的类型参数的友元 
 *                ：使用自己的类型参数，与友元函数参数类型没有半毛钱关系
 *
 *友元：在函数中可以访问该类的私有成员和受保护的成员.
 * 
 * 实现第2种友元函数，需要三步:
 *     (1)在模板类中声明友元函数
 *     (2)在模板类的外面实现友元函数
 *     (3)在类模板的前面声明友元函数
 * */

template <typename T> void print(T& t); //声明一下就可以了，第三步

template  <typename T>
class TemplateClass
{
private:
    T mValue;
public:
    TemplateClass(T value)
    {
        mValue = value;
    }
    friend void printSize();//此函数并没有使用模板类成员，属于普通函数
                            //只是写在了模板类中
    friend void print<>(TemplateClass<T>&);//要求传进来的必须是一个引用类型
    //并且必须是TemplateClass的实例.由于弱推导，需要在类外边再声明一下
};

template <typename T> //模板类的方法必须加次声明
void printSize()
{
    cout << "TemplateClass size:" << sizeof(TemplateClass<T>) << endl;
}

template <typename T>
void print(T& t)
{
    cout << "TemplateClass size:" << t.mValue  << endl;
}

//普通类
class MyClass
{
private:
    int mCode = 200;
public:
    template <class T1 , class T2> friend void show(T1& , T2&);
};

template <class T1, class T2> void show(T1& t1, T2& t2)
{
    cout << t1.mCode << endl;
    cout << t2 << endl;
}

int main(int argc, char *argv[])
{
    printSize<int>();//size = 4; 需要指明类型参数，如果不指明，无法推断
    printSize<long long>(); //size = 8


    cout << "-------------------------------------------------" << endl;
    TemplateClass<int> templateClass(123);
    print(templateClass);//不需要类型参数，他会自动推断，属于省略写法
    print<TemplateClass<int>>(templateClass);//完整写法

    cout << "-------------------------------------------------" << endl;

    MyClass  myClass;
    string s = "hellow world.";
    show(myClass, s);

    return 0;
}
