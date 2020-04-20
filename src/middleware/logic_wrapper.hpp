#pragma once
#include <memory>
#include "event.hpp"

class LogicWrapper
{
private:
    virtual void onEvent(std::unique_ptr<Event> event) = 0;

public:
    void event(std::unique_ptr<Event> event);
    virtual ~LogicWrapper() = default;
};

// ----------------------------------------------------

void LogicWrapper::event(std::unique_ptr<Event> event)
{
    onEvent(std::move(event));
}
