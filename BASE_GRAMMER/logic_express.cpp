#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    int m = 20;
    int n;

    if(m == 20 && (cout << "abc" << endl, n = 0))
        cout << "it's OK." << endl;        //can't cout.... <=> if(n)  ==> but n = 0 it's FALSE.
        
    return 0;
}
