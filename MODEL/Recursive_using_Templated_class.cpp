#include <iostream>

using namespace std;

template <typename T>
class TemplateClass
{
private:
    T mValue;
public:
    TemplateClass(T& value) : mValue(value)
    {
        //mValue = value;(错误)
        //必须显示的初始化mVlaue
        //如果是一般类型,long ,int,可以这样写.
    }
    T& getValue()
    {
        return mValue;
    }
};

int main(int ac, char **av)
{
    string s = "这是递归!";
    TemplateClass<string> templateClass(s);
    TemplateClass<TemplateClass<string>> RecursiveClass(templateClass);
    cout << RecursiveClass.getValue().getValue() << endl;
    
    return 0;
}
