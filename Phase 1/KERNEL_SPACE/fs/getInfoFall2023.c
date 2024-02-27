#include <linux/getInfoFall2023.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>
#include <linux/types.h>

asmlinkage int sys_getInfoFall2023(struct structFall2023 *data){
    cli();
    struct structFall2023 param;
    copy_from_user(&param, data, sizeof(struct structFall2023));

    struct task_struct *currentTask;
    currentTask = get_current();

    if(param.flag <= 23 && param.flag > 0){
        param.pid = currentTask->pid;
        param.pid_parent = currentTask->p_opptr->pid;
        param.process_counter = currentTask->counter;
        param.nice = currentTask->nice;
        param.nice_parent = currentTask->p_opptr->nice;
        param.uid = (long)currentTask->uid;
        param.weight = (currentTask->counter) ? currentTask->counter + 20 - currentTask->nice: 0;
        copy_to_user(data, &param, sizeof(struct structFall2023));
        sti();
        return 0;
    }
    else if(param.flag > 23){
        int weight = (currentTask->counter) ? currentTask->counter + 20 - currentTask->nice: 0;
        sti();
        return weight;
    }
    else{
        sti();
        return -1;
    }
}