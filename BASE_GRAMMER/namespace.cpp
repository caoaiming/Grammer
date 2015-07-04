#include <iostream>

using namespace std;

int value = 40;

namespace namespace1 {
    int value = 10;
    void process(int);
}

namespace namespace2 {
    int value = 20;
}

namespace namespace1 {
    void process(int n)
    {
        cout << n << endl;
        return n;
    }
}

int main(int ac, char **av)
{
    //命名空间可以是全局的（外部链接性），也可以在于另外一个命名空间内部
    //《嵌套命名空间》
    //命名空间不能存在于一个块内(block)
    //全局命名空间(global namespace) cout << ::value <<endl;
    //using 引用该命名空间下的所有成员
    //using namespace 可以放到函数内部
    //using namespace1::value 直接指定命名空间下的某个成员
    
    cout << namespace1::value << endl;
    cout << namespace2::value << endl;
    namespace1::process(100);
    
    return 0;
}
