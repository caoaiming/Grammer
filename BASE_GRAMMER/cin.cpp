#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    char city1[20];
    char city2[20];


    cout << "city1:";
    //cin >> city1;
    cin.get(city1, 20);

    cout << city1 << endl;
    
    return 0;
}
