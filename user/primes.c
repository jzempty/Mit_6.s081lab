#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int isprem(int n)
{
   for (int i = 2; i < n; i++)
   {
      if (n % i == 0)
         return 0;
   }
   return 1;
}

int main()
{
   int leftpipe[2], rightpipe[2];

   if (pipe(leftpipe) == -1 || pipe(rightpipe) == -1)
   {
      exit(-1);
   }
   

   int pid = fork();

   if (pid == 0)
   {
      close(leftpipe[1]);
      while (1)
      {
         int n;
         if(0== read(leftpipe[0], &n, sizeof(n)))         {
            break;
         }
         if (isprem(n) == 1)
         {
            write(rightpipe[1], &n, sizeof(n));
         }
      }
      close(leftpipe[0]);
      close(rightpipe[1]);
      exit(0);
   }
   else
   {
      for (int i = 1; i <= 35; i++)
      {
         write(leftpipe[1], &i, sizeof(i));
      }
      close(leftpipe[1]);

      wait((int *)0);
      close(rightpipe[1]);
      while (1)
      {
         int n;
         if (0 == read(rightpipe[0], &n, sizeof(n)))
         {
            break;
         }
         printf("prime %d \n", n);
      }
   }
   exit(0);
}