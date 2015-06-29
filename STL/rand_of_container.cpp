#include <iostream>
#include <vector>

using namespace std;
/* 随机排列容器元素的函数： random_shuffle           */
/*          要求：vector可以访问，因为要实时修改      */
void eachStr(string &str)
{
    cout << str << "  ";
}

int main(int ac, char **av)
{
    vector<string> names;
    names.push_back("Bill");
    names.push_back("Mike");
    names.push_back("Join");
    names.push_back("Mary");
    
    for_each(names.begin(), names.end(), eachStr);
    cout << endl;
    cout << "---------------------------------------" << endl;

    /*选择默认的种子发生器，不要第三个参数.*/
    random_shuffle(names.begin(), names.end());
    for_each(names.begin(), names.end(), eachStr);
    cout << endl;


    cout << "---------------------------------------" << endl;
    
    random_shuffle(names.begin(), names.end());
    for_each(names.begin(), names.end(), eachStr);
    cout << endl;
    
    return 0;
}
