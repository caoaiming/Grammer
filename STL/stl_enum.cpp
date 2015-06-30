#include <iostream>
#include <vector>

using namespace std;
/*  枚举容器中元素值的3种方法  */

void printNum(int value)
{
    cout << value << "   ";
}

int main(int ac, char **av)
{
    vector<int> num;
    
    num.push_back(10);
    num.push_back(15);
    num.push_back(20);
    num.push_back(17);
    
    /*1. 普通for循环 */
    cout << "普通for循环:" << endl;
    for(auto it = num.begin(); it != num.end(); it++)
        cout << *it << "   ";
    cout << endl;
    
    for(auto it = num.end()-1; it != num.begin()-1; it--)
        cout << *it << "   ";
    cout << endl;
    cout << "---------------------------------------" << endl;
    /* 2. for_each的循环 */
    cout << "基于or_each的循环:" << endl;
    for_each(num.begin(),num.end(), printNum);
    cout << endl;
    cout << "---------------------------------------" << endl;

    /* 3. C++11新提供的：基于范围for-in  语句*/
    cout << "基于范围的for循环：" << endl;
    for(auto n : num)  /* n就是10，15，20, 17,而不是容器下标 */
        cout << n << "   ";
    cout << endl;
   
    return 0;
}
