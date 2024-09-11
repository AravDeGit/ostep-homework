#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
int call = fork();
if (call < 0)
{
fprintf(stderr, "Fork unsuccessful\n");
return 1;
}
else if (call == 0)
{
printf("hello\n");
}
else
{
sleep(1);
printf("goodbye\n");
}
}
/*
We can put a sleep call in the parent process
*/
