#ifndef RRSS_H_
#define RRSS_H_

typedef struct feed {
    int size;
    char *name;
    char **urls;
    char **titles;
} feed_t;

feed_t *create_feed(char *, char *);

void free_feed(feed_t *);

#endif // RRSS_H_
