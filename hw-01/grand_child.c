/*
    CPSC-351, Homework 01
*/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
    {

    pid_t  pid01, pid02;

	pid01 = fork();

    pid02 = fork();
    
    if (pid01 < 0) {
        
    /* error occurred */
    fprintf(stderr, "Fork Failed");

    exit(-1);
        }

    else if (pid01 > 0 && pid02 > 0) {
        printf("parent\n");
		printf("%d %d \n", pid01, pid02);
		printf(" my id is %d \n", getpid());
	}
	else if (pid01 == 0 && pid02 > 0)
	{
		printf("First child\n");
		printf("%d %d \n", pid01, pid02);
		printf("my id is %d \n", getpid());
	}
	else if (pid01 > 0 && pid02 == 0)
        {

        printf("grandchild\n");
		printf("%d %d \n", pid01, pid02);
		printf("my id is %d \n", getpid());
        execlp("/usr/bin/firefox", "firefox", NULL);
        }
    
    }


/*
idea code?

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