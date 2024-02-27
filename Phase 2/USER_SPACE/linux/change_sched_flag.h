#include <linux/unistd.h>
#include <errno.h>
extern int errno;
_syscall1(void, change_sched_flag, int, flag);