CC = gcc
CFLAGS = -std=c99 -Wall -Wextra --pedantic -Wvla -Wshadow -Werror
CPPFLAGS = -DWARN #defines warning

EXEC_PALINDROME = palindrome_practice
EXEC_BINARY = binary_practice

BINARY_DIR = binary
PALINDROME_DIR = palindrome



TESTDIR = tests
TESTS = $(wildcard $(TESTDIR)/*)

#NOTE: for the flags, use different executable names, controlled with test

SRCS = recursion_practice.c

#OBJ_PAL = $(OBJ:$(wildcard %)=/$(PALINDROME_DIR)/$(wildcard %))
# ts hella chopped ma boi
# % is only special inside pattern rules, not functions like this, so it goes back to being a literal bum
# the "%" only works by capturing a step, which can be flexible, but still can only be a step
# this is valid: binary/%.o: %.c, as it will match binary/recursion to recursion.c (THIS IS THE MISSING TECH)
# SUPA TECH: A "STEM" IS JUST WHATEVER TEXT MATCHES THAT RULE!! doesnt have to be filename or something

#recall, this is called a substitution reference, VERY TECHY!!
#ALSO, WILDCARD IS ONLY FOR "*"!
OBJ_PAL = $(SRCS:%.c=$(PALINDROME_DIR)/%.o)
OBJ_BIN = $(SRCS:%.c=$(BINARY_DIR)/%.o)


#TECH 2: order-dependant pre-requisites |
#Normal pre-requisites = if out of date / doesnt exst , rebuild the file (affects build order and rebuild decision)
# order-dependant pre-requisite: ensures it exists before running recipe, but changes to it do not cause re-builds
#NOTE: RULE != RECIPE, recipe = the commands to make the target, RULE is the entire thing itself
#First, when you run make palindrome, the regular prereqs are run
# then order-only pre-reqs, and then lastly the recipe



palindrome_build: $(EXEC_PALINDROME)

binary_build: $(EXEC_BINARY)

$(EXEC_BINARY): $(OBJ_BIN)
	$(CC) $(OBJ_BIN) -o $@

$(OBJ_BIN): $(BINARY_DIR)/%.o: %.c | $(BINARY_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -DBINARY -c $< -o $@

$(EXEC_PALINDROME): $(OBJ_PAL)
	$(CC) $(OBJ_PAL) -o $@

#strict pattern, not free pattern, since say where it will be applied
# NOTE: binary/file.o is a perfectly valid name that also specifies location, so creating this file (assuming its parents
#exist) shoudl be a okay!
$(OBJ_PAL) : $(PALINDROME_DIR)/%.o: %.c | $(PALINDROME_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -DPALINDROME -c $< -o $@

#ISSUE HERE: circular dependency: you have given binary 2 different meanings

# you first have $(BINARY_DIR):
# 				mkdir -p $@

#but at the same time you have binary: $(EXEC BINARY)



.PHONY: $(BINARY_DIR) $(PALINDROME_DIR) clean
$(BINARY_DIR):
	mkdir -p $@

$(PALINDROME_DIR):
	mkdir -p $@



.PHONY=clean

clean:
	rm -rf $(OBJ_PAL) $(OBJ_BIN) $(EXEC_BINARY) $(EXEC_PALINDROME) $(BINARY_DIR) $(PALINDROME_DIR)


test_palindrome: palindrome_build
	@for test in $(TESTS); do \
		./$(EXEC_PALINDROME) $$test; \
	done

