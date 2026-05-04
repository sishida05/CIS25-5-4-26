#include "level.h"

Level::Level() : width(20), height(10) {
    grid.assign(height, std::vector<char>(width, ' '));
}

Level::~Level() {}

void Level::loadDemoLevel() {
    // Stub: Create a simple level
    for (int x = 0; x < width; ++x) {
        grid[9][x] = '#'; // Ground
    }
    grid[9][5] = ' '; // Gap
    grid[9][6] = ' ';
    grid[8][5] = '^'; // Hazard
    grid[9][15] = 'G'; // Goal
}

bool Level::isSolid(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return true;
    return grid[y][x] == '#';
}

bool Level::isHazard(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return grid[y][x] == '^';
}

bool Level::isGoal(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return grid[y][x] == 'G';
}

char Level::getTile(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return ' ';
    return grid[y][x];
}