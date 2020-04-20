#include <spdlog/spdlog.h>
#include <memory>

#include "domain/game/game.hpp"
#include "middleware/view_objects_generalizers/q_view_object_generalized.hpp"


int main(int argc, char *argv[])
{
    spdlog::info("Application running...");
    std::shared_ptr<IViewObjectGeneralized> view = std::make_shared<QViewObjectGeneralized>();
    spdlog::info("View has been initialized");
    Game game{view};
    auto gameFuture = game.run();
    spdlog::info("Game loop ran");
    view->show();

    spdlog::info("Exiting arcanoid");
}
