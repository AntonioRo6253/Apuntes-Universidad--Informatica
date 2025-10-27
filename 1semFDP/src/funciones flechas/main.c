#include <stdio.h>
#include <stdlib.h>

int main()
{
    void miFuncion(int num,char text[]) {
        return printf("Hello world!\n %d %s",num,text);
    }
    miFuncion(5,"guenasss");
    //printf("Hello world!\n %d",num);
    return 0;
}
