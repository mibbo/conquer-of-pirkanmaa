#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H
#include <QtWidgets>

namespace Student  {

/**
 * @brief The HoverButton class is a custom QPushButton that has
 * hover events added to the button.
 */
class HoverButton : public QPushButton
{
    Q_OBJECT
public:
    explicit HoverButton(QWidget *parent = 0);

protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

signals:
    void buttonInfoSignal(std::string text);

public slots:
};

}
#endif // HOVERBUTTON_H