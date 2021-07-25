#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "feed.h"

char* open_urls(char* urls_file_name) {
    FILE *urls_file;
    int c;
    size_t s = 1024, i = 0;
    char *buf = malloc(s * sizeof(char));
    urls_file = fopen(urls_file_name, "r");
    if (urls_file == NULL) {
        return NULL;
    }

    while ((c = fgetc(urls_file)) != EOF) {
        if (i >= s - 1) {
            s *= 2;
            buf = realloc(buf, s * sizeof(char));
        }
        buf[i++] = (char) c;
    }
    buf[i] = '\0';

    fclose(urls_file);
    return buf;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("Please specify a URLs file to open.\n");
        exit(1);
    }
    char *urls_raw = open_urls(argv[1]);
    if (urls_raw == NULL) {
        printf("Please specify a valid URLs file to open.\n");
        exit(1);
    }
    feed_t *feed = create_feed(urls_raw, "Test");
    printf("%s %d\n", feed->name, feed->size);
    for (int i = 0; i < 4; i++) {
        printf("%s ", feed->urls[i]);
        printf("%s\n", feed->titles[i]);
    }

    initscr();
    int cx = 0;
    int cy = 0;
    for (;;) {
        move(cx++, cy++);
        addch(65 + cx % 26);
        refresh();
        napms(100);
    }
    endwin();
    return 0;
}
