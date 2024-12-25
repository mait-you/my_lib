# LIBFT

This project is involves recreating essential C library functions. It aims to reinforce a deep understanding of low-level programming and memory manipulation in C.

## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Functions](#functions)
6. [Contributing](#contributing)

## Overview

`libft` is a custom library written in C that includes various standard library functions and additional utilities. This project is designed to strengthen skills in C programming by developing commonly used functions from scratch, enabling a better understanding of how they work under the hood.

## Features

- A collection of recreated C standard library functions.
- Helper functions for string manipulation, memory management, and linked list operations.
- Built with memory safety and efficiency in mind.
- Foundation for many C-based projects in the 42 curriculum.

## Installation

To compile `libft`, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/libft.git
   cd libft
   ```
2. Compile the library:

  ```bash
   make
  ```
  This will generate the libft.a file, which can be linked to your C projects.

## Usage

To use libft in your project, include it as follows:

  1. Add the libft.a file to your project's directory.

  2. Link the library during compilation. For example:

  ```bashå
    gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
  ```
  3. Include the libft.h header in your code to access the functions:
  ```c
    #include "libft.h"
  ```

## Functions

### String Manipulation

- **`ft_strlen`**: Calculate the length of a string.
- **`ft_strcpy`**: Copy a string to another location.
- **`ft_strcat`**: Concatenate two strings.
- **`ft_strchr`**: Find the first occurrence of a character in a string.
- **`ft_strrchr`**: Find the last occurrence of a character in a string.
- **`ft_strncmp`**: Compare two strings up to `n` characters.
- **`ft_strnstr`**: Find the first occurrence of a substring in a string.
- **`ft_strdup`**: Duplicate a string.

### Memory Management

- **`ft_memset`**: Fill a memory area with a constant byte.
- **`ft_memcpy`**: Copy data from one memory area to another.
- **`ft_memmove`**: Move a block of memory, handling overlapping areas.
- **`ft_bzero`**: Set all bytes in a memory area to zero.
- **`ft_memchr`**: Find the first occurrence of a byte in a memory area.
- **`ft_memcmp`**: Compare two memory areas.
- **`ft_calloc`**: Allocate memory and set it to zero.

### Character Checks

- **`ft_isalpha`**: Check if a character is alphabetic.
- **`ft_isdigit`**: Check if a character is numeric.
- **`ft_isalnum`**: Check if a character is alphanumeric.
- **`ft_isascii`**: Check if a character is an ASCII character.
- **`ft_isprint`**: Check if a character is printable.

### String Transformations

- **`ft_toupper`**: Convert a character to uppercase.
- **`ft_tolower`**: Convert a character to lowercase.
- **`ft_strtrim`**: Trim characters from both ends of a string.
- **`ft_substr`**: Extract a substring from a string.
- **`ft_strjoin`**: Concatenate two strings.
- **`ft_itoa`**: Convert an integer to a string.
- **`ft_strmapi`**: Apply a function to each character of a string and return a new string.
- **`ft_striteri`**: Apply a function to each character of a string with its index.
- **`ft_atoi`**: Convert a string representing a number into an integer.
- **`ft_split`**:  Split a string into parts based on a specified delimiter.
  
### Output Functions

- **`ft_putchar_fd`**: Output a character to a file descriptor.
- **`ft_putstr_fd`**: Output a string to a file descriptor.
- **`ft_putendl_fd`**: Output a string followed by a newline to a file descriptor.
- **`ft_putnbr_fd`**: Output an integer to a file descriptor.

### Linked List Utilities (Bonus)

- **`ft_lstnew`**: Create a new linked list node.
- **`ft_lstadd_front`**: Add a new node at the front of the linked list.
- **`ft_lstsize`**: Get the size of the linked list.
- **`ft_lstlast`**: Get the last node of the linked list.
- **`ft_lstadd_back`**: Add a new node at the end of the linked list.
- **`ft_lstdelone`**: Delete a single node from the linked list.
- **`ft_lstclear`**: Clear all nodes in the linked list.
- **`ft_lstiter`**: Apply a function to each node in the linked list.
- **`ft_lstmap`**: Create a new linked list by applying a function to each node.

Add any additional functions you've implemented here for easy reference.

---

## Contributing

Contributions are welcome! If you wish to contribute:

1. **Fork** the repository.
2. Make your changes on a new **branch**.
3. Submit a **pull request** with a clear description of your changes.

Contributions can include code optimizations, new utility functions, bug fixes, and documentation improvements.

---
