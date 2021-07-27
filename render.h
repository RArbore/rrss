#ifndef RENDER_H_
#define RENDER_H_

#include <ncurses.h>

#include "feed.h"

void init_curses();

void scroll_feed(int, feed_t *);

void scroll_page_feed(int, feed_t *);

int get_selected();

void render(feed_t *);

void kill_curses();

#endif // RENDER_H_
