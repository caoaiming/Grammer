#include <iostream>

using namespace std;
int main(int ac, char **av)
{
    int  i = 0;

loop:
    cout << i << endl;
    if(i++ < 10)
        goto loop;

    return 0;
}
