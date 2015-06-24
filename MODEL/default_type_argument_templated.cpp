#include <iostream>
#include <vector>

using namespace std;
//默认类型参数，如果不指定，则以默认为主。
template <class T1, class T2 = vector<short>>

class TemplateClass
{
public:
    T1 value1;
    T2 value2;
};

int main(int ac, char **av)
{
    TemplateClass<int> temp1;
    //默认value2就是vector<int>了.
    
    TemplateClass<int , char> temp2;
    return 0;
}