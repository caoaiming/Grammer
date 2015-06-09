#include <iostream>
using namespace std;

class String {
private:
    string mStr = "hello";
public:
    friend ostream& operator<<(ostream& os, const String& str);
};

ostream& operator<<(ostream& os, const String& str)
{
    return os << str.mStr;
}

class NewString : public String
{
};
#if 1
    //避免操作符重载造成的递归调用.
ostream& operator<<(ostream& os, const NewString& str)
{
    return os << "我在重复" << str;  //Error
}
#endif
#if 0
ostream& operator<<(ostream& os, const NewString& str)
{
    return os << "我在重复" << (String&)str;  //OK.
}
#endif
int main(int ac, char **av)
{
    NewString newString;

    cout << newString << endl;
    return 0;
}
