#include <iostream>
#include <bitset>

//  #pragma pack(1)  //按1字节方式对齐
//  如果结构体成员变量默认的对齐方式修改后的对齐方式冲突以最小的为准
//  1  2  4  8 16
using namespace std;

int main(int ac, char **av)
{
    struct Mystruct {
        short code1;
        char  c;
    }struct1{10, 'a'};

    cout << sizeof(Mystruct) << endl;
//结构体对其方式
    unsigned int *n1 = (unsigned int *)&struct1;
    bitset<32> b1(*n1);

    cout << "二进制" << b1 << endl;
    /*二进制010001000 1100001 0000000000001010*/

    struct Mystruct2 {
        char c;
        short code;
    }struct2{'a', 10};

    unsigned int *n2 = (unsigned int *)&struct2;
    cout << "Mystruct2 szie:" << sizeof(struct2) << endl;
    bitset<32> b2(*n2);
    cout << "二进制" << b2 << endl;
    /*0000000000001010  0000000001100001*/
    struct Mystruct3 {
        char c;
        int  a;
    }struct3{'0', 65535};

    unsigned long *n3 = (unsigned long *)&struct3;
    cout << "Mystruct3 szie:" << sizeof(struct3) << endl;
    bitset<64> b3(*n3);
    cout << "二进制" << b3<< endl;
    /*00000000000000001111111111111111  011100001111100111000001 00110000*/


    struct Mystruct4 {
        int  a;
        char c;
    }struct4{65535, '0'};

    unsigned long *n4 = (unsigned long *)&struct4;
    cout << "Mystruct4 szie:" << sizeof(struct4) << endl;
    bitset<64> b4(*n4);
    cout << "二进制" << b4<< endl;
    /*00000000000000000000000 00011000 000000000000000001111111111111111*/

    /*  #pragma pack(1)
     * 3
     * 二进制11110100 01100001 0000000000001010
     * Mystruct2 szie:3
     * 二进制11110100 0000000000001010  01100001
     * Mystruct3 szie:5
     * 00000000000000000000000000000000000000001111111111111111 00110000
     * Mystruct4 szie:5
     * 000000000000000000000000 00110000 00000000000000001111111111111111
     * */

    struct Nullstruct {
    
    };

    cout << "null struct size: <" << sizeof(Nullstruct) << ">" << endl;

    return 0;
}
