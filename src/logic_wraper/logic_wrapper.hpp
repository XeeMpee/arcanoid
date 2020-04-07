#pragma once
#include <memory>
#include "logic_wraper/event.hpp"

class LogicWrapper
{
private:
    virtual void onEvent(std::unique_ptr<Event> event) = 0;

public:
    LogicWrapper(/* args */);
    virtual ~LogicWrapper() = default;
};
