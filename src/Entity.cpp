#include <SFML/Graphics.hpp>

#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height) {
    setSize(sf::Vector2f(width, height));
    setPosition(x, y);
}
