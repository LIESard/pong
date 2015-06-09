#include <SFML/Graphics.hpp>

#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height, int speed) {
    setSize(sf::Vector2f(width, height));
    setPosition(x, y);

    this->speed = speed;
}

int Entity::getX() {
    return getGlobalBounds().left;
}

int Entity::getY() {
    return getGlobalBounds().top;
}

int Entity::getWidth() {
    return getGlobalBounds().width;
}

int Entity::getHeight() {
    return getGlobalBounds().height;
}

int Entity::getSpeed() {
    return speed;
}

void Entity::setSpeed(int speed) {
    this->speed = speed;
}
