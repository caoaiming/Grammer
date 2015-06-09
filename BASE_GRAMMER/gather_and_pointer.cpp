#include <iostream>
#include <vector>
#include <array>

using namespace std;
                                  /* begin()  <-->  end()  voerall method */


int main(int ac, char **av)
{
    int arr_int[4]{1, 2, 3, 4};

    int *endP = arr_int + sizeof(arr_int)/sizeof(int);

    for(int *p = arr_int; p != endP; p++)
        cout << *p << endl;
/*------------------------------------------------------------------------*/
    for(auto p= begin(arr_int);p != end(arr_int); p++)
        cout << "New<begin--end> = " << *p << endl;
/*------------------------------------------------------------------------*/
    
    vector<int> codes{200, 300, 400};
//    for(auto p = codes.begin(); p!= end(codes); p++)
    for(auto p = begin(codes); p!= end(codes); p++)
        cout << "vector :" << *p << endl;
/*------------------------------------------------------------------------*/

    array<int, 3> arr_code{123, 456, 789};

    for(auto p = begin(arr_code); p !=  end(arr_code); p++)
        cout << "array: " << *p << endl;

    return 0;
}
