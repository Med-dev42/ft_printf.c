*This project has been created as part
of the 42 curriculum by mlazar.*

# ft_printf

## Description

ft_printf is a project at 42 that re-implements the standard C function
`printf`. The goal is to learn how variadic functions work (`stdarg.h`)
and how to parse a format string and print each conversion without using
the libc `printf`. The result is a static library, `libftprintf.a`.

## Supported conversions

- `%c` prints a single character.
- `%s` prints a string (`(null)` if the pointer is NULL).
- `%p` prints a pointer in hexadecimal (`(nil)` if NULL).
- `%d` and `%i` print a signed integer.
- `%u` prints an unsigned integer.
- `%x` and `%X` print a number in lowercase or uppercase hexadecimal.
- `%%` prints a percent sign.

**Bonus:** the flags `-`, `0`, `+`, space and `#`, plus field width and
precision (`.`).

## Instructions

Compile the mandatory part:

```bash
make
```

Compile the bonus part:

```bash
make bonus
```

Both create `libftprintf.a`. Other rules: `make clean`, `make fclean`,
`make re`.

Use it in your project:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

For the bonus, include `ft_printf_bonus.h` instead.

## Algorithm and data structure

**Algorithm.** `ft_printf` walks through the format string one character
at a time. Normal characters are written directly with `write`. When a
`%` is found, the next character selects the conversion, and a dedicated
function prints the matching argument taken with `va_arg`. Every function
returns the number of characters it printed, and these are summed to get
the return value of `ft_printf`. Numbers are printed recursively (dividing
by 10 or 16) so digits come out in the right order without any buffer or
`malloc`. The `va_list` is passed by pointer so that each function
advances the same argument list.

I chose this design because it is simple, needs no dynamic allocation
(no leaks possible), respects the Norm, and keeps each conversion in its
own small function, which makes it easy to read, test and extend.

**Data structure.** The mandatory part uses no custom structure, only the
`va_list` and an `int` counter. The bonus part uses a `t_flags` structure
(`minus`, `zero`, `plus`, `space`, `hash`, `width`, `prec`). It is filled
once by the parsing function and passed to the printing functions, which
avoids passing many separate parameters.

## Resources

- `man 3 printf`, `man 3 stdarg`
- Documentation on variadic functions in C
- YouTube: "Portfolio Courses" with "Oceano"
- 

### AI usage

AI was used for the following tasks:
- Explaining how variadic functions and `va_list`, `va_start`, `va_end`, `va_copy`  work.
- Reviewing my code for bugs, Norm issues and header problems (bonus part).
- Fixing the Makefile relink behavior.
- hard test cases for my ftprintf.

I wrote and tested the code myself.
