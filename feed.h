#ifndef FEED_H_
#define FEED_H_

#include <stdlib.h>
#include <string.h>

typedef struct feed {
    int size;
    char *name;
    char **urls;
    char **titles;
} feed_t;

feed_t *create_feed(char *, char *);

void free_feed(feed_t *);

#endif // FEED_H_
