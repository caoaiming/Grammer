#include <iostream>
using namespace std;
/*模板类的部分具体化
 *保留一部分具体参数，然后初始化另一部分具体参数
 *1. 类型部分具体化
 *2. 指针部分具体化
 *  并不把类型参数具体化为具体的参数，而是给类型参数前面的范围进
 *  一步缩小，类型还是随便给，但是范围就小了，比如限定为"指针"
 *  类型
 */
template <class T1, class T2>
class TemplateClass
{
private:
    T1 mValue1;
    T2 mValue2;
public:
    TemplateClass(T1 &value1, T2 &value2)
    {
        mValue1 = value1;
        mValue2 = value2;
        cout << "同用模板类: TemplateClass(T1 &value1, T2 &value2)" << endl;
    }
};
//完全具体化，模板类所有的类型参数必须指定固定的类型参数
template<> class TemplateClass<int, string>
{
private:
    int mValue1;
    string mValue2;
public:
    TemplateClass(int &value1, string &value2)
    {
        mValue1 = value1;
        mValue2 = value2;
        cout << "完全具体化: TemplateClass(int &value1, string &value2)" << endl;
    }
};
//部分具体化：肯定是包含两个或两个以上的参数，如果只有一个，那就只能
//叫完全具体化.
template<class T1> class TemplateClass<T1, string>//数目一致
{
private:
    T1 mValue1;
    string mValue2;
public:
    TemplateClass(T1 &value1, string &value2)
    {
        mValue1 = value1;
        mValue2 = value2;
        cout << "部分具体化: TemplateClass(T1 &value1, string &value2)" << endl;
    }
};
//先考虑完全具体化 << 在考虑部分具体化 << 最后选择通用模板
template <class T>
class PointClass
{
public:
    PointClass()
    {
        cout << "通用模板:" << endl;
    }
};
//限定必须是T1的指针，不能是其他非指针类型
template <class T>class PointClass<T*>
{
public:
    PointClass()
    {
        cout << "指针部分具体化" <<endl;
    }
};
int main(int ac, char **av)
{
    int valueInt = 20;
    string valuestring = "Bill";
    //完全具体化
    TemplateClass<int, string>all(valueInt, valuestring);
    //部分具体化
    TemplateClass<string, string> part(valuestring, valuestring);
    //通用模板
    TemplateClass<string, int> tongyong(valuestring, valueInt);
    PointClass<int> point1;
    //指针部分具体化
    PointClass<int*> point2;
    return 0;
}
