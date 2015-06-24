//
//  File.cpp
//  C++
//
//  Created by westos on 15-6-12.
//  Copyright (c) 2015年 westos. All rights reserved.
//

//
//  main.cpp
//  C++
//
//  Created by westos on 15-6-12.
//  Copyright (c) 2015年 westos. All rights reserved.
//
#include <iostream>
using namespace std;

class ParentClass
{
private:
    int xCode = 20;
public:
    int code = 10;
    int getCode()
    {
        return 30;
    }
    int operator[](string key)
    {
        if(key == "code")
            return code;
        else
            return -1;
    }
};
#if 0
class subClass : private ParentClass
{
public:
    int getCode1()
    {
        return getCode();
    }
};
#endif
//使用using重新定义访问权限，只能改变以下情况：
//改变私有、保护继承方式中父类的public权限，不能改变父类是
//private类型的权限。
class subClass : private ParentClass
{
public:
    using ParentClass::code;
    using ParentClass::getCode;//不用括号，自定识别方法还是
    //变量
    using ParentClass::operator[];
    //using ParentClass::xCode;  Error不允许.
};
int main(int ac, char **av)
{
    subClass  one;
    cout << one.getCode() << endl;
    cout << one.code << endl;
    cout << one["code"] << endl;
    cout << one["abc"] << endl;
}