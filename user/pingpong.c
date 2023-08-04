#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int 
main(int argc,char* argv[]){
   int fd1[2],fd2[2];
   pipe(fd1);
   pipe(fd2);
   int pid = fork();
   if(pid==0){
      char rbuf[100];
      read(fd2[0], rbuf, 100);
      printf("%d: %s\n",getpid(),rbuf);

      char *sbuf = "received pong";
      write(fd1[1], sbuf, strlen(sbuf));
      exit(1);
   }
   else
   {
      char *sbuf = "received ping";
      write(fd2[1], sbuf,strlen(sbuf));
      wait((int*)0);

      char buf[100];
      read(fd1[0], buf, 100);
      printf("%d: %s\n",getpid(),buf);
      exit(0);
   }
   exit(0);
}