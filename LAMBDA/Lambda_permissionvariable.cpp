#include <iostream>

using namespace std;
/*
     Lambda表达式与所在作用域变量的访问权限.
     []  :不允许访问任何的外部变量.
 
     [&] :表示对外部变量是引用，一旦修改，外边也修改.
 
     [=] :可以访问外部的任何变量，拷贝参数到Lambda表达式里边，但是默
          认没有修改权限，不允许修改，需要添加关键字：mutable<可变的>
          并且不能再省略()，哪怕没有参数，因为如果不加，不知道是给返回值
          前边还是参数前边加此关键字,按常理应该给返回值前边加.
 
     [=, &a]: 除了a是引用外,其他都是拷贝.
    
     [&, a] : 除了a是拷贝外,其他都是引用.
 
     [&, a, b ,c ...]  
            
              :可以有更多的组合形式，用 ',' 隔开。。。
*/

int main(int ac, char **av)
{
    string str;
    str.resize(20);
    
    srand((unsigned)time(0));
    
    int a = 97;
    int length = 26;
    
    /*默认情况下，Lambda表达式不具有访问外部变量的权限.,所以a不让访问，出错.*/
    //generate(str.begin(), str.end(), []{return a + rand()%97 + 26;});
    
    /*解决办法1： 使用 ‘&’ 引用*/
    generate(str.begin(), str.end(), [&]{a = 40; return rand()%26 + 97;});
    cout << str << endl;
    cout << "a = " << a << endl;
    cout << "-------------------------------------------" << endl;
 
    /*解决办法2： 使用 ‘=’ 复制参数*/
    generate(str.begin(), str.end(), [=]()mutable{cout << "a = " << a << endl; return rand()%26 + 97;});// = 默认是不允许修改参数的
    
     generate(str.begin(), str.end(), [=]()mutable{a = 40; return rand()%26 + 97;}); //添加 mutable关键字后可以修改,注意此时要加()
    
    cout << str << endl;
    cout << "a = " << a << endl;
    cout << "-------------------------------------------" << endl;
    
    /* 3. 嵌套使用(1) */
    generate(str.begin(), str.end(), [=,&a]{a = 40; return rand()%26 + 97;}); //表示，除了a是引用外，其他全部是拷贝.
    cout << "-------------------------------------------" << endl;

    
    /* 3. 嵌套使用(2) */
    generate(str.begin(), str.end(), [&,length]{a = 40; return rand()%length + 97;}); //表示，除了length是拷贝外，其他全部是引用.
    
    return 0;
}
