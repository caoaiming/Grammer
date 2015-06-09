#include <iostream>

using namespace std;

struct Mystruct{
    mutable int code;
    mutable string name;
};


int main(int ac, char **av)
{
    const struct Mystruct mystruct = Mystruct();
    cout << mystruct.code << "   " << mystruct.name << endl;

    mystruct.code = 20;
    mystruct.name = "abc";

    cout << mystruct.code << "   " << mystruct.name << endl;

    return 0;
}
