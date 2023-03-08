CC = cc
CFLAGS = -pedantic -Wall -Os -s -Wno-deprecated-declarations -std=c99 -D_DEFAULT_SOURCE -D_POSIX_C_SOURCE=200809L
DEPS = text.h
OBJ = text.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

libstui.a: $(OBJ)
	ar rcs $@ $^

debug: $(OBJ) test.c
	$(CC) -o $@ $^ $(CFLAGS) -L. -lstui -pg
	valgrind --tool=memcheck --leak-check=full -s --expensive-definedness-checks=yes ./debug

.PHONY: clean
clean:
	rm -rf *.o
