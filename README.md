# Simple Unix Utilities

This repository contains basic implementations of some common **Unix utilities** written in **C**. The utilities implemented include `pwd`, `echo`, `cat`, `cp`, and `mv`, which are standard tools used in Unix-like operating systems.

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
The current working directory is:
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

The `mycp` and `mymv` utilities don't have an output. These utilities just allow you to copy and move files from one location to another.

---

## Dependencies

There are no external dependencies required for this project. The utilities are implemented using the **C programming language** and utilize standard libraries.

