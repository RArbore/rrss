#include <stdlib.h>
#include "feed.h"

feed_t *create_feed(char *urls_raw, char *name) {
    feed_t *feed = malloc(sizeof(feed_t));
    feed->name = name;

    size_t nls = 0, i, max_line_size = 0, cur_line_size = 0;
    for (i = 0; urls_raw[i] != '\0'; i++) {
        if (urls_raw[i] == '\n') {
            nls++;
            if (cur_line_size > max_line_size) max_line_size = cur_line_size;
            cur_line_size = 0;
        }
        else cur_line_size++;
    }
    if (cur_line_size > 0) {
        nls++;
        if (cur_line_size > max_line_size) max_line_size = cur_line_size;
        cur_line_size = 0;
    }
    feed->size = nls;

    feed->urls = malloc(nls * sizeof(char *));
    feed->titles = malloc(nls * sizeof(char *));
    for (i = 0; i < nls; i++) {
        feed->urls[i] = malloc(max_line_size * sizeof(char));
        feed->titles[i] = malloc(max_line_size * sizeof(char));
    }

    size_t line;
    int seen_space = 0;
    for (i = 0; urls_raw[i] != '\0'; i++) {

    }

    return feed;
}

void free_feed(feed_t *feed) {
    if (feed == NULL) {
        return;
    }
    int i;
    for (i = 0; i < feed->size; i++) {
        if (feed->urls != NULL) free(feed->urls[i]);
        if (feed->titles != NULL) free(feed->titles[i]);
    }
    free(feed->name);
    free(feed->urls);
    free(feed->titles);
    free(feed);
}
