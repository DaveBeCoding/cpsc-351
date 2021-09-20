#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
    {
    pid_t  pid;/* fork another process */

    pid = fork();

    if (pid < 0) {

        /* error occurred */
        fprintf(stderr, "Fork Failed");

        exit(-1);

        }
    else if (pid == 0)
        { /* child process */

        execlp("/bin/ls", "ls", NULL);

        }

    else
        { /* parent process *//* parent will wait for the child to complete test*/

        wait(NULL);

        printf("\n Child Complete \n");

        exit(0);

        }
    }





/*
idea code? resembles above idea.

if (pid == 0) {
    // child
    pid = fork();
    if (pid == 0) {
        // grandchild (of top-level parent)
        }
    else {
        // parent of the grandchild
        }
    }
else {
    // parent
    }

*/