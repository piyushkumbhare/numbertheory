# Compiler & Flags settings
CC := gcc
CFLAGS := -Werror -Wall -Wpedantic -g

# These are the auxiliary inputs
SOURCES := power-mod.c find-remainder-bf.c find-remainder-dp.c
TARGET := ../bin/power-mod

# Automatically gets created based on $(SOURCES)
OBJECTS := $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Compile Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link binary file
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Remove all non-source files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
