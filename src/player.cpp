#include "player.h"

Player::Player() : Entity(0, 0) {}

Player::Player(float x, float y) : Entity(x, y) {}

Player::~Player() {}

void Player::handleInput(char key) {
    // Stub: Handle keys
    if (key == 'a' || key == 'A') {
        vx = -5.0f;
    } else if (key == 'd' || key == 'D') {
        vx = 5.0f;
    } else if (key == ' ') {
        if (onGround) {
            vy = -10.0f; // Jump
        }
    } else {
        vx = 0;
    }
}

void Player::update(const Level& level, float dt) {
    Entity::update(level, dt);
}

void Player::reset() {
    x = 1;
    y = 8;
    vx = 0;
    vy = 0;
}