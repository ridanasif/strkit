/**
 * @file strkit.c
 * @brief Implementation of the StrKit string manipulation library
 * @author Ridan Muhammed Asif
 * @date May 5, 2025
 * @version 1.0.0
 * 
 * StrKit is a lightweight C library for common string manipulation operations.
 * It provides both in-place functions (which modify the original string) and
 * non-destructive functions (which return new strings).
 * 
 * Performance optimizations:
 * - Uses pointer arithmetic for faster traversal
 * - Minimizes unnecessary string copies
 * - Handles edge cases properly
 * 
 * Dependencies: Only requires stdlib.h and stdio.h
 */

#include <stdlib.h>
#include <stdio.h>
#include "strkit.h"

/* ========== PRIVATE HELPER FUNCTIONS ========== */

/**
 * @brief Convert a lowercase letter to uppercase
 * @param c Character to convert
 * @return Uppercase version of character, or unchanged if not a lowercase letter
 */
static inline char char_capitalize(char c) {
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

/**
 * @brief Convert an uppercase letter to lowercase
 * @param c Character to convert
 * @return Lowercase version of character, or unchanged if not an uppercase letter
 */
static inline char char_decapitalize(char c) {
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

/**
 * @brief Check if a character is whitespace
 * @param c Character to check
 * @return 1 if whitespace, 0 otherwise
 */
static inline int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

/* ========== CORE STRING FUNCTIONS ========== */

/**
 * @brief Calculate the length of a string
 * @param text Input string
 * @return Length of the string, 0 if NULL
 */
int str_len(const char* text) {
    if (!text) return 0;
    
    const char* ptr = text;
    while (*ptr) ptr++;
    return ptr - text;
}

/**
 * @brief Reverse a string in-place
 * @param text String to reverse
 * @return Pointer to the reversed string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_reverse(char* text) {
    if (!text) return NULL;
    
    char* start = text;
    char* end = text + str_len(text) - 1;
    
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    
    return text;
}

/**
 * @brief Create a new reversed copy of a string
 * @param text String to reverse
 * @return Newly allocated reversed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_reverse_n(const char* text) {
    if (!text) return NULL;

    int length = str_len(text);
    char* result = malloc(sizeof(char) * (length + 1));
    if (!result) return NULL;

    if (length > 0) {
        const char* src = text + length - 1;
        char* dest = result;
        
        while (length--) {
            *dest++ = *src--;
        }
    }
    
    result[str_len(text)] = '\0';
    return result;
}

/* ========== CASE CONVERSION FUNCTIONS ========== */

/**
 * @brief Capitalize the first character of a string in-place
 * @param text String to capitalize
 * @return Pointer to the capitalized string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_capitalize(char* text) {
    if (!text || !*text) return text;
    
    *text = char_capitalize(*text);
    return text;
}

/**
 * @brief Create a new string with the first character capitalized
 * @param text String to capitalize
 * @return Newly allocated capitalized string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_capitalize_n(const char* text) {
    if (!text) return NULL;
    if (!*text) {
        char* empty = malloc(1);
        if (!empty) return NULL;
        *empty = '\0';
        return empty;
    }

    int len = str_len(text);
    char* new_text = malloc(len + 1);
    if (!new_text) return NULL;

    // Copy with optimized first character
    *new_text = char_capitalize(*text);
    
    // Manual copy for the rest of the string
    for (int i = 1; i < len; i++) {
        new_text[i] = text[i];
    }
    new_text[len] = '\0';

    return new_text;
}

/**
 * @brief Convert a string to uppercase in-place
 * @param text String to convert
 * @return Pointer to the uppercase string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_uppercase(char* text) {
    if (!text) return NULL;
    
    char* p = text;
    while (*p) {
        *p = char_capitalize(*p);
        p++;
    }
    
    return text;
}

/**
 * @brief Create a new string converted to uppercase
 * @param text String to convert
 * @return Newly allocated uppercase string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_uppercase_n(const char* text) {
    if (!text) return NULL;

    int len = str_len(text);
    char* new_text = malloc(len + 1);
    if (!new_text) return NULL;

    const char* src = text;
    char* dest = new_text;
    
    while (*src) {
        *dest++ = char_capitalize(*src++);
    }
    *dest = '\0';
    
    return new_text;
}

/**
 * @brief Convert a string to lowercase in-place
 * @param text String to convert
 * @return Pointer to the lowercase string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_lowercase(char* text) {
    if (!text) return NULL;
    
    char* p = text;
    while (*p) {
        *p = char_decapitalize(*p);
        p++;
    }
    
    return text;
}

/**
 * @brief Create a new string converted to lowercase
 * @param text String to convert
 * @return Newly allocated lowercase string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_lowercase_n(const char* text) {
    if (!text) return NULL;

    int len = str_len(text);
    char* new_text = malloc(len + 1);
    if (!new_text) return NULL;

    const char* src = text;
    char* dest = new_text;
    
    while (*src) {
        *dest++ = char_decapitalize(*src++);
    }
    *dest = '\0';
    
    return new_text;
}

/**
 * @brief Convert a string to title case in-place (capitalize first letter of each word)
 * @param text String to convert
 * @return Pointer to the title case string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_title(char* text) {
    if (!text) return NULL;
    
    int capitalize_next = 1;
    char* p = text;
    
    while (*p) {
        if (is_whitespace(*p)) {
            capitalize_next = 1;
        } else if (capitalize_next) {
            *p = char_capitalize(*p);
            capitalize_next = 0;
        } else {
            *p = char_decapitalize(*p);
        }
        p++;
    }
    
    return text;
}

/**
 * @brief Create a new string converted to title case
 * @param text String to convert
 * @return Newly allocated title case string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_title_n(const char* text) {
    if (!text) return NULL;

    int len = str_len(text);
    char* new_text = malloc(len + 1);
    if (!new_text) return NULL;

    // Copy the string
    for (int i = 0; i < len; i++) {
        new_text[i] = text[i];
    }
    new_text[len] = '\0';
    
    // Then apply title case
    str_title(new_text);
    
    return new_text;
}

/* ========== STRING SPLITTING FUNCTIONS ========== */

/**
 * @brief Split a string by delimiter
 * @param text String to split
 * @param delimiter Character to split by
 * @return NULL-terminated array of strings, or NULL on failure
 * @note Caller is responsible for freeing both the array and each string
 *       using free_strs()
 */
char** str_split(const char *text, char delimiter) {
    if (!text) return NULL;
    
    // First pass: count delimiter occurrences to determine array size
    int token_count = 1; // At least one token even without delimiters
    for (const char* ptr = text; *ptr; ptr++) {
        if (*ptr == delimiter) token_count++;
    }

    // Allocate result array (tokens + NULL terminator)
    char **result = malloc(sizeof(char*) * (token_count + 1));
    if (!result) return NULL;

    // Second pass: extract tokens
    const char* token_start = text;
    char** result_ptr = result;
    int success = 1; // Flag to track allocation success
    
    for (const char* ptr = text; ; ptr++) {
        if (*ptr == delimiter || *ptr == '\0') {
            int token_length = ptr - token_start;
            char *token = malloc(token_length + 1);
            
            if (!token) {
                success = 0;
                break;
            }

            // Copy token content
            for (int i = 0; i < token_length; i++) {
                token[i] = token_start[i];
            }
            token[token_length] = '\0';
            
            *result_ptr++ = token;
            token_start = ptr + 1;
            
            if (*ptr == '\0') break;
        }
    }
    
    if (success) {
        *result_ptr = NULL; // NULL terminator
        return result;
    } else {
        // Cleanup on allocation failure
        for (char** p = result; p < result_ptr; p++) {
            free(*p);
        }
        free(result);
        return NULL;
    }
}

/**
 * @brief Free memory allocated by str_split
 * @param result Array of strings to free
 */
void free_strs(char **result) {
    if (!result) return;
    
    for (char** ptr = result; *ptr; ptr++) {
        free(*ptr);
    }
    free(result);
}

/* ========== STRING CONCATENATION ========== */

/**
 * @brief Concatenate two strings into a new string
 * @param s1 First string
 * @param s2 Second string
 * @return Newly allocated concatenated string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_concat_n(const char* s1, const char* s2) {
    if (!s1) s1 = ""; // Handle NULL inputs safely
    if (!s2) s2 = "";
    
    int l1 = str_len(s1);
    int l2 = str_len(s2);
    
    char* result = malloc(l1 + l2 + 1);
    if (!result) return NULL;
    
    // Copy first string
    for (int i = 0; i < l1; i++) {
        result[i] = s1[i];
    }
    
    // Copy second string
    for (int i = 0; i < l2; i++) {
        result[l1 + i] = s2[i];
    }
    
    result[l1 + l2] = '\0';
    return result;
}

/* ========== STRING VALIDATION FUNCTIONS ========== */

/**
 * @brief Check if a string contains only numeric characters
 * @param s String to check
 * @return 1 if string is numeric, 0 otherwise
 */
int str_is_numeric(const char* s) {
    if (!s || !*s) return 0;
    
    while (*s) {
        if (*s < '0' || *s > '9') return 0;
        s++;
    }
    return 1;
}

/**
 * @brief Check if a string contains only alphabetic characters
 * @param s String to check
 * @return 1 if string is alphabetic, 0 otherwise
 */
int str_is_alpha(const char* s) {
    if (!s || !*s) return 0;
    
    while (*s) {
        if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) return 0;
        s++;
    }
    return 1;
}

/**
 * @brief Check if a string contains only alphanumeric characters
 * @param s String to check
 * @return 1 if string is alphanumeric, 0 otherwise
 */
int str_is_alpha_numeric(const char* s) {
    if (!s || !*s) return 0;
    
    while (*s) {
        if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z') || 
              (*s >= '0' && *s <= '9'))) {
            return 0;
        }
        s++;
    }
    return 1;
}

