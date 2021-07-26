#include "render.h"

void init_curses() {
  initscr();
}

void render(feed_t *feed) {
    int cx, cy, w, h, ends_reached;
    char title[] = "RRSS - ";
    getmaxyx(stdscr, h, w);
    for (cy = 0; cy < h; cy++) {
        ends_reached = 0;
        for (cx = 0; cx < w; cx++) {
            move(cy, cx);
            if (cx == 0 || cx + 1 >= w || cy == 0 || cy + 1 >= h) addch('.');
            else if (cy == 1 && ends_reached == 0) {
                addch(title[cx - 1]);
                if (cx - 1 == 6) ends_reached++;
            }
            else if (cy == 1 && ends_reached == 1 && feed->name[cx - 8] == '\0') ends_reached++;
            else if (cy == 1 && ends_reached == 1) addch(feed->name[cx - 8]);
            else addch(' ');
        }
    }
    refresh();
}
