#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

class Entity : public sf::RectangleShape {
public:
    Entity(int x, int y, int width, int height, int speed);

    virtual void update();
    virtual void update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown);
    virtual void checkCollision(sf::FloatRect rect);
    virtual void checkCollision(int x, int y);
    void setSpeed(int speed);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getSpeed();
 
private:
    int speed;
};

#endif
