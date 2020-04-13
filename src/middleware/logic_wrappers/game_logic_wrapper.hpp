#include "logic_wrapper/logic_wrapper.hpp"


class GameLogicWrapper : public LogicWrapper
{
private:
    void onEvent(std::unique_ptr<Event> event) override;

public:
    GameLogicWrapper(/* args */);
    ~GameLogicWrapper();

};
