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
    
    boost::smatch what;
    if(boost::regex_search(s1, what, expr)) {
        cout << what[0] << endl;
    }
    cout << "----------------------------------" << endl;
    
    boost::cregex_iterator it_begin = make_regex_token_iterator(s.c_str(), expr);
    
    boost::cregex_iterator it_end;
    
    /* 获得满足规则的字符串 */
    for(boost::cregex_iterator it = it_begin; it != it_end; it++)
        cout << *it << endl;

    
    return 0;
}
