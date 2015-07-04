#include <iostream>
#include <boost/regex.hpp>
#include <locale>

using namespace std;
/*
     正则表达式与字符串的比较
*/

int main(int ac, char **av)
{
    string s1 = "2015-03-04";
    string s2 = "20150304";
    /*编译表达式*/
    boost::regex expr("^\\d{4}{\\-}\\d{1,2}{\\-|}\\d{1,2}$");
    /*匹配表达式*/
    cout << boost::regex_match(s1, expr) << endl;;
    cout << boost::regex_match(s2, expr) << endl;;
    
    return 0;
}
