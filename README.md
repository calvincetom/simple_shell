# __0x16. C - Simple Shell__

## Collaborative project between Aly Mtsumi and Calvince Tom on writing a simple UNIX command interpreter

 The repository includes a number of files that will be compiled together using __gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh__.

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General

- Who designed and implemented the original Unix operating system.
- Who wrote the first version of the [UNIX Shell](https://en.wikipedia.org/wiki/Unix_shell)
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Copyright - Plagiarism

- You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
- You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
- You are not allowed to publish any content of this project.
- Any form of plagiarism is strictly forbidden and will result in removal from the program.

## Requirements

<General

- Allowed editors: vi, vim, emacs

- All your files will be compiled on Ubuntu 20.04 LTS using __gcc__, using the options __-Wall -Werror -Wextra -pedantic -std=gnu89__.
- All your files should end with a new line.
- A README.md file, at the root of the folder of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
- Your shell should not have any memory leaks.
- No more than 5 functions per file.
- All your header files should be include guarded.
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## GitHub

*There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.*

## More Info

### Output

- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.

- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below).

### Example of error with sh

```text
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
```

### Same error with your program hsh

```text
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## List of allowed functions and system calls

- [access](https://manpages.org/access/2)
- [chdir](https://manpages.org/chdir/2)
- [close](https://manpages.org/close/2)
- [closedir](https://manpages.org/closedir/3)
- [execve](https://manpages.org/execve/2)
- [exit](https://manpages.org/exit/3)
- [_exit](https://manpages.org/_exit/2)
- [fflush](https://manpages.org/fflush/2)
- [fork](https://manpages.org/fork/2)
- [free](https://manpages.org/free/3)
- [getcwd](https://manpages.org/getcwd/3)
- [getline](https://manpages.org/getline/3)
- [getpid](https://manpages.org/getpid/2)
- [isatty](https://manpages.org/isatty/2)
- [kill](https://manpages.org/kill/2)
- [malloc](https://manpages.org/malloc/3)
- [open](https://manpages.org/open/2)
- [opendir](https://manpages.org/opendir/3)
- [perror](https://manpages.org/perror/3)
- [read](https://manpages.org/read/2)
- [readdir](https://manpages.org/readdir/3)
- [signal](https://manpages.org/signal/2)
- [stat](https://manpages.org/stat/2)
- [lstat](https://manpages.org/lstat/2)
- [fstat](https://manpages.org/fstat/2)
- [strtok](https://manpages.org/strtok/3)
- [wait](https://manpages.org/wait/2)
- [waitpid](https://manpages.org/waitpid/2)
- [wait3](https://manpages.org/wait3/2)
- [wait4](https://manpages.org/wait4/2)
- [write](https://manpages.org/write/2)

## Compilation

- Your shell will be compiled this way:
  
```text
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

### Your shell should work like this in interactive mode

```text
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
```

### But also in non-interactive mode

```text
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Checks

- The Checker will be released at the end of the project (1-2 days before the deadline).

- We strongly encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task 8. Test suite.
