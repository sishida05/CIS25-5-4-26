#include "renderer.h"
#include <iostream>
#include <vector>

Renderer::Renderer() : width(20), height(10) {}

Renderer::~Renderer() {}

void Renderer::initialize() {
    // Stub
}

void Renderer::renderFrame(const Level& level, const Player& player, const Score& score, const Timer& timer) {
    clearScreen();
    // Stub: Draw level grid
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (static_cast<int>(player.getX()) == x && static_cast<int>(player.getY()) == y) {
                std::cout << '@';
            } else {
                // Draw level tile
                std::cout << level.getTile(x, y); // Assume Level has getTile
            }
        }
        std::cout << std::endl;
    }
    // UI
    std::cout << "Score: " << score.formatted() << " Time: " << timer.formatted() << std::endl;
}

void Renderer::clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI clear
}

void Renderer::setCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}