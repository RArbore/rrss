#ifndef RENDER_H_
#define RENDER_H_

#include <ncurses.h>

#include "feed.h"

void init_curses();

void render(feed_t *);

#endif // RENDER_H_
