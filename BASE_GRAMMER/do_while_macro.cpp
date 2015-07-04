#include <iostream>

using namespace std;

#define PROCESS1  do{cout << "process1" << endl; cout << "next" << endl;}while(0)
#define PROCESS2  {cout << "process2" << endl; cout << "next" << endl;}
#define PROCESS3  cout << "process3" << endl; cout << "next" << endl;


int main(int ac, char **av)
{
    bool flag = true;

    if(flag)
        PROCESS1;
    if(flag)
        PROCESS2;
    if(flag)
        PROCESS3;
    cout << "-------------------------------------" << endl;
    bool flag2 = false;

    if(flag2)
        PROCESS1;
    if(flag2)
        PROCESS2;
    if(flag2)
        PROCESS3;
        
    return 0;

}
