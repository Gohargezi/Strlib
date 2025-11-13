# StrLib - C String Utility Library

## Overview
StrLib is a lightweight C library that provides safe and convenient string manipulation functions, similar to standard C string functions but with added safety and utility. It supports operations such as string duplication, safe copy, concatenation, trimming, splitting, searching, and more.

## Features
- Safe string length, copy, and concatenation functions.
- Custom string comparison with detailed result.
- String trimming and case conversion.
- Substring extraction and tokenization.
- Check if a string contains a substring.
- Split a string into tokens by a delimiter.

## Project Structure
```
.
├── makefile            # Build instructions
├── src
│   ├── strlib.c       # Implementation of StrLib
│   └── strlib.h       # Header file
└── test
    ├── test_strlib.c  # Unit tests for StrLib
    ├── unity.c        # Unity test framework source
    ├── unity.h        # Unity header
    └── unity_internals.h # Unity internals
```

## Build Instructions
Make sure you have `gcc` installed. From the project root:

```bash
make
```
This will compile the library and run the unit tests.

### Clean build artifacts
```bash
make clean
```

## Usage
Include the header and link your source files:

```c
#include "strlib.h"

int main() {
    const char* text = "  hello world  ";
    char* trimmed = strlib_trim(text);
    if (trimmed) {
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed);
    }
    return 0;
}
```

## Running Tests
Unit tests are located in `test/test_strlib.c` and use the Unity framework.

```bash
make test
```

You should see output indicating the result of each test.

## License
This project is released under the MIT License.

## Notes
- All functions that return dynamically allocated memory must be freed by the caller.
- Functions return special values (like `SIZE_MAX` or `NULL`) to indicate errors.
- Designed to be portable across standard C11 compilers.

