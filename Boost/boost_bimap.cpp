#include <iostream>
#include <boost/bimap.hpp>
using namespace boost;
using namespace std;
/*
     双值映射（bimap）
   
     单值映射 map<int, string> m;
                      m.find（const key_type &__k）
                      只能通过key寻找value,不可倒逆过来
     解决办法：
             1.同时维护两个map,分别查找.
             map<int, string> m1;  map<string, int> m2;
             
             2.使用boost库的bimap.

*/

int main(int ac, char **av)
{
    //1. 办法一
    map<int, string> m1;
    map<string, int> m2;
    m1.insert(map<int, string>::value_type(20, "abc"));
    m2.insert(map<string, int>::value_type("abc", 20));
    
    cout << m1.find(20)->second << endl;
    cout << m2.find("abc")->second << endl;
    
    //2. 办法二
    typedef bimap<string, int> bimap;
    bimap persons;
    
    persons.insert(bimap::value_type("a", 31));
    persons.insert(bimap::value_type("b", 33));
    persons.insert(bimap::value_type("c", 34));
    
    bimap::left_map::iterator it_left = persons.left.find("b");
    if(it_left != persons.left.end()) {
        cout << it_left->second << endl;
    } else {
        cout << "未找到left！！！" << endl;
    }
    
    bimap::right_map::iterator it_right = persons.right.find(34);
    if(it_right != persons.right.end()) {
        cout << it_right->second << endl;
    } else {
        cout << "未找到right！！！" << endl;
    }


    return 0;
}
