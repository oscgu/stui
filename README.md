# STUI

ISO & POSIX Compliant Simple Terminal UI

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

More to come...