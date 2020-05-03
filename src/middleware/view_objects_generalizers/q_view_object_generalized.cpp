#include <QQmlContext>
#include <QQuickStyle>

#include "q_view_object_generalized.hpp"
#include <domain/game/qgame.hpp>
#include <domain/entities/board/qboard.hpp>

/**
 * Initialize qt view
 * Registers ISpriteDecotation QT using classes.
 *
 */
QViewObjectGeneralized::QViewObjectGeneralized()
    : app_{argcFake, {}}
    , view_{nullptr}
{
    // Qt App initialization:
    spdlog::info("Initialing QT based view...");
    // Registing types types:
    registerQmlTypes();
    // Qt View initialization:
    view_ = std::make_unique<QQuickView>();
    view_->setSource(QUrl("qrc:///qml/Main.qml"));
}

/**
 * Registers QML Types
 * To register new class invoke qmlRegister<NewType>(<params>) function.
 */
void QViewObjectGeneralized::registerQmlTypes()
{

    qmlRegisterType<QGame>("com.game", 1, 0, "Game");
    qmlRegisterType<QBoard>("com.game.entities", 1, 0, "Board");
}

/**
 *  Inits game logic in qt impplementation of presentation layer.
 */
void QViewObjectGeneralized::initGame(std::shared_ptr<IGame> game)
{
    auto qgame = std::make_shared<QGame>(game);
    if (qgame == nullptr)
    {
        const std::string errorMessage = fmt::format("QViewObjectGeneralized::initGame() | Game logic QGame  uninitialized");
        spdlog::error(errorMessage);
        throw std::runtime_error{errorMessage};
    }
    view_->rootContext()->setContextProperty("game", qgame.get());
}

/**
 * Set context properties in root context of QQuickView
 * @param sprites decorated sprites with qt object derivered decorator
 * @throw std::runtime_error when downcasting fails
 */
void QViewObjectGeneralized::initSprites(std::vector<std::shared_ptr<ISprite>> sprites)
{
    for (auto i : sprites)
    {
        auto qsprite = std::dynamic_pointer_cast<QObject>(i);
        if (qsprite == nullptr)
        {
            const std::string errorMessage = fmt::format(
                "QViewObjectGeneralized::initSprites() | Sprite downcasting error: {} smart pointer to QObject smart pointer.", i->getId());
            spdlog::error(errorMessage);
            throw std::runtime_error{errorMessage};
        }
        view_->rootContext()->setContextProperty(i->getId().c_str(), qsprite.get());
    }
}

void QViewObjectGeneralized::show()
{
    spdlog::info("Showing qt view...");
    view_->show();
    app_.exec();
}
