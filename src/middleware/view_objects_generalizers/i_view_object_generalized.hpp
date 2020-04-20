#pragma once
#include <vector>
#include <memory>

#include "domain/entities/i_sprite_decorator.hpp"

/**
 * Class IViewObjectGeneralized 
 * 
 */
class IViewObjectGeneralized
{
public:
    /// Inits passed sprites.
    virtual void initSprites(std::vector<std::shared_ptr<ISpriteDecorator>> sprites) = 0;
    virtual void show() = 0;
    virtual ~IViewObjectGeneralized() = default;
};


