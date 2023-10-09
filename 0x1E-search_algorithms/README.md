# 0x1E. C - Search Algorithms

## Resources
### Read or watch:
* [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)
* [](https://www.geeksforgeeks.org/g-fact-86/)

## Learning Objectives
At the end of this project, you are expected to be able to [explain to anyone](https://fs.blog/feynman-learning-technique/) **without the help of Googele:**

### General
* What is a search algorithm
* What is a linear search
* What is a binary search
* What is the best search algorithm to use depending on the needs

## More Info
You will be asked to write files containing big O notations. Please use this format:
* O(1)
* O(n)
* O(n!)
* n * m->O(n!)
* n square->O(n^2)
* sqrt n->O(sqrt(n))
* log(n)->O(log(n))
* n * log(n)-> O(nlog(n))
* ...

## Tasks
### 0.Linear search
Write a function that searches for a value in an array of integers using the [Linear search algorithm](https://en.wikipedia.org/wiki/Linear_search)
* Prototype: *int linear_search(int *array, size_t size, int value)*
* Where *array* is a pointer to the first element of the array to search in
* *size* is the number of elements in the *array*
* And *value* is the value to search for
* Your function must return the first index where *value* is located
* If *value* is not present in *array* or if *array* is *NULL*, your function must return *-1*
* Every time you compare a value in the array to the value you are searching, you have to print this value(see example below)

```
wilfried@0x1E-search_algorithms$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        10, 1, 42, 3, 4, 42, 6, 7, -1, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, linear_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 42, linear_search(array, size, 42));
    printf("Found %d at index: %d\n", 999, linear_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-linear.c -o 0-linear
wilfried@0x1E-search_algorithms$ ./0-linear 
Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Found 3 at index: 3

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Found 42 at index: 2

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Value checked array[4] = [4]
Value checked array[5] = [42]
Value checked array[6] = [6]
Value checked array[7] = [7]
Value checked array[8] = [-1]
Value checked array[9] = [9]
Found 999 at index: -1
```

File: [0-linear.c]()

### 1. Binary search
Write a function that searches for a value in a sorted array of integers using the [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
* Prototype: *int binary_search(int *array, size_t size, int value);*
* Where *array* is a pointer to the first element of the array to search in
* *size* is the number of elements in *array*
* And *value* is the value to search for
* Your function must return the index where *value* is located
* You can assume that *array* will be sorted in ascending order
* You can assume that *value* won't appear more than once in *array*
* If *value* is not present in *array* or if *array* is *NULL*, your function must return *-1*
* You must print the array being searched every time it changes (e.g. at the beginning and when you search a subarray) (See example)

```
wilfried@0x1E-search_algorithms$ cat 1-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 2, binary_search(array, size, 2));
    printf("Found %d at index: %d\n\n", 5, binary_search(array, 5, 5));
    printf("Found %d at index: %d\n", 999, binary_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 1-main.c 1-binary.c -o 1-binary
wilfried@0x1E-search_algorithms$ ./1-binary 
Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 0, 1, 2, 3
Searching in array: 2, 3
Found 2 at index: 2

Searching in array: 0, 1, 2, 3, 4
Searching in array: 3, 4
Searching in array: 4
Found 5 at index: -1

Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 5, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

File: [1-binary.c]()

### 2. Big O #0
What is the *time complexity* (worst case) of a linear search in an array of size *n*?

File: [2-O]()

### 3. Big O #1
What is the *space complexity* (worst case) of an iterative linear search algorithm in an array of size *n*?

File: [3-O]()

### 4. Big O #2
What is the *time compexity* (worst case) of a binary search in an array of size *n*?

File: [4-O]()

### 5. Big O #3
What is the *space complexity* (worst case) of a binary search in an array of size *n*?

File: [5-O]()

### 6. Big O #4
What is the *space complexity* of this function / algorithm?

```
int **allocate_map(int n, int m)
{
     int **map;

     map = malloc(sizeof(int *) * n);
     for (size_t i = 0; i < n; i++)
     {
          map[i] = malloc(sizeof(int) * m);
     }
     return (map);
}
```

File: [6-O]()

### 7. Jump search
Write a function that searches for a value in a sorted array of integers using the [Jump search algorithm](https://en.wikipedia.org/wiki/Jump_search)
* Prototype: *int jump_search(int *array, size_t size, int value)*
* Where *array* is a pointer to the first element of the array to search in
* *size* is the number of elements in *array*
* And *value* is the value to search for
* Your function must return the first index where value is located
* You can assume that *array* will be sorted in ascending order
* If *value* is not present in *array* or if *array* is *NULL*, your function must return *-1*
* You have to use the square root of the size of the array as the junp step.
* You can use the *sqrt()* function included in *<math.h>* (don't forget to compile with -lm)
* Every time you compare a value in the array to the value you are searching for, you have to print this value (see example)

```
wilfried@0x1E-search_algorithms$ cat 100-main.c
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
    printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
    printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 100-main.c 100-jump.c -lm -o 100-jump
wilfried@0x1E-search_algorithms$ ./100-jump
Value checked array[0] = [0]
Value checked array[3] = [3]
Value found between indexes [3] and [6]
Value checked array[3] = [3]
Value checked array[4] = [4]
Value checked array[5] = [5]
Value checked array[6] = [6]
Found 6 at index: 6

Value checked array[0] = [0]
Value found between indexes [0] and [3]
Value checked array[0] = [0]
Value checked array[1] = [1]
Found 1 at index: 1

Value checked array[0] = [0]
Value checked array[3] = [3]
Value checked array[6] = [6]
Value checked array[9] = [9]
Value found between indexes [9] and [12]
Value checked array[9] = [9]
Found 999 at index: -1

```

File: [100-jump.c]()

### 8. Big O #5
What is the *time complexity* (average case) of a jump search in an array of size *n*, using *step = sqrt(n)*?

File: [101-O]()

### 9. Interpolation search
Write a function that searches for a value in a sorted array of integers using the [Interpolation search algorithm](https://en.wikipedia.org/wiki/Interpolation_search)
* Prototype: *int interpolation_search(int *array, size_t size, int value);*
* Where *array* is a pointer to the first element of the array to search in
* *size* is the number of elements in *array*
* And *value* is the value to search for
* Your function must return the first index where *value* is located
* You can assume that *array* will be sorted in ascending order
* If *value* is not present in *array* or if *array* is *NULL*, your function must return *-1*
* To determine the probe position, you can use: *size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]))*
* Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

```
wilfried@0x1E-search_algorithms$ cat 102-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, interpolation_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 7, interpolation_search(array, size, 7));
    printf("Found %d at index: %d\n", 999, interpolation_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 102-main.c 102-interpolation.c -o 102-interpolation
wilfried@0x1E-search_algorithms$ ./102-interpolation 
Value checked array[6] = [2]
Value checked array[7] = [3]
Found 3 at index: 7

Value checked array[14] = [7]
Found 7 at index: 14

Value checked array[2109] is out of range
Found 999 at index: -1
```

File: [102-interpolation.c]()

### 10. Exponential search
Write a function that searches for a value in a sorted array of integers using the [Exponential search algorithm](https://en.wikipedia.org/wiki/Exponential_search)
* Prototype: *int exponential_search(int *array, size_t size, int value)*
* where *array* is a pointer to the first element of the array to search in
* *size* is the number of elements in *array*
* And *value* is the value to search for
