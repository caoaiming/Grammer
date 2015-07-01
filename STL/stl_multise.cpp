#include <iostream>
#include <set>

using namespace std;
/*
     支持重复的集合容器类：multiset
     
     特点： 与set一样，也有反转功能.


*/
void output(int n)
{
    cout << n << "  ";
}

int main(int ac, char **av)
{
    set<int> values1 {1, 2, 2, 4, 5};

    for(auto n : values1)
        cout << n << "  "; /* 去掉一个重复的2 */
    cout << endl;
    
    cout << "----------------------------------" << endl;
    
    multiset<int> values2 {1, 2, 2, 4, 5};
    for(auto n : values2)
        cout << n << "  "; /* 保留了个重复的2 */
    cout << endl;
    
    cout << "----------------------------------" << endl;

    /* 反转 */
    for_each(values2.rbegin(), values2.rend(), output);
    cout << endl;
    
    return 0;
}
