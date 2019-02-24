#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Node.hpp"

class Snake
{
  private:
    std::vector<Node> body;
    const int maxWidth, maxHeight;

  public:
    Snake(Node startNode, const int maxWidth, const int maxHeight);

    ~Snake();

    bool hasBodyPartIn(const unsigned int x, const unsigned int y);
    bool isHead(const unsigned int x, const unsigned int y);

    bool ateFood(Node& foodPosition);
    bool onItself();

    void keepMoving();

    void updateDirections();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void moveNodes();
};

#endif /*SNAKE_H*/
