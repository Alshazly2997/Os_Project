#include <stdio.h> 
#include <unistd.h> //To use fork(), getpid() and getppid() functions, and it's a Linux library 
 
 
int main(){ 
 
    /*after call fork() function a child procrss will born and will have it's own copy for data, stack, heap, and the  
    code will execute separatly*/ 
    int fork_value = fork(); // fork() will return -1 for errors, 0 for new process and the PID of the new process to the old process 
    int N; 
    int sleep_time = 5; // number of seconds to sleep 
 
    if (fork_value == -1) { 
        printf("ERROR!"); 
    } else if (fork_value == 0) { 
        printf("The child process ID is: %d, and it's parent ID is: %d\n", getpid(), getppid()); /*gitpid() return the  
        process ID and gitppid() return the parent ID*/ 
 
        N = 100; 
        /* to demonstrate that the child process can modify its copy of a local variable in main() without  
        affecting the value in the parent’s copy of the variable. */ 
        printf("The value of N in child's copy is %d\n", N); 
 
    } else { 
        sleep(sleep_time); //to delay the execution of the perant unitl the child finished. 
        printf ("The parent process ID is %d\n", getpid()); 
 
        N = 200;  
        printf("The value of N in parent's copy is %d\n", N); 
    } 
     
     
    return 0; 
}
