#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Bat.hpp"

Bat::Bat(int x, int y) : Entity(x, y, 10, 100, 0, 6) {}

void Bat::checkCollision(int x, int y) {
    if (getX() < 0) {
        setPosition(0, getY());
    } else if (getX() + getWidth() > x) {
        setPosition(x - getWidth(), getY());
    }
    if (getY() < 0) {
        setPosition(getX(), 0);
    } else if (getY() + getHeight() > y) {
        setPosition(getX(), y - getHeight());
    }
}

void Bat::checkCollision(sf::FloatRect rect) {}

void Bat::update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown) {
    if (sf::Keyboard::isKeyPressed(keyUp)) {
        move(0, -4);
    }
    if (sf::Keyboard::isKeyPressed(keyDown)) {
        move(0, 4);
    }
}

void Bat::update() {}