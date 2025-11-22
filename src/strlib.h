#ifndef STRLIB_H
#define STRLIB_H

#include <stdlib.h>
#include <stdint.h>

/* --- Boolean type --- */
typedef enum {
    FALSE = 0,
    TRUE  = 1
} Bool;

/* --- Custom strcmp result --- */
typedef enum {
    STRCMP_ERROR   = -1,
    STRCMP_LESS    = -2,  // s1 < s2
    STRCMP_EQUAL   = 0,   // s1 == s2
    STRCMP_GREATER = 1    // s1 > s2
} StrcmpResult;


/* --- Function Declarations --- */

/**
 * @brief Returns length of a string, or SIZE_MAX if NULL.
 */
size_t strlib_strlen(const char* str);

/**
 * @brief Duplicates a string into a new allocated buffer.
 */
char* strlib_strdup(const char* src);

/**
 * @brief Copies src into dest safely.
 * @return 0 on success, SIZE_MAX on error (e.g., dest too small or NULL).
 */
size_t strlib_strcpy(char* dest, size_t dest_size, const char* src);

/**
 * @brief Concatenates up to n chars of src to dest safely.
 * @return 0 on success, SIZE_MAX on error.
 */
size_t strlib_strncat(char* dest, size_t dest_size, const char* src, size_t n);

/**
 * @brief Compares two strings.
 * @return STRCMP_LESS, STRCMP_EQUAL, STRCMP_GREATER, or STRCMP_ERROR.
 */
StrcmpResult strlib_strcmp(const char* s1, const char* s2);

/**
 * @brief Tokenizes a string using delimiters (like strtok).
 */
char* strlib_strtok(char* str, const char* delim);

/**
 * @brief Trims leading and trailing whitespace.
 * @return New allocated trimmed string or NULL.
 */
char* strlib_trim(const char* src);

/**
 * @brief Finds the first occurrence of `needle` in `haystack`.
 * @return Index position, or SIZE_MAX if not found or invalid.
 */
size_t strlib_find(const char* haystack, const char* needle);

/**
 * @brief Checks if haystack contains needle.
 */
Bool strlib_contains(const char* haystack, const char* needle);

/**
 * @brief Extracts substring starting at `start` with length `n`.
 */
char* strlib_substr(const char* src, size_t start, size_t n);

/**
 * @brief Converts all lowercase letters in string to uppercase.
 */
char* strlib_to_upper(const char* src);

/**
 * @brief Splits a string by a delimiter into tokens array.
 * @param count Output parameter: number of tokens.
 * @return NULL on failure, otherwise array of strings (must be freed).
 */
char** strlib_split(const char* src, char delim, size_t* count);

/**
 * @brief Converts a number to a new allocated string.
 * @return Newly allocated string, or NULL on error.
 */
char* strlib_NumToStr (size_t number) ;

#endif /* STRLIB_H */
