#include "score.h"
#include <sstream>

Score::Score() : score(0) {}

Score::~Score() {}

void Score::addPoints(int points) {
    score += points;
}

void Score::reset() {
    score = 0;
}

int Score::getScore() const {
    return score;
}

std::string Score::formatted() const {
    std::ostringstream oss;
    oss << score;
    return oss.str();
}