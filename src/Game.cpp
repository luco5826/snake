#include "Game.h"

Game::Game(const unsigned int width, const unsigned int height, Node startingPoint) : width(width), height(height)
{
    this->snake = new Snake(startingPoint);
    putRandomFood();
}

void Game::getInput()
{
    int c = getch();
    flushinp();
    switch (c)
    {
    case KEY_UP:
        this->snake->moveUp();
        break;
    case KEY_DOWN:
        this->snake->moveDown();
        break;
    case KEY_LEFT:
        this->snake->moveLeft();
        break;
    case KEY_RIGHT:
        this->snake->moveRight();
        break;
    default:
        this->snake->keepMoving();
        break;
    }

    this->checkSnakeOnFood();
    this->snake->updateDirections();
}

void Game::putRandomFood()
{
    srand(time(NULL));
    food.x = rand() % width;
    food.y = rand() % height;
}

void Game::checkSnakeOnFood()
{
    if (this->snake->ateFood(food))
    {
        putRandomFood();
    }
}

void Game::printField()
{
    unsigned int x = 0;
    unsigned int y = 0;

    std::stringstream ss;

    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (food.x == x && food.y == y)
            {
                ss << "A";
            }
            else
            {
                if (this->snake->hasBodyPartIn(x, y))
                {
                    ss << "o";
                }
                else
                {
                    ss << " ";
                }
            }
            x++;
        }
        y++;
    }
    refresh();
    mvprintw(0, 0, ss.str().c_str());
}