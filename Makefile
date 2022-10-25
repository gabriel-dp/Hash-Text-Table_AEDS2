# Defines the C Compiler
CC := gcc

# Final file name
BINARY := out

# Source code file extension
SRCEXT := c

# Source code directory structure
BINDIR := bin
SRCDIR := src
BUILDDIR := build
TESTDIR := test

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.$(SRCEXT))))
OBJECTS :=$(patsubst %,$(BUILDDIR)/%.o,$(NAMES))


# Rule for link and generate the binary file
all: $(OBJECTS)
	$(CC) -o $(BINDIR)/$(BINARY) $+

# Rule for object binaries compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) -c $^ -o $@