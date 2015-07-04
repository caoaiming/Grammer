#include <iostream>
#include <boost/regex.hpp>
#include <locale>
#include <string>

using namespace std;
/*
     正则表达式与字符串的比较
*/

int main(int ac, char **av)
{
    string s1 = "今天是2015-03-04，星期几知道吗？上个月，就是2015-03-15，知道是什么日子吗？";

    boost::regex expr("\\d{4}(\\-)\\d{1,2}(\\-)\\d{1,2}");
    
    string replace = "<日期>";
    cout << boost::regex_replace(s1, expr, replace) << endl;
    
    
    return 0;
}
