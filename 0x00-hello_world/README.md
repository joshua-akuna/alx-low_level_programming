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
