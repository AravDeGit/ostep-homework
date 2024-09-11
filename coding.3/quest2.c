#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        const char *child_message = "This is the child process writing.\n";
        for (int i = 0; i < 5; i++) {
            write(fd, child_message, sizeof(child_message));
        }
    } else {
        // Parent process
        const char *parent_message = "This is the parent process writing.\n";
        for (int i = 0; i < 5; i++) {
            write(fd, parent_message, sizeof(parent_message));
        }
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
/*
When fork is called both child and parent can inherit the same file descriptor (fd)
It will result in an output that will be in a way intertwined.
*/