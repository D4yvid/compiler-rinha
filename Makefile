SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

TARGET = compilerinha

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LFLAGS)

