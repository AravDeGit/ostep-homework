#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc)
{
    int x = 100;  // Initialize x to 100

    printf("Before fork, x = %d\n", x);

    pid_t pid = fork();  // Fork the process

    if (pid < 0) {
        // If fork fails
       	fprintf(stderr, "fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process before changing x, x = %d\n", x);
        x = 200;  // Change x in child
        printf("Child process after changing x, x = %d\n", x);
    } else {
        // Parent process
        printf("Parent process before changing x, x = %d\n", x);
        x = 300; 
        printf("Parent process after changing x, x = %d\n", x);
    }

    // This will be printed by both the child and parent process
    printf("Final x in process, x = %d\n", x);

    return 0;
}
/*
Question 1:
The value is 100 (the original value)
The parent process is run first and then the child process is run but the changes mad ein the parent process is not reflected
when the child process is run.
*/
