#include <iostream>

using namespace std;
/*
    <1> 模板调用的低效性.  auto xyz = process(20);
    process是什么？
    
    1. 函数：
    2. 函数指针：
    3. 函数对象：
    4. Lambda表达式：
 
    结论： double fun1(double value) 是最后所有渠道调用的形式
          调用了6次，却产生了5个process方法，比较消耗资源.
          而我们希望只产生一个.
 
    <2>  解决办法 :  使用function()包装器（由STL提供.）
                    解决模板调用的低效问题.
 
    <3>  更简洁的使用function包装器
           
             1.在调用上做一些文章
             2.在定义上做一些处理  (*推荐使用)
 
 
*/
template <class T, class F>
T process(T t, F f)
{
    static int count = 0;
    count ++;
    cout << "process count = " << count << "   Address = " << &count << endl;
    return f(t);
}

/* 第二种办法： 改造定义函数 */
template <class T>
T process1(T t, function<T(T)> f)
{
    static int count = 0;
    count ++;
    cout << "process count = " << count << "   Address = " << &count << endl;
    return f(t);
}

double fun1(double value)
{
    return value + 10;
}

double fun2(double value)
{
    return value - 10;
}

class MyClass1
{
private:
    double mValue;
public:
    MyClass1(double value)
    {
        mValue = value;
    }
    double operator()(double value)
    {
        return value + mValue;
    }
};

class MyClass2
{
private:
    double mValue;
public:
    MyClass2(double value)
    {
        mValue = value;
    }
    double operator()(double value)
    {
        return value - mValue;
    }
};

int main(int ac, char **av)
{
    auto lambda1 = [](double value){return value;};
    auto lambda2 = [](double value){return value * 2;};

    double t = 20.123;

    //                第<1>课时
#if 0
    cout << process(t, fun1) << endl;
    cout << process(t, fun2) << endl;
    cout << process(t, MyClass1(123.2)) << endl;
    cout << process(t, MyClass2(123.543)) << endl;
    cout << process(t, lambda1) << endl;
    cout << process(t, lambda2) << endl;
    
#endif

    
    //                第<2>课时
#if 0
    function<double(double)> f1 = fun1;
    function<double(double)> f2 = fun2;
    function<double(double)> f3 = MyClass1(123.2);
    function<double(double)> f4 = MyClass2(5432.1);
    function<double(double)> f5 = lambda1;
    function<double(double)> f6 = lambda2;
    
    cout << process(t, f1) << endl;
    cout << process(t, f2) << endl;
    cout << process(t, f3) << endl;
    cout << process(t, f4) << endl;
    cout << process(t, f5) << endl;
    cout << process(t, f6) << endl;

#endif

    
    //                     第<3>课时
#if 0
    //第一种办法： 改造调用函数

    typedef function<double(double)> f;
    cout << process(t, f(fun1)) << endl;
    cout << process(t, f(fun2)) << endl;
    cout << process(t, f(MyClass1(123.1))) << endl;
    cout << process(t, f(MyClass2(23.12))) << endl;
    cout << process(t, f(lambda1)) << endl;
    cout << process(t, f(lambda2)) << endl;
#endif
    
   //第二种办法： 改造调用函数(见上面)
    cout << process1<double>(t, fun1) << endl;
    cout << process1<double>(t, fun2) << endl;
    cout << process1<double>(t, MyClass1(123.2)) << endl;
    cout << process1<double>(t, MyClass2(123.543)) << endl;
    cout << process1<double>(t, lambda1) << endl;
    cout << process1<double>(t, lambda2) << endl;
    /* 由于此种情况不能自动推断泛型类型,所以需要添加<double>指明类型 */
    
    return 0;
}
