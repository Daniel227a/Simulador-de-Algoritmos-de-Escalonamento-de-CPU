#ifndef __COMPARE__FUNCTION__
#define __COMPARE__FUNCTION__
#include "./Process.h"
int compare_by_return_time(const void *a, const void *b)
{
    Process *ptA = (Process *)a;
    Process *ptB = (Process *)b;
    if (ptA->return_time < ptB->return_time)
        return -1;
    else if (ptA->return_time > ptB->return_time)
        return 1;
    else
        return 0;
}
void quick_sort_by_return_time(Process p[], int len)
{
    qsort(p, len, sizeof(Process), compare_by_return_time);
}
void merge(Process arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    Process *sortArr = (Process *)malloc(sizeof(Process) * (right + 1));
    int sIdx = left;
    while (fIdx <= mid && rIdx <= right)
    {
        if (arr[fIdx].arrive_time <= arr[rIdx].arrive_time)
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }
    if (fIdx > mid)
    {
        for (i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        for (i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    for (i = left; i <= right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}
void merge_sort_by_arrive_time(Process arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort_by_arrive_time(arr, left, mid);
        merge_sort_by_arrive_time(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void turnaround_time_total_times(Process *p,int len){
    int i;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    for (i = 0; i < len; i++)
        {   
            if(p[i].turnaround_time = p[i].return_time - p[i].arrive_time<0){

                p[i].turnaround_time = p[i].burst + p[i].waiting_time;
            }else{
                p[i].turnaround_time = p[i].return_time - p[i].arrive_time;
            }
            
            total_waiting_time += p[i].waiting_time;
            total_turnaround_time += p[i].turnaround_time;
            total_response_time += p[i].response_time;
        }

    printf(" \n\n");

    
    printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)len);
    printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)len);
    printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)len);


}

#endif
