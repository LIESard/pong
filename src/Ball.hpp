#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>

#include "Bat.hpp"
#include "Entity.hpp"

class Ball : public Entity {
public:
    Ball(int x, int y);

    void checkCollision(sf::FloatRect rect);
    void checkCollision(int x, int y);
    void update();
    void update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown);
    void changeScore(int x, int y, int * score1, int * score2);
};

#endif
