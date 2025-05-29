#pragma once

template<typename EventType>
class EventCommand {
public:
    virtual void execute(const EventType& event) = 0;
};
