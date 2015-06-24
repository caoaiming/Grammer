#include <iostream>

using namespace std;

template <class T1, class T2>
class Person
{

};

class TestClass
{

};
/*P的类型必须是模板类，且这个类型模板有且只能有两个类型参数*/
template<template<class T1, class T2> class p>
class MyClass
{
};

int main(int ac, char **av)
{

    MyClass<Person> myClass1;// OK.

    return 0;
}