/**
 * @brief Check if two strings are equal
 * @param s1 First string
 * @param s2 Second string
 * @return 1 if strings are equal, 0 otherwise
 */
int str_is_equal(const char* s1, const char* s2) {
    if (!s1 && !s2) return 1; // Both NULL, consider equal
    if (!s1 || !s2) return 0; // One NULL, other not NULL
    
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    return (*s1 == *s2);
}

/**
 * @brief Check if a string is a palindrome
 * @param text String to check
 * @return 1 if string is a palindrome, 0 otherwise
 */
int str_is_palindrome(const char* text) {
    if (!text) return 0;
    
    int len = str_len(text);
    if (len <= 1) return 1; // Empty string or single char is palindrome
    
    const char* front = text;
    const char* back = text + len - 1;
    
    while (front < back) {
        if (*front++ != *back--) return 0;
    }
    
    return 1;
}

/* ========== TRIMMING FUNCTIONS ========== */

/**
 * @brief Trim whitespace from both ends of a string in-place
 * @param s String to trim
 * @return Pointer to the trimmed string within the original memory,
 *         or NULL if input was NULL
 * @note This function modifies the original string
 * @warning The returned pointer may differ from the input pointer
 */
char* str_trim(char* s) {
    if (!s) return NULL;
    
    // Trim leading whitespace by finding first non-whitespace
    char* start = s;
    while (*start && is_whitespace(*start)) start++;
    
    // If string is all whitespace, make it empty
    if (!*start) {
        *s = '\0';
        return s;
    }
    
    // Trim trailing whitespace
    char* end = s + str_len(s) - 1;
    while (end > start && is_whitespace(*end)) end--;
    *(end + 1) = '\0';
    
    // If we trimmed leading space, move the string
    if (start > s) {
        char* dest = s;
        while ((*dest++ = *start++));
    }
    
    return s;
}

