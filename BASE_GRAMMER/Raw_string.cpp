#include <iostream>

using namespace std;

int main(int argc ,char **av)
{
    string str1 = "中华";
    char  c_str[] = "中";  //UTF-8 汉字3字节
    wchar_t wc_str[] = L"中"; // 宽字符类型：4字节

    cout << "str1 length:" << str1.length() << endl;
    cout << "c_str length" << sizeof(c_str)/sizeof(char) << endl;
    cout << "c_str byte length" << sizeof(c_str) << endl;
    cout << "wc_cahr length" << sizeof(wc_str) /sizeof(wchar_t);
    cout << "wc_str byte length:" << sizeof(wc_str) << endl;
  //-------------------------------------------------------------

    char16_t w16_char[] = u"中国";
    cout << "w16_char length" << sizeof(w16_char) << endl;
    cout << "w16_char byte length" << sizeof(char16_t) << endl;//2字节

    cout << R"(Hello \n \n \n world!)" << endl;  //Raw_string 不转义
            //必须在两端加上();
    
    cout << R"123(Hello \n \n \n world!)123" << endl;
    cout << R"1(Hello \n \n \n world!)1" << endl; //括号外必须对称


    return 0;
}
