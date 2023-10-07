# 0x00. C - Hello, World

## Concepts
For this project, we expect you to look at the concept:
* [Everything you need to know to start with C.pdf]()

## Resources
### Read or watch:
* [0x00. C - Hello, World]()
* [Everything you need to know to start with C.pdf]() (You do not have to learn everything in there yet, but make sure you read it entirely first)
* [Dennis Ritchie]()
* ["C" Programming Language: Brian Kernighan]()
* [Why C Programming is Awesome]()
* [Learning to program in C part 1]()
* [Learning to program in C part 2]()
* [Understanding C program Compilation process]()
* [Betty Coding Style]()
* [Hash-bang under the hood]() (Look at only after you finish consuming the other resources)
* [Linus Torvalds on C vs C++]() (Look at only after you finish consuming the other resources)

### man or help
* gcc
* printf (3)
* puts
* putchar

## General
* Why C programming is awesome
* Who invented C
* Who are Dennis Ritchie, Brian Kernighan and Linus Torvalds
* What happens when you type *gcc main.c*
* What is an entry point
* What is *main*
* How to print text using *printf*, *puts* and *putchar*
* How to get the size of a specific type using the unary operator *sizeof*
* How to compile using *gcc*
* What is the default program name when compiling with *gcc*
* What is the official C coding style and how to check your code with *betty-style*
* How to find the right header to include in your source code when using a standard library function
* How does the *main* function influence the return value of the program

## More Info
### Betty Linter
To run the Betty linter just with the command *betty <filename>*
* Go to the [Betty]() repository
* Clone the [repo]() to your machine
* *cd* into the Betty directory
* Install the linter with *sudo ./install.sh*
* *emacs* or *vi* a new file called *betty*, and copy the script below:

```
#!/bin/bash
# Simply a wrapper script to keep you from having to use betty-style
# and betty doc separately on every item
# Originally by Tim Britton (@wintermanc3r), multiargument added by
# Larry Madeo (@hillmonkey)

BIN_PATH="/usr/local/bin"
BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"

if [ "$#" = 0 ]; then
    echo "No argument passed."
    exit 1
fi

for arguments in "$@"; do
    echo -e "\n========== $argument ========="
    ${BIN_PATH}/${BETTY_STYLE} "$argument"
    ${BIN_PATH}/${BETTY_DOC} "$argument"
done
```

* Once saved, exit the file and change permissions to apply to all users with *chmod a+x betty*
* Move the *betty* file into */bin/* directory or somewhere else in your *$PATH* with *sudo mv betty /bin/*

You can now type *betty <filename>* to run the betty linter!

## Tasks
### 0. Preprocessing
Write a script that runs a C file through the preprocessor and save the result into the another file,
* The C file name will be saved in the variable *$CFILE*
* The output should be saved in the file *C*

```

```

File: [0-preprocessor]()

### 1. Compiler
Write a script that compiles a C file but does not link.
* The C file name will be saved in the variable $CFILE
* The output file should be named the same as the C file, but with the extension *.o* instead of *.c*.
    * Example: if the C file is *main.c*, the output file should be *main.o*

```

```

File: [1-compiler]()

### 2. Assembler
Write a script that generates the assembly code of a C code and save it in an outpuf file
* The C file name will be saved in the variable $CFILE
* The output file should be named the same as the C file, but with the extension *.s* instead of *.c*.
    * Example: if the C file is *main.c*, the output file should be *main.s*

```

```

File: [2-assembler]()

### 3. Name
Write a script that compiles a C file and creates an executable named *cisfun*
* The C file name will be saved in the variable *$CFILE*

```

```

File: [3-name]()

### 4. Hello, puts
Write a C program that prints exactly *"Programming is like building a multilingual puzzle"*, followed by a new line
* Use the function *puts*
* You are not allowed to use *printf*
* Your program should end with the value *0*

```

```

File: [4-puts.c]()

### 5. Hello, printf
Write a C program that prints exactly *"with proper grammar, but the outcome is a piece of art"*, followed by a new line
* Use the function *printf*
* You are not allowed to use the function *puts*
* Your program should return *0*
* Your program should compile without warning when using the *-Wall gcc* option

```

```

File: [5-printf.c]()

### 6. Size is not grandeur, and territory does not make a nation
Write a C program that prints the size of various types on the computer it is compiled and run on
* You should produce the exact same output as in the example
* Warnings are allowed\
* Your program should return *0*
* You might have to install the package *libc6-dev-i386* on your Linux to test the *-m32 gcc* option

```

```

File: [6-size.c]()

### 7. Intel
Write a script that generates the assembly code (Intel syntax) of a C code and save it in an outpuf file
* The C file name will be saved in the variable $CFILE
* The output file should be named the same as the C file, but with the extension *.s* instead of *.c*.
    * Example: if the C file is *main.c*, the output file should be *main.s*

```

```

File: [100-intel]()

### 8. UNIX is basically a simple operating system, but you have to be a genius to understande the simplicity
Write a C program the prints exactly *and that piece of art is useful" - Dora Korpar, 2015-10-19*, followed by a new line, to the standard error
* You are not allowed to use any functions listed in the NAME section of the man (3) *printf* and man (3) *puts*
* Your program should return 1
* Your program should compile without any warnings when using the *-Wall gcc* option

```

```

File: [101-quote.c]()