/**
 * @brief Create a new trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_trim_n(const char* s) {
    if (!s) return NULL;
    
    // Skip leading whitespace
    const char* start = s;
    while (*start && is_whitespace(*start)) start++;
    
    // If all spaces, return empty string
    if (!*start) {
        char* result = malloc(1);
        if (result) *result = '\0';
        return result;
    }
    
    // Find end (last non-whitespace)
    const char* end = s + str_len(s) - 1;
    while (end > start && is_whitespace(*end)) end--;
    
    // Allocate and copy trimmed string
    int new_len = end - start + 1;
    char* result = malloc(new_len + 1);
    if (!result) return NULL;
    
    for (int i = 0; i < new_len; i++) {
        result[i] = start[i];
    }
    result[new_len] = '\0';
    
    return result;
}

/**
 * @brief Trim whitespace from the left side of a string in-place
 * @param s String to trim
 * @return Pointer to the left-trimmed string, or NULL if input was NULL
 * @note This function returns a pointer to the first non-whitespace character
 * @warning The returned pointer may differ from the input pointer
 */
char* str_ltrim(char* s) {
    if (!s) return NULL;
    
    char* start = s;
    while (*start && is_whitespace(*start)) {
        start++;
    }

    if (start != s) {
        // Shift trimmed string to the front, including null terminator
        size_t len = str_len(start);
        for (size_t i = 0; i <= len; ++i) {
            s[i] = start[i];
        }
    }

    return s;
}

