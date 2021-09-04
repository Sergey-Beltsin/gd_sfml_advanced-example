#ifndef SFML_BEGINNER_PLAYER_H
#define SFML_BEGINNER_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

namespace PLAYER {
    const float PLAYER_WIDTH = 50.0f;
    const float PLAYER_HEIGHT = 50.0f;
    const int MAX_HP = 10;

    class Player {
    private:
        sf::RectangleShape shape;

        float movementSpeed;
        int hp;
        int hpMax;

        void initVariables();
        void initShape();
    public:
        Player(float x = 0.0f, float y = 0.0f);
        virtual ~Player();

        void updateInput();
        void updateWindowBoundsCollision(const sf::RenderTarget * target);
        void update(const sf::RenderTarget * target);
        void render(sf::RenderTarget * target);
    };
}

#endif //SFML_BEGINNER_PLAYER_H
