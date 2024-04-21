#include <stdio.h>
// ifdef~endif条件コンパイルを使ったデバッグ処理の埋め込み
#define D_DEBUG_ON

int add(int num1,int num2){
#ifdef D_DEBUG_ON
    printf("num1:%d,num2:%d\n",num1,num2);
#endif
    return num1 + num2;
}

int main(){
    int num1 = -1,num2 = -1;
    int sum = -1;
    printf("INPUT num1\n");
    scanf("%d",&num1);
    printf("INPUT num2\n");
    scanf("%d",&num2);
    sum = add(num1,num2);
    printf("sum = %d\n",sum);
    return 0;
}