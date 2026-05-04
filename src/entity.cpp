#include "entity.h"

Entity::Entity(float x, float y) : x(x), y(y), vx(0), vy(0), onGround(false) {}

Entity::~Entity() {}

void Entity::update(const Level& level, float dt) {
    applyGravity(dt);
    move(vx * dt, vy * dt);
    checkCollision(level);
}

void Entity::applyGravity(float dt) {
    if (!onGround) {
        vy += 9.8f * dt; // Stub gravity
    }
}

void Entity::move(float dx, float dy) {
    x += dx;
    y += dy;
}

bool Entity::checkCollision(const Level& level) {
    // Stub: Simple collision
    int ix = static_cast<int>(x);
    int iy = static_cast<int>(y);
    if (level.isSolid(ix, iy)) {
        // Adjust position
        y = iy - 1; // Above solid
        vy = 0;
        onGround = true;
    } else {
        onGround = false;
    }
    return false;
}

float Entity::getX() const { return x; }

float Entity::getY() const { return y; }