#include "hoverbutton.h"
#include "QtDebug"
#include <iostream>

namespace Student {

HoverButton::HoverButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
    setCheckable(true);
}

void HoverButton::hoverEnter(QHoverEvent *)
{
    QFont font = this->font();
    font.setBold(true);
    this->setFont(font);
    repaint();
}

void HoverButton::hoverLeave(QHoverEvent *)
{
    QFont font = this->font();
    font.setBold(false);
    this->setFont(font);
    repaint();
}

void HoverButton::hoverMove(QHoverEvent *)
{
    QFont font = this->font();
    font.setBold(true);
    this->setFont(font);
    repaint();
}

bool HoverButton::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        emit buttonInfoSignal(this->text().toStdString());
        return true;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
    default:
        break;
    }
    return QWidget::event(event);
}

} // namespace Student
