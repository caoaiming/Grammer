#include <iostream>

using namespace std;
/*  typeid 运算符
 *  原型：std::type_info typeid(expression-or-type)
 *  注意：
          1.参数可以是一个类名
          2.参数不是类名时，必须是一个对象，而不是对象指针.
 *   作用：
          判断参数值是不是一个对象？（内部重载了 ’=‘ 号）
 */
class Biology
{
public:
    virtual void process()
    {
    }
};

class Person : public Biology
{
public:
    int code = 200;
    virtual void process()
    {
        cout << "Person" << endl;
    }
};

class Teacher : public Person
{
public:
    string name = "Bill";
};


int main(int ac, char **av)
{
    /*  .name() 方法可以获得参数的类型  */
    cout<<"typeid(Biology).name="<<typeid(Biology).name()<< endl;
    cout<<"typeid(Teacher).name="<<typeid(Teacher).name()<< endl;
    
    Teacher teacher1;
    Teacher *teacher2 = new Teacher();
    if(typeid(Teacher) == typeid(teacher1)) {
        cout << "Teacher == teacher1" << endl;
    }
    if(typeid(Biology) == typeid(teacher1)) {
        cout << "Biology == teacher1" << endl;//不会输出
    }
    cout << "-----------------------------------" << endl;
    if(typeid(Teacher) == typeid(teacher2)) {
        cout << "Teacher == teacher2" << endl;
        /* 不会输出, 因为需要的是对象，而我们给了一个指针 */
    }
    if(typeid(Teacher) == typeid(*teacher2)) {
        cout << "Teacher == teacher2" << endl;
    }
    cout << "-----------------------------------" << endl;
    
    Biology *biology = new Person();
    Person *person = nullptr;
    if(typeid(Person) == typeid(*biology)) {
        cout << "ypeid(Person) == typeid(biology)" << endl;
        person = (Person *)biology;
        cout << person->code << endl;
    }
    cout << "-----------------------------------" << endl;
    
    Person *p;
    try {
        typeid(*p); //检测空指针多对应的对象会失败
    } catch (exception &e) {//异常类基类
        cout << e.what() << endl;
    }
    
    return 0;
}
