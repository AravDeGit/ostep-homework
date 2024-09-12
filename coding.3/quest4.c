
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

int var = fork();

if (var < 0) {
fprintf(stderr, "fork unsuccessfull");
return 1;
}

else if (var == 0){
char *args[] = { "ls", "-l", NULL };
execvp("ls", args);
printf("Execute command running");
}

else{
printf("This is the parent function");
}

}

/*
We need all these different variants as different exec calls might need varying parameters, some take a single argument, some follow a path, whereas some 
need an environment to be specified.
*/
