#pragma once

#include <QObject>
#include "domain/entities/i_sprite_decorator.hpp"
#include "board.hpp"

class QBoard : public QObject, public ISpriteDecorator
{
    Q_OBJECT
    Q_PROPERTY(double x READ getXPos WRITE setXPos NOTIFY xPosChanged)
    Q_PROPERTY(double y READ getYPos WRITE setYPos NOTIFY yPosChanged)
    Q_PROPERTY(double length READ getLength WRITE setLength NOTIFY lengthChanged)


public:
    QBoard() = default;
    QBoard(std::shared_ptr<ISprite> sprite);
    ~QBoard() = default;

    void decorate(std::shared_ptr<ISprite> sprite) override;

    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(double x) override;
    void setYPos(double y) override;
    const double getWidth();
    const double setWidth(const double width);

    const double getLength();
    void setLength(const double length);


signals:
    void xPosChanged(const double& newValue);
    void yPosChanged(const double& newValue);
    void lengthChanged(const double& newValue);


private:
    std::shared_ptr<Board> decoratedSprite_;

};
