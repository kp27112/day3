#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *foo(void* a)
{
    pid_t p = fork();
    printf("Forka na watku %d/n",p);

    if (p==0)
    {
        printf("Child process");
        execvp (a);
    }
    else if (p<0)
    {
        printf("Failed fork");
    }
    else
    {
        printf("Parent process");
    }
return 0;
}

int main(void)
{
    int i = 0;

    pthread_t t_id;
    pthread_create(&t_id,NULL,foo,NULL);
    pthread_join(t_id,0);

    sleep(10);

return 0;
}
