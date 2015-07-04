#include <iostream>
#include <bitset>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(int ac, const char **av)
{
    char str[]  = "Linux";
    int num = 0;

    memcpy(&num, str, 4);

    cout << str << endl;

    unsigned int *n1 = (unsigned int *)&num;
    bitset<32> b1(*n1);

    cout << "resault: " << b1 << endl;

    char *ptr = (char *)n1;
    
    for(int i = 0; i < 4; i++) {
        printf("addr[%p], %c  %d\n", ptr+i, *(ptr+i), *(ptr+i));
    }

    return 0;
}

