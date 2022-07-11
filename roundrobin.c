#include<stdio.h>
#include<stdbool.h>
int turn_around_time(int process[],int n,int bt[],int wt[],int tat[]){
for(int i=0;i&lt;n;i++){
tat[i] = bt[i] + wt[i];
}
}
int waiting_time(int process[],int n,int bt[],int wt[],int q){
int rem_bt[n];
for(int i=0;i&lt;n;i++)
rem_bt[i] = bt[i];
int t =0;
while(1)
{
bool done =true;
for(int i=0;i&lt;n;i++)
{
if(rem_bt[i]&gt;0)
{
done = false;
if(rem_bt[i] &gt;q)
{
t+= q;
rem_bt[i] -= q;
}
else
{
t += rem_bt[i];
wt[i] = t - bt[i];
rem_bt[i] = 0;
}
}
}
if(done == true)
break;
}
}
int find_avg_time(int process[],int n,int bt[],int q)
{
int wt[n],tat[n],total_wt = 0,total_tat = 0;
waiting_time(process,n,bt,wt,q);
turn_around_time(process,n,bt,wt,tat);
printf(&quot;Process\tBurstTime\tWaitingTime\tTurnAroundTime\n&quot;);
for(int i=0;i&lt;n;i++)
{
total_wt += wt[i];
total_tat += tat[i];
printf(&quot;%d\t\t%d\t\t%d\t\t%d\n&quot;,i+1,bt[i],wt[i],tat[i]);
}
printf(&quot;Average waiting time = %f\n&quot;,(float)total_wt/(float)n);
printf(&quot;Average turn arounf time = %f\n&quot;,(float)total_tat/(float)n);
}
int main(){
int n ,i,q;
printf(&quot;enter no of processes&quot;);
scanf(&quot;%d&quot;,&amp;n);
int bt[n],process[n];
for(int i=0;i&lt;n;i++){
printf(&quot;process=&quot;);
scanf(&quot;%d&quot;,&amp;process[i]);
printf(&quot;burst time:&quot;);
scanf(&quot;%d&quot;,&amp;bt[i]);
}
printf(&quot;quantum=&quot;);
scanf(&quot;%d&quot;,&amp;q);
find_avg_time(process,n,bt,q);
return 0;
}
