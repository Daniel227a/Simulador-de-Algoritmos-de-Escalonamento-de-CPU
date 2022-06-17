#include "CpuSchedulingAlgorithms.h"

int main() {
    int process_count = 0;

    int i = 0;


    Quantum quantum;

    Process *process;

    FILE *fp = fopen("process.txt", "r");


    if (fp == NULL) {
        printf("FILE OPEN ERROR! - Verificar Arquivo do Entrada\n");
        return 0;
    }

    fscanf(fp, " %d", &process_count);

    process = (Process *) malloc(sizeof(Process) * process_count);


    while (i < process_count) {
        fscanf(fp, "%s %d %d %d",
               process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);

        i++;

    }

    fscanf(fp, " %d", &quantum);


    //Chamada da Função que simula a execução do FCFS
    puts("┏                                                                                                                             ┓\n\n");
    printf("%s"," \tFCFS");
    FCFS(process, process_count);
    fcfs_print_gantt_chart(process ,process_count);
    turnaround_time_total_times(process ,process_count);
    print_table(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");

    
    //Chamada da Função que simula a execução do SJF
    puts("┏                                                                                                                             ┓\n\n");
    printf("%s"," \n\tSJF\n");
    SJF(process, process_count);
    sjf_print_gantt_chart(process,process_count);
    turnaround_time_total_times(process ,process_count);
    print_table(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");

    
    //Chamada da Função que Simula a execução do Round-Robin
    puts("┏                                                                                                                             ┓\n\n");
        quantum=3;
        //printf("%s"," \tRR");
        RR(process,  process_count, quantum);
        rr_print_gantt_chart(process,process_count,quantum);
        turnaround_time_total_times(process ,process_count);
        print_table(process,process_count);


    puts("┗                                                                                                                             ┛\n\n");

    
    puts("┏                                                                                                                             ┓\n\n");
    printf("%s"," \tLOTERY");
    process_init(process, process_count);
    Lotery(process, process_count);
    rr_print_gantt_chart(process,process_count,quantum);
    turnaround_time_total_times(process ,process_count);
    print_table(process,process_count);
    puts("┗                                                                                                                             ┛\n\n");

   
    puts("┏                                                                                                                             ┓\n\n");
    printf("%s"," \n\tSRT\n");
    SRT(process, process_count);
    rr_print_gantt_chart(process,process_count,quantum);
    turnaround_time_total_times(process ,process_count);
    print_table(process,process_count);
    puts("┗                                                                                                                             ┛\n\n");
 
    puts("┏                                                                                                                             ┓\n\n");
    printf("%s"," \tPPS");
    PPS(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");



    fclose(fp);


    free(process);


    system("pause");

    
    return 0;

}
