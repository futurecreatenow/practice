#include <stdio.h>

int str_length(const char *s){
    int len = 0;
    while(*s++){
        len++;
    }
    return len;
}
int main(void){
    char str[128];
    printf("Input mozi\n");
    scanf("%s",str);
    printf("mozi>>>%s_%d\n",str,str_length(str));
    return 0;
}