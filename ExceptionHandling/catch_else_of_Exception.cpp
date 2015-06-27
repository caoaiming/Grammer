#include <iostream>
using namespace std;
//将对象作为异常表达类抛出 + 将多个异常对象都放到一起用else判断。
/*
 * 统一使用父类捕获异常，然后再父类里判断是哪个类型的异常，再强制转换
 */
class ParentExceptClass
{
public:
    float value;
    string msg;
    string information;
};
class ExceptionClass1 : public ParentExceptClass
{
public:
    int code;
    string msg;
    ExceptionClass1(int v1, string v2):code(v1), msg(v2)
    {
        information = "ExceptionClass1";

    }
};

class ExceptionClass2 : public ParentExceptClass
{
public:
    int value;
    string msg;
    ExceptionClass2(int v1, string v2):value(v1), msg(v2)
    {
        information = "ExceptionClass2";
    }
};

class ExceptionClass3 :public ParentExceptClass
{
public:
    ExceptionClass3() {
        information = "ExceptionClass3";
    }
};


void exceptionFunc(int n)
{
                   /* 这里只抛出异常 */
    if(n  <  0) {
        throw ExceptionClass1(n, "N小于0");
    }
    else if(n == 0)
        throw ExceptionClass3();
    else
        throw ExceptionClass2(100.2, "N大于0");
    
}
//捕捉异常的else
int main(int ac, char **av)
{
    try {
        exceptionFunc(-100);
    } catch (ParentExceptClass &parent) {
        if("ExceptionClass1" == parent.information)
        {/* 把 parent 强制转换为 ExceptionClass1类型的 ec */
            ExceptionClass1 &ec = static_cast<ExceptionClass1&>(parent);
            cout << ec.information << endl;
            cout << ec.code << endl;
            cout << ec.msg << endl;
        }
        
        /* ...类似上面 ... */
        
        else
        {
            cout << parent.information << endl;
            cout << "parent.value" << parent.value << endl;
        }
    }
    
    return 0;
}