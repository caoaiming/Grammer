#include <iostream>
#include <bitset>

using namespace std;

int main(int ac, char **av)
{
    union Union1 {
        int code1;
        long long code2;
        float price;
        bool falg;
    }myUnion; //size = 8 byte

    myUnion.code1 = 300;
    myUnion.code2 = 32767;
    cout << "MyUnion.code1  :" << myUnion.code1 << endl;
    cout << "MyUnion.cede2  :" << myUnion.code2 << endl;


    struct Struct1 {
        int code1;
        long long code2;
        float price;
        bool falg;
    };// size = 24byte

    union Union2 {
        int code1;
        long long code2:4;
        float price;
        bool falg;
    }myUnion2;// size = 8byte
    
    myUnion2.code2 = 13;  // =  -3

    unsigned long long *n = (unsigned long long *)&myUnion2;
    bitset<64> b(*n);
    cout << b << endl;                                               //补码
/*000000000000000001111111111111110100001111110000011010100110 1101*/ <1011>

    cout << "myUnion   :" << myUnion2.code2 << endl;
    cout << "MyUnion1 size:" << sizeof(Union1) << endl;
    cout << "MyStruct size:"  << sizeof(Struct1) << endl;
    cout << "MyUnion2  size:"  << sizeof(Union2) << endl;

    return 0;
}
