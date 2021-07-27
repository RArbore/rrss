#ifndef FEED_H_
#define FEED_H_

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

typedef struct feed {
    int size;
    char *name;
    char **urls;
    char **titles;
} feed_t;

typedef struct curl_data {
    char *data;
    size_t size;
} curl_data_t;

feed_t *create_feed(char *, char *);

void free_feed(feed_t *);

size_t write_data(void *, size_t, size_t, void *);

char *curl_rss(char *, int *);

#endif // FEED_H_
