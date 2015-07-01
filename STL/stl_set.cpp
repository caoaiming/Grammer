#include <iostream>
#include <set>
#include <array>

using namespace std;
/*
    集合容器类： set
         
         特点：元素是唯一的,不能重复, 函数较多，比较复杂.
         函数：插入、拷贝、合并、求交集...
*/
void  output(string s)
{
    cout << s << "   ";
}
int main(int ac, char **av)
{
    /* 1. 定义 */
    set<string> set1 {"Bill", "Mike"};
    cout << set1.size() << endl;
    set1.insert("Bill");/*以树形结构查找，发现相同的，会被剔除 */
    cout << set1.size() << endl;
    
    cout << "----------------------------------" << endl;
    
    /* 2. 拷贝 */
    array<string, 2> array_string;
    copy(set1.begin(), set1.end(), array_string.begin());
    
    for_each(array_string.begin(), array_string.end(), output);
    cout << endl;

    set<string> set2;
    //copy(set1.begin(), set1.end(), set2.begin());
    /*set2.begin() 是一个常量迭代器，不允许插入 ...*/
    copy(set1.begin(), set1.end(), insert_iterator<set<string>>(set2, set2.begin()));
    /* 改变常量迭代器类型为插入迭代器，变为可写 */
    for_each(set2.begin(), set2.end(), output);
    cout << endl;
    
    cout << "----------------------------------" << endl;
    
    /* 3. 插入 */
    set2.insert("abc");
    set2.insert("ok");
    
    for_each(set2.begin(), set2.end(), output);
    cout << endl;
    
    cout << "----------------------------------" << endl;

    
    /*4. 取交集 */
    
    set<string> set3;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator<set<string>>(set3, set3.begin()));
    for_each(set3.begin(), set3.end(), output);
    cout << endl;
    cout << "----------------------------------" << endl;

    
    /* 5. 合并 <包含去重操作> */
    set<string> set4;
    
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator<set<string>>(set4,set4.begin()));
    for_each(set4.begin(), set4.end(), output);
    cout << endl;


    
    return 0;
}
