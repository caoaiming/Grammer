#include <iostream>

using namespace std;

class MyClass1
{
    /* private       私有    
       public        公有    
       protected   继承里用*/

private:
    int code = 100;
public:
    string name = "Bill";
};

int main(int ac, char **av)
{
    MyClass1  c1;
//    cout << c1.code << endl;   [Error]
    cout << c1.name << endl;
    
    MyClass1 *p = new MyClass1();

    cout << p->name << endl;

    delete(p);

    return 0;
}
