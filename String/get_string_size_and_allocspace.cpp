#include <iostream>

using namespace std;
/*
      获取string的尺寸和已分配内存空间的尺寸
      因为：string动态添加，所以会对效率有所影响
*/
 

int main(int ac, char **av)
{
    string empty;
    string small = "hello";
    string large = "获取string的尺寸和已分配内存空间的尺寸";
                         /*<16 * 3 + 6  = 54 > 汉字占3个字符*/
    
    cout << "empty size is " << empty.size() << endl;
    cout << "small size is " << small.size() << endl;
    cout << "large size is " << large.size() << endl;
    cout << "-----------------------------------------" << endl;
    
    cout << "empty capacity is " << empty.capacity() << endl;
    /*可以看出系统预先分配了22字节（不同系统有差别）,小于22时不扩展空间*/
    cout << "samll capacity is " << small.capacity() << endl;
    /*仍然是22，不足22*/
    cout << "large capacity is " << large.capacity() << endl;
    /*一步到位63，每次扩增16倍数-1要接近实际大小值，离54最近的就是63*/
    cout << "-----------------------------------------" << endl;
   
    string big = "获取string的尺寸和已分配内存空间的尺寸1234567890";
    cout << "big capacity is " << big.capacity() << endl;
    /*实际是64, 结果计算： 16 * 5 - 1 = 79 */
    cout << "-----------------------------------------" << endl;
    
    //预先分配 resize
    empty.resize(80);
    cout << "empty capacity is " << empty.capacity() << endl;
    /* 16 * 6 - 1 = 95 */
    
    cout << "-----------------------------------------" << endl;
    string hehe;
    for(int i = 0; i < 50; i++)
    {
        hehe += 'a';//干脆一次提高空间，增加运行效率
        if((hehe.capacity()+1) % 16 == 0)
        cout << "hehe capacity is " << hehe.capacity() << endl;
    }
    
    return 0;
}
