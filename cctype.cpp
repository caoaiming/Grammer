#include <iostream>
#include <cctype>

using namespace std;

#if 0
cctype synopsis
namespace std
{
   int isalnum(int c);
   int isalpha(int c);
   int isblank(int c);
   int iscntrl(int c);
   int isdigit(int c);
   int isgraph(int c);
   int isalower(int c);
   int isprint(int c);
   int ispunct(int c);
   int isspace(int c);
   int isupper(int c);
   int isxdigit(int c);
   int tolower(int c);
   int toupperint c);
} //std

#endif


int main(int argc, const char **argv)
{
    char c1 = 'a';
    char c2 = '5';
    char c3 = 'A';

    if(isalpha(c1))
        cout << "c1 is alpha" << endl;
    if(isalnum(c2))
        cout << "c2 is a num" << endl;

    return 0;
}

