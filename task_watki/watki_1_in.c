#include <stdlib.h>
#include <pthread.h>



void *foo(void* a)
{


return 0;
}


int main(void)
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


    sleep(2);
return 0;
}
