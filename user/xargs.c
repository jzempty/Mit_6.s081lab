#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int 
main(int argc,char* argv[]){
   int end=0;
   char buf[514];
   
 //  printf("M%sM\n", argv[1]);

   char **ar = malloc((argc + 2) * sizeof(char *));
   for (int i = 0; i < argc;i++){
      ar[i] = argv[i];
   }
   ar[argc + 1] = 0;
      while (1)
      {
         char c;
         if (0 == read(0, &c, sizeof(c)))
            break;
         buf[end++] = c;
         if (c == '\n')
         {
            buf[end - 1] = '\0';
          int pid = fork();
            ar[argc] = buf;
            
            if (pid == 0)
            {
               exec(ar[1], &ar[1]);
            }
            else
            {
               wait((int *)0);
               end = 0;
            }
         }
      }
   exit(0);
}




// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// #include "kernel/fs.h"

// int main(int argc, char *argv[])
// {
//   // printf("M%sM\n", argv[1]);
//   // fprintf(2, "argc: %d", argc);
//   char buf[512];
//   int from = 0;
//   int to = 0;
//   char **argv2 = malloc((argc + 1) * sizeof(char *));
//   for (int i = 0; i < argc - 1; ++i)
//   {
//     argv2[i] = argv[i + 1];
//   }
//   argv2[argc] = 0;
//   while (1)
//   {
//     char c;
//     if (0 == read(0, &c, sizeof(char)))
//       break;
//     buf[to++] = c;
//     // fprintf(2, "%c\n", c);
//     if ('\n' == c)
//     {
//       buf[to - 1] = '\0';
//       argv2[argc - 1] = buf + from;
//       int pid = fork();
//       if (pid == 0)
//       {
//           for (int i = 0; i <=argc; i++)
//                {
//                   printf("%s\t", argv2[i]);
//                }
//                printf("end\n");

//         exec(argv2[0], argv2);
//       }
//       else
//       {
//         int st;
//         wait(&st);
//       }
//       from = to;
//     }
//   }
//   exit(0);
// }





// grep    hello   ./zombie        (null)  end
// find:30 ./a b
// grep    hello   ./a/b   (null)  end
// find:30 ./c b
// hello
// grep    hello   ./c/b   (null)  end
// hello
// grep    hello   ./b     (null)  end
// hello



// grep    hello   ./zombie        (null)  end
// find:30 ./a b
// grep    hello   ./a/b   find:30 ./c b
// (null)  end
// hello
// grep    hello   ./c/b   (null)  end
// hello
// grep    hello   ./b     (null)  end
// hello
// $ $ 