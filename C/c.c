#define _XOPEN_SOURCE 700 //To use sigaction struct
#define _DEFAULT_SOURCE //Enable BSD functions
#include <stdio.h>  //Standard I/O functions
#include <signal.h> //To use signals 
#include <unistd.h> //To use fork(), getpid() and getppid() functions, and it's a Linux library 
#include <sys/wait.h> 
 
//Prints the process’s PID that receive SIGALRM signal 
void sigalrm_handler(int sig){ 
    printf("SIGALRM has been Received by Process : %d\n", getpid()); 
} 
 
int main(){ 
    //The way we handle the SIGALRM signal for the parent process 
    struct sigaction sa; 
    sa.sa_handler = &sigalrm_handler; 
    sa.sa_flags = 0; 
    sigaction(SIGALRM , &sa , NULL); 
 
    printf("An alarm for 2 seconds is going to be set \n"); 
    alarm(2); 
     
    int pid = fork(); 
     
    if (pid == 0) { 
        //The way we handle the SIGALRM signal for the child process 
        struct sigaction child_sa; 
        sigaction(SIGALRM, NULL, &child_sa); 
 
       //Testing if the child process inherited a signal 
        if (child_sa.sa_handler == sigalrm_handler) { 
            printf("Child inherited the signal handler from the parent.\n"); 
            printf("The process ID is : %d\n", getpid()); 
 
        } else { 
            printf("Child did not inherit the signal handler from the parent.\n");
            printf("The process ID is : %d\n", getpid());
        }
        //child process loop
        for (int i = 0; i < 5; i++) {
            usleep(500000);
            printf("Child process ID : %d\n", getpid());
    }
    _exit(0); //To terminate the child process 
    } else if (pid > 0){
    //parent process loop 
    for (int i = 0; i < 5; i++) {
            usleep(500000);
            printf("Parent process ID : %d\n", getpid());
    }
    wait(NULL); 
    } else { 
        perror("fork failed"); 
        return 1; 
    }
    printf("Only the parent process receives the SIGALRM signal because the child does not inherit the alarm timer.\n"); 
    return 0; 
}
