#include "render.h"

int colors = 0;

void init_curses() {
    initscr();
    if (has_colors() && start_color() == OK) {
        colors = 1;
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
    }
}

void render(feed_t *feed) {
    int cx, cy, w, h, ends_reached;
    char title[] = "RRSS - ";
    getmaxyx(stdscr, h, w);
    for (cy = 0; cy < h; cy++) {
        ends_reached = 0;
        for (cx = 0; cx < w; cx++) {
            move(cy, cx);
            attroff(COLOR_PAIR(1));
            if (cy == 0) {
                attrset(COLOR_PAIR(1) | A_BOLD);
                if (ends_reached == 0) {
                    addch(title[cx]);
                    if (cx == 6) ends_reached++;
                }
                else if (ends_reached == 1 && feed->name[cx - 7] == '\0') {
                    addch(' ');
                    ends_reached++;
                }
                else if (ends_reached == 1) addch(feed->name[cx - 7]);
                else addch(' ');
            }
            else addch(' ');
        }
    }
    refresh();
}
