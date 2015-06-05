#ifndef BAT
#define BAT

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bat : public Entity {
public:
    Bat(int x, int y) : Entity(x, y, 10, 100) {}

    void checkBoundaries(int width, int height);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
};

#endif
