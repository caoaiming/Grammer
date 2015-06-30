#include <iostream>
#include <vector>

using namespace std;
/*
     将STL算法用于非STL容器： sort、 copy
     
     指针 = 迭代器;
 */

bool compareInt(int n1, int n2)
{
    if(n1 >= n2)
        return true;
    else
        return false;
}

int main(int ac, char **av)
{
    int values[] {4, 5, 1, 7, -20};
    size_t size = sizeof(values) / sizeof(int);
    
    /* 1. 将数组（非STL）排序 */
    sort(values, values + size);
    for(auto v : values)
        cout << v << "   ";
    cout << endl;
    cout << "-----------------------------------" << endl;
    
    sort(values, values + size, compareInt);
    for(auto v : values)
        cout << v << "   ";
    cout << endl;
    
    cout << "*****************************************" << endl;
    /* 2. 将数组（非STL）拷贝到 STL容器中 */
    vector<int> v_values(5);
    copy(values, values+size, v_values.begin());
    for(auto it : v_values)
        cout << it << "   ";
    cout << endl;

    
    return 0;
}
