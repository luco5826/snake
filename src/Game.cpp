#include "Game.h"

Game::Game(const unsigned int width, const unsigned int height, Node startingPoint) : width(width), height(height), gameLost(false)
{
    this->snake = new Snake(startingPoint, width, height);
    putRandomFood();
}

Game::~Game()
{
    delete this->snake;
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
    this->checkSnakeOnItself();
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

void Game::checkSnakeOnItself()
{
    if (this->snake->onItself())
    {
        this->gameLost = true;
    }
    return;
}

bool Game::notEnded()
{
    return !gameLost;
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
                    if (this->snake->isHead(x, y))
                    {
                        ss << "O";
                    }
                    else
                    {
                        ss << "o";
                    }
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