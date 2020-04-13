#include "board.hpp"

Board::Board(double length, const std::string &id)
    : length_(length)
    , id_(id)
{}

const std::string Board::getId()
{
    return id_;
}

const double Board::getXPos()
{
    return xPos_;
}

const double Board::getYPos()
{
    return yPos_;
}

const double Board::getLength()
{
    return length_;
}

void Board::setXPos(const double x)
{
    xPos_ = x;
}

void Board::setYPos(const double y)
{
    yPos_ = y;
}