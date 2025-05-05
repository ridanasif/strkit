/**
 * @file strkit.h
 * @brief Header file for the StrKit string manipulation library
 * @author Ridan Muhammed Asif
 * @date May 5, 2025
 * @version 1.0.0
 * 
 * StrKit is a lightweight C library for common string manipulation operations.
 * It provides both in-place functions (which modify the original string) and
 * non-destructive functions (which return new strings).
 */

#ifndef STRKIT_H
#define STRKIT_H

/**
 * @brief Calculate the length of a string
 * @param text Input string
 * @return Length of the string, 0 if NULL
 */
int str_len(const char* text);

/**
 * @brief Reverse a string in-place
 * @param text String to reverse
 * @return Pointer to the reversed string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_reverse(char* text);

/**
 * @brief Create a new reversed copy of a string
 * @param text String to reverse
 * @return Newly allocated reversed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_reverse_n(const char* text);

/**
 * @brief Capitalize the first character of a string in-place
 * @param text String to capitalize
 * @return Pointer to the capitalized string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_capitalize(char* text);

/**
 * @brief Create a new string with the first character capitalized
 * @param text String to capitalize
 * @return Newly allocated capitalized string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_capitalize_n(const char* text);

/**
 * @brief Convert a string to uppercase in-place
 * @param text String to convert
 * @return Pointer to the uppercase string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_uppercase(char* text);

/**
 * @brief Create a new string converted to uppercase
 * @param text String to convert
 * @return Newly allocated uppercase string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_uppercase_n(const char* text);

/**
 * @brief Convert a string to lowercase in-place
 * @param text String to convert
 * @return Pointer to the lowercase string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_lowercase(char* text);

/**
 * @brief Create a new string converted to lowercase
 * @param text String to convert
 * @return Newly allocated lowercase string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_lowercase_n(const char* text);

/**
 * @brief Convert a string to title case in-place (capitalize first letter of each word)
 * @param text String to convert
 * @return Pointer to the title case string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_title(char* text);

/**
 * @brief Create a new string converted to title case
 * @param text String to convert
 * @return Newly allocated title case string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_title_n(const char* text);

/**
 * @brief Split a string by delimiter
 * @param text String to split
 * @param delimiter Character to split by
 * @return NULL-terminated array of strings, or NULL on failure
 * @note Caller is responsible for freeing both the array and each string
 *       using free_strs()
 */
char** str_split(const char *text, char delimiter);

/**
 * @brief Free memory allocated by str_split
 * @param result Array of strings to free
 */
void free_strs(char **result);

/**
 * @brief Concatenate two strings into a new string
 * @param s1 First string
 * @param s2 Second string
 * @return Newly allocated concatenated string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_concat_n(const char* s1, const char* s2);

/**
 * @brief Check if a string contains only numeric characters
 * @param s String to check
 * @return 1 if string is numeric, 0 otherwise
 */
int str_is_numeric(const char* s);

/**
 * @brief Check if a string contains only alphabetic characters
 * @param s String to check
 * @return 1 if string is alphabetic, 0 otherwise
 */
int str_is_alpha(const char* s);

/**
 * @brief Check if a string contains only alphanumeric characters
 * @param s String to check
 * @return 1 if string is alphanumeric, 0 otherwise
 */
int str_is_alpha_numeric(const char* s);

/**
 * @brief Check if two strings are equal
 * @param s1 First string
 * @param s2 Second string
 * @return 1 if strings are equal, 0 otherwise
 */
int str_is_equal(const char* s1, const char* s2);

/**
 * @brief Check if a string is a palindrome
 * @param text String to check
 * @return 1 if string is a palindrome, 0 otherwise
 */
int str_is_palindrome(const char* text);

/**
 * @brief Trim whitespace from both ends of a string in-place
 * @param s String to trim
 * @return Pointer to the trimmed string within the original memory,
 *         or NULL if input was NULL
 * @note This function modifies the original string
 * @warning The returned pointer may differ from the input pointer
 */
char* str_trim(char* s);

/**
 * @brief Create a new trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_trim_n(const char* s);

/**
 * @brief Trim whitespace from the left side of a string in-place
 * @param s String to trim
 * @return Pointer to the left-trimmed string, or NULL if input was NULL
 * @note This function returns a pointer to the first non-whitespace character
 * @warning The returned pointer may differ from the input pointer
 */
char* str_ltrim(char* s);

/**
 * @brief Create a new left-trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated left-trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_ltrim_n(const char* s);

/**
 * @brief Trim whitespace from the right side of a string in-place
 * @param s String to trim
 * @return Pointer to the trimmed string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_rtrim(char* s);

/**
 * @brief Create a new right-trimmed copy of a string
 * @param s String to trim
 * @return Newly allocated right-trimmed string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_rtrim_n(const char* s);

/**
 * @brief Find the index of a character in a string
 * @param search Character to find
 * @param text String to search in
 * @return Index of first occurrence, or -1 if not found
 */
int index_of(const char search, const char* text);

/**
 * @brief Find the index of a substring in a string
 * @param text String to search in
 * @param substring Substring to find
 * @return Index of first occurrence, or -1 if not found
 */
int index_of_str(const char* text, const char* substring);

/**
 * @brief Check if a string contains a substring
 * @param text String to search in
 * @param substring Substring to find
 * @return 1 if substring is found, 0 otherwise
 */
int str_contains(const char *text, const char *substring);

/**
 * @brief Get the first character of a string
 * @param text Input string
 * @return First character, or '\0' if string is empty or NULL
 */
char str_first_char(const char* text);

/**
 * @brief Get the last character of a string
 * @param text Input string
 * @return Last character, or '\0' if string is empty or NULL
 */
char str_last_char(const char* text);

/**
 * @brief Get the character at a specific index
 * @param text Input string
 * @param index Position to get character from
 * @return Character at index, or '\0' if index is out of bounds
 */
char str_char_at(const char* text, int index);

/**
 * @brief Create a new string by repeating a string multiple times
 * @param text String to repeat
 * @param times Number of times to repeat
 * @return Newly allocated repeated string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_repeat_n(const char* text, int times);

/**
 * @brief Join an array of strings with a separator
 * @param str NULL-terminated array of strings
 * @param sep Separator character
 * @return Newly allocated joined string, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_join_n(char** str, char sep);

/**
 * @brief Create a substring from a string
 * @param text Input string
 * @param start Starting index (inclusive)
 * @param length Number of characters to include
 * @return Newly allocated substring, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_substring_n(const char* text, int start, int length);

/**
 * @brief Replace all occurrences of a character in a string
 * @param text String to modify
 * @param find Character to find
 * @param replace Character to replace with
 * @return Pointer to the modified string, or NULL if input was NULL
 * @note This function modifies the original string
 */
char* str_replace_char(char* text, char find, char replace);

/**
 * @brief Create a new string with all occurrences of a character replaced
 * @param text String to process
 * @param find Character to find
 * @param replace Character to replace with
 * @return Newly allocated string with replacements, or NULL on failure
 * @note Caller is responsible for freeing the returned string
 */
char* str_replace_char_n(const char* text, char find, char replace);

#endif /* STRKIT_H */