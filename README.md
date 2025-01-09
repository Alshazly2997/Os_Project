# University of Khartoum Faculty of Mathematical Sciences.
Department of Computer Science.

Operating Systems Lab #11: `Creating a new process: Handling Signals`.

# Paricipants
- Ahmed Abdelghani Abdelgalil Hassan 17-303![WhatsApp Image 2025-01-09 at 18 20 14_2a1b4316](https://github.com/user-attachments/assets/8dccc047-1b8b-48b1-ab87-81ca4c2b0085)


- Abdallah Mustafa Yousif Mohammed 16-311 ![WhatsApp Image 2025-01-09 at 18 24 05_d0b7d910](https://github.com/user-attachments/assets/5ed42d00-88d4-4e1d-b59a-e3835538235b)


- Alshazly Mohamed Abdalaziz Yasin  17-305 ![photo_2025-01-08_21-50-33](https://github.com/user-attachments/assets/b888813f-9c9b-4fe7-9bc3-83f52526ffe4)

- Ahmed Obied Eltreifi Obeid 17-308

# Overview
This is a repository containing the solution of lab #11 of the Operating Systems course

Each folder contains the solution of the corresponding letter problem statement alongside with its `README.md` and `MAKEFILE` for both A and C 


# Objectives
- Learn	about	different	ways	to	create	processes	in	Linux.
- Learn	how	to	handle	some	types	of	signals	in	your	program.
- Make	sure	that	you	understand	the	environment		created	
processes

# Problem Statment A
Write a program that uses fork() to create a child process ([template: 
procexec/ex.fork_var_test.c]). 
- After the fork() call, both the parent and child should display 
their PIDs (getpid()). 
- Include code to demonstrate that the child process created by 
fork() can modify its copy of a local variable in main() without 
affecting the value in the parent’s copy of the variable.

# Problem Statment B
Processes have many attributes. When a new process is created using
fork(), which of those attributes are inherited by the child and which are 
not (e.g., are reset to some default)? Here, we explore whether two
process attribute–signal dispositions and alarm timers–are inherited by
a child process.

# Problem Statment C
Write a program ([template: procexec/ex.inherit_alarm.c]) that performs 
the following steps in order to determine if a child process inherits signal 
dispositions and alarm timers from the parent:
- Establishes a SIGALRM handler that prints the process’s PID.
- Starts an alarm timer that expires after two seconds. Do this
using the call alarm(2). When the timer expires, it will notify by
sending a SIGALRM signal to the process.
- Creates a child process using fork().
- After the fork(), the child fetches the disposition of the SIGALRM
signal (sigaction()) and tests whether the sa_handler field in the
returned structure is the address of the signal handler
- Both processes then loop 5 times, sleeping for half a second (use
usleep()) and displaying the process PID. Which of the processes
receives a SIGALRM signal?
