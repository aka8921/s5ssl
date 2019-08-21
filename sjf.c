#include<stdio.h>
 
void main()
{
    int burst_t[20],p[20],waiting_t[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter BT:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_t[i]);
        p[i]=i+1;      
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_t[j]<burst_t[pos])
                pos=j;
        }
 
        temp=burst_t[i];
        burst_t[i]=burst_t[pos];
        burst_t[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    waiting_t[0]=0; 


    for(i=1;i<n;i++)
    {
        waiting_t[i]=0;
        for(j=0;j<i;j++)
            waiting_t[i]+=burst_t[j];
 
        total+=waiting_t[i];
    }
 
    avg_wt=(float)total/n;  
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_t[i]+waiting_t[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_t[i],waiting_t[i],tat[i]);
    }
 
    avg_tat=(float)total/n;   
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
