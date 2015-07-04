#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
/*
        第一个boost程序 : 类型转换
*/

using boost::lexical_cast;

int main(int ac, char **av)
{
    int n = lexical_cast<int>("321");
    
    cout << n << endl;
    double d = boost::lexical_cast<double>("123.321");
    cout << d << endl;
    
    string s1 = lexical_cast<string>(n);
    string s2 = lexical_cast<string>(d); /* 可能精度会发生变化 */
    
    cout << s1 << endl;
    cout << s2 << endl;
    
    try {
        n = lexical_cast<int>("abcd");//抛出异常
    }
    catch (boost::bad_lexical_cast& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
