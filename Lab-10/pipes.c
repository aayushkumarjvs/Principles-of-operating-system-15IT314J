#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
void main()
{
int pr,pid,fd[2]={NULL,NULL};
char writemsg[20] = "Hello";
char readmsg[20];
pr = pipe(fd);
if(pr==1)
{
printf("Pipe Error");
}
pid = fork();
if(pid==0)
{
close(fd[1]);
read(fd[0],readmsg,sizeof(readmsg));
printf("%s",readmsg);
close(fd[0]);
}
}

