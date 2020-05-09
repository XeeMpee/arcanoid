#pragma once
#include <string>

class ISprite
{
public:
    virtual ~ISprite() = default;
    virtual const std::string getId() = 0;
    virtual double getXPos() = 0;
    virtual double getYPos() = 0;
    virtual void setXPos(double x) = 0;
    virtual void setYPos(double y) = 0;
};
