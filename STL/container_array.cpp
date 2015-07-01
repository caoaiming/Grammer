#include <iostream>
#include <array>

using namespace std;
/*
    数组模板类： array <并不属于STL>
    方法：
          insert, push_back, [] , at, begin, end ...
*/

void output(int value)
{
    cout << value << "  ";
}

int main(int ac, char **av)
{
    array<int, 5> array_int {1, 2, 3 ,4 ,5};
    
    for_each(array_int.begin(), array_int.end(), output);
    cout << endl;
    cout << "------------------------------------------" << endl;
    
    for_each(array_int.rbegin(), array_int.rend(), output);
    cout << endl;
    cout << "------------------------------------------" << endl;

    cout << "array_int[2] = " << array_int[2] << endl;
    
    cout << "array_int.at(3) = " << array_int.at(3) << endl;
    
    cout << "array_int.size() = " << array_int.size() << endl;
    
    return 0;
}
