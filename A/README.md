# Process Fork Program Documentation

## Program Overview
This C program shows how to use Linux's `fork()` system call to create and manage parent and child processes. It demonstrates memory independence between parent and child processes, process IDs, and process creation.
## Header Files
```c
#include <stdio.h>
#include <unistd.h>
```
- `stdio.h`: Standard input/output library for functions like `printf()`
- `unistd.h`: POSIX operating system API that provides access to:
  - `fork()`: Process creation
  - `getpid()`: Get current process ID
  - `getppid()`: Get parent process ID
  - `sleep()`: Process suspension

## Main Function Variables
```c
int fork_value = fork();
int N;
int sleep_time = 5;
```
- `fork_value`: Stores the return value of `fork()`
- `N`: Demonstrates memory independence between processes
- `sleep_time`: Duration (in seconds) for parent process sleep

## Process Creation and Control Flow

### Fork System Call
```c
int fork_value = fork();
```
The `fork()` function creates a new process by duplicating the calling process. It returns:
- `-1`: Fork failed (error condition)
- `0`: In the newly created child process
- Positive integer: In the parent process (value is child's PID)

### Error Handling
```c
if (fork_value == -1) {
    printf("ERROR!");
}
```
Checks for fork failure and prints error message if fork unsuccessful.

### Child Process Block
```c
else if (fork_value == 0) {
    printf("The child process ID is: %d, and it's parent ID is: %d\n", 
           getpid(), getppid());
    N = 100;
    printf("The value of N in child's copy is %d\n", N);
}
```
- Executes in child process
- Gets and prints:
  - Own process ID using `getpid()`
  - Parent's process ID using `getppid()`
- Sets local variable `N` to 100
- Demonstrates independent memory space

### Parent Process Block
```c
else {
    sleep(sleep_time);
    printf("The parent process ID is %d\n", getpid());
    N = 200;
    printf("The value of N in parent's copy is %d\n", N);
}
```
- Executes in parent process
- Sleeps for 5 seconds to allow child process to complete
- Prints own process ID
- Sets local variable `N` to 200
- Demonstrates separate memory space from child

## Memory Management
- After fork, child gets copy of parent's:
  - Data segment
  - Stack
  - Heap
- Variable `N` demonstrates memory independence:
  - Child sets N = 100
  - Parent sets N = 200
  - Changes don't affect each other's copy

## Program Output
Program produces output similar to:
```
The child process ID is: 1234, and it's parent ID is: 1233
The value of N in child's copy is 100
The parent process ID is 1233
The value of N in parent's copy is 200
```
Note: Actual PIDs will vary with each execution.

## Limitations and Considerations
1. **Process Synchronization**
   - Uses simple `sleep()` for synchronization
   - Not suitable for production use
   - Should use proper synchronization mechanisms

2. **Error Handling**
   - Basic error checking for fork failure
   - Production code should include more robust error handling

3. **Resource Management**
   - No cleanup of child processes
   - Should implement `wait()` or `waitpid()` in production
   - No resource limit checking

4. **Memory Usage**
   - Creates complete copy of parent process
   - May be inefficient for large programs
   - Modern systems use copy-on-write optimization

## Compilation and Execution
```bash
gcc -o project_a_program a.c
./project_a_program
```
Note: Must be compiled and run on a UNIX-like system (Linux, macOS, etc.) as `unistd.h` is POSIX-specific.

