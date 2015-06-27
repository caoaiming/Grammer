#include <iostream>

using namespace std;
/*异常类的基类 exception.
 *   1.在std的命名空间中存在一个基本的异常类： exception
 *   2.exception 必须公有继承，其他方式都不可以.
 */
class ExceptionClass1 : public exception    /*必须是public*/
{
    
};

class ExceptionClass2 : public exception
{
    
};

int main(int ac, char **av)
{
    try {
        throw ExceptionClass2();
    } catch (ExceptionClass1 &ec1) {
        cout << "ExceptionClass1" << endl;
    } catch (exception &e) /*如果找不到对应类型，则用exception捕获*/
    {
        cout << "exception" << endl;
    }
    return 0;
}