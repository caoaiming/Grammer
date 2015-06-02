#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(int ac, char **av)
{
    int arr_int[4]{1, 2, 3, 4};

    for(auto n:arr_int)
        cout << n << endl;
    cout << "-----------------------------" << endl;
    
    vector<int>  codes{100, 200, 300};

    for(auto code:codes)
        cout << code << endl;
    cout << "-----------------------------" << endl;

    array<int, 3> arr_codes{123, 456, 789};

    for(auto b:arr_codes)
        cout << b << endl;
    return 0;
}

