#include "block.hpp"

Block::Block(double length, const std::string &id)
    : length_(length)
    , id_(id)
{}

const std::string Block::getId()
{
    return id_;
}

double Block::getXPos()
{
    return xPos_;
}

double Block::getYPos()
{
    return yPos_;
}

void Block::setXPos(double x)
{
    xPos_ = x;
}

void Block::setYPos(double y)
{
    yPos_ = y;
}