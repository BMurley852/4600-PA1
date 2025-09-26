#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{

    // Seed rand based on PID, create random number and delay, return random number
    srand(getpid());

    int random = (rand() % 100)+ 1;

    int delay_timer = (rand() % 401) + 200;

    usleep(delay_timer);

    return random;
}