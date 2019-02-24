#ifndef GAME_H
#define GAME_H

#include <sstream>
#include <ncurses.h>
#include <random>

#include "Snake.h"

class Game
{
  private:
    Snake* snake;
    unsigned int width, height;
    Node food;
    bool gameLost, endGame;
    

    public:
    Game(const unsigned int width, const unsigned int height, Node startingPoint);

    ~Game();
    void getInput();
    void putRandomFood();
    void checkSnakeOnFood();
    void checkSnakeOnItself();
    bool notEnded();
    bool lost();
    void printField();
};

#endif