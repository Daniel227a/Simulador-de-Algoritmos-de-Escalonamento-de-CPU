#ifndef __FIRST__COME__FIRST__SERVED__
#define __FIRST__COME__FIRST__SERVED__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"


void fcfs_print_gantt_chart(Process *p, int len)
{
    int i, j;
    printf("\t ");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t|");


    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("%s", p[i].id);

        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("|");
    }

    printf("\n\t ");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t");


    printf("0");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("  ");

        if (p[i].return_time > 9)
            printf("\b");

        printf("%d", p[i].return_time);

    }

    printf("\n");
}


void FCFS(Process *process, int process_count)
{
    
    
    merge_sort_by_arrive_time(process ,0,process_count - 1);
    int time_cont;
    time_cont=0;
    int i=0;
    int j=0;
    int response_time_cont;
    for(i=0;i<process_count;i++){
        for(j=i;j>=0;j--){
             time_cont=time_cont+process[j].burst;
             response_time_cont=response_time_cont+process[j].arrive_time;
            
        }
    
        process[i].return_time=time_cont;
        if(i!=0){
            process[i].response_time=process[i-1].return_time-process[i].arrive_time;
            process[i].waiting_time=process[i-1].return_time-process[i].arrive_time;
            process[i].turnaround_time=process[i].return_time-process[i].arrive_time;
        }else{
            process[i].response_time=0;
            process[i].waiting_time=0;
            process[i].turnaround_time=process[i].return_time-process[i].arrive_time;
        }
        
        process[i].completed=TRUE;
        time_cont=0;
        printf("\n");
    }
   
}

#endif
