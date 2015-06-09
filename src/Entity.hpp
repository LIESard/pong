#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

class Entity : public sf::RectangleShape {
public:
    Entity(int x, int y, int width, int height, int speedx, int speedy);

    virtual void update() = 0;
    virtual void update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown) = 0;
    virtual void checkCollision(sf::FloatRect rect) = 0;
    virtual void checkCollision(int x, int y) = 0;
    void setSpeedX(float speed);
    float getSpeedX();
    void setSpeedY(float speed);
    float getSpeedY();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
 
private:
    float speedx, speedy;
};

#endif
