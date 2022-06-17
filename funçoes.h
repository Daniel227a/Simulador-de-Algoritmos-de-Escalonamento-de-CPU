#include<stdio.h>
#include<stdlib.h>
#include"Process.h"
void lerTxt();

void lerTxt(){
    FILE *fp = fopen("process.txt", "r");
    char c;
    do
    {
    //faz a leitura do caracter no arquivo apontado por pont_arq
    c = fgetc(fp);
    
    //exibe o caracter lido na tela
    printf("%c" , c);    
    
    }while (c != EOF);

}

int arrive_time_sort(Process *process,int i, int process_count,Process *temp){
//recebe i == index do prcesso que esta na cpu
//temp = vet do tipo process 
//gera um novo temp ordenado com os arrive time <que o bruts do prrocesso atual 
//retorna o tamnho do vet com todos os arrive time <que o bruts do prrocesso atual 
   // printf("AAAAAAAAAAaaa");
    int j;
    int cont;
    cont=0;
    Process temp_process;
    for(j=i+1;j<process_count-1;j++){
        if((process[i].burst+process[i].arrive_time)>process[j].arrive_time &&process[i].completed!=1){
            
            temp[cont]=process[j];
           
            cont++;
        }

    }
    
    int len_vet=cont;
    cont=0;
    
    //printf("----\n");
    for(i=0;i<len_vet-1;i++){
        for(j=i+1;j<len_vet;j++){
            if((temp[i].arrive_time)>(temp[j].arrive_time )){
                temp_process=temp[i];
                temp[i]=temp[j];
                temp[j]=temp_process;

            }
          
        }
    

    }
    for (i=0;i<len_vet;i++){
         printf("%d",temp[i].arrive_time);

    }
    return cont;
}

int bruts_time_sort(Process *process,int i, int process_count,Process *temp){

    

















    int j;
    int cont;
    cont=0;
    Process temp_process;
    for(j=i+1;j<process_count-1;j++){
        if((process[i].burst)>process[j].burst ){
            
            temp[cont]=process[j];
           
            cont++;
        }

    }
    
    int len_vet=cont;
    cont=0;
    
    //printf("----\n");
    for(i=0;i<len_vet-1;i++){
        for(j=i+1;j<len_vet;j++){
            if((temp[i].burst)>(temp[j].burst )){
                temp_process=temp[i];
                temp[i]=temp[j];
                temp[j]=temp_process;

            }
          
        }
    

    }
    for (i=0;i<len_vet;i++){
         printf("%d\n",temp[i].burst);

    }
    return cont;
}


