#include "Snake.h"

Snake::Snake(Node startNode, const int maxWidth, const int maxHeight) : maxWidth(maxWidth), maxHeight(maxHeight)
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

bool Snake::isHead(const unsigned int x, const unsigned int y)
{
    return this->body[0].x == x && this->body[0].y == y;
}

bool Snake::ateFood(Node &foodPosition)
{
    // Not only the head can eat: if the snake just ate, the head is "updated" when
    // the snake's last node steps on food, but in the meantime it can eat a new food!
    bool ate = this->hasBodyPartIn(foodPosition.x, foodPosition.y);
    if (ate)
    {
        this->body.insert(this->body.begin(), Node(foodPosition.x, foodPosition.y, body[0].lastDirection));
        body[0].move(maxWidth, maxHeight);
    }

    return ate;
}

bool Snake::onItself()
{
    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i].x == body[0].x && body[i].y == body[0].y)
        {
            return true;
        }
    }
    return false;
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
    if (this->body[0].y == -1)
    {
        this->body[0].y = maxHeight - 1;
    }
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
    if (this->body[0].y == maxHeight)
    {
        this->body[0].y = 0;
    }
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
    if (this->body[0].x == -1)
    {
        this->body[0].x = maxWidth - 1;
    }
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
    if (this->body[0].x == maxWidth)
    {
        this->body[0].x = 0;
    }
    body[0].lastDirection = Direction::RIGHT;
    moveNodes();
}

void Snake::moveNodes()
{
    for (size_t i = 1; i < body.size(); i++)
    {
        body[i].move(this->maxWidth, this->maxHeight);
    }
}