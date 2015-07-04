#include <iostream>
#include <bitset>

/* 结构体的位字段
 *1.定义位字段
 *2.初始化位字段
 *3.如果位字段溢出，会发生什么?
 *4.位字段如何存储
 * */

using namespace std;

int main(int ac, const char **av)
{
    struct Mystruct{
        unsigned int code1;
        unsigned int code2;
        bool flag;
    };  //size = 12 byte

    struct Mystruct2{
        unsigned int code1:4;
        unsigned int code2:4;
        bool flag:1;
    }myStruct2{15,15, true};  //size = 4 byte
    
    struct Mystruct3{
        unsigned int code1:18;
        unsigned int code2:14;
        bool flag:1;
    };  //size = 8 byte
//----------------------------------上面默认是4字节对齐------------
    cout << sizeof(Mystruct) << endl;
    cout << sizeof(Mystruct2) << endl;

    cout << myStruct2.code1 << "\n" << myStruct2.code2 << "\n" << myStruct2.flag << endl;    
    struct Mystruct4{
        unsigned int code1:4;
        unsigned int code2:4;
        bool flag:1;
    }myStruct3{17, 16, false};  //size = 4 byte
    cout << endl;
    cout << myStruct3.code1 << "\n" << myStruct3.code2 << "\n" << myStruct3.flag << endl;    
    unsigned int *n = (unsigned int *)&myStruct3;

    bitset<32> b(*n);

    cout << b << endl;
    /*10111100110111111010011  0 0000 0001  可见发生了溢出截断*/ 
    
    return 0;
}
