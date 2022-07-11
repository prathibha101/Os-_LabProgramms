#include<stdio.h>
int main()
{
int i,j;
int pass,f,wt[10],bt[10],n,twt,tat[10],ttat,temp;
float avgwt,avgtat;
printf(&quot;Enter the No.of Processors : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the Brust Time : \n&quot;);
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;bt[i]);
}
for(pass = 0;pass &lt; n-1;pass++)
{
f=0;
for(j=0;j&lt;n-pass-1;j++)
{
if(bt[j]&gt;bt[j+1])
{
temp=bt[j];
bt[j] = bt[j+1];
bt[j+1] = temp;
f=1;
}
}
if(f==0)
break;
}
printf(&quot;Sorted Brust Times are \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;%d\n&quot;,bt[i]);
}
wt[0] = 0;
for(i=1;i&lt;n;i++)
{
wt[i] = bt[i-1]+wt[i-1];
twt+=wt[i];
}
printf(&quot;Waiting time for the processor : \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;%d\n&quot;,wt[i]);
}
for(i=0;i&lt;n;i++)
{
tat[i] = wt[i]+bt[i];
ttat+=tat[i];
}
printf(&quot;Turn Around time \n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;%d\n&quot;,tat[i]);
}
printf(&quot;Average waiting time :%f\n&quot; ,twt/(float)n);
printf(&quot;Averaget turn around time :%f\n&quot;,ttat/(float)n);
return 0;
