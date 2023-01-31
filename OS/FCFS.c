#include<stdio.h>
#define MAX 10

int main()
{
    int n,burst_time[MAX],turnaround_time[MAX],processes[MAX],waiting_time[MAX];

    float average_waiting_time=0, average_turnaround_time = 0;

    printf("\nEnter number of processes: \n");
    scanf("%d",&n);

    printf("\nEnter all Processes: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&processes[i]);

    printf("\nEnter Burst Times of all processes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&burst_time[i]);
    
    printf("\nProcess \t Burst Time \t Waiting Time \t Turnaround Time");

    waiting_time[0] = 0;   
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            waiting_time[i] = burst_time[i-1]+waiting_time[i-1];
        }

        turnaround_time[i] = burst_time[i] + waiting_time[i];

        average_turnaround_time = average_turnaround_time+turnaround_time[i];
        average_waiting_time = average_waiting_time+waiting_time[i];

        printf("\n   %d \t\t   %d \t\t    %d \t\t   %d",processes[i],burst_time[i],waiting_time[i],turnaround_time[i]);
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;

    printf("\nAverage Waiting Time = %f",average_waiting_time);
    printf("\nAverage Turnaround Time = %f",average_turnaround_time);

    return 0;
}