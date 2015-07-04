#include <iostream>
#include <array>

using namespace std;

int main(int ac, char **av)
{
    //Array template (C++ 11)
    // different:
    //            1. Init is differ.
    //            2. General array is can used variable , but array templat is only can useing constant quantity.
    //       ***  3. Genetal array is sometimes can useing as pointer, but  array template is refuse pointer.
    //            4. Template array get size is easy than generate arry.
    //            5. Generate arry useing pointer, it's copy address, addation cite, not copy value.

    array<string , 5> Names = {"iPhone6", "iPhone 6 plus"};   //Exist statc.

    array<int ,3> codes;
    codes = {200, 300, 400}; // This init is OK, but general array is cat't be do init use this method.

    cout << "Names[0] = " << Names[0] << endl;

    if(Names[4] == "")
    {
        cout << "Names[4] is not init" << endl;
    }
    int abc[3] = {1, 2, 3};

    cout << "Names size = "  << Names.size() << endl;

    cout << " abc size  = "  << sizeof(abc)/sizeof(int) << endl;
/*    
 *     abc[5] = 3;    // [OK.] , no check.
 *     Names[10] = 4; // [OK.] , no check.
 *     cout << "Names[10] = "  << Names[10] << endl;  //result is no judge.
 */   
    for(long i = 0; i < Names.size(); i++)
    {
        cout << "Names[..]" << Names[i] << endl;
    }

    for (int value:codes)
    {
        cout << "codes[..]" << value << endl;
    }

#if 0  
          <1>

    int codes1[3];
    codes1 = {1, 2, 3};  // error! , [FALSE].

    codes1[0] = 200;
    codes1[0] = 300;
    codes1[0] = 400;
#endif
#if 0
           <2>

    int n = 100;
    int codes1[n];           // [OK.]
    array<int , n> caming;   // [FALSE.]

    const int n = 10;
    array<int , n> caming;   // [OK.]
#endif

    array<int , 3> codes2;

    codes2 = codes;  // This is value copy, not pointer copy.
    codes2[0] = 123;
    cout << "codes[0] = " << codes[0] << endl;
    cout << "codes2[0] = " << codes2[0] << endl;

    int codes3[]{1, 2, 3};
    int *pCodes = codes3;
    pCodes[0] = 777;

    cout << "codes3[0] = " << codes3[0] << endl;

    return 0;
}

