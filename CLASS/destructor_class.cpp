#include <iostream>

using namespace std;

string str;

class Persion {
public:
    Persion()
    {
        cout << "I'm persion constructor" << endl;
    }
};

class Myclass {
private:
    Persion *p_persion;
    int Mcode;
public:
    Myclass(int code)
    {
        p_persion = new Persion();
        Mcode = code;
        cout  << "Myclass is used and  [ code = " << code << " ]" << endl;
    }

    ~Myclass()
    {
        delete p_persion;
        cout << "Myclass destructor mathod is used." << endl;
        cout << str << endl;
    }
};

int main(int ac, char **av)
{
    Myclass myClass(1);

    Myclass *p_myClass1 = new Myclass(2);

    str = "Now is delete p_myClass1";
    delete p_myClass1;

   str = "Now is delete myClass";

    return 0;
}
