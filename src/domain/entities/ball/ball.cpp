#include "ball.hpp"

namespace Arcanoid {

Ball::Ball(const std::string& id)
    : id_(id)
{}

const std::string Ball::getId()
{
    return id_;
}

const double Ball::getXPos()
{
    return xPos_;
}

const double Ball::getYPos()
{
    return yPos_;
}

void Ball::setXPos(const double x)
{
    xPos_ = x;
}

void Ball::setYPos(const double y)
{
    yPos_ = y;
}

}