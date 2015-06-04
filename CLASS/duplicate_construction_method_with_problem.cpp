#include <iostream>
#include <string.h>

using namespace std;

class MyClass {
private:
    string name;
    char *str;
public:
    MyClass()
    {
        name = "xiao ming";
        str = new char[20];
        strcpy(str, "你好!");
    }

    string getName() {return name;}
    char * getStr()  {return str; }

    void changeStr()
    {
        strcpy(strlen(str) + str, "+尾巴..");
    }

    ~MyClass()
    {
        cout << "析构方法启动:" << endl;
        delete [] str;
    }
};

int main(int ac, char **av)
{
    MyClass *class1 = new MyClass();
    MyClass *pClass2 = new MyClass(*class1);

    cout << "Name = " << pClass2->getName() << endl;
    cout << "String = " << pClass2->getStr() << endl;

    pClass2->changeStr();
    cout << "String = " << class1->getStr() << endl;//两个都发生更改. 
    
    delete class1;
    cout << "----------------------------\n" << "delete after :" << endl;
    cout << "Name = " << pClass2->getName() << endl;
    cout << "String = " << pClass2->getStr() << endl; //disapper.....
    //复制构造方法带来的问题是：
    //复制一个类时：对于new得来的空间，不进行复制而是仅仅做简单的引用
    //所以如果复制源释放空间，则后边所有复制生成的类丢失引用.

    return 0;
}
