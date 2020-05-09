#include "ball.hpp"

Ball::Ball(const std::string& id)
    : id_(id)
{}

const std::string Ball::getId()
{
    return id_;
}

double Ball::getXPos()
{
    return xPos_;
}

double Ball::getYPos()
{
    return yPos_;
}

void Ball::setXPos(double x)
{
    xPos_ = x;
}

void Ball::setYPos(double y)
{
    yPos_ = y;
}
