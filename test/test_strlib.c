#include "unity.h"
#include "strlib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* -------------------- Setup / Teardown -------------------- */
void setUp(void) {}
void tearDown(void) {}

/* ==========================================================
 *                  strlib_strlen()
 * ========================================================== */
void test_strlen_NormalString(void) {
    TEST_ASSERT_EQUAL_INT(5, strlib_strlen("apple"));
}

void test_strlen_EmptyString(void) {
    TEST_ASSERT_EQUAL_INT(0, strlib_strlen(""));
}

void test_strlen_NullPointer(void) {
    TEST_ASSERT_EQUAL_INT(-1, strlib_strlen(NULL));
}

/* ==========================================================
 *                  strlib_strdup()
 * ========================================================== */
void test_strdup_NormalString(void) {
    char *copy = strlib_strdup("hello");
    TEST_ASSERT_NOT_NULL(copy);
    TEST_ASSERT_EQUAL_STRING("hello", copy);
    free(copy);
}

void test_strdup_EmptyString(void) {
    char *copy = strlib_strdup("");
    TEST_ASSERT_NOT_NULL(copy);
    TEST_ASSERT_EQUAL_STRING("", copy);
    free(copy);
}

void test_strdup_NullPointer(void) {
    TEST_ASSERT_NULL(strlib_strdup(NULL));
}

/* ==========================================================
 *                  strlib_strcpy()
 * ========================================================== */
void test_strcpy_Normal(void) {
    char dest[10];
    TEST_ASSERT_EQUAL_INT(0, strlib_strcpy(dest, sizeof(dest), "cat"));
    TEST_ASSERT_EQUAL_STRING("cat", dest);
}

void test_strcpy_DestTooSmall(void) {
    char dest[3];
    TEST_ASSERT_EQUAL_INT(-1, strlib_strcpy(dest, sizeof(dest), "hello"));
}

void test_strcpy_NullInputs(void) {
    TEST_ASSERT_EQUAL_INT(-1, strlib_strcpy(NULL, 5, "abc"));
    char buf[5];
    TEST_ASSERT_EQUAL_INT(-1, strlib_strcpy(buf, sizeof(buf), NULL));
}

/* ==========================================================
 *                  strlib_strncat()
 * ========================================================== */
void test_strncat_Normal(void) {
    char dest[15] = "Hello";
    TEST_ASSERT_EQUAL_INT(0, strlib_strncat(dest, sizeof(dest), " World", 6));
    TEST_ASSERT_EQUAL_STRING("Hello World", dest);
}

void test_strncat_LimitedAppend(void) {
    char dest[15] = "123";
    TEST_ASSERT_EQUAL_INT(0, strlib_strncat(dest, sizeof(dest), "abcdef", 3));
    TEST_ASSERT_EQUAL_STRING("123abc", dest);
}

void test_strncat_DestTooSmall(void) {
    char dest[6] = "hi";
    TEST_ASSERT_EQUAL_INT(-1, strlib_strncat(dest, sizeof(dest), "there", 5));
}

/* ==========================================================
 *                  strlib_strcmp()
 * ========================================================== */
void test_strcmp_EqualStrings(void) {
    TEST_ASSERT_EQUAL_INT(STRCMP_EQUAL, strlib_strcmp("abc", "abc"));
}

void test_strcmp_LessString(void) {
    TEST_ASSERT_EQUAL_INT(STRCMP_LESS, strlib_strcmp("abc", "bcd"));
}

void test_strcmp_GreaterString(void) {
    TEST_ASSERT_EQUAL_INT(STRCMP_GREATER, strlib_strcmp("xyz", "xy"));
}

void test_strcmp_NullInput(void) {
    TEST_ASSERT_EQUAL_INT(STRCMP_ERROR, strlib_strcmp(NULL, "abc"));
}

/* ==========================================================
 *                  strlib_strtok()
 * ========================================================== */
void test_strtok_Basic(void) {
    char str[] = "apple,banana,cherry";
    char *token = strlib_strtok(str, ",");
    TEST_ASSERT_EQUAL_STRING("apple", token);
    token = strlib_strtok(NULL, ",");
    TEST_ASSERT_EQUAL_STRING("banana", token);
    token = strlib_strtok(NULL, ",");
    TEST_ASSERT_EQUAL_STRING("cherry", token);
}

void test_strtok_NoDelim(void) {
    char str[] = "singleword";
    char *token = strlib_strtok(str, ",");
    TEST_ASSERT_EQUAL_STRING("singleword", token);
}

/* ==========================================================
 *                  strlib_trim()
 * ========================================================== */
void test_trim_Basic(void) {
    char *res = strlib_trim("   hello world   ");
    TEST_ASSERT_EQUAL_STRING("hello world", res);
    free(res);
}

void test_trim_NoSpaces(void) {
    char *res = strlib_trim("test");
    TEST_ASSERT_EQUAL_STRING("test", res);
    free(res);
}

