#ifndef ENTITY_H
#define ENTITY_H

#include "level.h"

class Entity {
public:
    Entity(float x, float y);
    virtual ~Entity();
    virtual void update(const Level& level, float dt);
    void applyGravity(float dt);
    void move(float dx, float dy);
    bool checkCollision(const Level& level);
    float getX() const;
    float getY() const;
protected:
    float x, y;
    float vx, vy;
    bool onGround;
};

#endif