#include "render.h"

int colors = 0;
int scrolled = 0;
int selected = 0;

void init_curses() {
    initscr();
    curs_set(0);
    if (has_colors() && start_color() == OK) {
        colors = 1;
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
    }
}

void scroll_feed(int scroll_amount, feed_t *feed) {
    selected += scroll_amount;
    if (selected < 0) selected = 0;
    else if (selected >= feed->size) selected = feed->size - 1;

    int h = getmaxy(stdscr);
    if (selected > scrolled + h - 2) scrolled = selected - h + 2;
    else if (selected < scrolled) scrolled = selected;
}

void scroll_page_feed(int dir, feed_t * feed) {
    int h = getmaxy(stdscr) - 1;
    scroll_feed(dir * h, feed);
}

int get_selected() {
    return selected;
}

void render(feed_t *feed) {
    int cx, cy, w, h, ends_reached;
    char title[] = "RRSS - ";
    getmaxyx(stdscr, h, w);
    for (cy = 0; cy < h; cy++) {
        ends_reached = 0;
        for (cx = 0; cx < w; cx++) {
            move(cy, cx);
            attroff(COLOR_PAIR(1) | A_BOLD);
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
            else if (cy + scrolled - 1 < feed->size) {
                if (cy + scrolled - 1 == selected && colors) attrset(COLOR_PAIR(1));
                else if (cy + scrolled - 1 == selected) attrset(A_BOLD);
                if (ends_reached == 0 && feed->titles[cy + scrolled - 1][cx] != '\0') {
                    addch(feed->titles[cy + scrolled - 1][cx]);
                }
                else if (ends_reached == 0) {
                    ends_reached++;
                    addch(' ');
                }
                else addch(' ');
            }
            else addch(' ');
        }
    }
    refresh();
}

void kill_curses() {
    curs_set(1);
    endwin();
}
