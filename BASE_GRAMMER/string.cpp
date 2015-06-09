#include <iostream>
#include <string.h>
using namespace std;

int main(int ac, const char **av)
{
    string str1 = "曹爱明uuuuuuuuu";
    string str2 = str1;
    
    cout << "str2 = " << str2 << endl;

    const char *p = str1.c_str();

    str1[10] = 'p';
    cout << "New =" << str1 << endl;
    str2 += str1;

    cout << "NEW-str2 :" << str2 << endl;

    cout << "p =" << p<< endl;
    char c_str1[] = "hello";
    char c_str2[6];

    strcpy(c_str2, c_str1);

    cout << c_str1 << endl;

    //char out[11] = "0123456789";
    string out= "0123456789";
    cout << out << endl;
    cout << out.length() << endl;

    return 0;
}
