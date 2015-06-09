#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int  main(int ac, const char **av) 
{
    enum Color{red1 , green1 = 10 , yellow1};

    cout << "Color::green = " << Color::green1 << endl;
    cout << "Color::red1 = " << Color::red1 << endl;
    cout << "Color::green1 = " << Color::green1 << endl;
    cout << "Color::yellow1 = " << Color::yellow1 << endl;

    enum Color2{red2, green2 = 0, bulu2, yellow2 = 1};

    cout << "Color::red2 = " << Color2::red2 << endl;
    cout << "Color::green2 = " << Color2::green2 << endl;
    cout << "Color::bulu2 = " << Color2::bulu2 << endl;
    cout << "Color::yellow2 = " << Color2::yellow2 << endl;

    enum Color3{red3 = -10, green3, bulu3 = 1, yellow3 = 1};
    cout << "Color::red3 = " << Color3::red3 << endl;
    cout << "Color::green3 = " << Color3::green3 << endl;
    cout << "Color::bulu3 = " << Color3::bulu3 << endl;
    cout << "Color::yellow3 = " << Color3::yellow3 << endl;
    
    enum Tem{red , green, bulu};
    Tem tem = Tem::green;
    if(1 == tem && tem == Tem::green) {
        cout << "Tem::green is equal's 1" << endl;
    }

    enum class Colar4{red,green, bulu};
    enum class Colar5{red,green, bulu};
    Color4 color4 = Color4::green;
#if 0
    if(1 == color4 {
        printf("Ok\n");
    }
#endif
    if(Color4::green == color4) {
        printf("Ok2\n");
    }

    return 0;
}
