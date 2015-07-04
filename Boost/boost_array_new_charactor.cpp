#include <iostream>
#include <string>
#include <algorithm>
#include <boost/array.hpp>

//using namespace std;
/*
      array新特性
*/
//由于boost与标准库数组类名字一样,所以不直接使用using namespace std;
typedef boost::array<std::string, 3> array;
int main(int ac, char **av)
{
    array a;
    a[0] = "Bill";
    a.at(1) = "Mike";
    *a.rbegin() = "John"; //使用迭代器，数组最后一个值赋值
    
    std::sort(a.begin(), a.end());
    for(array::const_iterator it = a.begin(); it != a.end(); it ++)
        std:: cout << *it << "  ";
    std::cout << std::endl;

    std::cout << a.size() << std::endl;
    std::cout << a.max_size() << std::endl;//事先分配的大小
    
    a = {"abc", "bcd", "aaa"};
    for(auto n : a)
        std::cout << n << "  ";
    std::cout << std::endl;
    
    /*----------------------------------------------------------*/
    boost::array<std::string, 1> aa = {"caming"};//boost特有的初始化
    
    return 0;
}
