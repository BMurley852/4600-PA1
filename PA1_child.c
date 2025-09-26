#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
    srand(getpid());

    int random = (rand() % 100)+ 1;

    int delay_timer = (rand() % 401) + 200;

    usleep(delay_timer);

    return random;
}