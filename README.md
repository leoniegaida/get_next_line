# get_next_line
This project is about programming a function that returns a line read from a file descriptor.

## How to compile with tester:
```shell
gcc -Wall -Wextra -Werror -g test.c get_next_line.c get_next_line_utils.c -Wl,--wrap,malloc -Wl,--wrap,free
```

## Thoughts on future implementations:
- add global error handling with errno variable