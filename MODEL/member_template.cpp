#include <iostream>
using namespace std;
//成员模板：
//模板还可以作为结构体、类或者是模板类的成员

template <class T>
class Myclass {
private:
    template <class V>
    class TemplateClass1
    {
    public:
        V value;
    };
    
    template <class V1, typename V2>
    class TempalteClass2
    {
    public:
        V1 value1;
        V2 value2;
    };
    template <typename V1> class TempalteClass2<V1,
    string>
    {
    public:
        V1 value1;
        string value2;
        TempalteClass2()
        {
            cout << "部分具体化" << endl;
        }
    };
    //只声明，不去实现，在外边实现.
    template <class V>
    class TemplateClass3;
public:
    TemplateClass1<T> templateClass1;
    TempalteClass2<T, int> templateClass2;
    TempalteClass2<int, string> templateClass2_2;
};
//在外边实现
template <typename T>
template <typename V>
class Myclass<T>::TemplateClass3
{
public:
    V value;
};
int main(int argc, char *argv[])
{
    Myclass<string> myClass;
    return 0;
}