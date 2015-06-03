#include <iostream>

using namespace std;

namespace persons 
{
    int code = 1;
    namespace teacher 
    {
        int age = 40;
        int code = 100;
    }

    namespace student 
    {
        int age = 15;
        int code = 200;
    }
}

//using namespace persons;
using namespace persons::student;
int main(int ac, char **av)
{
    cout << "code = " << code << endl;
    cout << "age ="<< persons::teacher::age << endl;
    using persons::teacher::code;
    cout << code << endl;

    return 0;
}
