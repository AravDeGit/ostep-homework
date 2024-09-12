#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int var = fork();  // Fork a new process

    if (var < 0) {
        // Fork failed
        fprintf(stderr, "Fork unsuccessful\n");
        return 1;
    } else if (var == 0) {
        // Child process
        printf("Child process is running (PID: %d)\n", getpid());
        sleep(2);  // Simulate some work
        exit(0);   // Exit the child process with status 0
    } else {
        // Parent process
        int status;
        pid_t result = waitpid(var, &status, 0);  // Wait for the specific child process

        if (result == -1) {
            // waitpid() failed
            perror("waitpid failed");
            return 1;
        }

        printf("Parent process: Child with PID %d has terminated\n", result);

        // Check how the child process terminated
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child was killed by signal %d\n", WTERMSIG(status));
        }

        printf("Parent process is running\n");
    }

    return 0;
}
