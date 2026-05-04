#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <chrono>

class Timer {
public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void update();
    double elapsedSeconds() const;
    std::string formatted() const;
private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    bool running;
};

#endif