#include <iostream>
#include <list>
using namespace std;
/*
    STL函数对象
    
    特点: 只有一个参数值
    功能: 处理容器中的元素值
 
 函数+对象 : 如果将对象重载()的话，那么对象可以向函数那样调用.

*/
//回调函数
bool removeFunction(int n)
{
    if( n < 4)
        return true;
    else
        return false;
}

void output(int n)
{
    cout << n << "  ";
}
/* 函数指针 */
typedef bool (*RemoveFunction_p)(int);

/*定义对象，然后重载()，可以使对象像函数一样调用.*/
class RemoveClass
{
private:
    int mValue;
public:
    RemoveClass(int value)
    {
        mValue = value;
    }
    /* 重载的函数应该返回bool类型 */
    bool operator()(int n)
    {
        if (n >= mValue)
            return false;
        else
            return true;
    }
};

int main(int ac, char **av)
{
    list<int> values {1, 4, 3, 2, 8, 5};
    
    //values.remove_if(removeFunction); //此处参数可以传递函数指针或对象.
    
    //RemoveFunction_p p = removeFunction;
    //values.remove_if(p); //传递函数指针
    
    RemoveClass removeClass(4);
    values.remove_if(removeClass); /*传递重载了圆括号()的对象,
                                     可以像函数一样使用    */
    
    for_each(values.begin(), values.end(), output);
    cout << endl;
    
    return 0;
}
