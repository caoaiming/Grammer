#include <iostream>

using namespace std;

class Inline {
public:
    void method()
    {
        cout << "method" << endl;
    }
    void process();
};

inline void Inline::process()
{
    cout << "This is process()" << endl;
}

int main(int ac, char **av)
{
    Inline myline;
    myline.method();
    myline.process();
    return 0;
}
