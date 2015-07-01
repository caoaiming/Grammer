#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/*
    无序关联容器: （C++11）
    unordered_set
    unordered_multiset
    unordered_map
    unordered_multimap
 
    数据结构 : 哈希结构 <
    每一个key都回索引一个像链表一样的东西(桶), 如果算法好，会瞬间查到结果
                        >
 
 优点 : 在一定情况下：无序关联容器的定位查找速度要优于基于树的有序关联容器.
 
 C++98   : < set   multiset   map   multimap >
 数据结构 : 排序树 <有序的关联容器>

*/

int main(int ac, char **av)
{
    unordered_set<int> set_int {1, 2, 3, 4, 5};
    cout << set_int.size() << endl;
    
    cout << "---------------------------------------" << endl;
    
    unordered_multimap<int, string> multimap_int;
    pair<int, string> value1(10, "Bill");
    pair<int, string> value2(10, "Mike");
    pair<int, string> value3(30, "Jony");
    
    multimap_int.insert(value1);
    multimap_int.insert(value2);
    multimap_int.insert(value3);
    pair<unordered_multimap<int, string>::iterator,unordered_multimap<int, string>::iterator> range = multimap_int.equal_range(10);
    
    for(auto it = range.first; it != range.second; it++)
        cout << "key = " << it->first << "  value = " << it->second << endl;
    
    return 0;
}
