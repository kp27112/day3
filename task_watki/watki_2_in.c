#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t p = fork();
    printf("Forka na watku %d \n",p);



    if (p==0)
    {
        printf("Child process\n");
        execl("/bin/ls", "ls", NULL);
    }
    else if (p<0)
    {
        printf("Failed fork");
    }
    else
    {
        printf("Parent process\n");
    }


    sleep(10);

return 0;
}
