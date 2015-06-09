#include <SFML/Graphics.hpp>

#include "Ball.hpp"

Ball::Ball(int x, int y) : Entity(x, y, 10, 10, 4) {}

void Ball::checkCollision(sf::FloatRect rect) {
    if (getGlobalBounds().intersects(rect)) {
        setSpeed(-getSpeed());
    }
}

void Ball::update() {
    move(getSpeed(), 0);
}
