#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
public:
    Player();
    Player(float x, float y);
    ~Player();
    void handleInput(char key);
    void update(const Level& level, float dt) override;
    void reset();
private:
    // Player-specific state
};

#endif