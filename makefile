CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# List your source files here
SOURCES = main_menu.c checkout_file.c

# Derive object file names from source file names
OBJECTS = $(SOURCES:.c=.o)

# Name of the final executable
EXECUTABLE = myprogram

# Default target
all: $(EXECUTABLE)

# Rule to build the executable from object files
$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Rule to compile each source file into an object file
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up intermediate object files and the executable
clean:
    rm -f $(OBJECTS) $(EXECUTABLE)
