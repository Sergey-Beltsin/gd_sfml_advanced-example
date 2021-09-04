#include "SwagBall.h"

void SWAG_BALL::SwagBall::initShape(const sf::RenderTarget * target) {
    shape.setRadius(static_cast<float>(rand() % 10 + 10));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    shape.setFillColor(color);
    const float positionX = rand() % target -> getSize().x;
    const float positionY = rand() % target -> getSize().y;
    shape.setPosition(
        sf::Vector2f(
            static_cast<float>(positionX > target -> getSize().x ? positionX - shape.getGlobalBounds().width : positionX),
            static_cast<float>(positionY > target -> getSize().y ? positionY - shape.getGlobalBounds().height : positionY)
        )
    );
}

SWAG_BALL::SwagBall::SwagBall(const sf::RenderTarget * target) {
    initShape(target);
}

SWAG_BALL::SwagBall::~SwagBall() {

}

void SWAG_BALL::SwagBall::update() {

}

void SWAG_BALL::SwagBall::render(sf::RenderTarget * target) {
    target -> draw(shape);
}
