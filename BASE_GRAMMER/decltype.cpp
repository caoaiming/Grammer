#include <iostream>

using namespace std;

int fun(int);


int main(int ac, const char **av)
{
    //decltype的规则
    //decltype(expression) var
    //1.    expression 是一个未用括号括起来的标识符，var的类型与标示符相同，包括const等限定符
    //2.    expression是一个函数调用，var的类型与函数的返回类型相同
    //3.    expression是一个带括号的标示符，var 的类型是标示符对应类型的引用类型
    //4.    以上三种情况都不满足，则var 的类型和expression的类型相同

    /*情况1*/
    double x =30.5;
    int y = 20;
    const short sum = 30;
    double &k = x;

    decltype(x) var_x; //double
    decltype(y) var_y; //int
    decltype(sum) sum1 = 30;     //const short 必须初始化
    decltype(k) kk = x;          //别名引用,必须初始化，已经是一个引用类型，必须需要一个引用的对象，都是x的别名

    kk = 123.321;
    cout << "x = " <<  x <<endl;
    /*情况2*/
    decltype(fun(20)) return_type = 100; //double，并不会调用函数，只是取得返回值类型确定变量的类型

    /*情况3*/
    double value = 30.1;
//    decltype(value)  value1; //double
    decltype((value))  value1 = x; //double & 引用类型
    value1 = 100000.111;

    cout << value1 << endl;
    cout << x  << endl;

    /*情况4*/
    int m = 20;
    short n = 10;
    decltype(m+n) mn; //int

    decltype (100.1f) valuef; //float

    int &abc = m;
    decltype(m+abc) mabc; //普通int 

    double mmm = 100000.001;


    return 0;
}
