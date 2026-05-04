#ifndef GAME_H
#define GAME_H

#include "level.h"
#include "player.h"
#include "renderer.h"
#include "timer.h"
#include "score.h"

class Game {
public:
    Game();
    ~Game();
    void initialize();
    void run();
    void update(float dt);
    void render();
    void shutdown();
private:
    Level level;
    Player player;
    Renderer renderer;
    Timer timer;
    Score score;
    bool running;
    char readKey(); // Direct input handling
};

#endif