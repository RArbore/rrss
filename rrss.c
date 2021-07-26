#include <stdlib.h>
#include <stdio.h>

#include "keyboard.h"
#include "render.h"
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
    feed_t *feed = create_feed(urls_raw, argv[1]);

    init_curses();
    for (;;) {
        render(feed);
        block_handle_input(feed);
    }

    return 0;
}
