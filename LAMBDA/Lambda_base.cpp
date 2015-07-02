#include <iostream>
#include <vector>

using namespace std;
/*
     lambda (C++11)表达式基础
     C++11新特性：
           auto、智能指针、模板别名(using)、decltype(用返回值作为类型)...
 
     本质：是一个匿名函数,可作为STL容器的最后一个参数，作为回调函数.
     特点：没有函数名，我们用一对[]来表示 ，Lambda函数名可以省略，参数与函数体
          需要写。
*/
void output(int n)
{
    cout << n << " ";
}

/* 函数对象 */
bool countIfPred(int n)
{
    return n % 2 == 0;
}

int main(int ac, char **av)
{
    vector<int> randValues(10);
    /* 产生随机种子 */
    srand((unsigned)time(0));
    generate(randValues.begin(), randValues.end(), rand);
    
    for_each(randValues.begin(), randValues.end(), output);
    cout << endl;
    cout << "-----------------------------------------" << endl;
    
    /* eg:1 改用Lambda表达式 <可自动推断返回值> */
    for_each(randValues.begin(), randValues.end(),[](int n){cout << n << "  ";});
    cout << endl;
    cout << "-----------------------------------------" << endl;
    
    int count = (int)count_if(randValues.begin(), randValues.end(), countIfPred);
    cout << "偶数个数 cnt = " << count << endl;

    
    /* eg:2 改用Lambda表达式 <可自动推断返回值> */

    int cnt = (int)count_if(randValues.begin(), randValues.end(), [](int n){return n%2 == 0;}); /* 自动推断返回值. */
    cout << "偶数个数 cnt = " << cnt << endl;

    
    return 0;
}