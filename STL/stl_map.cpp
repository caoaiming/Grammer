#include <iostream>
#include <map>

using namespace std;
/*
     映射类容器: map <key, value>
     特点：
          1.key不能重复.
          2.如果后插入的与之前key重复，则直接忽略掉,丢弃，而不发生覆盖或替换
*/

int main(int ac, char **av)
{
    map<int, string> persons;
    
    pair<int, string> person1(10, "Bill");
    persons.insert(person1);
    pair<int, string> person2(20, "Mike");
    persons.insert(person2);
    pair<int, string> person3(30, "John");
    persons.insert(person3);
    
    cout << "first = key:" << persons.find(20)->first << endl;
    /* find 返回了pair的指针, first返回了 key的指针*/
    cout << "second = value:" <<persons.find(20)->second << endl;
    cout << "-----------------------------------------" << endl;


    map<int, string>::iterator it1 = persons.find(30);
    if(it1 != persons.end())
        cout << "key = " << it1->first << " value = " << it1->second << endl;
    else
        cout << "没找到!" << endl;
    
    map<int, string>::iterator it2 = persons.find(35);
    if(it2 != persons.end())
        cout << "key = " << it2->first << " value = " << it2->second << endl;
    else
        cout << "没找到!" << endl;
    cout << "----------------------------------" << endl;
    
    /*造成重复*/

    pair<int, string> person4(20, "Bee");
    cout << "添加之前尺寸：size = " << persons.size() << endl;
    persons.insert(person4);
    cout << "添加之后尺寸：size = " << persons.size() << endl;
    
    cout << persons.find(20)->second << endl;//没有替换掉，直接丢弃

    return 0;
}
