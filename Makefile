# Defines the C Compiler
CC := gcc

# Final file name
BINARY := out

# Source code file extension
SRCEXT := c

# Code directory structure
SRCDIR := src
BINDIR := bin
BUILDDIR := build

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.$(SRCEXT))))
OBJECTS :=$(patsubst %,$(BUILDDIR)/%.o,$(NAMES))


# Rule for link and generate the binary file
all: $(OBJECTS)
ifdef OS # Windows
	if not exist "$(BINDIR)" mkdir $(BINDIR)
else # Linux
	mkdir -p $(BINDIR)
endif
	$(CC) -o $(BINDIR)/$(BINARY) $+

# Rule for object binaries compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
ifdef OS # Windows
	if not exist "$(BUILDDIR)" mkdir $(BUILDDIR)
else # Linux
	mkdir -p $(BUILDDIR)
endif
	$(CC) -c $^ -o $@