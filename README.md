# get_next_line
This project is about programming a function that returns a line read from a file descriptor.

## How to compile with main (1 file descriptor):
with default BUFFER_SIZE 42
```shell
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```
with adjusted BUFFER_SIZE n
```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=n main.c get_next_line.c get_next_line_utils.c
```
## How to compile with main (bonus -> up to 1024 file descriptors):
with default BUFFER_SIZE 42
```shell
gcc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
with adjusted BUFFER_SIZE n
```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=n main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
## How to compile with test (wrapper to check malloc fails):
```shell
gcc -Wall -Wextra -Werror -g test.c get_next_line.c get_next_line_utils.c -Wl,--wrap,malloc -Wl,--wrap,free
```
1. compile
2. manually run ./a.out to iterate through all malloc calls (wrapper sets one after one =NULL)

don't change anything while iterating, or test won't work properly.

if you test, change somehting, want to test again: delete STATE_FILE and OUTPUT_FILE before next test

## Thoughts on future implementations:
- add global error handling with errno variable
