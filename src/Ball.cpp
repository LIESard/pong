#include <SFML/Graphics.hpp>

#include "Ball.hpp"

Ball::Ball(int x, int y) : Entity(x, y, 10, 10, 4, 0) {}

void Ball::checkCollision(sf::FloatRect rect) {
    if (getGlobalBounds().intersects(rect)) {
        if (getY() > rect.top && getY() < rect.top + rect.height / 3) {
            setSpeedY(getSpeedY() - 0.1);
        } else if (getY() > rect.top + (rect.height / 3) * 2 && getY() < rect.top + rect.height) {
            setSpeedY(getSpeedY() + 0.1);
        }

        setSpeedX(-(getSpeedX() * 1.05));
    }
}

void Ball::checkCollision(int x, int y) {
    if (getY() < 0 || getY() + getHeight() > y) {
        setSpeedY(-getSpeedY());
    }
}

void Ball::update() {
    move(getSpeedX(), getSpeedY());
}

void Ball::update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown) {}
