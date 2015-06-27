#include <iostream>

using namespace std;
//类型识别：dynamic_cast(运算符) <多个方法中的一种>
/*   功能： 1.将一个指针转换为另一个指针.
           2.转换为一个引用（后边再说）.
 
     如何知道转换成功还是失败？用dynamic_cast
     ynamic_cast<<#type#>>(<#expression#>)
                目标类型   变量名称（待转换）
     成功： 返回指向目标类型的指针
     失败： 返回空指针 <nullptr>
 */

class Biology/*父类必须包含一个虚方法，否则没有多态性，后边继承会有问题*/
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
};

class Teacher : public Person
{
public:
    string name = "Bill";
};

int main(int ac, char **av)
{
    Biology* biology = new Biology();
    Biology* biology_person = new Person();//利用多态作隐式转换
    Biology* biology_teacher = new Teacher();//子孙类也可以
    /*虽然是Biology类，但是后台空间是Teacher类的空间*/
    
    Teacher* teacher1 = (Teacher*)biology_teacher;//安全的
    Teacher* teacher2 = (Teacher*)biology;//不安全的
                            /*有可能是Teacher类，也有可能不是*/
    cout << teacher2->name << endl;//没有输出,转换是失败的,空指针
    /*实际上teacher2是 new Biology()所创建的空间,没有name的值 */
    
    cout << "----------------------------------------" << endl;
    Person *person = (Teacher *)biology_teacher;//安全的
    /*因为biology_teacher就是new Teacher()创建的，作为Person
      的子类，会发生隐式的转换*/
    
    Teacher *teacher3 = dynamic_cast<Teacher*>(biology_teacher);
                                   /* <目标类型> <变量名称> */
    //报错说，后边并不是多态的一个东西，我们是层层继承下来的，默认是多态
    //为什么不是呢？  答案：C++规定，要作为一个多态的类，内部必须要有一个
    //虚方法，而我们的Biology 父类 是 <空类>.
    
    cout << "teacher3 Address:" << teacher3 << endl;
    cout << "----------------------------------------" << endl;
    
    Teacher *teacher4 = dynamic_cast<Teacher*>(biology);
    cout << "teacher4 Address:" << teacher4 << endl;
    if(teacher4 == nullptr) {
        cout << "teacher4 转换失败" << endl;
    }
    
    
    return 0;
}