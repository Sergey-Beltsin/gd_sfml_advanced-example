#include "Game.h"

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    GAME::Game game;

    while (game.getIsWindowOpen()) {
        game.update();
        game.render();
    }

    return 0;
}
