#include <iostream>
#include <string>

using namespace std;
/*
     Lambda表达式的参数和返回值
    
     知识点： 如何省略中括号[],以及如何指定返回值.
*/

int initChar()
{
    return (rand()%26 + 97);
}

int main(int ac ,char **av)
{
    string str;
    str.resize(10);
    srand((unsigned)time(0));
    
    //97 - 122 (a - z)
    generate(str.begin(), str.end(), initChar);
    cout << str << endl;
    cout << "---------------------------------" << endl;
    
    generate(str.begin(), str.end(), [](){return (rand()%26 + 97);});
    cout << str << endl;
    
    cout << "---------------------------------" << endl;
     //省去返回值参数，由编译器推算出int
    generate(str.begin(), str.end(), []{return (rand()%26 + 97);});
    cout << str << endl;
    
    cout << "---------------------------------" << endl;
    
    //完整写法
    generate(str.begin(), str.end(), []()->char{return rand()%26+97;});  //这里返回值也可以是char，在128范围内.
    cout << str << endl;
             
    
 
    return 0;
}