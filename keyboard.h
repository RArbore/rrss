#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <ncurses.h>
#include <expat.h>

#include "feed.h"

void block_handle_input(feed_t *, XML_Parser);

#endif // KEYBOARD_H_
