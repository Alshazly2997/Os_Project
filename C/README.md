# Signal and Process Handling Program Documentation

## Program Overview
This program demonstrates the behavior of signal handlers and alarm timers in a parent-child process relationship under Linux. It specifically showcases how the SIGALRM signal handler is inherited by child processes while the alarm timer is not. The program creates a parent process that sets an alarm and spawns a child process, with both processes executing concurrent loops while displaying their respective Process IDs (PIDs).

## Header Files
```c
#define _XOPEN_SOURCE 700    // Enable POSIX.1-2008 features
#define _DEFAULT_SOURCE      // Enable BSD functions
#include <stdio.h>          // Standard I/O functions
#include <signal.h>         // Signal handling functions
#include <unistd.h>         // POSIX operating system API
#include <sys/wait.h>       // Process control functions
```

### Header File Purposes:
- `stdio.h`: Provides standard input/output operations
- `signal.h`: Enables signal handling functionality
- `unistd.h`: Provides access to POSIX operating system API
- `sys/wait.h`: Contains process control and wait functions

## Main Function Variables

### Signal Handling Structures
```c
struct sigaction sa;              // Parent process signal handler
struct sigaction child_sa;        // Child process signal handler verification
```

### Process Management Variables
```c
int pid;                         // Stores process ID after fork()
```

### Loop Control Variables
```c
int i;                          // Loop counter for both processes
```

## Process Creation and Control Flow

### 1. Signal Handler Setup
```c
void sigalrm_handler(int sig) {
    printf("SIGALRM has been Received by Process : %d\n", getpid());
}
```
- Purpose: Handles SIGALRM signals
- Functionality: Prints the PID of the process receiving the signal

### 2. Parent Process Initialization
```c
sa.sa_handler = &sigalrm_handler;
sa.sa_flags = 0;
sigaction(SIGALRM, &sa, NULL);
alarm(2);                        // Set 2-second alarm
```

### 3. Process Creation
```c
pid = fork();
```
Process branching:
- pid == 0: Child process
- pid > 0: Parent process
- pid < 0: Fork failure

### 4. Child Process Flow
1. Verifies signal handler inheritance
2. Executes 5 iterations with 0.5-second delays
3. Terminates using _exit(0)

### 5. Parent Process Flow
1. Executes 5 iterations with 0.5-second delays
2. Waits for child process completion
3. Prints final message about SIGALRM behavior

## Memory Management

### Resource Allocation
- No explicit dynamic memory allocation
- System resources managed by fork()
- Process cleanup handled by _exit() and wait()

### Cleanup Procedures
1. Child Process:
   - Uses _exit(0) to prevent multiple cleanup calls
   - Ensures clean termination of child process

2. Parent Process:
   - Uses wait(NULL) to prevent zombie processes
   - Ensures proper cleanup of child process resources

## Limitations and Considerations

### 1. Timing Considerations
- Alarm timer set to 2 seconds
- Process loops use 0.5-second delays
- Potential timing variations on loaded systems

### 2. Resource Limitations
- System process limits
- Memory availability for fork()
- Signal queue limitations

### 3. Platform Dependencies
- Linux-specific implementation
- POSIX compliance requirements
- System-specific behavior variations

### Error Conditions
```bash
# Check for process errors
echo $?

# Monitor process status
ps -ef | grep c_program
```

## Troubleshooting

### Common Issues
1. Fork Failure
   - Check system resources
   - Verify process limits
   - Monitor system load

2. Signal Handling Issues
   - Verify signal handler installation
   - Check for signal blocking
   - Monitor signal delivery

3. Process Synchronization
   - Verify wait() behavior
   - Check process termination
   - Monitor process states

### System Requirements
- Linux operating system
- GCC compiler
- Sufficient system resources
- Appropriate user permissions


## Compilation and Execution

### Compilation
```bash
# Basic compilation
gcc -o c_program c.c

# With warnings enabled
gcc -Wall -o c_program c.c

# With debugging information
gcc -g -o c_program c.c
```

### Execution
```bash
# Run the program
./signal_program

# Expected Output
# Note: the actual PIDs may vary with each execution.
An alarm for 2 seconds is going to be set
Child inherited the signal handler from the parent.
The process ID is: [PID]
Child process ID: [PID]
Parent process ID: [PID]
[Additional output...]
SIGALRM has been Received by Process: [PID]
```


