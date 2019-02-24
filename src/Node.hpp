#ifndef NODE_HPP
#define NODE_HPP

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

struct Node
{
    unsigned int x, y;
    Direction nextDirection, lastDirection;

    Node(unsigned int x, unsigned int y, Direction dir) : x(x), y(y), nextDirection(dir) {}
    Node() {}

    void move()
    {
        switch (this->nextDirection)
        {
        case Direction::UP:
            this->y--;
            break;
        case Direction::DOWN:
            this->y++;
            break;
        case Direction::LEFT:
            this->x--;
            break;
        case Direction::RIGHT:
            this->x++;
            break;
        default:
            break;
        }
        this->lastDirection = this->nextDirection;
    }

};

#endif