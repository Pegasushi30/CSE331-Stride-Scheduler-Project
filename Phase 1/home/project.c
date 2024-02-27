#include <stdio.h>
#include <linux/getInfoFall2023.h>

int main(){
    struct structFall2023 mystruct;

    mystruct.flag = 10;

    int returnVal = getInfoFall2023(&mystruct);

    if(returnVal == 0){
        printf("flag: %d\npid: %d\npidparent: %d\ncounter: %d\nnice: %d\nnice parent: %d\nuid: %d\nweight: %d\n",
            mystruct.flag,mystruct.pid,mystruct.pid_parent,mystruct.process_counter,
            mystruct.nice,mystruct.nice_parent,mystruct.uid,mystruct.weight);
    }
    else if(returnVal == -1){
        printf("Invalid flag value\n");
    }
    else{
        printf("Weight: %d\n", returnVal);
    }
}