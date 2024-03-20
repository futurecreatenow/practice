#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct JANKEN
{
    int me;
    int pc;
    bool input_flag;
    bool finish_flag;
}JANKEN;

typedef enum SELECT{
    LOCK,PAPER,SCISSORS
}SELECT;

int main(void){
    JANKEN janken;
    janken.me = -1;
    janken.pc = -1;
    janken.input_flag = false;
    janken.finish_flag = false;

    do
    {
        //自分の出し手
        do
        {
            printf("Lock:0,Paper:1,Scissors:2\n");
            scanf("%d",&janken.me);
            if (janken.me == LOCK || janken.me == PAPER || janken.me == SCISSORS)                    
                janken.input_flag = true;
            switch (janken.me)
            {
                case LOCK:
                    printf("you select LOCk\n");
                    break;
                case PAPER:
                    printf("you select PAPER\n");
                    break;
                case SCISSORS:
                    printf("you select SCISSORS\n");
                    break;
                
                default:
                    break;
            }
        } while (janken.input_flag == false);


        //PCの出し手
        srand((unsigned int)time(NULL));
        janken.pc = rand() % 3;

        switch (janken.pc)
            {
                case LOCK:
                    printf("PC select LOCk\n");
                    break;
                case PAPER:
                    printf("PC select PAPER\n");
                    break;
                case SCISSORS:
                    printf("PC select SCISSORS\n");
                    break;
                
                default:
                    break;
            }

        if (janken.me == janken.pc)
            janken.finish_flag = false,
            printf("draw\n");

        else
        {
            switch(janken.me){
                case LOCK:
                    if (janken.pc == PAPER) janken.finish_flag = true, printf("lose\n");
                    if (janken.pc == SCISSORS) janken.finish_flag = true, printf("win\n");
                    break;
                case PAPER:
                    if (janken.pc == SCISSORS)janken.finish_flag = true,printf("lose\n");
                    if (janken.pc == LOCK)janken.finish_flag = true,printf("win\n");
                    break;
                case SCISSORS:
                    if (janken.pc == LOCK)janken.finish_flag = true,printf("lose\n");
                    if (janken.pc == PAPER)janken.finish_flag = true,printf("win\n");
                    break;
                default:
                    break;
            }
        }
        
    }while(janken.finish_flag == false);
        
}