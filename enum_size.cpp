#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    enum Color1{RED, GREEN, BLUE};

    cout << "Color size  " << sizeof(Color1) << endl; //every one is (int), only one int ,not 3.
#if 0
    enum class Color2{RED, GREEN, BLUE};

    cout << "Color2 size =  " << sizeof(Color2) << endl;  // 4 byte
    
    enum class Color3{RED, GREEN, BLUE = INT32_MAX};  //refuse  fuzhi > 4byte_Max;

    Color3 color3 = Color3::BLUE;

    cout << "Colorr3::BLUE=  " << color3 << endl;  
#endif

    /*change enum default size*/

    enum class Color4:short {RED, GREEN, BLUE};  //num < INT16_MAX
    enum class Color5:char  {RED, GREEN, BLUE};  //num < 127

    cout << "Color5 size = " << sizeof(Color5) << endl;

    enum class Color6:unsigned char {RED, GREEN, BLUE};  //num < 255 unsignde
    
    //C++ 11 type
    cout << "Color6 size = " << sizeof(Color6) << endl;

    enum class Color7:int8_t {RED, GREEN, BLUE = -128};  //num < 255 unsignde

    return 0;
}
