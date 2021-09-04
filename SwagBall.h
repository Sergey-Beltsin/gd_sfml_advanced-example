#ifndef SFML_BEGINNER_SWAGBALL_H
#define SFML_BEGINNER_SWAGBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

namespace SWAG_BALL {
    class SwagBall {
    private:
        sf::CircleShape shape;

        void initShape(const sf::RenderTarget * target);
    public:
        SwagBall(const sf::RenderTarget * target);
        virtual ~SwagBall();

        void update();
        void render(sf::RenderTarget * target);
    };
}

#endif //SFML_BEGINNER_SWAGBALL_H
