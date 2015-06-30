#include <iostream>
#include <deque>

using namespace std;
/* 同时兼具vector和list的双端队列.
 
   介绍：具有双方的部分优势: 
                       1.可以随机访问 
                       2.插入或者删除两端是常量操作
  注意：如果从中间插入或删除，时间复杂度就不是常量了.
 
 */

int main(int ac, char **av)
{
    deque<int> values {1, 2, 3, 4 ,5};

    cout << "values[2] = " << values[2] << endl; // 3

    values.erase(values.begin());
    cout << values[0] << endl;   // 2

    values.insert(values.begin(), 20);
    cout << values[0] << endl;   // 20

    cout << "-------------------------------------------" << endl;
    values.erase(values.end()-1);
    cout << *(values.end()-1) << endl;

    return 0;
}
