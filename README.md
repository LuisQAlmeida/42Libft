# 42 Libft

A custom C utility library developed as part of the **42 Common Core** curriculum.

This repository reimplements a selection of standard C library functions, includes the bonus linked-list utilities, and also contains reusable implementations from later 42 projects such as [`ft_printf`](https://github.com/LuisQAlmeida/42ft_printf) and [`get_next_line`](https://github.com/LuisQAlmeida/42get_next_line).

The goal of this project is to keep Libft not only functional, but also clean, documented, tested, and ready to reuse in future C projects such as [`minishell`](https://github.com/LuisQAlmeida/42Minishell).

---

## Table of Contents

- [About](#about)
- [Project Goals](#project-goals)
- [Repository Structure](#repository-structure)
- [Included Functions](#included-functions)
- [Build Instructions](#build-instructions)
- [Automated Tests](#automated-tests)
- [Memory Checking with Valgrind](#memory-checking-with-valgrind)
- [Doxygen Documentation](#doxygen-documentation)
- [Using Libft in Other Projects](#using-libft-in-other-projects)
- [Quality Checklist](#quality-checklist)
- [Notes](#notes)
- [License](#license)

---

## About

`Libft` is one of the first projects in the 42 curriculum. It focuses on rebuilding essential C functions from scratch while learning about:

- memory management;
- pointer manipulation;
- string handling;
- file descriptor output;
- linked lists;
- static libraries;
- modular C project organization.

This version includes:

- mandatory Libft functions;
- bonus linked-list functions;
- `ft_printf`;
- `get_next_line`;
- Doxygen-style documentation in `libft.h`;
- automated tests;
- Valgrind memory checks.

---

## Project Goals

The main goals of this repository are:

- reimplement essential C library behavior;
- understand memory allocation, ownership, and cleanup;
- create reusable utilities for later 42 projects;
- test edge cases and common failure scenarios;
- detect leaks, invalid reads/writes, and double frees;
- keep the codebase professional and portfolio-ready.

This library is intended to be reused in projects such as:

- [`ft_printf`](https://github.com/LuisQAlmeida/42ft_printf);
- [`get_next_line`](https://github.com/LuisQAlmeida/42get_next_line);
- `pipex`;
- [`push_swap`](https://github.com/LuisQAlmeida/42push_swap);
- [`minitalk`](https://github.com/LuisQAlmeida/42minitalk);
- [`so_long`](https://github.com/LuisQAlmeida/42so_long);
- [`minishell`](https://github.com/LuisQAlmeida/42Minishell).

---

## Repository Structure

```text
42Libft/
├── libft/
│   ├── ft_*.c
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   ├── libft.h
│   └── Makefile
├── tests/
│   ├── tests.c
│   └── run_tests.sh
├── LICENSE
└── README.md
```

### `libft/`

Contains the actual library source code, the public header, and the Makefile used to build `libft.a`.

### `tests/`

Contains the automated test program and the shell script used to build, test, run Valgrind, and clean the project.

---

## Included Functions

### Character Checks and Conversion

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic. |
| `ft_isdigit` | Checks whether a character is a digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII table. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase character to uppercase. |
| `ft_tolower` | Converts an uppercase character to lowercase. |

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset` | Fills memory with a byte value. |
| `ft_bzero` | Sets memory to zero. |
| `ft_memcpy` | Copies memory from source to destination. |
| `ft_memmove` | Copies memory safely when areas overlap. |
| `ft_memchr` | Searches memory for a byte value. |
| `ft_memcmp` | Compares two memory areas. |
| `ft_calloc` | Allocates and zero-initializes memory. |

### String Functions

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strlcpy` | Copies a string into a sized buffer. |
| `ft_strlcat` | Appends a string into a sized buffer. |
| `ft_strchr` | Finds the first occurrence of a character. |
| `ft_strrchr` | Finds the last occurrence of a character. |
| `ft_strncmp` | Compares two strings up to `n` characters. |
| `ft_strnstr` | Finds a substring within a limited range. |
| `ft_strdup` | Duplicates a string into newly allocated memory. |
| `ft_substr` | Extracts a substring into newly allocated memory. |
| `ft_strjoin` | Joins two strings into newly allocated memory. |
| `ft_strtrim` | Trims characters from both ends of a string. |
| `ft_split` | Splits a string into a NULL-terminated array. |
| `ft_strmapi` | Creates a new string by mapping a function over another string. |
| `ft_striteri` | Applies a function to each character of a string in place. |

### Conversion Functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an integer. |
| `ft_itoa` | Converts an integer to a newly allocated string. |

### File Descriptor Output

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Linked List Bonus Functions

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node. |
| `ft_lstadd_front` | Adds a node to the front of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Deletes a single node. |
| `ft_lstclear` | Deletes and clears an entire list. |
| `ft_lstiter` | Applies a function to each node content. |
| `ft_lstmap` | Creates a new list by mapping a function over another list. |

### ft_printf

This repository includes a custom implementation of `printf`.

Supported conversions:

| Conversion | Description |
|---|---|
| `%c` | Character. |
| `%s` | String. |
| `%p` | Pointer address. |
| `%d` | Signed decimal integer. |
| `%i` | Signed decimal integer. |
| `%u` | Unsigned decimal integer. |
| `%x` | Lowercase hexadecimal. |
| `%X` | Uppercase hexadecimal. |
| `%%` | Percent sign. |

### get_next_line

This repository includes a `get_next_line` implementation:

```c
char	*get_next_line(int fd);
```

It reads one line at a time from a file descriptor and returns a newly allocated string.

The caller is responsible for freeing the returned line.

Example usage:

```c
char	*line;

line = get_next_line(fd);
while (line)
{
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
}
```

---

## Build Instructions

Go into the `libft` directory:

```bash
cd libft
```

Build the mandatory library:

```bash
make
```

Build the bonus functions as well:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove object files and the static library:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

The build produces:

```text
libft.a
```

---

## Automated Tests

This repository includes an automated test runner inside `tests/`.

From the repository root:

```bash
cd tests
chmod +x run_tests.sh
./run_tests.sh
```

The runner performs the following steps:

1. Runs `make fclean` inside `libft/`.
2. Builds the mandatory library with `make`.
3. Builds the bonus functions with `make bonus`.
4. Compiles `tests.c` against `libft/libft.a`.
5. Runs all unit tests.
6. Runs Valgrind when available.
7. Removes generated test files.
8. Runs `make fclean` again to leave `libft/` clean.

### Current Test Coverage

The test suite covers:

- character functions;
- memory functions;
- string functions;
- string allocation functions;
- `ft_split` ownership and cleanup;
- `ft_strmapi`;
- `ft_striteri`;
- conversion functions;
- file descriptor output functions;
- linked-list bonus functions;
- `ft_printf`;
- `get_next_line`;
- edge cases;
- NULL handling where applicable;
- allocation and cleanup behavior;
- Valgrind leak detection.

Example successful result:

```text
105/105 tests passed
All tests passed.
```

---

## Memory Checking with Valgrind

The test runner automatically runs Valgrind if it is installed.

Expected successful output:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors
```

You can also run the tests manually:

```bash
cd libft
make bonus
cd ../tests
cc -Wall -Wextra -Werror -I../libft tests.c ../libft/libft.a -o tests
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./tests
```

---

## Doxygen Documentation

The public API in `libft.h` is documented using Doxygen-style comments.

The documentation explains:

- function purpose;
- parameters;
- return values;
- allocation behavior;
- ownership rules;
- caller responsibilities.

To generate HTML documentation, install Doxygen and run from the `libft/` directory:

```bash
doxygen -g
doxygen Doxyfile
```

By default, Doxygen generates documentation in:

```text
html/
```

Open:

```text
html/index.html
```

Recommended `.gitignore` entries for generated documentation:

```gitignore
html/
latex/
Doxyfile
```

A custom `Doxyfile` can be added later if generated documentation should become part of the repository workflow.

---

## Using Libft in Other Projects

To reuse this library in another C project, copy the `libft/` directory into the target repository.

Example structure:

```text
my_project/
├── libft/
│   ├── libft.h
│   ├── Makefile
│   └── ...
├── include/
├── src/
└── Makefile
```

Example Makefile integration:

```make
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
```

Include the header in source files:

```c
#include "libft.h"
```

---

## Quality Checklist

This repository aims to maintain the following standards:

- compiles with `-Wall -Wextra -Werror`;
- static library builds with `make`;
- bonus functions build with `make bonus`;
- automated tests pass;
- Valgrind reports no leaks or memory errors in the automated test suite;
- public API is documented in `libft.h`;
- tests are kept separate from production source files;
- generated files are cleaned after test execution;
- library is ready to be reused in later 42 projects.

---

## Notes

This project follows the constraints and learning objectives of the 42 curriculum.

Some functions intentionally mimic standard C library behavior, including undefined behavior in cases where the original function would also be undefined.

The automated tests are designed to catch common bugs, edge cases, memory leaks, and ownership mistakes, but they do not replace careful code review.

---

## License

See the `LICENSE` file for licensing information.
