#include <iostream>
#include <stdio.h>
using namespace std;


int main(int argc , const char* argv[])
{
    float f_v1 = 123.4F;

    float f_v2 = 123.4;
    cout << f_v1  << "  " << f_v2 << endl;

    float v1 = 565.292484256;

    printf("%0.7f\n", v1);

    printf("%0.12f\n", 1e7 /9.0);
    printf("%0.12f\n", 1e7F /9.0F);

    return 0;
}
