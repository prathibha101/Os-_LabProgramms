#include<stdio.h>
int main()
{
int bt[10],n,i,wt[10],tat[10],twt,ttat;
printf("Enter the no of processes");
scanf("%d",&n);
printf("Enter Burst times for  processes");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i] = bt[i-1] + wt[i-1];
}

printf("Waiting Time of each process\n");
for(i=0;i<n;i++)
{
printf("%d\n",wt[i]);
}

printf("Turn Around Time of each process\n");

for(i=0;i<n;i++)
{
tat[i] = wt[i] + bt[i];
}


for(i=0;i<n;i++)
{
printf("%d\n",tat[i]);
}

for(i=0;i<n;i++)
{
twt+=wt[i];
ttat+=tat[i];
}
printf("Average Waiting Time = %f",twt/(float)n);
printf("Average Turn Around Time = %f",ttat/(float)n);
return 0;
}
