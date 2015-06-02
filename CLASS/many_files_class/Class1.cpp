#include "Class1.h"

void Persion::setCode(int code)
{
    mCode = code;
}

void Persion::setName(string name)
{
    mName = name;
}

void Persion::setValue(string value)
{
    this->value  = value;
}

int Persion::getCode()
{
    return mCode;
}

string Persion::getValue()
{
    return value;
} 
