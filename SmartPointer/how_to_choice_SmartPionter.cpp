#include <iostream>

using namespace std;
/* 如何选择智能指针 auto_ptr(C++98)、 unique_ptr、shared_ptr（C++11）
   1. auto_ptr: 
                不建议使用，如果是C++98环境，那只能选择它，但是行为不确定.
   2. unique_ptr:
                 只能用在只有一个指针指向内存空间，不允许存在多个引用
   3. shared_ptr:
                 允许多个指针指向同一片对象,
                 eg: 数组中交换对象时,可能需要一个临时值，用到了多个指针
 */

void sortStr(shared_ptr<string> strArray[], size_t size)
{
    for(size_t i = 0; i < size - 2; i++) {
        for(size_t j = 0; j < size - i - 1; j++) {
            if(*strArray[j] > *strArray[j + 1]) {
                shared_ptr<string> temp;
                
                temp = strArray[j];
                strArray[j] = strArray[j + 1];
                strArray[j + 1] = temp;
            }//end if
        }//end for
    }//end for
}

int main(int ac, char **av)
{
    shared_ptr<string> strArray[] {
        shared_ptr<string>(new string("abc")),
        shared_ptr<string>(new string("xyz")),
        shared_ptr<string>(new string("jqx")),
        shared_ptr<string>(new string("lmn")),
        shared_ptr<string>(new string("opq"))
    };
    
    size_t size = 5;
    
    sortStr(strArray, size);
    for(size_t i = 0; i < size; i++)
        cout << *strArray[i] << endl;
    
    return 0;
}
