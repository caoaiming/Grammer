#ifndef _CLASS1_H_
#define _CLASS1_H_

#include <iostream>
using namespace std;

class Persion {
private:
    int    mCode;
    string mName;
    string value;
public:
    void setCode(int code);
    void setName(string name);
    void setValue(string value);
    int  getCode();
    string  getValue();
};
#endif
