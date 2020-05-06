#include <QQmlContext>
#include <QQuickStyle>
#include <boost/type_index.hpp>
#include "utils/vector_subtype_converter.hpp"

#include "q_view_object.hpp"

#include <domain/entities/board/qboard.hpp>
#include <domain/entities/ball/qball.hpp>
#include <domain/entities/block/qblock.hpp>

/**
 * Initialize qt view
 * Registers ISpriteDecotation QT using classes.
 *
 */
QViewObject::QViewObject()
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
void QViewObject::registerQmlTypes()
{
    qmlRegisterType<QGame>("com.game", 1, 0, "Game");
    qmlRegisterType<QBoard>("com.game.entities", 1, 0, "Board");
}

/**
 *  Inits game logic in qt impplementation of presentation layer.
 */
void QViewObject::initGame(std::shared_ptr<IGame> game)
{
    game_ = std::make_shared<QGame>(game);
    if (game_ == nullptr)
    {
        const std::string errorMessage = fmt::format("QViewObjectGeneralized::initGame() | Game logic QGame  uninitialized");
        spdlog::error(errorMessage);
        throw std::runtime_error{errorMessage};
    }
    view_->rootContext()->setContextProperty("game", game_.get());
}

/**
 * Set context properties in root context of QQuickView
 * @param sprites decorated sprites with qt object derivered decorator
 * @throw std::runtime_error when downcasting fails
 */
template<typename SpriteQType>
void QViewObject::initSprites(std::vector<std::shared_ptr<ISprite>> sprites)
{
    for (auto i : sprites)
    {
        //TODO: keep SpriteQType *sprite as <<unique_ptr>> in some kind of member vector
        // Then it will be destroed automaticly on <<this>> destroy...

        SpriteQType *sprite = new SpriteQType(i);
        if (sprite == nullptr)
        {
            const std::string errorMessage = fmt::format("QViewObject::initSprites() | Sprite of type {} is invalid.",
                boost::typeindex::type_id_with_cvr<SpriteQType>().pretty_name());
            spdlog::error(errorMessage);
            throw std::runtime_error{errorMessage};
        }
        view_->rootContext()->setContextProperty(sprite->getId().c_str(), sprite);
    }
}

void QViewObject::initSprites(std::vector<std::shared_ptr<Board>> sprites)
{
    initSprites<QBoard>(VectorSubtypeConverter::convert<ISprite, Board>(sprites));
}

void QViewObject::initSprites(std::vector<std::shared_ptr<Ball>> sprites)
{
    initSprites<QBall>(VectorSubtypeConverter::convert<ISprite, Ball>(sprites));
}

void QViewObject::initSprites(std::vector<std::shared_ptr<Block>> sprites)
{
    initSprites<QBlock>(VectorSubtypeConverter::convert<ISprite, Block>(sprites));
}


/**
 *  Execs QQuickView::show() and QApplication::exec() functions
 *  to display presentation layer.
 */
void QViewObject::show()
{
    spdlog::info("Showing qt view...");
    view_->show();
    app_.exec();
}
