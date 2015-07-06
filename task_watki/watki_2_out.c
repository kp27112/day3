#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void *foo(void* a)
{
    pid_t p = fork();
    printf("Forka na watku %d\n",p);



    if (p==0)
    {
        printf("Child process\n");
        execl("/bin/ls", "ls", NULL);
    }
    else if (p<0)
    {
        printf("Failed fork\n");
    }
    else
    {
        printf("Parent process");
    }
return 0;
}

int main(void)
{
    pthread_t t_id;
    pthread_create(&t_id,NULL,foo,NULL);
    pthread_join(t_id,0);

    sleep(10);

return 0;
}
