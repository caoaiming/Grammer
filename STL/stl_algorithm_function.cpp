#include <iostream>
#include <vector>

#include <algorithm> /* 前三类算法要引用的头文件 */
#include <numeric>   /* 最后一类算法，通用数字运算 */
using namespace std;
/*
     STL中的算法
 
     1.非修改式 
                :会操作序列，不是不会修改
     2.修改式序列操作
                :会发生修改
     3.排序与相关操作
                :排序操作
     4.通用数字运算
                :累加...一些计算函数

*/

bool compare(int n1, int n2)
{
    if (n1 > n2)
        return true;
    else
        return false;
}

int main(int ac, char **av)
{
    vector<int> values {3, 5, 6, 8, 6, 10};
    
    /* 1.非修改式 */
    vector<int>::iterator it = find(values.begin(), values.end(), 6);
    if(it != values.end())//结果中只找到了第一个
        cout << *it << endl;
    cout << *(it + 1) << endl;//紧跟的元素是8,证明了返回第一个被找到的
    cout << "--------------------------------------------" << endl;
    
    /*2. 修改式序列操作 */
    replace(values.begin(), values.end(), 6, 100);
    for(auto it = values.begin(); it != values.end(); it++)
        cout << *it << "  ";
    cout << endl;
    cout << "--------------------------------------------" << endl;

    /* 3. 排序与相关操作 */
    sort(values.begin(), values.end(), compare);
    for(auto n : values)
        cout << n << "   ";
    cout << endl;
    cout << "--------------------------------------------" << endl;

    /* 4. 通用数字相关 */
    
    int n = accumulate(values.begin(), values.end(), 10);
    cout << "n = " << n << endl;
    
    return 0;
}
