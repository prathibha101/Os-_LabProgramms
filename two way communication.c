/* Two-way Communication Using Pipes*/
#include<stdio.h>
#include<unistd.h>
int main()
{
int pipefds1[2], pipefds2[2];
int returnstatus1, returnstatus2;
int pid;
char pipe1writemessage[20] = {&quot;Gunjari &quot;};
char pipe2writemessage[20] = {&quot;Sneha&quot;};
char readmessage[20];
returnstatus1 = pipe(pipefds1);
if (returnstatus1 == -1)
{
    printf(&quot;Unable to create the pipe 1&quot;);
    return 1;
}
returnstatus2 = pipe(pipefds2);
if (returnstatus2 == -1)
{
    printf(&quot;Unable to create the pipe 2 &quot;);
    return 1;
}
pid = fork();
if (pid != 0) // Parent process
{
    close(pipefds1[0]); // Close the unwanted pipe1 read side
    close(pipefds2[1]); // Close the unwanted pipe2 write side
    printf(&quot;In Parent: Writing to pipe 1 – Message is----- %s\n&quot;,pipe1writemessage);
    write(pipefds1[1], pipe1writemessage,sizeof(pipe1writemessage));
    read(pipefds2[0], readmessage, sizeof(readmessage));
    printf(&quot;In Parent: Reading from pipe 2 – Message is ---- %s\n&quot;,readmessage);
}
else
{ //child process
    close(pipefds1[1]); // Close the unwanted pipe1 write side
    close(pipefds2[0]); // Close the unwanted pipe2 read side
    read(pipefds1[0], readmessage, sizeof(readmessage));
    printf(&quot;In Child: Reading from pipe 1 – Message is ---- %s\n&quot;,readmessage);
    printf(&quot;In Child: Writing to pipe 2 – Message is--- %s\n&quot;,pipe2writemessage);
    write(pipefds2[1], pipe2writemessage,sizeof(pipe2writemessage));
}
    return 0;
   
}
