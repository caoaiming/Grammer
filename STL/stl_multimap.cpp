#include <iostream>
#include <map>

using namespace std;
/*
    //允许key重复的映射容器类: multimap
       set<-> multiset
       map<-> multimap
    
    核心问题: 如何获得重复的key对应的所有value集合
    本质:  三种方法本质都是获得迭代器，只是获取的方式不同.
*/

int main(int ac, char **av)
{
    multimap<int, string>values;
    pair<int, string> value1(10, "Bill");
    pair<int, string> value2(10, "Mike");
    pair<int, string> value3(10, "Mary");
    
    pair<int, string> value4(20, "Jony");
    
    values.insert(value1);
    values.insert(value2);
    values.insert(value3);
    values.insert(value4);
    
    cout << "multimap size = " << values.size() << endl;
    /* 如果换成map, 则 size = 2 ，会忽略后插入的value2、value3 */
    cout << "-----------------------------------" << endl;
    
    size_t count = values.count(10);
    cout << "cnt = " << values.count(10) << endl;
    
    /* 1. 获取方法1 */
    cout << "第一种获取方法： " << endl;
    multimap<int, string>::iterator it1 = values.find(10);
    cout << "查找结果首元素：" << it1->second << endl;
    /* 返回的是一个指针数组 <集合> */
    for(int i = 0; i < count ; i++)
        cout << (it1++)->second << endl;
    cout << "-----------------------------------" << endl;
    
    /* 2. 获取方法2 */
    cout << "第二种获取方法： " << endl;
    multimap<int, string>::iterator it_lower = values.lower_bound(10);
    multimap<int, string>::iterator it_upper = values.upper_bound(10);  /* 获得的是迭代器中最后一个10的下一个pair迭代器 */
    for(auto it = it_lower; it != it_upper; it++)
        cout << "key = " << it->first << " value = " << it->second << endl;
    cout << "-----------------------------------" << endl;
    
    /* 3. 获取方法3 */
    cout << "第三种获取方法： " << endl;
    pair< multimap<int, string>::iterator, multimap<int, string>::iterator> range =
    values.equal_range(10);
    /* 第一个参数 multimap<int, string>::iterator 相当于 it_lower
       第二个参数 multimap<int, string>::iterator 相当于 it_upper
       pair返回一对儿结果，分别是first 、second 两个迭代器.
     */
    for(auto it = range.first; it != range.second; it++)
        cout << "key = " << it->first << " value = " << it->second << endl;


    return 0;
}