/**
 * @brief Create a new left-trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated left-trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_ltrim_n(const char* s) {
    if (!s) return NULL;
    
    // Skip leading whitespace
    const char* start = s;
    while (*start && is_whitespace(*start)) start++;
    
    // Get length of trimmed string
    int new_len = str_len(start);
    
    // Allocate and copy
    char* result = malloc(new_len + 1);
    if (!result) return NULL;
    
    for (int i = 0; i < new_len; i++) {
        result[i] = start[i];
    }
    result[new_len] = '\0';
    
    return result;
}

/**
 * @brief Trim whitespace from the right side of a string in-place
 * @param s String to trim
 * @return Pointer to the trimmed string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_rtrim(char* s) {
    if (!s) return NULL;
    
    int len = str_len(s);
    if (len == 0) return s;
    
    char* end = s + len - 1;
    while (end >= s && is_whitespace(*end)) end--;
    *(end + 1) = '\0';
    
    return s;
}

/**
 * @brief Create a new right-trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated right-trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_rtrim_n(const char* s) {
    if (!s) return NULL;
    
    int len = str_len(s);
    if (len == 0) {
        char* result = malloc(1);
        if (result) *result = '\0';
        return result;
    }
    
    // Find last non-whitespace character
    const char* end = s + len - 1;
    while (end >= s && is_whitespace(*end)) end--;
    
    // Calculate new length
    int new_len = end - s + 1;
    if (new_len <= 0) {
        char* result = malloc(1);
        if (result) *result = '\0';
        return result;
    }
    
    // Allocate and copy
    char* result = malloc(new_len + 1);
    if (!result) return NULL;
    
    for (int i = 0; i < new_len; i++) {
        result[i] = s[i];
    }
    result[new_len] = '\0';
    
    return result;
}

/* ========== STRING SEARCHING FUNCTIONS ========== */

/**
 * @brief Find the index of a character in a string
 * @param search Character to find
 * @param text String to search in
 * @return Index of first occurrence, or -1 if not found
 */
int index_of(const char search, const char* text) {
    if (!text) return -1;
    
    const char* ptr = text;
    while (*ptr) {
        if (*ptr == search) return ptr - text;
        ptr++;
    }
    
    return -1;
}

/**
 * @brief Find the index of a substring in a string
 * @param text String to search in
 * @param substring Substring to find
 * @return Index of first occurrence, or -1 if not found
 */
int index_of_str(const char* text, const char* substring) {
    if (!text || !substring) return -1;
    if (!*substring) return 0; // Empty substring is at position 0
    
    const char* haystack = text;
    while (*haystack) {
        const char* needle = substring;
        const char* h = haystack;
        
        // Check for match at current position
        while (*needle && *h && *needle == *h) {
            needle++;
            h++;
        }
        
        // If we reached the end of needle, we found a match
        if (!*needle) return haystack - text;
        
        haystack++;
    }
    
    return -1;
}

/**
 * @brief Check if a string contains a substring
 * @param text String to search in
 * @param substring Substring to find
 * @return 1 if substring is found, 0 otherwise
 */
int str_contains(const char *text, const char *substring) {
    return index_of_str(text, substring) >= 0;
}

/* ========== CHARACTER ACCESS FUNCTIONS ========== */

/**
 * @brief Get the first character of a string
 * @param text Input string
 * @return First character, or '\0' if string is empty or NULL
 */
char str_first_char(const char* text) {
    return (text && *text) ? *text : '\0';
}

