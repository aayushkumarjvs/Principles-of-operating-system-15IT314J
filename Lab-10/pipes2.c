#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
void main()
{
int pr1,pr2,pid,fd1[2],fd2[2];
char writemsg2[20] = "Hello there.!!\n";
char writemsg1[20]="Hi.How are you?\n";

char readmsg1[20];
char readmsg2[20];
pr1 = pipe(fd1);
pr2 = pipe(fd2);
if(pr1==1 || pr2==1)
{
printf("Pipe Error");
}
pid = fork();
if(pid>0)
{
close(fd1[0]);
close(fd2[1]);
write(fd1[1],writemsg1,strlen(writemsg1)+1);
read(fd2[0],readmsg2,sizeof(readmsg2));
printf("%s",readmsg2);
close(fd1[1]);
close(fd2[0]);
}  
else
{
close(fd1[1]);
close(fd2[0]);
write(fd2[1],writemsg2,strlen(writemsg2)+1);
read(fd1[0],readmsg1,sizeof(readmsg1));
printf("%s",readmsg1);
close(fd1[0]);
close(fd2[1]);
}
}

