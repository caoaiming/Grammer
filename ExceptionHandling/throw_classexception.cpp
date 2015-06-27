#include <iostream>
using namespace std;
//将对象作为异常表达类抛出
class ExceptionClass1
{
public:
    int code;
    string msg;
    ExceptionClass1(int v1, string v2):code(v1), msg(v2)
    {
    }
};

class ExceptionClass2
{
public:
    double value;
    string msg;
    ExceptionClass2(double v1, string v2):value(v1),msg(v2)
    {}
    
};

void exceptionFunc(int n)
{
    try {
        if(n  <  0)
            throw ExceptionClass1(n, "N小于0");
        else if(n == 0)
            cout << "n = " << n << endl;
        else
            throw ExceptionClass2(100.2, "N大于0");
    }
    catch(ExceptionClass1 &rc1){
        cout << "rc1.code = " << rc1.code << endl;
        cout << "rc1.msg = " << rc1.msg << endl;
    }
    catch(ExceptionClass2 &rc2){
        cout << "rc2.value = " << rc2.value << endl;
        cout << "rc2.msg = " << rc2.msg << endl;
    }
    
}

int main(int ac, char **av)
{
    exceptionFunc(100);
    exceptionFunc(-100);
    exceptionFunc(0);
    return 0;
}