#include <stdio.h>
#include <process.h>

void print(int num,const char **pp){
    for (int i = 0; i < num; i++)
    {
        printf("%s\n",pp[i]);
    }
    
}
int main(void){
    const char * p[] = {
        "ABC",
        "DEF",
        "GHI",
    };
    int num = sizeof(p) /sizeof(p[0]);
    print(num,p);
    return 0;
}