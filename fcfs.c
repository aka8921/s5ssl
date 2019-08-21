#include<stdio.h>
 
void main()
{
// <_________________DECLARING THE VARIABLES _________________>
    int burst_t[20],arrival_t[20],completion_t[20],p[20],waiting_t[20],tat[20],i,j,n,total=0,total_tat = 0,pos,temp;
    float avg_wt,avg_tat;
    
    
// <_________________ SCANNING THE NUMBER OF PROCESSES _________________>
    printf("Enter number of process:");
    scanf("%d",&n);



// <_________________SCANNING THE BT AND AT _________________> 
    printf("\nEnter BT and AT:\n");
    for(i=0;i<n;i++)
    {
        printf("(BT) p%d:",i+1);
        scanf("%d",&burst_t[i]);
        
        printf("(AT) p%d:",i+1);
        scanf("%d",&arrival_t[i]);
        
        p[i]=i+1;      
    }


// <_________________SORTING THE AT (AND REARRANGING ALL THE CORRESPONDING TERMS)_________________>
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arrival_t[j]<arrival_t[pos])
                pos=j;
        }
 
        temp=arrival_t[i];
        arrival_t[i]=arrival_t[pos];
        arrival_t[pos]=temp;
        
        temp=burst_t[i];
        burst_t[i]=burst_t[pos];
        burst_t[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
 
 // <_________________ CALCULATING THE WAITING TIME _________________>


    
    completion_t[0] = burst_t[0]+arrival_t[0];
    tat[0] = completion_t[0] - arrival_t[0];
    waiting_t[0]=tat[0] - burst_t[0]; 

    for(i=1;i<n;i++)
    {
        completion_t[i]=burst_t[i];
        for(j=0;j<i;j++)
        	completion_t[i]+=burst_t[j];
 		tat[i] = completion_t[i]-arrival_t[i];
 		waiting_t[i] = tat[i] - burst_t[i];
        total+=waiting_t[i];
        total_tat+=tat[i];
    }
 

 
    printf("\nProcess\t Arrival Time \t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        //tat[i]=burst_t[i]+waiting_t[i];   
        //total+=tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t    %d\t\t\t%d",p[i],arrival_t[i],burst_t[i],waiting_t[i],tat[i]);
    }
 
 
 	avg_wt=(float)total/n;  
    avg_tat=(float)total_tat/n;   
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
