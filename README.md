# StrKit

StrKit is a lightweight C library for common string manipulation operations. It provides both in-place functions (which modify the original string) and non-destructive functions (which return new strings).

## Features

- Core string operations (length, reverse, concatenate)
- Case manipulation (uppercase, lowercase, title case, capitalize)
- String validation (numeric, alphabetic, alphanumeric, palindrome)
- String trimming (left, right, both)
- String searching (index of, contains)
- Character operations (first, last, at position)
- String creation (substring, repeat)
- String splitting and joining

## Repository Structure

```
strkit/
├── include/
│   └── strkit.h         # Header file with function declarations
├── src/
│   └── strkit.c         # Source file with function implementations
├── docs/
│   └── API.md           # Detailed API documentation
├── README.md            # This file
├── LICENSE              # License information
└── .gitignore           # Git ignore file
```

## How to Use

Using StrKit in your project is simple! Just follow these steps:

1. **Include the library in your project**

   Simply copy the two necessary files into your project:

   - Copy `include/strkit.h` to your project's include directory
   - Copy `src/strkit.c` to your project's source directory

2. **Include the header in your code**

   ```c
   #include "strkit.h"
   ```

3. **Compile your project**

   When compiling your project, make sure to include the strkit.c file:

   ```bash
   gcc your_program.c src/strkit.c -Iinclude -o your_program
   ```

That's it! No need for complex compilation steps or library builds.

## Example Usage

```c
#include <stdio.h>
#include <stdlib.h>
#include "strkit.h"

int main() {
    // String length
    const char* text = "Hello, World!";
    printf("Length: %d\n", str_len(text));  // Output: 13

    // String reversal (non-destructive)
    char* reversed = str_reverse_n(text);
    printf("Reversed: %s\n", reversed);  // Output: !dlroW ,olleH
    free(reversed);

    // Uppercase conversion (non-destructive)
    char* uppercase = str_uppercase_n(text);
    printf("Uppercase: %s\n", uppercase);  // Output: HELLO, WORLD!
    free(uppercase);

    // String splitting
    char** parts = str_split(text, ',');
    printf("First part: %s\n", parts[0]);  // Output: Hello
    printf("Second part: %s\n", parts[1]);  // Output:  World!
    free_strs(parts);

    // Check if palindrome
    printf("Is palindrome: %d\n", str_is_palindrome("radar"));  // Output: 1
    printf("Is palindrome: %d\n", str_is_palindrome(text));     // Output: 0

    return 0;
}
```

## API Documentation

For detailed API documentation, see [docs/API.md](docs/API.md).

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

Ridan Muhammed Asif

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request
