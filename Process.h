#ifndef __PROCESS__
#define __PROCESS__
#include <stdio.h>
#include <stdlib.h>
#define ID_LEN 20
#define TRUE 1
#define FALSE 0
typedef struct _process
{
    char id[ID_LEN];
    int arrive_time;//hora de chegada
    int waiting_time;//tempo de espera
    int return_time;//exit time 
    int turnaround_time;//delta  t
    int response_time;//tempo de resposta
    int burst;
    int priority;
    int completed;
} Process;

typedef int Quantum;
void process_init(Process p[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        p[i].waiting_time = 0;
        p[i].return_time = 0;
        p[i].response_time = 0;
        p[i].completed = FALSE;
    }
}

#endif
