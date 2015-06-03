#include <iostream>

using namespace std;

class Myclass
{
private:
    int Code;
public:
    Myclass()
    {
        Code = -1;
        cout << "This is zero argv" << endl;
    }
    Myclass(int code)
    {
        Code = code;
        cout << "this is 1 argv" << endl;
    }
    Myclass(string name, int code)
    {
        Code = code;
        cout << "this is 2 argv" << endl;
    }

    void process()
    {
        cout << Code << endl;
    }
};

int main(int ac, char **av)
{
    Myclass classes[3] = {Myclass(), Myclass(1)};//this 3 class will default init no argv mathod
//    Myclass classes[3] = {Myclass(), Myclass(1), Myclass("Linux", 2)};

    classes[2].process();
    cout << "---------------------------------------------------" << endl;
    Myclass classes2[] = { Myclass(), Myclass(1)}; //OK two class.
    cout << "---------------------------------------------------" << endl;

    Myclass *pClasses = new Myclass[3];
    pClasses[1].process();
    delete pClasses;

    cout << "----------------------------------------------------" << endl;

    Myclass *arryMyclass[3] = {new Myclass(1), new Myclass(2)};

    cout << arryMyclass[2] << endl;

    delete arryMyclass[0];
    delete arryMyclass[1];
//    delete arryMyclass[2];
    cout << "----------------------------------------------------" << endl;

    Myclass **pp;

    typedef Myclass* NewType;

    pp = new NewType[3];

    for(int i = 0; i < 3; i++)
    {
        pp[i] = new Myclass(i+1);
        pp[i]->process();
        delete pp[i];
    }
    delete pp;

    return 0;
}
