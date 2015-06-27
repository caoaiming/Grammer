#include <iostream>
#include <exception>

using namespace std;
//系统预定义的异常类（在std中）：  exception
/*
 *logoc_error
 *runtime_error
 *   ....
 */
class MyException : public exception //派生类,在自己的异常类中最好这样
{
private:
    const char *mWhat;
public:
    explicit MyException(const char *s)
    {
        mWhat = s;
    }
    virtual const char* what() const _NOEXCEPT//const限定我们不能
    {                                         //修改类的成员变量
        return mWhat;
    }
};
int main(int ac, char **av)
{
    int n = 30;
    try {
        if(n == 10)
            throw length_error("长度错误");
        else if (n == 20)
            throw out_of_range("超出范围");
        else if(n == 30)
        {
            throw MyException("MyException");
        }
    }
    catch(length_error &length)
    {
        cout << length.what() << endl;
    }
    catch(logic_error &logic)
    {
        cout << logic.what() << endl;
    }
    //捕获所有前边未捕获的异常,系统基类(抛出我们自己的异常)
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}