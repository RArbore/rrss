#include "keyboard.h"
#include "render.h"
#include "feed.h"

void block_handle_input(feed_t *feed) {
    timeout(-1);
    char c = (char) getch();
    switch (c) {
        case 'j':
            scroll_feed(1, feed);
            break;
        case 'k':
            scroll_feed(-1, feed);
            break;
        case 'J':
            scroll_page_feed(1, feed);
            break;
        case 'K':
            scroll_page_feed(-1, feed);
            break;
        case 'q':
            kill_curses();
            exit(0);
        case 10: //enter
            int response_size;
            char *response = curl_rss(feed->urls[get_selected()], &response_size);
        default:
    }
}
