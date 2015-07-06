#include <stdlib.h>
#include <pthread.h>



void *foo(void* a)
{

    pid_t p = fork();
    printf("Fork na watku %d \n",p);

    if (p==0)
    {
        printf("Child process \n");
    }
    else if (p<0)
    {
        printf("Failed fork \n");
    }
    else
    {
        printf("Parent process \n");
    }

return 0;
}


int main(void)
{
    pthread_t t_id;
    pthread_create(&t_id,NULL,foo,NULL);
    pthread_join(t_id,0);

    sleep(2);
return 0;
}
