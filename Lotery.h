#ifndef __Lotery__
#define __Lotery__
#include<time.h>
#include<string.h>
#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"
typedef struct Bilhete
{
    char id[255];
    int inicio;
    int fim;
    int completa;


    /* data */
}bilhete;


void lotery_print_gantt_chart(Process *p, int len) {
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

		if (p[i].turnaround_time > 9)
			printf("\b");

		printf("%d", p[i].return_time);
	}

	printf("\n");
}

void Lotery(Process *process, int process_count) {
       
    
    int i = 0;
    int j;
    int cont_bilhetes=0;
    bilhete *aloca_bilhete;
    Process *temp;
    aloca_bilhete=(bilhete *) malloc(sizeof(bilhete) * process_count);
    temp=(Process *) malloc(sizeof(Process) * process_count);
    
    for(i =0;i<process_count;i++){

        cont_bilhetes+=process[i].priority;

    }
    bilhete vet_bilhete[cont_bilhetes];

    for (int i = 0; i < process_count; i++)
    {
        
        if(i!=0){
            
            strcpy(aloca_bilhete[i].id,process[i].id);
            aloca_bilhete[i].inicio=aloca_bilhete[i-1].fim;
            aloca_bilhete[i].fim=process[i].priority+aloca_bilhete[i].inicio;

        }else{

            strcpy(aloca_bilhete[i].id,process[i].id);
            aloca_bilhete[i].inicio=0;
            aloca_bilhete[i].fim=process[i].priority;
        }   

    }
    for(int i =0;i<process_count;i++){
        for (int y= aloca_bilhete[i].inicio;y<=aloca_bilhete[i].fim;y++){

             strcpy(vet_bilhete[y].id,aloca_bilhete[i].id);
        }
    }
    
    for(i =0;i<cont_bilhetes;i++){

        vet_bilhete[i].completa=0;
      //  printf("%s   ",vet_bilhete[i].id);

    }
     int premiado=0;
     int cont_process_completed=0;

     srand((unsigned)time(NULL));
     srand(time(NULL));
  
      for (int i = 0; i <process_count; i++)
    {    
            srand((unsigned)time(NULL));
            srand(time(NULL));
            premiado=(rand()%cont_bilhetes);
       if(process[i].completed!=1 && (strcmp(vet_bilhete[premiado].id,process[i].id))){
            srand((unsigned)time(NULL));
            srand(time(NULL));
            temp[cont_process_completed]=process[i];
            cont_process_completed+=1;
            process[i].completed=1;
            //printf("\n%d",premiado);
            //printf("\n o processo %s",process[i].id);
            printf("\n");

        }
       
        if(cont_process_completed ==process_count-1){
           
            for (j=0;j<process_count;j++){

                if( process[j].completed!=1){
                        process[j].completed=1;
                        //printf("\n o processo %s",process[j].id);
                        temp[cont_process_completed]=process[j];
                        cont_process_completed+=1;
                        break;

                }

                    
            }
          
            break;
        }else if(cont_process_completed!=6 && i== process_count-1){
            i=0;
            srand((unsigned)time(NULL));
            srand(time(NULL));
       }
  

     }






for (int i=0;i<process_count;i++){


    process[i].completed=0;

    }
    merge_sort_by_arrive_time(process ,0,process_count );
    int time_cont;
    time_cont=0;
    i=0;
    j=0;
    int response_time_cont;
    for(i=0;i<process_count;i++)
    {
        for(j=i;j>=0;j--)
        {
                time_cont=time_cont+temp[j].burst;
                response_time_cont=response_time_cont+temp[j].arrive_time;
                
        }
        
        temp[i].return_time=time_cont;
        if(i!=0){
            temp[i].response_time=temp[i-1].return_time-temp[i].arrive_time;
            temp[i].waiting_time=temp[i-1].return_time-temp[i].arrive_time;
            temp[i].turnaround_time=temp[i].burst+temp[i].waiting_time;
        }else{
            temp[i].response_time=0;
            temp[i].waiting_time=0;
            temp[i].turnaround_time=temp[i].return_time-temp[i].arrive_time;
        }
        
        temp[i].completed=TRUE;
        time_cont=0;
        //printf("\n");
    }
   
    // fcfs_print_gantt_chart(temp ,process_count);
    // print_table(temp, process_count);
    /* for(i=0;i<process_count;i++){

         printf(" id %s",temp[i].id);
        printf(" tempo de espera (waiting_time): %d",temp[i].arrive_time);
        printf(" é o tempo total gasto pelo processo para sua execução na CPU (brust): %d",temp[i].burst);
        printf(" priridade : %d",temp[i].priority);
        printf("\n");
     */
    
    
    }



#endif