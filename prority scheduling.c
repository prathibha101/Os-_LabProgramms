#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,k,avg_wt,avg_tat;
    printf("Enter Number of Process:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Burst Time for process%d:\n",i+1);
        scanf("%d",&bt[i]);
        printf("Priority for process%d:\n",i+1);
        scanf("%d",&pr[i]);
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        k=pr[i];
         pr[i]=pr[pos];
        pr[pos]=k;

        k=bt[i];
        bt[i]=bt[pos];
        bt[pos]=k;


    }

    wt[0]=0;
    for(i=1;i<n;i++)
    {
wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    for (i=0;i<n;i++)
    {
        total+=wt[i];
       }

    avg_wt=total/n;
    total=0;
    printf("Waiting time\n");
    for (i=0;i<n;i++)
    {
        printf("%d\n",wt[i]);
    }
    printf("Turn around time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];

    }
     for (i=0;i<n;i++)
   {
 printf("%d\n",tat[i]);
      }

    avg_tat=total/n;
    printf("\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

return 0;
}



