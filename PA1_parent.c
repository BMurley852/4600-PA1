#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUMBER_CHILDREN 100


// Create child
pid_t create_child()
{
    pid_t pid = fork();

    if (pid < 0 )
    {
        // Fork failed
        printf("Fork failed, exiting..\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Child

        if (execve("./PA1_child", NULL, NULL) == -1)
        {
            printf("Execve error");
            exit(EXIT_FAILURE);
        }


    }

    return pid;
}

int main()
{
    pid_t children[NUMBER_CHILDREN];
    int sum = 0, children_created = 0, children_terminated = 0;

    for (int i=0; i< NUMBER_CHILDREN; i++)
    {
        pid_t child_pid = create_child();
        children[i] = child_pid;
        children_created++;
    }    
    while(children_terminated < NUMBER_CHILDREN)
    {
        int status;
        pid_t exit_status = wait(&status);

        if (exit_status == -1)
        {
            break;
        }

        if (WIFEXITED(status))
        {
            int rand_value = WEXITSTATUS(status);
            sum += rand_value;
            children_terminated++;
        }

    }
    

    printf("\n\nChildren created: %d\n", children_created);
    printf("Children successfully terminated: %d\n", children_terminated);
    printf("Sum of numbers returned by children: %d\n", sum);
}