#ifndef BAT
#define BAT

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bat : public Entity {
public:
    Bat(int x, int y);

    void checkCollision(int x, int y);
    void checkCollision(sf::FloatRect rect);
    void update(sf::Keyboard::Key keyUp, sf::Keyboard::Key keyDown);
    void update();
};

#endif
