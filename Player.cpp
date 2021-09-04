#include "Player.h"

void PLAYER::Player::initVariables() {
    movementSpeed = 5.0f;
    hpMax = MAX_HP;
    hp = hpMax;
}

void PLAYER::Player::initShape() {
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(PLAYER::PLAYER_WIDTH, PLAYER::PLAYER_HEIGHT));
}

PLAYER::Player::Player(float x, float y) {
    shape.setPosition(x, y);

    initVariables();
    initShape();
}

PLAYER::Player::~Player() {

}

void PLAYER::Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-movementSpeed, 0.0f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(movementSpeed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0.0f, -movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0.0f, movementSpeed);
    }
}

void PLAYER::Player::updateWindowBoundsCollision(const sf::RenderTarget * target) {
    // Left
    if (shape.getGlobalBounds().left <= 0.0f) {
        shape.setPosition(0.0f, shape.getGlobalBounds().top);
    }
    // Right
    if (static_cast<unsigned int>(shape.getGlobalBounds().left + shape.getGlobalBounds().width) >= target -> getSize().x) {
        shape.setPosition(target -> getSize().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);
    }
    // Top
    if (shape.getGlobalBounds().top <= 0.0f) {
        shape.setPosition(shape.getGlobalBounds().left, 0.0f);
    }
    // Bottom
    if (static_cast<unsigned int>(shape.getGlobalBounds().top + shape.getGlobalBounds().height) >= target -> getSize().y) {
        shape.setPosition(shape.getGlobalBounds().left, target -> getSize().y - shape.getGlobalBounds().height);
    }
}

void PLAYER::Player::update(const sf::RenderTarget * target) {
    updateInput();

    updateWindowBoundsCollision(target);
}

void PLAYER::Player::render(sf::RenderTarget * target) {
    target -> draw(shape);
}
