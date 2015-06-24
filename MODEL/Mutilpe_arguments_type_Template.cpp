#include <iostream>
#include <vector>

using namespace std;
//多类型参数得模板
template <class T1, class T2, class T3>
class TemplateClass
{
private:
    T1 mValue1;
    T2 mValue2;
    T3 mValue3;
public:
    TemplateClass(T1 &value1, T2 &value2, T3 &value3):mValue1(value1), mValue2(value2),mValue3(value3)
    {}
};


int main(int ac, char **av)
{
    int n = 100;
    string s = "hello";
    
    vector<string> v;
    TemplateClass<int, string, vector<string>> ss(n,s,v);
    cout << "It's Ok!" << endl;
    return 0;
}