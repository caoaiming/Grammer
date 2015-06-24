//
//  Multipe_extend.cpp
//  C++
//
//  Created by westos on 15-6-12.
//  Copyright (c) 2015年 westos. All rights reserved.
//
#include <iostream>
using namespace std;
//多继承(multiple inheritance, MI)
/*
优点:
1.完成单继承无法描述的事情
缺点:
1.每个类都多继承了父类的话，继承树的层次非常复杂，代码不易维护
  容易长生冲突,可能多个父类中成员的名字都是相同的.
2.有人建议去掉多继承，但是不可能，因为考虑到向下兼容，不能去掉
*/
class Person
{
public:
    string name;
    int age;
};
ostream& operator<<(ostream& os, Person& person)
{
    return os << "姓名：" << person.name << "  年龄：" << person.age;
}

class Teacher
{
public:
    int code;
    string school;
    string specialty;
};
ostream& operator<< (ostream& os, Teacher& teacher)
{
    return os << "职工编号：" << teacher.code << "学校：" <<teacher.school << "专业：" << teacher.specialty;
}

class Professor : public Person, public Teacher
{
public:
    string title;
};
ostream& operator<< (ostream& os, Professor& professor)
{
    return os << (Person&)professor << endl << (Teacher&)professor << endl << professor.title;
}
//教授具有多重身份
int main(int argc, char **argv)
{
    Professor p;
    p.name = "小王";
    p.age = 40;
    p.code = 25;
    p.school = "西安邮电大学";
    p.specialty = "物联网";
    p.title = "教授";
    
    cout << p << endl;
    
    return 0;
}
