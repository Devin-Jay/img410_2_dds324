# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Target executable
TARGET = v3test

# Source files
SRCS = v3test.c v3math.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile
%.o: %.c v3math.h
	$(CC) $(CFLAGS) -c $<

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean