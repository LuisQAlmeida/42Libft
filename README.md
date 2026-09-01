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
- [Continuous Integration](#continuous-integration)
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
├── .github/
│   └── workflows/
│       └── ci.yml
├── libft/
│   ├── ft_*.c
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   ├── libft.h
│   └── Makefile
├── tests/
│   ├── tests.c
│   └── run_tests.sh
├── .gitignore
├── Doxyfile
├── LICENSE
└── README.md
```

### `libft/`

Contains the buildable C library: implementation source files, the public
header, and the Makefile used to produce `libft.a`.

### `tests/`

Contains the repository-controlled automated test suite and runner used to
build the library, execute the tests, run Valgrind, and clean generated
artefacts.

### `.github/workflows/ci.yml`

Defines the GitHub Actions workflow that validates reference GCC builds,
Clang compiler-diversity builds, incremental build behaviour, automated
tests, Valgrind, Doxygen generation, and repository cleanliness.

### `Doxyfile`

Defines the canonical repository-controlled configuration used to generate
and validate the Libft API documentation.

Generated build artefacts, test output, and Doxygen HTML are intentionally
excluded from this maintained repository structure.

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

## Continuous Integration

GitHub Actions validates the maintained build and test contracts on pull
requests targeting `main` and on pushes to `main`.

The workflow runs on Ubuntu 24.04 and contains two jobs:

### `CI / build`

The reference job validates:

- the normal GCC build;
- creation of `libft.a`;
- incremental `make` behaviour;
- rebuild propagation after a `libft.h` change;
- bonus compilation and expected linked-list symbols;
- incremental `make bonus` behaviour;
- the `re` and `fclean` targets;
- the repository-controlled `tests/run_tests.sh` suite;
- all 105 automated tests;
- Valgrind memory validation;
- removal of generated build artefacts;
- repository cleanliness after validation.

Valgrind is installed explicitly in CI, so the memory-safety phase of the
test runner is required rather than optional in the reference job.

### `CI / quality`

The quality job validates the maintained build interface with Clang,
including mandatory and bonus builds, incremental archive behaviour,
`re`, and cleanup.

It also installs Doxygen and validates the repository-controlled API
documentation by generating HTML from `Doxyfile`, checking the expected
output and representative public API entries, and removing the generated
documentation before the final repository-cleanliness check.

The workflow uses an immutable reviewed `actions/checkout` revision and
does not persist repository credentials.

---

## Doxygen Documentation

The public API in `libft/libft.h` is documented using Doxygen-style comments.

The documentation explains:

- function purpose;
- parameters;
- return values;
- allocation behavior;
- ownership rules;
- caller responsibilities;
- the public `t_list` type and its members.

The repository tracks a canonical `Doxyfile`, so documentation generation
does not depend on a locally generated configuration.

Install Doxygen on Ubuntu if required:

```bash
sudo apt install doxygen
```

Then generate the documentation from the repository root:

```bash
doxygen Doxyfile
```

Generated HTML is written to:

```text
docs/html/
```

The main entry point is:

```text
docs/html/index.html
```

Generated documentation is intentionally ignored by Git, while the
`Doxyfile` itself is version-controlled as part of the maintained
documentation contract.

The configuration treats Doxygen warnings as validation failures. The
`CI / quality` job installs Doxygen, generates the documentation, verifies
the expected HTML output and representative API entries, removes the
generated files, and checks repository cleanliness afterward.

---

## Using Libft in Other Projects

Libft can be integrated into another C project in several valid ways.
The appropriate model depends on how much dependency provenance,
repository independence, and update automation the consumer requires.

For maintained portfolio repositories, the recommended workflow is a
**Git submodule pinned to an explicit reviewed revision**.

Manual vendoring remains a valid simpler alternative, while Git subtree
provides a third option for projects that want dependency source stored
directly in the consumer repository while retaining an upstream
relationship.

### Choosing an integration model

| Property | Pinned Git submodule | Vendored copy | Git subtree |
|---|---|---|---|
| Dependency revision representation | Exact Gitlink | Manual provenance | Imported Git history |
| Source stored as ordinary files in parent repository | No | Yes | Yes |
| Additional clone initialization required | Yes | No | No |
| Upstream update path retained | Yes | Manual | Yes |
| Controlled upstream updates | Yes | Manual | Yes |
| Workflow complexity | Moderate | Low | Higher |
| Portfolio recommendation | **Recommended** | Supported | Optional |

### Pinned Git submodule — recommended

The canonical Libft repository is:

```text
git@github.com:LuisQAlmeida/42Libft.git
```

A submodule keeps Libft as an independent Git repository while the
consumer records the exact Libft commit it was validated against.

A recommended consumer layout is:

```text
project/
├── external/
│   └── libft/                  # 42Libft repository
│       ├── libft/              # buildable C library
│       │   ├── libft.h
│       │   ├── Makefile
│       │   ├── *.c
│       │   └── ...
│       ├── tests/
│       ├── Doxyfile
│       └── README.md
├── include/
├── src/
└── Makefile
```

The resulting library paths are therefore typically:

```text
external/libft/libft/libft.h
external/libft/libft/libft.a
```

The repeated `libft/libft` is intentional. The first `libft` identifies
the dependency repository under `external/`; the second identifies the
buildable library directory inside the 42Libft repository.

#### Adding and pinning the dependency

Add the canonical repository:

```bash
git submodule add git@github.com:LuisQAlmeida/42Libft.git external/libft
```

Then select the exact revision the consumer should use:

```bash
git -C external/libft fetch origin
git -C external/libft checkout <reviewed-commit-or-tag>
```

Inspect the selected revision with:

```bash
git -C external/libft rev-parse HEAD
```

The parent repository stores the selected submodule commit as a
**Gitlink**. It can be inspected with:

```bash
git ls-files -s external/libft
```

A submodule entry uses Git mode `160000`, identifying the exact commit
recorded by the consumer rather than storing Libft files as ordinary files
in the parent repository. After initialization, the dependency files still
appear normally in the consumer working tree under `external/libft/`.

Commit both the submodule configuration and selected revision in the
consumer repository:

```bash
git add .gitmodules external/libft
```

Do not rely on automatically following the latest upstream `main`.
Explicit pinning prevents a consumer from silently adopting Libft changes
that it has not rebuilt and tested.

#### Cloning a project with Libft

Clone a consumer and initialize its dependencies in one command:

```bash
git clone --recurse-submodules <repository>
```

For an already cloned repository, initialize the recorded dependencies
with:

```bash
git submodule update --init --recursive
```

#### Updating Libft

A Libft upgrade should be an explicit dependency change:

1. fetch the canonical Libft repository;
2. inspect the available upstream revisions;
3. select a reviewed commit or release;
4. check out that revision inside `external/libft`;
5. rebuild and test the consuming project;
6. commit the changed Gitlink in the consumer repository.

For example:

```bash
git -C external/libft fetch origin
git -C external/libft checkout <reviewed-commit-or-tag>
git add external/libft
```

Updating the canonical Libft repository does **not** automatically update
its consumers. That separation is intentional and preserves
reproducibility.

### Vendored copy — simple and self-contained

Libft may instead be copied directly into a consuming repository.
This is a valid option when a completely self-contained source tree and a
simple clone experience are more important than preserving a live Git
relationship with upstream.

A typical layout is:

```text
project/
├── libft/
│   ├── libft.h
│   ├── Makefile
│   ├── *.c
│   └── ...
├── include/
├── src/
└── Makefile
```

The buildable `libft/` directory from this repository can be copied into
the consumer using the normal file-management workflow appropriate for
that project.

When vendoring Libft, record its provenance where practical:

- canonical upstream repository;
- exact commit or release used;
- import or update date where useful.

Vendoring provides a simple, self-contained checkout with no submodule
initialization requirement. In exchange, Git no longer records the
upstream Libft relationship automatically, and copied files can drift
from the canonical repository. Updates must therefore be synchronized and
validated manually.

Vendoring is not inherently less professional than using a submodule. It
represents a different engineering trade-off between dependency
provenance, update mechanics, and repository independence.

### Git subtree — optional alternative

Git subtree provides another model in which Libft source is stored
directly inside the consumer repository while retaining a structured
relationship with the canonical upstream repository.

It can be useful when a project wants:

- a self-contained checkout;
- no separate submodule initialization;
- an explicit mechanism for importing future upstream changes.

A subtree therefore sits between a submodule and a manually vendored
copy. Its trade-off is a more complex import and update workflow, with
additional decisions around imported history and squash commits.

For example, after fetching the canonical repository as an upstream Git
remote, a reviewed revision can be imported beneath a dedicated prefix:

```bash
git remote add libft-upstream git@github.com:LuisQAlmeida/42Libft.git
git fetch libft-upstream
git subtree add --prefix=external/libft libft-upstream <reviewed-revision> --squash
```

Subtree is an optional alternative rather than the default recommendation
for the maintained portfolio repositories.

### Build integration

Dependency management and build integration are related but separate
concerns. Each consumer remains responsible for adapting its Makefile to
the selected layout.

For the recommended submodule layout, paths can be centralized through
Makefile variables:

```make
LIBFT_REPO := external/libft
LIBFT_DIR  := $(LIBFT_REPO)/libft
LIBFT      := $(LIBFT_DIR)/libft.a
CPPFLAGS   += -I$(LIBFT_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
```

For a vendored layout, the same pattern may instead use:

```make
LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a
```

Adding `$(LIBFT_DIR)` to the compiler's include search path allows source
files to include the public header normally:

```c
#include "libft.h"
```

### Dependency revisions and releases

A maintained consumer should always be able to answer:

> Which exact Libft revision was this project built and validated against?

Explicit dependency identification improves:

- reproducible builds;
- dependency provenance;
- controlled upgrades;
- auditable Git history;
- regression investigation;
- protection against silent upstream changes.

A submodule records the selected commit directly through its Gitlink.
A vendored copy requires provenance to be recorded separately. A subtree
retains its imported upstream relationship through Git history and the
subtree workflow.

Consumers may pin either an exact reviewed commit or, when maintained
release tags are available, a reviewed release. In both cases the
dependency should ultimately resolve to an immutable Git object.

---

## Quality Checklist

This repository aims to maintain the following standards:

- compiles with `-Wall -Wextra -Werror`;
- reference builds succeed with GCC;
- compiler-diversity builds succeed with Clang;
- static library builds with `make`;
- bonus functions build with `make bonus`;
- unchanged builds preserve `libft.a`;
- header changes invalidate dependent object files;
- automated tests pass;
- Valgrind reports no leaks or memory errors in the automated test suite;
- GitHub Actions protects the maintained build and test contracts;
- CI validates warning-free Doxygen generation;
- CI leaves the repository free of generated artefacts;
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
