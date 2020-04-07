#include "ball.hpp"

Ball::Ball(double length)
    : length_(length)
{}


const double Ball::getXPos()
{
    return xPos_;
}

const double Ball::getYPos()
{
    return yPos_;
}

const double Ball::getLength()
{
    return length_;
}

void Ball::setXPos(const double x)
{
    xPos_ = x;
}

void Ball::setYPos(const double y)
{
    yPos_ = y;
}