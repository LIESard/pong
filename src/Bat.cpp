#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Bat.hpp"

Bat::Bat(int x, int y) {
    setSize(sf::Vector2f(10, 100));
    setPosition(x, y);
}

void Bat::checkBoundaries(int width, int height) {
    if (getX() < 0) {
        setPosition(0, getY());
    } else if (getX() + getWidth() > width) {
        setPosition(width - getWidth(), getY());
    }
    if (getY() < 0) {
        setPosition(getX(), 0);
    } else if (getY() + getHeight() > height) {
        setPosition(getX(), height - getHeight());
    }
}

int Bat::getX() {
    return getGlobalBounds().left;
}

int Bat::getY() {
    return getGlobalBounds().top;
}

int Bat::getWidth() {
    return getGlobalBounds().width;
}

int Bat::getHeight() {
    return getGlobalBounds().height;
}
