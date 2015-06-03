#include <iostream>

using namespace std;

class Myclass
{
private:
    enum egg{large = 65536, medium = 20, small = 30};
    enum class  shirt:short{large, medium, small};//不指定是int类型
    enum struct shirtr2{large, medium, small};//防止冲突的办法class=struct.
public:
    void display()
    {
        egg a = large;
        cout << a << endl;

        shirt s = shirt::medium; //名字冲突,按照类的方式访问

        cout << (int)s << endl;
    }
};

int main(int ac, char **av)
{
    Myclass myclass;

    myclass.display();
    
    return 0;
}
