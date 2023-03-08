#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constants */
const unsigned short FG_OFFSET = 29;
const unsigned short BG_OFFSET = 39;

const unsigned short FG_RESET = 39;
const unsigned short BG_RESET = 49;

const unsigned short UNSET = 0;

const char *FMT = "\033[%hu;%hu;%hum%s\033[0m\033[0m";

/* function prototypes */
static unsigned short intlen(short num);
static unsigned short bgcol(TextColors color);
static unsigned short fgcol(TextColors color);

/* function implementations */
void
pprintf(char *text, unsigned short fg, unsigned short bg, unsigned short style)
{
        printf(FMT, style, bgcol(bg), fgcol(fg), text);
}

char *
prettify(char *text, Pretty pretty)
{
        unsigned short fg = fgcol(pretty.foreground);
        unsigned short bg = bgcol(pretty.background);

        uint len = strlen(FMT) - 10 + intlen(fg) + intlen(bg) + strlen(text);
        char *tmp = pretty.alloc(len);
        snprintf(tmp, len, FMT, pretty.style, bg, fg, text);

        return tmp;
}

static unsigned short
fgcol(TextColors color)
{
        return color == UNSET ? FG_RESET : FG_OFFSET + color;
}

static unsigned short
bgcol(TextColors color)
{
        return color == UNSET ? BG_RESET : BG_OFFSET + color;
}

static unsigned short
intlen(short num)
{
        return num > 9 ? 2 : 1;
}
