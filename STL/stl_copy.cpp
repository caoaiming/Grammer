#include <iostream>
#include <vector>

using namespace std;
/*  copy函数： 用于将一个容器中的元素值复制到另一个容器中  */

int main(int ac, char **av)
{
    vector<string> names;
    
    names.push_back("Bill");
    names.push_back("Mike");
    names.push_back("Mike");
    names.push_back("Mary");
   
    vector<string> names1(4);//记得分配空间,分配空间应该 >= 4
    copy(names.begin(), names.end(), names1.begin());
    
    for(auto v:names1)
        cout << v << endl;
    
    return 0;
}
