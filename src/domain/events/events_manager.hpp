#pragma once
#include <vector>
#include <memory>

#include "events.hpp"

class EventsManager
{
public:
    void sendInputEvent(std::unique_ptr<IEvent> event);
    void receiveInputEvent(std::unique_ptr<IEvent> event);

private:
    std::vector<std::unique_ptr<IEvent>> inputEventsQueue_;
    std::vector<std::unique_ptr<IEvent>> outputEventsQueue_;
};