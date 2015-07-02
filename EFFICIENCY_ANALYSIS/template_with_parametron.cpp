#include <iostream>

using namespace std;
/*
     模板与可变参函数

*/

template <typename... T>
void process(T... t) //基于递归的解析参数
{
}

#if 1
void process2() //添加一个终止条件,因为最后变得没有参数了，所以会调用它
{               //如果没有这个函数，会报错的: process()函数没定义
    cout << endl;
}
#endif

template <typename First, typename... T>
void process2(First first, T... t) //pack:参数打包到t
{
    cout << first << " ";
    process2(t...); //第一次调用剔除1,第二遍把2变成first剔除2...以此类推
    /*
           第1遍：process2(1, 2, 3, 4, "abc");  first = 1
           第2遍：process2(2, 3, 4, "abc");     first = 2
           第3遍：process2(3, 4, "abc");        first = 3
           第4遍：process2(4, "abc");           first = 4
           第5遍：process2("abc");              first = "abc"
            ...
           参数列表为空时:  调用无参的process2()，作为终止条件
                                        <该函数必须存在，否则编译报错>
     */
}

int main(int ac, char **av)
{
    //process(1, 2, 3, 4, "abc");
    process2(1, 2, 3, 4, "abc");

    
    return 0;
}
