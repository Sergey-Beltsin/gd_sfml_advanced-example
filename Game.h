#ifndef SFML_BEGINNER_GAME_H
#define SFML_BEGINNER_GAME_H

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "SwagBall.h"

namespace GAME {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    class Game {
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow * window;
        bool isGameEnded;
        sf::Event event;

        PLAYER::Player player;

        std::vector<SWAG_BALL::SwagBall> swagBalls;
        float spawnTimerMax;
        float spawnTimer;
        int maxSwagBalls;

        void initVariables();
        void initWindow();
    public:
        // Constructors and desctructors
        Game();
        ~Game();

        // Accessors
        const bool getIsWindowOpen() const;

        // Modifiers

        // Functions
        void pollEvents();

        void spawnSwagBalls();
        void update();
        void render();
    };
}

#endif //SFML_BEGINNER_GAME_H
