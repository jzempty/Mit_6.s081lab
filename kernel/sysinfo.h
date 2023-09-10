#include "types.h"
struct sysinfo{
   uint64 freemem;//this field shows he number of bytes of free memory,
   uint nproc;//be set to the number of processes whose state is not UNUSED
};