#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

class Entity : public sf::RectangleShape {
public:
    Entity(int x, int y, int width, int height);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
};

#endif
