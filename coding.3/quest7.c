#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: Before closing STDOUT\n");
        
        // Close the standard output
        close(STDOUT_FILENO);
        
        // Now try to print something after closing STDOUT
        printf("Child process: After closing STDOUT\n");

        // Flush the output buffer manually to force it to write
        fflush(stdout);
        
        exit(0);
    } else {
        // Parent process
        wait(NULL);  // Wait for the child to terminate
        printf("Parent process: Child terminated\n");
    }

    return 0;
}
/*
NOthing gets printed out
*/
