#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>

#include "Bat.hpp"
#include "Entity.hpp"

class Ball : public Entity {
public:
    Ball(int x, int y);

    void checkCollision(sf::FloatRect rect);
    void update();
};

#endif
