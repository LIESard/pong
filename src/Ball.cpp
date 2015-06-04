#include <SFML/Graphics.hpp>

#include "Ball.hpp"

Ball::Ball(int x, int y) {
    setSize(sf::Vector2f(10, 10));
    setOrigin(getWidth() / 2, getHeight() / 2);
    setPosition(x, y);

    velocityx = 4;
}

void Ball::setSpeed(int speed) {
    velocityx = speed;
}

int Ball::getSpeed() {
    return velocityx;
}

int Ball::getX() {
    return getGlobalBounds().left;
}

int Ball::getY() {
    return getGlobalBounds().top;
}

int Ball::getWidth() {
    return getGlobalBounds().width;
}

int Ball::getHeight() {
    return getGlobalBounds().height;
}
