#include <iostream>


namespace space{
    int n = 100;
}

namespace {
    int n = 10;
}
//1.不能在其他文件中使用匿名命名空间的任何资源
//2.匿名空间可以代替static，拥有内部链接性

int main(int argc, char **argv)
{
    using namespace space;
    std::cout << n << std::endl;
    
    return 0;
}
