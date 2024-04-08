#include <iostream>
#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    // Disable line buffering and echoing
    cbreak();
    noecho();
    // Enable keypad input
    keypad(stdscr, TRUE);

    while (true) {
        int ch = getch();
        if (ch == KEY_UP) {
            printw("Up\n");
            refresh();
        } else if (ch == KEY_DOWN) {
            printw("Down\n");
            refresh();
        } else if (ch == 'q') {
            break;
        }
    }

    // Clean up ncurses
    endwin();

    return 0;
}