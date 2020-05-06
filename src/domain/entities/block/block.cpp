#include "block.hpp"

Block::Block(double length, const std::string &id)
    : length_(length)
    , id_(id)
{}

const std::string Block::getId()
{
    return id_;
}

const double Block::getXPos()
{
    return xPos_;
}

const double Block::getYPos()
{
    return yPos_;
}

const double Block::getLength()
{
    return length_;
}

void Block::setXPos(const double x)
{
    xPos_ = x;
}

void Block::setYPos(const double y)
{
    yPos_ = y;
}