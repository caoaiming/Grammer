#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
/*
        分割字符串
*/

int main(int ac, char **av)
{
    string s = "I love you.";
    
    typedef  boost::tokenizer<boost::char_separator<char>> tokenizer;
    
    tokenizer tok(s);
    
    for(tokenizer::iterator it = tok.begin();it != tok.end();it++)
    {
        cout << *it << endl;
    }
    
    cout << "--------------------------------------" << endl;
    boost::char_separator<char> sep(" ");//按空格分(指定分隔符)
    tokenizer tok1(s, sep);
    
    for(tokenizer::iterator it = tok1.begin();it!= tok1.end();it++)
    {
        cout << *it << endl;
    }
    
    
    
    return 0;
}
