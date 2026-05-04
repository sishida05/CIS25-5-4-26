#include "game.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

Game::Game() : running(false) {}

Game::~Game() {}

void Game::initialize() {
    // Stub: Set up terminal, load level, etc.
    std::cout << "Initializing game..." << std::endl;
    level.loadDemoLevel();
    player.reset(); // Set to start position
    timer.start();
    score.reset();
    running = true;
}

void Game::run() {
    initialize();
    while (running) {
        char key = readKey();
        player.handleInput(key);
        update(0.016f); // Stub delta time
        render();
        // Check win/lose
        if (level.isGoal(static_cast<int>(player.getX()), static_cast<int>(player.getY()))) {
            score.addPoints(100);
            running = false;
        }
        if (level.isHazard(static_cast<int>(player.getX()), static_cast<int>(player.getY()))) {
            running = false;
        }
    }
    shutdown();
}

void Game::update(float dt) {
    // Stub: Handle input, update player, etc.
    player.update(level, dt);
    timer.update();
    // Deduct points over time
    score.addPoints(-1); // Stub
}

void Game::render() {
    renderer.renderFrame(level, player, score, timer);
}

void Game::shutdown() {
    // Stub: Restore terminal
    std::cout << "Shutting down..." << std::endl;
    timer.stop();
}

char Game::readKey() {
    // Stub: Raw input
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    char ch = 0;
    read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}