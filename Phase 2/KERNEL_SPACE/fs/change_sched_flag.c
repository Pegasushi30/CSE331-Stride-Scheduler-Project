#include <linux/change_sched_flag.h>
#include <linux/sched.h>
asmlinkage void sys_change_sched_flag(int flag){
    sched_flag = flag;
}