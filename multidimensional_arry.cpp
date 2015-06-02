#include <iostream>
#include <strings.h>

using namespace std;

int main(int argc , char **argv)
{
    int code1[10] = {1, 2, 3};

    int code2[5][10] = {{1,2}, {4, 5}, {}, {}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

//    int *p1  = code1;   //[OK.]
//    int **p2 = code2;   //[FALSE.]
        
#if 0
      int **p2 = (int **)code2;  // it's 'OK' now, but ...error..
      cout << p2[1][1] << endl;  // [FALSe.] --> coredump. 


      int *pp1 = new int;  //[OK.]

      int **pp2 = new int [10][10]; //[FALSE]
      int **pp2 = (int **)new int [10][10]; //it's 'OK' now, but ..error..  [no allocte memery]--->[NO SPACE]
      *pp2 = 3;     //[error]. write refused.
      **pp2 = 3;    //[error]. write refused.
      
      
      int * xyz[10];
      *xyz[0] = 3;      // [FALSE.] , it's error.!
#endif
/*----------------------------------------------------------*/      
      int * xyz[10];

      cout << "sizeof(xyz) = " << sizeof(xyz) << endl;

      bzero(xyz, sizeof(xyz));
      xyz[0] = new int;
      *xyz[0] = 3;      // [OK.] , it's corect.!

      cout << "*xyz[0] = " << *xyz[0] << endl;
      cout << "pointer xyz[0] = " << xyz[0] << endl;
      cout << "pointer xyz[1] = " << xyz[1] << endl;
      cout << "pointer xyz[2] = " << xyz[2] << endl;
      cout << "pointer xyz[3] = " << xyz[3] << endl;
      cout << "pointer xyz[4] = " << xyz[4] << endl;
      delete(xyz[0]);
/*----------------------------------------------------------*/      

      int **ppp2 = new int * [10];

      for(int i = 0; i < 10; i++)
      {
          *(ppp2+i) = new int [10];            // <=>  int ppp2[10][10]
      }
      **ppp2 = 203;
      **(ppp2 + 1) = 100;

      cout << "**(ppp2 + 1) = " << **(ppp2 + 1) << " <===>" << " ppp2[1][0] = " << ppp2[1][0] << endl;

      for(int i = 0; i < 10; i++)
          delete(*(ppp2+i));
      delete(ppp2);
 /*--------------------------------------------------------------------------------------------------------------------*/
//      int **pp2 = (int **) new int [10][10]; //[FALSE]
//      cout << "szieof(pp2) = " <<sizeof(pp2) << endl;  // size = 8 byte. = * pointer size = long
    return 0;
}
