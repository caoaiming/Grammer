#include <iostream>
#include <valarray>

using namespace std;

int main(int ac, char **av)
{
    //valarray模板类可做一些数学运算

    valarray<int> array1{10, 20, 30};

    cout << array1.size() << endl;
    cout << array1.sum() << endl;
    cout << array1.max() << endl;

    cout << "-------------------------------------" << endl;
    valarray<int> array2{30, 20 , 10};
    array1.swap(array2);
    cout << array2[0] << endl;
    cout << array2[1] << endl; //valarray内部重载了[]操作符号
    cout << array2[2] << endl;
    cout << "-------------------------------------" << endl;
    valarray<int> array3{99};
    array1.swap(array3);

    cout << "3 = " << array1.size() << endl;
    cout << "1 = " << array3.size() << endl;
    return 0;
}
