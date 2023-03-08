/* enums */
typedef enum {
        NORMAL,
        BOLD,
        FAINT,
        ITALIC,
        UNDERLINE,
        SLOW_BLINK,
        FAST_BLINK,
        REVERSE_VIDEO,
        ERASE,
        STRIKETRHOUGH,
        DOUBLE_UNDERLINE,
} TextStyles;

typedef enum {
        BLACK = 1,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        RESET
} TextColors;

/* structs */
typedef struct {
        void *(*alloc)(unsigned long);
        TextColors foreground;
        TextColors background;
        TextStyles style;
} Pretty;

/* functions */
char *prettify(char *text, Pretty pretty);
void pprintf(char *text, unsigned short fg, unsigned short bg,
             unsigned short style);
