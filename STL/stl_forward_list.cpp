#include <iostream>
#include <forward_list>
#include <list>
using namespace std;
/*
   单链表容器： forward_list (C++11)
*/

int main(int ac, char **av)
{
    list<int> list_values {1, 2, 3, 4, 5};
    /* list双向链：逆向输出 */
    for(auto it=list_values.rbegin();it != list_values.rend();it++)
        cout << *it << "  ";
    cout << endl;
    cout << "--------------------------------" << endl;
    
    for(auto it=list_values.begin();it != list_values.end();it++)
        cout << *it << "  ";
    cout << endl;
    cout << "--------------------------------" << endl;
    
    /* forward只能正向输出 */
    forward_list<int> list2 {6, 7, 8, 9, 10};
    for(auto it = list2.begin(); it != list2.end(); it++)
        cout << *it << "  ";
    cout << endl;
    
    return 0;
}