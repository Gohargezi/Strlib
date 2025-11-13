# ==========================
# Compiler settings
# ==========================
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
INCLUDE = -Isrc -Itest

# ==========================
# Project structure
# ==========================
SRC_FILES  = src/strlib.c
TEST_FILES = test/test_strlib.c test/unity.c

TARGET_TEST = test_runner

.PHONY: all clean test

all: test

$(TARGET_TEST): $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

test: $(TARGET_TEST)
	@echo "=============================="
	@echo " Running unit tests with Unity"
	@echo "=============================="
	./$(TARGET_TEST)

clean:
	rm -f $(TARGET_TEST)