/**
 * @brief Get the last character of a string
 * @param text Input string
 * @return Last character, or '\0' if string is empty or NULL
 */
char str_last_char(const char* text) {
    if (!text || !*text) return '\0';
    
    int len = str_len(text);
    return text[len - 1];
}

/**
 * @brief Get the character at a specific index
 * @param text Input string
 * @param index Position to get character from
 * @return Character at index, or '\0' if index is out of bounds
 */
char str_char_at(const char* text, int index) {
    if (!text || index < 0) return '\0';
    
    int len = str_len(text);
    if (index >= len) return '\0';
    
    return text[index];
}

/* ========== STRING GENERATION FUNCTIONS ========== */

/**
 * @brief Create a new string by repeating a string multiple times
 * @param text String to repeat
 * @param times Number of times to repeat
 * @return Newly allocated repeated string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_repeat_n(const char* text, int times) {
    if (!text) return NULL;
    if (times <= 0) {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }
    
    int len = str_len(text);
    if (len == 0) {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }
    
    int result_len = len * times;
    char* result = malloc(result_len + 1);
    if (!result) return NULL;
    
    char* dest = result;
    for (int i = 0; i < times; i++) {
        for (int j = 0; j < len; j++) {
            dest[j] = text[j];
        }
        dest += len;
    }
    *dest = '\0';
    
    return result;
}

/**
 * @brief Join an array of strings with a separator
 * @param str NULL-terminated array of strings
 * @param sep Separator character
 * @return Newly allocated joined string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_join_n(char** str, char sep) {
    if (!str) return NULL;
    
    // First pass: calculate total length
    int total_len = 0;
    int count = 0;
    for (char** ptr = str; *ptr; ptr++) {
        total_len += str_len(*ptr);
        count++;
    }
    
    if (count == 0) {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }
    
    // Add space for separators
    total_len += (count - 1);
    
    // Allocate and build result
    char* result = malloc(total_len + 1);
    if (!result) return NULL;
    
    char* dest = result;
    for (int i = 0; i < count; i++) {
        int part_len = str_len(str[i]);
        
        // Copy current string
        for (int j = 0; j < part_len; j++) {
            *dest++ = str[i][j];
        }
        
        // Add separator if not the last string
        if (i < count - 1) *dest++ = sep;
    }
    *dest = '\0';
    
    return result;
}

/**
 * @brief Create a substring from a string
 * @param text Input string
 * @param start Starting index (inclusive)
 * @param length Number of characters to include
 * @return Newly allocated substring, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_substring_n(const char* text, int start, int length) {
    if (!text) return NULL;
    
    int text_len = str_len(text);
    
    // Validate parameters
    if (start < 0) start = 0;
    if (start >= text_len) {
        char* empty = malloc(1);
        if (empty) *empty = '\0';
        return empty;
    }
    
    // Adjust length if needed
    if (length < 0 || start + length > text_len) {
        length = text_len - start;
    }
    
    // Allocate and copy substring
    char* result = malloc(length + 1);
    if (!result) return NULL;
    
    for (int i = 0; i < length; i++) {
        result[i] = text[start + i];
    }
    result[length] = '\0';
    
    return result;
}

/**
 * @brief Replace all occurrences of a character in a string
 * @param text String to modify
 * @param find Character to find
 * @param replace Character to replace with
 * @return Pointer to the modified string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_replace_char(char* text, char find, char replace) {
    if (!text) return NULL;
    
    char* ptr = text;
    while (*ptr) {
        if (*ptr == find) {
            *ptr = replace;
        }
        ptr++;
    }
    
    return text;
}

/**
 * @brief Create a new string with all occurrences of a character replaced
 * @param text String to process
 * @param find Character to find
 * @param replace Character to replace with
 * @return Newly allocated string with replacements, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_replace_char_n(const char* text, char find, char replace) {
    if (!text) return NULL;
    
    int len = str_len(text);
    char* result = malloc(len + 1);
    if (!result) return NULL;
    
    const char* src = text;
    char* dest = result;
    
    while (*src) {
        *dest++ = (*src == find) ? replace : *src;
        src++;
    }
    *dest = '\0';
    
    return result;
}