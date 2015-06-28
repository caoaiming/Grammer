#include <iostream>

using namespace std;
/*  模板类string的构造方法（大量操作字符串API，比较复杂）*/

int main(int ac, char **av)
{
    string test = "1234567890";
    
    /* 1.无参构造方法 */
    string str1 = "超人";
    cout << "str1 = " << str1 << endl;
    cout << "-----------------------------------------" << endl;
    
    /* 2. string(const cahr *s)*/
    const char s[] = "hello world";
    string str2_1(s);
    cout << "str2_1 = " << str2_1 << endl;
    string str2_2("师姐你好");
    cout << "str2_2 = " << str2_2 << endl;
    cout << "-----------------------------------------" << endl;

    /* 3. string(size_type n, char c) 将n个c连成字符串 */
    string str3(12, 'd');
    cout << "str3 = " << str3 << endl;
    cout << "-----------------------------------------" << endl;
    
    /* 4. string(const string &str) 发生拷贝 */
    string str4(str2_1);
    cout << "str4 = " << str4 << endl;
    cout << "-----------------------------------------" << endl;

    /* 5. string(const char *s, size_type n) 截取字符串前n个字符*/
    char greeting[] = "1234567890";
    string str5(greeting, 5);
    cout << "str5 = " << str5 << endl;
    cout << "-----------------------------------------" << endl;

    /* 6. template<class Iter>string(Iter begin, Iter end)  */
    /*    参数分别为 首指针，尾指针,从begin开始截取到end,但不包括end*/
    
    string str6_1(greeting + 5, greeting + 9);
    cout << "str6_1 = " << str6_1 << endl;
    string str6_2(&test[0] + 1, &test[0] + 5);//不能将类作为参数
    cout << "str6_2 = " << str6_2 << endl;
    cout << "-----------------------------------------" << endl;

/* 7. string(const string& str, size_type pos, size_type npos)*/
/*     从pos开始截取，如果指定个数，则截取指定个数，如果没有则截取到末尾 */
    string str7_1(test, 6);
    cout << "str7_1 = " << str7_1 << endl;
    string str7_2(test, 6, 2);
    cout << "str7_2 = " << str7_2 << endl;
    cout << "-----------------------------------------" << endl;
    
    /*8. (C++11) string(initialier_list<char> list) 字符列表   *
     *创建一个类的对象，如果后面只有一个值，并且该值与只有一个参数的构造 *
     *方法参数类型一致，就会自动调用类的构造方法                     */
    string str8_1 = {'H', 'a', 'c'};
    cout << "str8_1 = " << str8_1 << endl;
    string str8_2 {'1', '2', '3'};
    cout << "str8_1 = " << str8_2 << endl;
    cout << "-----------------------------------------" << endl;
    
    return 0;
}
