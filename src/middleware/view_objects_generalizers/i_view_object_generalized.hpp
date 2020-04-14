#pragma once
#include <vector>
#include <memory>

/**
 * Class IViewObjectGeneralized 
 * 
 */
template<typename T>
class IViewObjectGeneralized
{
public:
    /// Inits passed sprites.
    virtual void initSprites(std::vector<std::shared_ptr<T>> sprites) = 0;
    virtual ~IViewObjectGeneralized() = default;
};


