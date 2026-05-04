#include "timer.h"
#include <sstream>
#include <iomanip>

Timer::Timer() : running(false) {}

Timer::~Timer() {}

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
    running = true;
}

void Timer::stop() {
    running = false;
}

void Timer::update() {
    // No-op, elapsed is calculated on demand
}

double Timer::elapsedSeconds() const {
    if (!running) return 0.0;
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(now - startTime).count();
}

std::string Timer::formatted() const {
    double secs = elapsedSeconds();
    int minutes = static_cast<int>(secs) / 60;
    int seconds = static_cast<int>(secs) % 60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    return oss.str();
}