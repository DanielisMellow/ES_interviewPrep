# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Linker flags
LDFLAGS = 

# Source files
SOURCES = disjointSet.c graph.c main.c
# Object files
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = myProgram

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
