#include <SFML/Graphics.hpp>

#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height, int speedx, int speedy) {
    setSize(sf::Vector2f(width, height));
    setPosition(x, y);

    this->speedx = speedx;
    this->speedy = speedy;
}

void Entity::setSpeedX(float speed) {
    speedx = speed;
}

float Entity::getSpeedX() {
    return speedx;
}

void Entity::setSpeedY(float speed) {
    speedy = speed;
}

float Entity::getSpeedY() {
    return speedy;
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
