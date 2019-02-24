#include <iostream>

#include <ncurses.h>

#include "Game.h"

int main()
{

    { // Don't know what this block does, initialize ncurses
        initscr();
        cbreak();
        curs_set(FALSE);
        keypad(stdscr, TRUE);
        refresh();      // Refresh the screen
        attron(A_BOLD); // Set font to BOLD
        nodelay(stdscr, true);
    }

    const unsigned int width = COLS;
    const unsigned int height = LINES;

    refresh();

    Game *game = new Game(width, height, Node(width / 2, height / 2, Direction::NONE));
    while (true)
    {
        game->printField();
        game->getInput();
        delay_output(50);
    }

    char c = getch();

    clear();         // Clear the screen
    attroff(A_BOLD); // Disable BOLD font
    endwin();        // Close the Window

    return 0;
}