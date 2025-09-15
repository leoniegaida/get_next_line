/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:12:21 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/15 20:36:31 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include "get_next_line.h"

void *__real_malloc(size_t size);
void __real_free(void *ptr);

#define STATE_FILE "malloc_fail_state.txt"

// global counter for current malloc call
static size_t malloc_call_count = 0;

// total mallocs and current failure index read from file
static size_t total_mallocs = 0;
static size_t fail_index = 0;

// ensure thread safety if your program is multithreaded
static pthread_mutex_t malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

// helper: read state from file, returns 1 if file exists, 0 otherwise
static int read_state() {
    FILE *f = fopen(STATE_FILE, "r");
    if (!f)
        return 0;
    if (fscanf(f, "%zu %zu", &total_mallocs, &fail_index) != 2) {
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}

// helper: write state back to file
static void write_state() {
    FILE *f = fopen(STATE_FILE, "w");
    if (!f) return;
    fprintf(f, "%zu %zu\n", total_mallocs, fail_index);
    fclose(f);
}

void *__wrap_malloc(size_t size)
{
    void *ptr;

    pthread_mutex_lock(&malloc_mutex);
    malloc_call_count++;

    // first run: no state file -> count mallocs
    if (total_mallocs == 0 && !read_state()) {
        ptr = __real_malloc(size);
    } else {
        // later runs: fail exactly one malloc deterministically
        if (malloc_call_count == fail_index + 1)  // 1-based counting
            ptr = NULL;
        else
            ptr = __real_malloc(size);
    }

    // print debug info
    dprintf(2, "malloc(%zu) = %p (call %zu)\n", size, ptr, malloc_call_count);

    pthread_mutex_unlock(&malloc_mutex);
    return ptr;
}

void __wrap_free(void *ptr)
{
    dprintf(2, "free(%p)\n", ptr);
    __real_free(ptr);
}

// call at program exit to update state file
__attribute__((destructor))
static void update_state() {
    if (!read_state()) {
        // first run: save total mallocs, fail_index = 0
        total_mallocs = malloc_call_count;
        fail_index = 0;
    } else {
        // later runs: increment fail_index for next run
        fail_index = (fail_index + 1) % total_mallocs;
    }
    write_state();
}

int	main(void)
{
	FILE    *log;
    int		fd;
    int		lines;
	char	*line;

    log = fopen("output.txt", "w");
	fd = open("file.txt", O_RDONLY);
    lines = 1;
	while ((line = get_next_line(fd)))
	{
		fprintf(log, "%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);
    fclose(log);
	return (0);
}
