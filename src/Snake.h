#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Node.hpp"

class Snake
{
  private:
    std::vector<Node> body;

  public:
    Snake(Node startNode);

    ~Snake();

    bool hasBodyPartIn(const unsigned int x, const unsigned int y);

    bool ateFood(Node& foodPosition);

    void keepMoving();

    void updateDirections();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void moveNodes();
};

#endif /*SNAKE_H*/
