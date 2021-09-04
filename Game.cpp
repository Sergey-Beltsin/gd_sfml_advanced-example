#include "Game.h"

void GAME::Game::initVariables() {
    isGameEnded = false;
    window = nullptr;
    spawnTimerMax = 10.0f;
    spawnTimer = spawnTimerMax;
    maxSwagBalls = 10;
}

void GAME::Game::initWindow() {
    videoMode = sf::VideoMode(GAME::WINDOW_WIDTH, GAME::WINDOW_HEIGHT);
    window = new sf::RenderWindow(
    videoMode,
    "Game 2",
    sf::Style::Close | sf::Style::Titlebar
    );
    window->setFramerateLimit(60);
}

// Constructors and destructors
GAME::Game::Game() {
    initVariables();
    initWindow();
}

GAME::Game::~Game() {
    delete window;
}

const bool GAME::Game::getIsWindowOpen() const {
    return window -> isOpen();
}

void GAME::Game::pollEvents() {
    while (window -> pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window -> close();

                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window -> close();
                }

                break;
            default:
                break;
        }
    }
}

void GAME::Game::spawnSwagBalls() {
    if (spawnTimer < spawnTimerMax) {
        spawnTimer += 1.0f;
    } else {
        if (swagBalls.size() < maxSwagBalls) {
            swagBalls.emplace_back(window);
            spawnTimer = 0.0f;
        }
    }
}

void GAME::Game::update() {
    pollEvents();

    spawnSwagBalls();

    player.update(window);
}

void GAME::Game::render() {
    window -> clear();

    player.render(window);

    for (auto i : swagBalls ) {
        i.render(window);
    }

    window -> display();
}
