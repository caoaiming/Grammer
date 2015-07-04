#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    union MyUnion {
        int  code1;
        long code2;
    };

    MyUnion *p = new MyUnion();
    p->code1 = 200;  //  resout=>p->code1 = p->code2 = 200,  They are equls.

    cout << "p->code1 = " << p->code1 << endl;
    cout << "p->code2 = " << p->code2 << endl;

    (*p).code2 = 400;//  They are equls.
    cout << "p->code1 = " << p->code1 << endl;
    cout << "p->code2 = " << p->code2 << endl;

    delete(p);
    
    return 0;
}
