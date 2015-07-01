#include <iostream>
#include <aliasdb.h>
#include <string>
#include <vector>

using namespace std;
/*
      STL与string<并不是STL中的类，但是提供了begin、end方法>

*/
bool compareChar(char c1, char c2)
{
    if(c1 > c2)
        return true;
    else
        return false;
}
int main(int ac, char **av)
{
    string str = "sldfjlsjl23ssfljsjjlj234dsdf";
    /* 1. 排序 */
    sort(str.begin(), str.end(), compareChar);
    cout << str << endl;
    
    /* 2. 拷贝 */
    string str1;
    str1.resize(str.size());//拷贝不会自动调整尺寸
    copy(str.begin(), str.end(), str1.begin());
    cout << str1 << endl;
    
    /* 3. 拷到vector里边 */
    vector<char> charValues;
    charValues.resize(str.size());
    copy(str.begin(), str.end(), charValues.begin());
    for(char c : charValues)
        cout << "<" << c << ">";
    cout << endl;
    
    return 0;
}
