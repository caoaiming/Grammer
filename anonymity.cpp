#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    struct MyStruct {
    }; //1 byte

    union Myunion {
    };// 1 byte

    enum Color {};  // 4 byte

    cout << sizeof(MyStruct) << endl;
    cout << sizeof(Myunion) << endl;
    cout << sizeof(Color) << endl;

    /*匿名类型 和 类型别名(typedef)*/

    //匿名结构体
    struct {
        int code;
        string name;
    }product;//是一个变量

    product.code = 100;

    typedef struct {
        int code;
        long code1;
    }mode_struct; //类型别名,不再是变量了

    mode_struct niming;
    cout << niming.code << "  " << niming.code1 << endl;


    product.name = "abc";
    //匿名共用体
    union {
        int code;
        long code1;
    }mycode;
    mycode.code1 = 1000;
    //匿名枚举类型
    enum {one, tow, three} value;
    value = one;  //此处无名称,全局，不能用 name::one,全局i,名字不可重复
    typedef enum {one1, tow2, three3} type_value;//类型，不是变量

    //枚举类
    enum class {ONE, TWO, THREE} value1;
    //枚举类中匿名中每一个成员都是全局的，不能和其他每句类或匿名每句类型重复
    typedef enum class {ONE1, TWO1, THREE1} value2;

    /*
     *匿名的： 无论是枚举类还是枚举类型，里变所有的值，都是全局的,即不能
     *相同的
     *reasion : 匿名时访问成员没有所属关系，即没有前缀，
     *就不能让成员相同，否则乱了，不知道是谁的
     */

    return 0;
}
