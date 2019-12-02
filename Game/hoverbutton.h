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
    /**
     * @brief emits event when entering button area
     *
     * @param QHoverEvent hover enter event
     */
    void hoverEnter(QHoverEvent *event);

    /**
     * @brief emits event when leaving button area
     *
     * @param QHoverEvent hover leave event
     */
    void hoverLeave(QHoverEvent *event);

    /**
     * @brief emits event when moving in button area
     *
     * @param QHoverEvent hover move event
     */
    void hoverMove(QHoverEvent *event);

    /**
     * @brief emits data when hover events happen
     *
     * @param QEvent hover  event
     */
    bool event(QEvent *event);

signals:
    void buttonInfoSignal(std::string text);

public slots:
};

}
#endif // HOVERBUTTON_H
