#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int  i;
    long j;
    string s;

    for(i = 0, j = 0, s = "ab"; i < 5 && j < 10; i++, j+=4){
        //TODO...
    }

    for(i = 0; cout << "hello,world!" << endl, i < 3, false; i++)
    {
        //TODO...
    }

    for(i = 0; cout << "hello,world!" << endl, i < 3 ;i++, cout << "xyz" << endl){
        //TODO...
    }
#if 0
    for(;;){   // is can't stop.
         //TODO...
    }
#endif
    return 0;
}
