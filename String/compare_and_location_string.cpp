#include <iostream>

using namespace std;
/* string的基本功能
 *      1. 字符串的比较 <可以 string 与 char * 比较>(内部重载)
 *      2. 字符串的定位
 */

int main(int ac, char **av)
{
    /*1. 字符串比较过程：顺次根据字符串ASCII码，前边相同了在看长度*/
    string str1("hello");
    string str2("world");
    
    if(str1 > str2)
        cout << "str1 > str2" << endl;
    else if (str1 < str2)
        cout << "str1 < str2" << endl;
    else
        cout << "str1 = str2" << endl;
    cout << "-----------------------------------------" << endl;
    
    char str3[20] = "I love you.";
    if(str3 < str1)
        cout << "str3 < str1" << endl;
    cout << "-----------------------------------------" << endl;

    /*2. [字符串的定位] 以find开头的都是,没找到则返回一个常量:npos */
    cout << "string::npos = " << string::npos << endl;//大于long值
    cout << "-----------------------------------------" << endl;
    

    cout << "str1.find(\"l\") = " << str1.find("l") << endl;
    cout << "str1.find(\"y\") = " << str1.find("y") << endl;
    cout << "-----------------------------------------" << endl;


    cout << "str1.find(\"l\", 3) = " << str1.find("l", 3) <<endl;
    cout << "str1.find(\"l\", 4) = " << str1.find("l", 4) <<endl;
    if(str1.find("l", 4) == string::npos)
        cout << "未找到字符串\"l\"" << endl;
    
    cout << "-----------------------------------------" << endl;
    
    cout << "str1.find(\"l\", 3) = " << str1.find("l", 3) <<endl;
    cout << "str1.rfind(\"l\") = " << str1.rfind("l") << endl;
    
    
    cout << "----------------world--------------------" << endl;
/* 拿原字符串中的字符在参数中查找第一个出现的字符，返回位置，取最先找到的*/

    cout <<"str2.find_first_of(\"hero\") = " << str2.find_first_of("hero") << endl; //'o'在前,'r'在后，所以取'o'
    cout <<"str2.find_last_of(\"hero\") = " << str2.find_last_of("hero") << endl;//从world后边开始找，'r'
    
    
    cout << "-----------------world------------------" << endl;
/* 拿原字符串中的字符在参数中查找第一个没出现的字符，返回位置，取最先找到的*/
    cout <<"str2.find_first_not_of(\"hero\") = " << str2.find_first_not_of("hero") << endl; //'w'就是
    cout <<"str2.find_first_not_of(\"whero\") = " << str2.find_first_not_of("whero") << endl; //'l'就是


    return 0;
}
