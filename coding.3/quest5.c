#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int var = fork();

if (var < 0) {
fprintf(stderr , "fork unsuccessfull");
return 1;
}

else if (var == 0){
    int f = wait(NULL);
printf("Child process is running %d\n", f );
}

else{

printf("Parent process is running");
}
}
/*
The wait returns the process id of the process that runs and is not waiting
*/
