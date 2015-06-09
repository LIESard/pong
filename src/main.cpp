#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bat.hpp"
#include "Ball.hpp"

constexpr int WIDTH = 640, HEIGHT = 480;
static bool paused = false;

void draw(sf::RenderWindow * window, Entity * entities[3]) {
    window->clear();

    for (int i = 0; i < 3; i++) {
        window->draw(*entities[i]);
    }

    window->display();
}

void update(sf::RenderWindow * window, Entity * entities[3], int * score1, int * score2) {
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

        for (int i = 0; i < 2; i++) {
            entities[i]->checkCollision(WIDTH, HEIGHT);
            entities[2]->checkCollision(entities[i]->getGlobalBounds());
        }
        entities[2]->checkCollision(WIDTH, HEIGHT);
        entities[0]->update(sf::Keyboard::Comma, sf::Keyboard::O);
        entities[1]->update(sf::Keyboard::Up, sf::Keyboard::Down);
        entities[2]->update();
        entities[2]->changeScore(WIDTH, HEIGHT, score1, score2);
    }

}

int main(int argc, char ** argv) {
    sf::VideoMode mode(WIDTH, HEIGHT);
    sf::RenderWindow window;
    Bat bat1(10, HEIGHT / 2 - 50);
    Bat bat2(WIDTH - 20, HEIGHT / 2 - 50);
    Ball ball(WIDTH / 2, HEIGHT / 2);
    Entity * entities[3] = {&bat1, &bat2, &ball};
    int bat1score = 0, bat2score = 0;

    window.create(mode, "Pong");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        draw(&window, entities);
        update(&window, entities, &bat1score, &bat2score);
    }

    return 0;
}
