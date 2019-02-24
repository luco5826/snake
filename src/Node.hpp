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

    void move(const int width, const int height)
    {
        switch (this->nextDirection)
        {
        case Direction::UP:
            this->y--;
            if (this->y == -1)
                this->y = height - 1;
            break;
        case Direction::DOWN:
            this->y++;
            if (this->y == height)
                this->y = 0;
            break;
        case Direction::LEFT:
            this->x--;
            if (this->x == -1)
                this->x = width - 1;
            break;
        case Direction::RIGHT:
            this->x++;
            if (this->x == width)
                this->x = 0;
            break;
        default:
            break;
        }
        this->lastDirection = this->nextDirection;
    }
};

#endif