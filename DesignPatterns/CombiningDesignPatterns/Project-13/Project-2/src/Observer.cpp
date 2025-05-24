
#include "Observer.hpp"
#include <algorithm>  // <-- Required for std::remove

void Subject::attach(Observer* obs) {
    observers_.push_back(obs);
}

void Subject::detach(Observer* obs) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
}

void Subject::notify(const std::string& state) {
    for (auto obs : observers_) {
        obs->update(state);
    }
}
