#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass()
    {
        //TODO...
    }
    /*虽然带有默认参数值，但是和无参数一样，定义类对象时参数可有可无，
     * 不传或者参数不足就用默认参数，但是别让编译器范难*/
    MyClass(int code = 1, string name = "Kali")
    {
        cout << "code = " << code << "\n" << "name = " << name << endl;;
    }
};

int main(int ac, char **av)
{
//    MyClass class1;  //错误，不传参数时,编译器搞不定你要调用哪个
    MyClass class2 = {10};
    MyClass class3 = {10, "Hello, World"};
//    MyClass class4 = {"Unix"};
    MyClass *p_class3 = new MyClass(10000,"Linux");

    delete p_class3;

    return 0;
}
