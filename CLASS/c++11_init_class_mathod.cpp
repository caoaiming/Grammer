#include <iostream>

using namespace std;

class Myclass
{
 public:
    int code;
    string name;

    Myclass()
    {

    }

    Myclass(int code ,string name)
    {
        cout << code << "    " << name  << endl;
    }
};

int main(int ac, char **av)
{
    Myclass myclass1 = {20, "Bill"};
    Myclass myclass2{10000, "Caming"};

    return 0;
}
