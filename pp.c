#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define ADD(x,y) (x + y) //関数形式のマクロの使用

typedef struct DATA{
    int before_score;
    int after_score;
    struct DATA *next;
}DATA;

int main (void){
    DATA first_data;
    DATA second_data;
    DATA *pdata;

    first_data.next = &second_data;
    second_data.next = NULL;

    bool score_flag = false;
    int add_score;
    do
    {
        printf("first subject input\n");
        scanf("%d",&first_data.before_score);
        printf("second subject input\n");
        scanf("%d",&second_data.before_score);
        printf("add score input\n");
        scanf("%d",&add_score);

        if ((0 <= first_data.before_score) && (first_data.before_score <= 100) &&
            (0 <= second_data.before_score) && (second_data.before_score <= 100) &&
            (0 <= add_score) && (add_score <= 100))
        {
            score_flag = true;
        }
        else
        {
            printf("input agein\n");
        }
        
    } while (score_flag == false);
    
    first_data.after_score = ADD(first_data.before_score,add_score);
    second_data.after_score = ADD(second_data.before_score,add_score);

    for (pdata  = &first_data; pdata != NULL; pdata = pdata->next)
    {
        printf("score>>>%d\n",pdata->after_score);
    }
    
    return 0;
    

}