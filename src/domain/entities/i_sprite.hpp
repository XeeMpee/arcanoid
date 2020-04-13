#pragma once
#include <string>

class ISprite
{
public:
    virtual const std::string getId() = 0;
    virtual const double getXPos() = 0;
    virtual const double getYPos() = 0;
    virtual void setXPos(const double x) = 0;
    virtual void setYPos(const double y) = 0;
    virtual ~ISprite() = default;
};
