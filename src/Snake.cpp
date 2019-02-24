#include "Snake.h"

Snake::Snake(Node startNode)
{
    this->body.push_back(startNode);
    body[0].lastDirection = Direction::NONE;
}

Snake::~Snake()
{
}

bool Snake::hasBodyPartIn(const unsigned int x, const unsigned int y)
{
    for (Node &n : body)
    {
        if (n.x == x && n.y == y)
        {
            return true;
        }
    }
    return false;
}

bool Snake::ateFood(Node &foodPosition)
{
    bool ate = this->body[0].x == foodPosition.x && this->body[0].y == foodPosition.y;
    if (ate)
    {
        this->body.insert(this->body.begin(), Node(foodPosition.x, foodPosition.y, body[0].lastDirection));
        body[0].move();
    }

    return ate;
}

void Snake::keepMoving()
{
    switch (body[0].lastDirection)
    {
    case Direction::UP:
        this->moveUp();
        break;
    case Direction::DOWN:
        this->moveDown();
        break;
    case Direction::LEFT:
        this->moveLeft();
        break;
    case Direction::RIGHT:
        this->moveRight();
        break;
    default:
        break;
    }
}

void Snake::updateDirections()
{

    for (size_t i = body.size() - 1; i > 0; i--)
    {
        body[i].nextDirection = body[i - 1].lastDirection;
    }
}

void Snake::moveUp()
{
    if (body[0].lastDirection == Direction::DOWN)
    {
        this->keepMoving();
        return;
    }
    this->body[0].y -= 1;
    body[0].lastDirection = Direction::UP;
    moveNodes();
}
void Snake::moveDown()
{
    if (body[0].lastDirection == Direction::UP)
    {
        this->keepMoving();
        return;
    }
    this->body[0].y += 1;
    body[0].lastDirection = Direction::DOWN;
    moveNodes();
}
void Snake::moveLeft()
{
    if (body[0].lastDirection == Direction::RIGHT)
    {
        this->keepMoving();
        return;
    }
    this->body[0].x -= 1;
    body[0].lastDirection = Direction::LEFT;
    moveNodes();
}
void Snake::moveRight()
{
    if (body[0].lastDirection == Direction::LEFT)
    {
        this->keepMoving();
        return;
    }
    this->body[0].x += 1;
    body[0].lastDirection = Direction::RIGHT;
    moveNodes();
}

void Snake::moveNodes()
{
    for (size_t i = 1; i < body.size(); i++)
    {
        body[i].move();
    }
}