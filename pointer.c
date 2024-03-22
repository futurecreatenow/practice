#include <stdio.h>
#include <stdbool.h>

typedef void (*pointer)(int *a,int *b);
void add(int *a,int *b);
void sub(int *a,int *b);
void mul(int *a,int *b);
int main(){
    pointer func[3] = {add,sub,mul}; //関数ポインタでジャンプテーブルを定義
    int select_num;
    bool input_flag = false;
    int a,b;
    do
    {
        printf("Select 0:add,1:sub,2:mul\n");
        scanf("%d",&select_num);
        printf("\n");
        printf("first num\n");
        scanf("%d",&a);
        printf("\n");
        printf("second num\n");
        scanf("%d",&b);
        printf("\n");
        if (select_num >= 0 && select_num <= 2)
        {
            input_flag = true;
        }
        
    } while (input_flag == false);
    
    func[select_num](&a,&b);
    return 1;
}
void add(int *a,int *b){
    int answer;
    answer = *a + *b;
    printf("%d",answer);
}
void sub(int *a,int *b){
    int answer;
    answer = *a - *b;
    printf("%d",answer);
}
void mul(int *a,int *b){
    int answer;
    answer = *a * *b;
    printf("%d",answer);
}
