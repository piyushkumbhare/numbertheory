# Compiler & Flags settings
CC := gcc
CFLAGS := -Werror -Wall -Wpedantic -g
LFLAGS := -lm

# These are the auxiliary inputs
SOURCES := qr.c
TARGET := ../bin/qr

# Automatically gets created based on $(SOURCES)
OBJECTS := $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Compile Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link binary file
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

# Remove all non-source files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
