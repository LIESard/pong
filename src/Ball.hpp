#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>

#include "Bat.hpp"

class Ball : public sf::RectangleShape {
public:
    Ball(int x, int y);

    void checkCollision(Bat bat);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getSpeed();
    void setSpeed(int speed);

private:
    int velocityx;
};

#endif
