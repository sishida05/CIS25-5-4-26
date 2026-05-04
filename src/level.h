#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

class Level {
public:
    Level();
    ~Level();
    void loadDemoLevel();
    bool isSolid(int x, int y) const;
    bool isHazard(int x, int y) const;
    bool isGoal(int x, int y) const;
    char getTile(int x, int y) const;
private:
    std::vector<std::vector<char>> grid;
    int width, height;
};

#endif