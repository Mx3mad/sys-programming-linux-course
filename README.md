# Simple Unix Utilities and Shells

This repository contains basic implementations of some common **Unix utilities** written in **C**. The utilities implemented include `pwd`, `echo`, `cat`, `cp`, and `mv`, which are standard tools used in Unix-like operating systems. Additionally, various custom shells have been implemented.

## Description

The project implements the following Unix utilities:

- **mypwd**: Prints the current working directory.
- **myecho**: Reprints the line of text passed as an argument.
- **mycat**: Prints the contents of file passed as an argument.
- **mycp**: Copies the contents of a file into another (basic implementation).
- **mymv**: Moves files from one location to another / rename a file (basic implementation).

These utilities provide an essential introduction to working with Unix-like systems and how to mimic simple Unix tools using basic system calls and standard libraries in C.

## Compilation Command

The project is compiled using the GCC (GNU Compiler Collection). The following command compiles all the utilities:

```bash
gcc -o mypwd mypwd.c
gcc -o myecho myecho.c
gcc -o mycat mycat.c
gcc -o mycp mycp.c
gcc -o mymv mymv.c
```

You can compile each utility separately by using the corresponding source file and command.

## Example Usage and Output

### 1. **mypwd**

Run the `mypwd` utility to display the current working directory:

```bash
./mypwd
```

**Example Output:**
```
/home/mx3mad/Desktop/build_steps/apps
```

---

### 2. **myecho**

The `myecho` utility prints a string to the terminal. Here’s how to use it:

```bash
./myecho Hello My name is medo, hello world this is linux
```

**Example Output:**
```
Hello My name is medo, hello world this is linux
```

---

### 3. **mycat**

The `mycat` utility displays the contents of a file. Here's an example using the source code for `myecho`:

```bash
./mycat myecho.c
```

**Example Output:**
```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s [The text to be echoed]\n\tThere is Nothing to be echoed\n", argv[0]);
        exit(-1);
    }
    char** p;
    for(p = argv+1; *p != NULL; p++)
    {
        printf("%s", *p);
        if(*(p+1) != NULL) printf(" ");
    }
    printf("\n");
    return 0;
}
```

---

### 4. **mycp** and **mymv**

The `mycp` and `mymv` utilities don't have an output on success. These utilities just allow you to copy and move files from one location to another.

---

## Custom Shell Implementations

## Compilation Command

They are compiled using the GCC (GNU Compiler Collection). The following command compiles all the shells:

```bash
gcc -o femto femto_shell.c
gcc -o pico pico_shell.c
gcc -o nano nano_shell.c
gcc -o micro micro_shell.c
```

The project includes the following custom shell programs, providing an introduction to shell programming concepts:

### 1. **Femto Shell**
- **File**: [`femto_shell.c`](https://github.com/Mx3mad/sys-programming-linux-course/blob/main/femto_shell.c)
- **Description**: A simple shell that supports basic commands like `echo` and `exit`. It provides a minimal interactive command-line interface.
- **Usage**:
  ```bash
  ./femto
  FemtoSha > echo Hello World
  Hello World
  ```

### 2. **Pico Shell**
- **File**: [`pico_shell.c`](https://github.com/Mx3mad/sys-programming-linux-course/blob/main/pico_shell.c)
- **Description**: A shell that supports additional built-in commands like `pwd`, and `cd`, along with UNIX commands execution by forking processes.
- **Usage**:
  ```bash
  ./pico
  PicoSha >> pwd
  /home/user
  PicoSha >> cd /tmp
  ```

### 3. **Nano Shell**
- **File**: [`nano_shell.c`](https://github.com/Mx3mad/sys-programming-linux-course/blob/main/nano_shell.c)
- **Description**: Expands functionality with support for local and environment variables manipulation.
- **Usage**:
  ```bash
  ./nano
  NanoSha >> x=5
  NanoSha >> echo $x
  ```

### 4. **Micro Shell**
- **File**: [`micro_shell.c`](https://github.com/Mx3mad/sys-programming-linux-course/blob/main/micro_shell.c)
- **Description**: A more advanced shell that includes input/output redirection.
- **Usage**:
  ```bash
  ./micro
  MicroSha >> ls > output.txt
  MicroSha >> echo Hello
  MicroSha >> cat < /tmp/input_iored.txt
  MicroSha >> echo World!
  ```

---

## Dependencies

This project does not require external dependencies. The utilities are implemented using the C programming language and utilize standard libraries.

