#pragma once
#include <vector>
#include <memory>

/**
 * Class IViewObjectGeneralized 
 * 
 */
class IViewObjectGeneralized
{
public:
    /// Inits passed sprites.
    virtual void initSprites(std::vector<std::shared_ptr<ISprite>> sprites) = 0;
    virtual void show() = 0;
    virtual ~IViewObjectGeneralized() = default;
};


