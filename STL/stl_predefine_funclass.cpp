#include <iostream>
#include <vector>
#include <algorithm> /* 隶属于STL头文件,里边有一些实现算法的函数
                        包括这个 transform() */
#include <functional> /* 定义了很多的函数对象 */

using namespace std;
/*
     STL : 提供 预定义的函数对象(函数符)
eg:
   将一个或者两个集合中的元素复制到另外一个集合中，不是简单的复制，而是在
   复制的过程中，完成一些操作. 最后一个参数就是我们定义的函数对象或函数符
   比如让元素相加或者相乘..操作，然后将结果复制给最后一个集合.
 
 transform(<#_InputIterator __first#>, <#_InputIterator __last#>, <#_OutputIterator __result#>, <#_UnaryOperation __op#>)
 
*/

int main(int ac, char **av)
{
    vector<int> values1 {1, 2, 3, 4, 5, 6};
    //vector<int> values2 {6, 7, 8, 9, 10, 11, 99};
    //vector<int> values2 {6, 7, 8, 9};
    /*如果长短不一的情况（假设集合3的长度以1和2中最长的为准）：
            集合1 > 集合2 ：  结果不确定 （）
            集合1 < 集合2 ：  多余的值结果为 0
     */
    
    vector<int> values2 {6, 7, 8, 9, 10, 11};


    vector<int> values3;
    cout << values3.size() << endl;
    values3.resize(values1.size());//给他设定尺寸，否则会报错
    cout << values3.size() << endl;

     /* 第二个集合元素个数应该 大于 第一个集合元素个数 */
    transform(values1.begin(), values1.end(), values2.begin(), values3.begin(), plus<int>());//plus是个重载()的结构体
    
    for(int i = 0; i < values3.size(); i++)
        cout << values3[i] << "  ";
    cout << endl;
    
    vector<int> values4;
    values4.resize(values1.size());
    
    transform(values1.begin(), values1.end(), values2.begin(), values4.begin(), multiplies<int>());
    
    for(int i = 0; i < values4.size(); i++)
        cout << values4[i] << "  ";
    cout << endl;
    
    return 0;

}
