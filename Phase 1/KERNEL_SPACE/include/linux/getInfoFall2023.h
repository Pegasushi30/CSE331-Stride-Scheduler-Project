#ifndef __LINUX_GETINFOFALL2023_H
#define __LINUX_GETINFOFALL2023_H
#include <linux/linkage.h>
#include <linux/types.h>
int getInfoFall2023(struct structFall2023 *data);
struct structFall2023 {
int flag; /* flag for option */
pid_t pid; /* process id */
pid_t pid_parent; /* process id of parent process */
long process_counter; /* counter value of the process */
long nice; /* nice value of the process */
long nice_parent; /* nice value of parent process’s owner */
long uid; /* user id of process owner */
long weight; /* weight is 0 if counter is 0, otherwise; value calculated with counter+20-nice */
};
#endif