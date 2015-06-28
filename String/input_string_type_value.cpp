#include <iostream>

using namespace std;
/*  输入string类型的值
 *
 *
 */

int main(int ac, char **av)
{
    char cInput[20]; //只能输入19个有意义的字符+'\0'
#if 0
    cin >> cInput;   //读一个字符,空格结束
    cout << cInput << endl;
    cout << "-----------------------------------" << endl;
#endif
    
#if 0
    cin.getline(cInput, 20); //第一行，换行符'\n'结束，不要'\n'
    cout << cInput << endl;
    cout << "-----------------------------------" << endl;
#endif
    
#if 0
    cin.get(cInput, 20);
    cout << cInput << "***" << endl;//包括换行符'\n'一起读进去
#endif
    cout << "-----------------------------------" << endl;
    /* 系统自动动态调整大小，不会超过int的最大值，读文件时要小心 */
    string sInput;
    //cin >> sInput;
    //cin.getline(cin, sInput);
#if 0
    cin.getline(cInput, 20, ':'); //自定义结束符,只有遇到:才结束
    cout << cInput << endl;
#endif
    getline(cin, sInput, ';');//遇上边一样，连同回车'\n'一块读了，不停
    cout << sInput << endl;
    
    return 0;
}
