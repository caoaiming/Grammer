/*
 *float : +38    -37
 *精度：  6  - 7
 *double  +308   -307
 *精度：  15 - 16
 * long double  +4932   -4931
 *精度： 18 - 19
 */



     /*    0   |  10000001  |  11110000000000000000000
      *  符号位     指数                尾数 
      *     |         |                  |
      *     |         |                  |
      *float      :      32位， 4个字节
      *    <1>       <8>                <23>
      *double     ：     64位   8个字节      
      *    <1>       <11>               <52>             
      *long double：     128位  16个字节
      *    <1>       <64>               <63>
      */
/*
 *  20.5
 *  20 = 16 + 4 = 10100
 *  0.5 * 2 = 1.0 (1)
 *  0   * 2 = 0
 *    ...
 *  
 *      => 0.5 = 0.1 (二进制小数位)
 *  20.5 = 10100.1（二进制结果）======>1.01001E100(2^4)
 *存储方式:float              0-00000100  <移位存储> +   127  【01111111】
 *                         +    01111111
 *                         ==>4 + 127 = 128 + 3 = 10000011
 *                      -->0-10000011-01001 000000000000000000  <23位尾数>
 *
 *存储方式：double            0-00000000100 <移位存储> + 1023 【0111111111】
 *                         +    01111111111
 *                         ==>4 + 1023 = 3 + 1024 = 10000000011
 *                      -->0-10000000011-01001 00000000000...(52位尾数)
 *比较过程：
          符号位    指数<移位后>                 尾数
 *float ：  0     000-00000100<补齐11位>   01001000000000000000000..<补齐0>
 *double：  0      00000000100             01001000000000000000000..
 *
 */

/*
 *  20.3
 *  20 = 16 + 4 = 10100
 *  0.3 * 2 = 0.6 （0）
 *  0.6 * 2 = 1.2 （1）
 *  0.2 * 2 = 0.4 （0）
 *  0.4 * 2 = 0.8 （0）
 *  0.8 * 2 = 1.6 （1）
 *  0.6 * 2 = 1.2 （1）
 *  0.2 * 2 = 0.4 （0）
 *        ...
 *         =>0.3 = 0.01001 1001 1001 1001 ...
 *  20.3 = 10100.01001 1001 1001 ...=============>1.0100010011001...E100
 *  float :         0-   10000011-01000100110011001100110      (23位尾数)
 *  double:         0-10000000011-01000100110011001100110011...(52位尾数)
 *
 * 比较过程：
          符号位    指数<移位后>                 尾数
 *float ：  0     000-00000100<补齐11位>   01000100110011001100110..<补齐0>
 *double：  0      00000000100             01000100110011001100110011...
 *
 *double 强制转换 float:
 *  (1)符号位不变 (2)指数位还原缩减至8位 (3)小数位由52位截断至23位
 */

#include <iostream>
#include <cfloat>
#include <stdio.h>
using namespace std;

void binary(float f1, double d1)
{
    unsigned int *f = (unsigned int*)(&f1);
    unsigned long *d = (unsigned long*)(&d1);
    //printf("num = %f\n", f1);
    cout << f1 << endl;
    for(int i = 31; i >= 0; i--)
        cout << (*f >> i & 1) << (i == 31 || i == 23 ? "-":"");
    cout << endl;

    for(int j = 63; j >= 0; j--)
        cout << (*d >> j & 1) << (j == 63 || j == 52 ? "-" : "");
    cout << endl;
    cout << "-------------------------------------------------" << endl;
}

int main(int argc, const char *argv[])
{
    float f_v1 = 20;
    float f_v2 = 20.3;
    float f_v3 = 20.5;

    double d_v1 = 20;
    double d_v2 = 20.3;
    double d_v3 = 20.5;

    float  fl1 = 3.123432343234323432343234;
    double db1 = 3.123432343234323432343234;

    printf("float : %0.10f\n", fl1);
    printf("double : %0.20lf\n", db1);
    //cout <<"double :" << db1 << endl;

    cout << ((f_v1 == d_v1)? "true" : "false") << endl;
    cout << ((f_v2 == d_v2)? "true" : "false") << endl;
    cout << ((f_v3 == d_v3)? "true" : "false") << endl;
    
    binary(f_v1, d_v1);
    binary(f_v2, d_v2);
    binary(f_v3, d_v3);

    return 0;
}