#ifndef BAT
#define BAT

#include <SFML/Graphics.hpp>

class Bat : public sf::RectangleShape {
public:
    Bat(int x, int y);

    void checkBoundaries(int width, int height);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
};

#endif
