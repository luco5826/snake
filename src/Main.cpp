#include <iostream>

#include <ncurses.h>

#include "Game.h"
#include "Utils.hpp"

int main()
{
    setlocale(LC_ALL, "");
    bindtextdomain("snake", "./locale");
    textdomain("snake");

    int refreshRate = Utils::introduction();

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

    Game *game = new Game(width, height, Node(width / 2, height / 2, Direction::NONE));
    while (game->notEnded())
    {
        game->printField();
        game->getInput();
        delay_output(refreshRate);
    }

    clear();         // Clear the screen
    attroff(A_BOLD); // Disable BOLD font
    endwin();        // Close the Window

    if (game->lost())
    {
        Utils::gameLost();
    }
    delete game;

    return 0;
}