#include <iostream>
#include <vector>

using namespace std;
/*  用于查找容器中元素值的find函数  */

int main(int ac, char **av)
{
    vector<string> names;
    
    names.push_back("Bill");
    names.push_back("Mike");
    names.push_back("Mike");
    names.push_back("Mary");
    
    vector<string>::iterator const it = find(names.begin(), names.end(), "Mike");
    
    if(it != names.end()) {
        cout << "已经找到." << endl;
        cout << it->size() << endl;
        cout << *(it) << endl;
        cout << *(it+1) << endl; //包含4个元素,但是只有前两个有值.
         }
    else
        cout << "未找到." << endl;

    
    return 0;
}
