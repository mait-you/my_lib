# LIBFT

## Overview

**LIBFT** is a custom C library developed to replicate and extend standard C library functionalities. It includes implementations of various functions for character checks, string manipulation, memory management, and more. This library serves as a foundational toolkit for C projects, especially in educational settings like the 42 School curriculum.

## Features

- **Character Checks**: Functions to assess character types (e.g., `ft_isalpha`, `ft_isdigit`).
- **String Manipulation**: Utilities for string operations such as copying, concatenation, and searching.
- **Memory Management**: Functions like `ft_memset`, `ft_memcpy`, and custom memory allocation with `ft_safe_allocate`.
- **Linked List Operations**: Creation and manipulation of singly linked lists.
- **Output Functions**: Custom implementations like `ft_printf` for formatted output.
- **Line Reading**: `get_next_line` function to read input line by line.

## Usage

Include the header file in your C source files:

```c
#include "libft.h"
```

Compile your project with the `libft.a` archive:

```bash
gcc your_program.c -L. -lft -o your_program
```

## Project Structure

- `Character_Checks/`: Functions for character evaluation.
- `String_Manipulation/`: String operation utilities.
- `Memory_Management/`: Memory handling functions.
- `Linked_List/`: Linked list data structures and operations.
- `Output_Functions/`: Custom output functionalities.
- `ft_printf/`: Implementation of the `printf` function.
- `ft_safe_allocate/`: Safe memory allocation routines.
- `get_next_line/`: Function to read input line by line.
- `libft.h`: Header file containing function prototypes.
- `Makefile`: Build script to compile the library.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements or bug fixes.

## Acknowledgments

This project is part of the 42 School curriculum and follows its licensing requirements.
