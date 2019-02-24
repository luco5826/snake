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
        // wresize(stdscr, 20, 20);
        resize_term(20, 20);
    }

    const unsigned int width = 20;
    const unsigned int height = 20;

    refresh();

    Game *game = new Game(width, height, Node(width / 2, height / 2, Direction::NONE));
    while (game->notEnded())
    {
        game->printField();
        game->getInput();
        delay_output(80);
    }

    char c = getch();

    clear();         // Clear the screen
    attroff(A_BOLD); // Disable BOLD font
    endwin();        // Close the Window
    // delete game;
    return 0;
}