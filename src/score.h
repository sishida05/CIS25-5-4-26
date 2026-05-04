#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score {
public:
    Score();
    ~Score();
    void addPoints(int points);
    void reset();
    int getScore() const;
    std::string formatted() const;
private:
    int score;
};

#endif