#include <spdlog/spdlog.h>
#include <memory>

#include "domain/game/game.hpp"
#include "middleware/view_objects_generalizers/q_view_object_generalized.hpp"


int main(int argc, char *argv[])
{
    spdlog::info("Application running...");
    std::unique_ptr<IViewObjectGeneralized> view = std::make_unique<QViewObjectGeneralized>();
    spdlog::info("View has been initialized");
    Game game{std::move(view)};
    game.run();
    view->show();
    spdlog::info("Exiting arcanoid");
}
