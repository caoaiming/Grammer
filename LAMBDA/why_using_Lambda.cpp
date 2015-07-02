#include <iostream>
#include <vector>

using namespace std;
/*
      为什么要使用Lambda表达式.
       1. 距离
               传统函数调用要不停的寻址，而Lambda表达式再哪出调用
               ，在哪处写，维护了空间局部性
       2. 简洁
               简洁性优于函数，可以将Lambda表达式赋给一个变量，解决重复定义
               的问题,而且打破了不能在函数内部（main）定义函数的缺陷,而且可
               以直接当做普通函数调用.
       3. 效率
               普通函数存在跳转寻址的缺陷，但是Lambda表达式采用内联的形式
               嵌入到调用处，降低了寻址的代价.
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
    vector<int> values1 {4, 5, 6, 8};
    vector<int> values2 {1, 2, 3};
    
    /* 1. 使用函数对象 */
    for_each(values1.begin(), values1.end(), output);
    cout << endl;
    cout << "-----------------------------------------" << endl;
    
    /* 2. 使用Lambda表达式 */
    for_each(values1.begin(), values1.end(),[](int n){cout << n << "  ";});
    cout << endl;
    cout << "-----------------------------------------" << endl;
    
    /* 3. 使用Lambda变量，解决重复定义的问题 */
    
    auto lambda = [](int n){cout << n << "  ";};
    
    lambda(100); //可以像普通函数一样直接调用
    cout << endl;

    
    for_each(values1.begin(), values1.end(),lambda);
    cout << endl;
    
    return 0;
}