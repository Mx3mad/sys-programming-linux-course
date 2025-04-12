# Simple Unix Utilities

This repository contains basic implementations of some common **Unix utilities** written in **C**. The utilities implemented include `pwd`, `echo`, `cat`, `cp`, and `mv`, which are standard tools used in Unix-like operating systems.

## Description

The project implements the following Unix utilities:

- **pwd**: Prints the current working directory.
- **echo**: Displays a line of text passed as arguments.
- **cat**: Concatenates and displays file contents.
- **cp**: Copies files from one location to another (not fully implemented).
- **mv**: Moves files from one location to another (not fully implemented).

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

### 1. **pwd**

Run the `pwd` utility to display the current working directory:

```bash
./mypwd
```

**Example Output:**
```
The current working directory is:
/home/mx3mad/Desktop/build_steps/apps
```

---

### 2. **echo**

The `echo` utility prints a string to the terminal. Here’s how to use it:

```bash
./myecho Hello My name is medo, hello world this is linux
```

**Example Output:**
```
Hello My name is medo, hello world this is linux
```

---

### 3. **cat**

The `cat` utility displays the contents of a file. Here's an example using the source code for `myecho`:

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

### 4. **cp** and **mv**

The `cp` and `mv` utilities have not been fully implemented yet. These utilities will allow you to copy and move files from one location to another once completed.

---

## Dependencies

There are no external dependencies required for this project. The utilities are implemented using the **C programming language** and utilize standard libraries.

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for more details.
