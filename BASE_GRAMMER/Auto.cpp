#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc , const char* argv[])
{
    short s_v = 20;
    int i_v = 20.3;
    float v = 123456789456;

    wchar_t c2{3000};
    printf("%f\n", v);

    cout << c2 << endl;

    return 0;
}
