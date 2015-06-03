#include <iostream>

using namespace std;

class Myclass
{
private:
    int mCode = 100;
public:
    int process(int code) const;

    void method() const//error ,have to add const keyword.
    {
        //mCode = 200;  //error , mCode is readonly!
    }
};

int Myclass::process(int code) const //class's all member is const readonly.
{
    //mCode = code;// forbiden to exchanged!

    return mCode;
}

int main(int ac, char *av[])
{
    Myclass myclass;

    cout << myclass.process(200) << endl;
    
    return 0;
}
