#include <iostream>

using namespace std;

template <typename T1, typename T2>
void templateFun(T1 x, T2 y)
{
    // x: double  , y: int --> double
    // double sum = x + y;
    decltype(x + y) sum; //declare
    sum = x + y;

    cout << sum << endl;
}

int main(int ac, char **av)
{
    /*decltype (c++11)*/
    int a = 30;
    double b = 30.4;
    for(i = 0; i< 10; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            //TODO.
        }
    }
    templateFun(a, b);

    return 0;
}
