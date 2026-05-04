#ifndef RENDERER_H
#define RENDERER_H

#include "level.h"
#include "player.h"
#include "score.h"
#include "timer.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void initialize();
    void renderFrame(const Level& level, const Player& player, const Score& score, const Timer& timer);
    void clearScreen();
    void setCursor(int x, int y);
private:
    int width, height;
};

#endif