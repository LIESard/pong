#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Bat.hpp"
#include "Ball.hpp"

const int WIDTH = 640, HEIGHT = 480;
const std::string TITLE = "Pong";
static bool paused = false;

void draw(sf::RenderWindow * window, Bat bats[], Ball ball) {
    window->clear();

    for (int i = 0; i < 2; i++) {
        window->draw(bats[i]);
    }
    window->draw(ball);

    window->display();
}

void update(sf::RenderWindow * window, Bat bats[], Ball * ball) {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::LostFocus) {
            paused = true;
        } else if (event.type == sf::Event::GainedFocus) {
            paused = false;
        }
    }

    if (!paused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            bats[0].sf::RectangleShape::move(0, -6);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            bats[0].sf::RectangleShape::move(0, 6);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            bats[1].sf::RectangleShape::move(0, -6);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            bats[1].sf::RectangleShape::move(0, 6);
        }

        for (int i = 0; i < 2; i++) {
            bats[i].checkBoundaries(WIDTH, HEIGHT);
            
            if (ball->getGlobalBounds().intersects(bats[i].getGlobalBounds())) {
                ball->setSpeed(-ball->getSpeed());
            }
        }

        ball->move(ball->getSpeed(), 0);
    }

}

int main(int argc, char ** argv) {
    sf::VideoMode mode(WIDTH, HEIGHT);
    sf::RenderWindow window;
    Bat bat1(10, 10);
    Bat bat2(WIDTH - 20, 10);
    Bat bats[2] = {bat1, bat2};
    Ball ball(WIDTH / 2, HEIGHT / 2);

    window.create(mode, TITLE);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        draw(&window, bats, ball);
        update(&window, bats, &ball);
    }

    return 0;
}