void test_trim_AllSpaces(void) {
    char *res = strlib_trim("    ");
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

/* ==========================================================
 *                  strlib_find()
 * ========================================================== */
void test_find_Found(void) {
    TEST_ASSERT_EQUAL_INT(6, strlib_find("hello world", "world"));
}

void test_find_NotFound(void) {
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, strlib_find("abcdef", "xyz"));
}

void test_find_NullInputs(void) {
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, strlib_find(NULL, "a"));
    TEST_ASSERT_EQUAL_INT(SIZE_MAX, strlib_find("abc", NULL));
}

/* ==========================================================
 *                  strlib_contains()
 * ========================================================== */
void test_contains_Found(void) {
    TEST_ASSERT_TRUE(strlib_contains("abcdef", "bcd"));
}

void test_contains_NotFound(void) {
    TEST_ASSERT_FALSE(strlib_contains("abcdef", "xyz"));
}

void test_contains_NullInputs(void) {
    TEST_ASSERT_FALSE(strlib_contains(NULL, "a"));
}

/* ==========================================================
 *                  strlib_substr()
 * ========================================================== */
void test_substr_Normal(void) {
    char *res = strlib_substr("abcdef", 2, 3);
    TEST_ASSERT_EQUAL_STRING("cde", res);
    free(res);
}

void test_substr_OutOfRange(void) {
    TEST_ASSERT_NULL(strlib_substr("abc", 10, 2));
}

void test_substr_NullInput(void) {
    TEST_ASSERT_NULL(strlib_substr(NULL, 0, 2));
}

/* ==========================================================
 *                  strlib_to_upper()
 * ========================================================== */
void test_to_upper_Normal(void) {
    char *res = strlib_to_upper("aBc");
    TEST_ASSERT_EQUAL_STRING("ABC", res);
    free(res);
}

void test_to_upper_Empty(void) {
    char *res = strlib_to_upper("");
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

void test_to_upper_Null(void) {
    TEST_ASSERT_NULL(strlib_to_upper(NULL));
}

/* ==========================================================
 *                  strlib_split()
 * ========================================================== */
void test_split_Basic(void) {
    size_t count = 0;
    char **tokens = strlib_split("a,b,c", ',', &count);
    TEST_ASSERT_NOT_NULL(tokens);
    TEST_ASSERT_EQUAL_INT(3, count);
    TEST_ASSERT_EQUAL_STRING("a", tokens[0]);
    TEST_ASSERT_EQUAL_STRING("b", tokens[1]);
    TEST_ASSERT_EQUAL_STRING("c", tokens[2]);
    for (size_t i = 0; i < count; i++) free(tokens[i]);
    free(tokens);
}

void test_split_EmptyString(void) {
    size_t count = 0;
    char **tokens = strlib_split("", ',', &count);
    TEST_ASSERT_NOT_NULL(tokens);
    TEST_ASSERT_EQUAL_INT(0, count);
    free(tokens);
}

void test_split_NullInput(void) {
    size_t count = 0;
    TEST_ASSERT_NULL(strlib_split(NULL, ',', &count));
}

/* ==========================================================
 *                      main()
 * ========================================================== */
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_strlen_NormalString);
    RUN_TEST(test_strlen_EmptyString);
    RUN_TEST(test_strlen_NullPointer);

    RUN_TEST(test_strdup_NormalString);
    RUN_TEST(test_strdup_EmptyString);
    RUN_TEST(test_strdup_NullPointer);

    RUN_TEST(test_strcpy_Normal);
    RUN_TEST(test_strcpy_DestTooSmall);
    RUN_TEST(test_strcpy_NullInputs);

    RUN_TEST(test_strncat_Normal);
    RUN_TEST(test_strncat_LimitedAppend);
    RUN_TEST(test_strncat_DestTooSmall);

    RUN_TEST(test_strcmp_EqualStrings);
    RUN_TEST(test_strcmp_LessString);
    RUN_TEST(test_strcmp_GreaterString);
    RUN_TEST(test_strcmp_NullInput);

    RUN_TEST(test_strtok_Basic);
    RUN_TEST(test_strtok_NoDelim);

    RUN_TEST(test_trim_Basic);
    RUN_TEST(test_trim_NoSpaces);
    RUN_TEST(test_trim_AllSpaces);

    RUN_TEST(test_find_Found);
    RUN_TEST(test_find_NotFound);
    RUN_TEST(test_find_NullInputs);

    RUN_TEST(test_contains_Found);
    RUN_TEST(test_contains_NotFound);
    RUN_TEST(test_contains_NullInputs);

    RUN_TEST(test_substr_Normal);
    RUN_TEST(test_substr_OutOfRange);
    RUN_TEST(test_substr_NullInput);

    RUN_TEST(test_to_upper_Normal);
    RUN_TEST(test_to_upper_Empty);
    RUN_TEST(test_to_upper_Null);

    RUN_TEST(test_split_Basic);
    RUN_TEST(test_split_EmptyString);
    RUN_TEST(test_split_NullInput);

    return UNITY_END();
}
