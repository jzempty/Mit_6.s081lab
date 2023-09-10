#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argv,char* argc[]){
   if(argv!=2){
      const char *buf = "argc number err,only need one parase";
      write(2, "buf", sizeof(buf));
   }
   sleep(atoi(argc[1]));
   exit(0);
}
