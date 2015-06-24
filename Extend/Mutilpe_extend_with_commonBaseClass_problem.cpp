#include <iostream>

using namespace std;
//多继承与共同基类
/*
 一个子类继承了多个父类，多个父类又有共同的基类，这样的话会怎么样？
 
 */
class baseClass
{
};

class ParentClass1 : public baseClass
{
};

class ParentClass2 : public baseClass
{
};
//SubClass有两份baseClass.
class SubClass : public ParentClass1, public ParentClass2
{
};

int main(int ac, char **av)
{
    SubClass* subClass = new SubClass();
    //baseClass* base = subClass;   此处有歧义
    //转的时候不知道是转给ParentClass1的baseClass，还是
    //ParentClass2的baseClass.
    //解决办法：
    //1.去掉一个继承，只保留一份
    //2.强调一下:
    baseClass *base = (ParentClass2 *)subClass;
    return 0;
}