#include <iostream>

using namespace std;

int main(int ac, const char **av)
{
    int a = 1;
    int b = 2;

   // const int *c = &a;   <=> int const *c
   // c = &b;  [OK]
   // *c = b;  [FALSE]  value space is const, read-only.  location is before *.
   
#if 0    
   int * const c = &a;
   c = &b;              [FALSE.]  pointer is read-only.  location is after *.
   *c = b;              [OK.]
#endif

/*
   const int * const c = &a;   value space AND pointer is all read-only.
   c = &b;                      [FALSE.]
   *c = b;                      [FALSE.]
*/   
    return 0;
}
