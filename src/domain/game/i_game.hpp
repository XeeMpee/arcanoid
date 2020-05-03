#pragma once

/**
 *  IGame interface - all games logics, that will be build should implements it.
 *  It will allow to decorate it in proper way and pass to presentation layer.
 */
class IGame
{
public:
    virtual ~IGame() = default;
    virtual void run() = 0;
    virtual void stop() = 0;
};
