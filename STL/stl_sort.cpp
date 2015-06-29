#include <iostream>
#include <vector>

using namespace std;
/* 用于对容器中元素值排序的sort函数
sort(<#_RandomAccessIterator __first#>,<#_RandomAccessIterator __last#>, <#_Compare __comp#>)
<指定升序还是降序> 如果是对象：那么比较的依据是什么？完全靠第3个参数
  
 比较器：起着可以改变比较规则的作用
        1.默认使用重载了 '<' 的操作符，所以重载 '<',简单类型不允许重载
          所以要用类。
        2.传入一个比较器，首先要定义,与重载差不多.
 
 */

void eachInt(int& num)
{
    cout << num << "  ";
}

class Person
{
public:
    int code;
    Person(int code)
    {
        this->code = code;
    }
};

bool operator<(const Person& p1, const Person& p2)
{
    //if(p1.code <= p2.code)//升序
    if(p1.code >= p2.code)  //降序

        return true;
    else
        return false;
}

bool compareInt(int n1, int n2)
{
    //if(n1 <= n2) //升序
    if(n1 >= n2)
        return true;
    else
        return false;
}

bool comparePerson(const Person& p1, const Person& p2)
{
    if(p1.code <= p2.code)//升序
    //if(p1.code >= p2.code)  //降序
        return true;
    else
        return false;
}

int main(int ac, char **av)
{
    vector<int> num;
    
    num.push_back(10);
    num.push_back(3);
    num.push_back(20);
    
    for_each(num.begin(), num.end(), eachInt);
    cout << endl;
    cout << "------------------------------------------" << endl;
    
    sort(num.begin(), num.end());//默认升序
    for_each(num.begin(), num.end(), eachInt);
    cout << endl;
    cout << "------------------------------------------" << endl;
    
    sort(num.begin(), num.end(),compareInt);//传入比较器,<降序>
    for_each(num.begin(), num.end(), eachInt);
    cout << endl;
    
    cout << "******************************************" << endl;

    vector<Person> persons;
    persons.push_back(Person(20));
    persons.push_back(Person(10));
    persons.push_back(Person(30));
    persons.push_back(Person(15));
    
    for(auto it = persons.begin(); it != persons.end(); it++)
        cout << it->code << "    ";
    cout << endl;
    
    cout << "------------------------------------------" << endl;
    sort(persons.begin(), persons.end());
    for(auto it = persons.begin(); it != persons.end(); it++)
        cout << it->code << "    ";
    cout << endl;
 
    cout << "------------------------------------------" << endl;
    sort(persons.begin(),persons.end(),comparePerson);//传入比较器
    for(auto it = persons.begin(); it != persons.end(); it++)
        cout << it->code << "    ";
    cout << endl;
 
    return 0;
}
