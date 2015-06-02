#include <iostream>

using namespace std;

class Myclass
{
private:
    int code;
    void process()
    {
        cout << code << "---> I'm process() mathod." << endl;
    }
public:
    void method(int code)
    {
        this->code = code;
        (*this).code = code;
        this->process();
        (*this).process();
    }
    Myclass *getObject()   //return class pointer.
    {
        return this;
    }
};

int main(int ac, char **av)
{
    Myclass class1;
    class1.method(999);
    if(class1.getObject() == &class1) 
        cout << "equl == " << class1.getObject() << endl;
    
    return 0;

}
