#include <iostream>
#include "Class1.h"

using namespace std;

int main(int ac, char **av)
{
    Persion *p1 = new Persion();

    p1->setCode(20);
    p1->setName("Caming");
    p1->setValue("Casheng");

    cout << p1->getCode() << endl;

//    cout << "Class: value =" << p1->value << endl;
    cout << "value = " <<  p1->getValue() << endl;

    delete p1;
    

    return 0;
}

