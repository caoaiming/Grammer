#include <iostream>
#include <vector>

using namespace std;
/*  迭代器(Iterator)基础
    1.回顾一下vector的基本功能
    2.向vector追加值
    3.什么是迭代器
    4.使用迭代器获取vector中所有的值
    5.使用 begin() 和 end()
    6.利用迭代器枚举vector中所有的值
    7.删除vector中特定区间的值
    8.在vactor中特定的位置插入一个或一组值
*/

void Display(vector<int> &ages)
{
    for(auto it2 = ages.begin(); it2 != ages.end(); it2++)
        cout << *it2 << "  ";
    cout << endl;
}

int main(int ac, char **av)
{
    /*                  vector的基本功能：
     vector是STL中的一个容器，用于存储若干个值
     
     1. vector可以像数组一样，使用[n]来引用特定位置的值
     2. size方法：获取vector中值的个数
     3. swap方法：用于交换容器的内容
     4. begin 和 end 方法：来获取首、尾两个迭代器
     */

    vector<int> ages;
    ages.push_back(20);
    ages.push_back(30);
    ages.push_back(40);
    ages.push_back(50);
    ages.push_back(60);
    
#if 0
    cout << "Now_size1 = " <<ages.size() << endl;
    ages.pop_back();
    cout << "Now_size2 = " <<ages.size() << endl;
    cout << ages[4] << endl;//很奇怪：60已经弹出了，但是还能输出
    //原因：弹出只改变了他的尺寸，和伪指针指向,实际上他的值还是在vector里
    cout << "------------------------------------------" <<endl;
    
             /*弹出后，若新插入值，则会覆盖以前弹出去的值的空间*/
    ages.push_back(61);
    cout << ages[4] << endl;
#endif
    
    /******************************************************/
    /*                  迭代器
     迭代器是一个广义的指针，用于指向容器中当前的值，可以使用
     ++ 、-- 、+ 、- 来移动指针.
     */
     /* 1. 使用迭代器来获取vector中特定位置的值 */
    vector<int>::iterator it;
    it = ages.begin();       /*指向第一个元素*/
    cout <<  "begin() = "<< *it << endl;
    it++;
    cout << *it << endl;
    cout << *(it+2) << endl;
    
    /* begin 和 end 方法 
       注意： begin()指向第一个元素
             end()  指向最后一个元素的下一个(next)元素地址
    */
    it = ages.end();
    cout << *it << endl;/* = 0 */
    cout << *(it-1) << endl; /* = 60，这才是最后一个元素 */
    
    auto it1 = ages.begin();//auto:自动类型识别
    cout << *it1 << endl;
    
                 /*【6】 枚举vector中所有的值 */
    
    /* 1.传统方法 */
    for(int i = 0; i < ages.size(); i++) {
        cout << ages[i] << "  ";
    }
    cout << endl;

    /* 2.新型方法 */
    for(auto it2 = ages.begin(); it2 != ages.end(); it2++)
        cout << *it2 << "  ";
    cout << endl;
    
                 /*【7】 删除vector中特定区间值 */

    ages.erase(ages.begin()+2);//删除第三个
    Display(ages);
    
    ages.erase(ages.begin(), ages.begin() + 3);//左闭右开区间
    Display(ages); //只剩60了.
    
            /*【8】在vactor中特定的位置插入一个或一组值 */
    
    ages.insert(ages.begin(), 10);
    ages.insert(ages.end(), 30);//相当于在60的后边，next成员的前面插入
    Display(ages);
    
    /*区间插入*/
    vector<int> ages1;
    ages1.push_back(100);
    ages1.push_back(200);
    ages1.push_back(300);
    /*          被插对象(含位置)|   从这开始   |  到这结束(开区间)| */
    ages.insert(ages.begin(), ages1.begin()+1, ages1.end());
    Display(ages);

    return 0;
}
