#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>

using namespace std;
/*
       元组类型(tuple)
       定义：帮两个值放到一起来使用，把两个值绑定，形影不离。
*/


int main(int ac, char **av)
{
    typedef boost::tuple<string, string> person;
    
    person p("Bill", "Boss");
    cout << p << endl;
    
    cout << p.head << endl;    //读取第一个值
    cout << p.tail << endl;    //读取第二个值
    cout << p.tail.head << endl;

}