# STUI

ISO & POSIX Compliant Simple Terminal UI

## Building

Just run `make`

## Compiling with the lib

Make sure to compile with the following options:

`-L. --lstui`

The `.` is the directory to search in for the lib (current)

## Coloring Text

Using the pretty struct:
```c
#include "text.h"
#include <stdio.h>
#include <stdlib.h>

int
main() {
        char *text = "hello, world!\n";
        Pretty p;
        p.foreground = BLACK;
        p.background = WHITE;
        p.style = BOLD;
        p.alloc = &malloc;

        char *pretty = prettify(text, p);

        printf("%s", pretty);

        free(pretty);
}
```
![prettystruct](https://user-images.githubusercontent.com/94227101/223873232-aab957f3-dc45-42aa-97e6-759db14a9cff.png)

Usint prettyprint:
```c
#include "text.h"
#include <stdio.h>
#include <stdlib.h>

int
main() {
        char *text = "hello, world!\n";
        pprintf(text, YELLOW, RED, BOLD);
}
```
![prettyprint](https://user-images.githubusercontent.com/94227101/223873284-8bae93f3-376f-4ee0-a32c-3c3d6972ffe3.png)

More to come soon...
