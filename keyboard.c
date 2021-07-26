#include "keyboard.h"

void block_handle_input(feed_t *feed) {
    timeout(-1);
    char c = (char) getch();
    if (c == 'j') scroll_feed(1, feed);
    else if (c == 'k') scroll_feed(-1, feed);
}
