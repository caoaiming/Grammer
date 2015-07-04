#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0;
    char *ptr = "Linux";
    int i;

    memcpy(&a, ptr, 4);

    printf("%d\n", a);

    unsigned int *b = (unsigned int *)&a;

    for(i = 0; i < 5; i++) {
        printf("%c, %d\n", ptr[i], ptr[i]);
    }

    for(i = 0; i < 32; i++) {
        printf("%d", (*b) >> i & 1);
        if((i+1) % 8 == 0)
            printf("  ");
    }
    printf("\n");

    for(i = 0; i < 4; i++) {
        printf("%d  %c\n", (*b) >> i*8 & 255);
    }
    printf("%s\n", b);

    return 0;
}
