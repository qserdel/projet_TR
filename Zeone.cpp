#include "camOpen.hpp"
#include "mcc.hpp"
#include "ir.hpp"
#include "pwm.hpp"
#include <pthread.h>
#include <semaphore.h>

static unsigned int n_thread = 3;

int main()
{
    pthread_t id[n_thread+1];
    pthread_create(&id[0], NULL, getDistance, NULL);
    pthread_create(&id[1], NULL, getPos, NULL);
    pthread_create(&id[2], NULL, balayage, NULL);



    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);
    pthread_join(id[2], NULL);


    return 0;
}