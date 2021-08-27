#ifndef FEED_H_
#define FEED_H_

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <expat.h>

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

typedef struct rss {
    int size;
} rss_t;

typedef struct xml_tag {
    char *name;
    void *data;
} xml_tag_t;

feed_t *create_feed(char *, char *);

void free_feed(feed_t *);

size_t write_data(void *, size_t, size_t, void *);

char *curl_rss(char *, int *);

void XMLCALL start_tag(void *, const XML_Char *, const XML_Char **);

void XMLCALL end_tag(void *, const XML_Char *);

XML_Parser initialize_expat();

rss_t *process_rss(char *, int, XML_Parser);

#endif // FEED_H_
