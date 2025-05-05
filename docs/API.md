# StrKit API Documentation

**Author:** Ridan Muhammed Asif  
**Version:** 1.0.0  
**Date:** May 5, 2025

StrKit is a lightweight C library for common string manipulation operations. It provides both in-place functions (which modify the original string) and non-destructive functions (which return new strings).

## Table of Contents

- [String Information](#string-information)
- [String Transformation](#string-transformation)
- [String Case Manipulation](#string-case-manipulation)
- [String Splitting and Joining](#string-splitting-and-joining)
- [String Validation](#string-validation)
- [String Trimming](#string-trimming)
- [String Searching](#string-searching)
- [Character Operations](#character-operations)
- [String Creation](#string-creation)

## String Information

### `int str_len(const char* text)`

Calculate the length of a string.

**Parameters:**

- `text`: Input string

**Returns:**

- Length of the string, 0 if NULL

## String Transformation

### `char* str_reverse(char* text)`

Reverse a string in-place.

**Parameters:**

- `text`: String to reverse

**Returns:**

- Pointer to the reversed string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_reverse_n(const char* text)`

Create a new reversed copy of a string.

**Parameters:**

- `text`: String to reverse

**Returns:**

- Newly allocated reversed string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_replace_char(char* text, char find, char replace)`

Replace all occurrences of a character in a string.

**Parameters:**

- `text`: String to modify
- `find`: Character to find
- `replace`: Character to replace with

**Returns:**

- Pointer to the modified string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_replace_char_n(const char* text, char find, char replace)`

Create a new string with all occurrences of a character replaced.

**Parameters:**

- `text`: String to process
- `find`: Character to find
- `replace`: Character to replace with

**Returns:**

- Newly allocated string with replacements, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

## String Case Manipulation

### `char* str_capitalize(char* text)`

Capitalize the first character of a string in-place.

**Parameters:**

- `text`: String to capitalize

**Returns:**

- Pointer to the capitalized string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_capitalize_n(const char* text)`

Create a new string with the first character capitalized.

**Parameters:**

- `text`: String to capitalize

**Returns:**

- Newly allocated capitalized string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_uppercase(char* text)`

Convert a string to uppercase in-place.

**Parameters:**

- `text`: String to convert

**Returns:**

- Pointer to the uppercase string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_uppercase_n(const char* text)`

Create a new string converted to uppercase.

**Parameters:**

- `text`: String to convert

**Returns:**

- Newly allocated uppercase string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_lowercase(char* text)`

Convert a string to lowercase in-place.

**Parameters:**

- `text`: String to convert

**Returns:**

- Pointer to the lowercase string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_lowercase_n(const char* text)`

Create a new string converted to lowercase.

**Parameters:**

- `text`: String to convert

**Returns:**

- Newly allocated lowercase string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_title(char* text)`

Convert a string to title case in-place (capitalize first letter of each word).

**Parameters:**

- `text`: String to convert

**Returns:**

- Pointer to the title case string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_title_n(const char* text)`

Create a new string converted to title case.

**Parameters:**

- `text`: String to convert

**Returns:**

- Newly allocated title case string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

## String Splitting and Joining

### `char** str_split(const char *text, char delimiter)`

Split a string by delimiter.

**Parameters:**

- `text`: String to split
- `delimiter`: Character to split by

**Returns:**

- NULL-terminated array of strings, or NULL on failure

**Note:** Caller is responsible for freeing both the array and each string using `free_strs()`.

### `void free_strs(char **result)`

Free memory allocated by `str_split`.

**Parameters:**

- `result`: Array of strings to free

### `char* str_concat_n(const char* s1, const char* s2)`

Concatenate two strings into a new string.

**Parameters:**

- `s1`: First string
- `s2`: Second string

**Returns:**

- Newly allocated concatenated string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_join_n(char** str, char sep)`

Join an array of strings with a separator.

**Parameters:**

- `str`: NULL-terminated array of strings
- `sep`: Separator character

**Returns:**

- Newly allocated joined string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

## String Validation

### `int str_is_numeric(const char* s)`

Check if a string contains only numeric characters.

**Parameters:**

- `s`: String to check

**Returns:**

- 1 if string is numeric, 0 otherwise

### `int str_is_alpha(const char* s)`

Check if a string contains only alphabetic characters.

**Parameters:**

- `s`: String to check

**Returns:**

- 1 if string is alphabetic, 0 otherwise

### `int str_is_alpha_numeric(const char* s)`

Check if a string contains only alphanumeric characters.

**Parameters:**

- `s`: String to check

**Returns:**

- 1 if string is alphanumeric, 0 otherwise

### `int str_is_equal(const char* s1, const char* s2)`

Check if two strings are equal.

**Parameters:**

- `s1`: First string
- `s2`: Second string

**Returns:**

- 1 if strings are equal, 0 otherwise

### `int str_is_palindrome(const char* text)`

Check if a string is a palindrome.

**Parameters:**

- `text`: String to check

**Returns:**

- 1 if string is a palindrome, 0 otherwise

## String Trimming

### `char* str_trim(char* s)`

Trim whitespace from both ends of a string in-place.

**Parameters:**

- `s`: String to trim

**Returns:**

- Pointer to the trimmed string within the original memory, or NULL if input was NULL

**Notes:**

- This function modifies the original string
- The returned pointer may differ from the input pointer

### `char* str_trim_n(const char* s)`

Create a new trimmed copy of a string.

**Parameters:**

- `s`: String to trim

**Returns:**

- Newly allocated trimmed string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_ltrim(char* s)`

Trim whitespace from the left side of a string in-place.

**Parameters:**

- `s`: String to trim

**Returns:**

- Pointer to the left-trimmed string, or NULL if input was NULL

**Notes:**

- This function returns a pointer to the first non-whitespace character
- The returned pointer may differ from the input pointer

### `char* str_ltrim_n(const char* s)`

Create a new left-trimmed copy of a string.

**Parameters:**

- `s`: String to trim

**Returns:**

- Newly allocated left-trimmed string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_rtrim(char* s)`

Trim whitespace from the right side of a string in-place.

**Parameters:**

- `s`: String to trim

**Returns:**

- Pointer to the trimmed string, or NULL if input was NULL

**Note:** This function modifies the original string.

### `char* str_rtrim_n(const char* s)`

Create a new right-trimmed copy of a string.

**Parameters:**

- `s`: String to trim

**Returns:**

- Newly allocated right-trimmed string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

## String Searching

### `int index_of(const char search, const char* text)`

Find the index of a character in a string.

**Parameters:**

- `search`: Character to find
- `text`: String to search in

**Returns:**

- Index of first occurrence, or -1 if not found

### `int index_of_str(const char* text, const char* substring)`

Find the index of a substring in a string.

**Parameters:**

- `text`: String to search in
- `substring`: Substring to find

**Returns:**

- Index of first occurrence, or -1 if not found

### `int str_contains(const char *text, const char *substring)`

Check if a string contains a substring.

**Parameters:**

- `text`: String to search in
- `substring`: Substring to find

**Returns:**

- 1 if substring is found, 0 otherwise

## Character Operations

### `char str_first_char(const char* text)`

Get the first character of a string.

**Parameters:**

- `text`: Input string

**Returns:**

- First character, or '\0' if string is empty or NULL

### `char str_last_char(const char* text)`

Get the last character of a string.

**Parameters:**

- `text`: Input string

**Returns:**

- Last character, or '\0' if string is empty or NULL

### `char str_char_at(const char* text, int index)`

Get the character at a specific index.

**Parameters:**

- `text`: Input string
- `index`: Position to get character from

**Returns:**

- Character at index, or '\0' if index is out of bounds

## String Creation

### `char* str_repeat_n(const char* text, int times)`

Create a new string by repeating a string multiple times.

**Parameters:**

- `text`: String to repeat
- `times`: Number of times to repeat

**Returns:**

- Newly allocated repeated string, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.

### `char* str_substring_n(const char* text, int start, int length)`

Create a substring from a string.

**Parameters:**

- `text`: Input string
- `start`: Starting index (inclusive)
- `length`: Number of characters to include

**Returns:**

- Newly allocated substring, or NULL on failure

**Note:** Caller is responsible for freeing the returned string.
