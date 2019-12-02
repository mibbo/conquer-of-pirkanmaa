#ifndef STARTWINDOW_HH
#define STARTWINDOW_HH

#include <QDialog>
#include <QString>

namespace Ui {
class StartWindow;
}

/**
 * @brief The StartWindow class is a custom Qdialog that pops
 * a starting window when starting the game.
 *
 * In starting window players can set their names and colors.
 * Also the map size form 3 options (small/normal/huge).
 */
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    /**
     * @brief emits all the data from startWindow to game.cpp
     */
    void on_playButton_clicked();

    /**
     * @brief setups mapsize according to selected size
     *
     * @param const QString map size value as a string (small/normal/huge)
     */
    void on_mapSizeComboBox_currentTextChanged(const QString &value);

    /**
     * @brief Open color selection, save the selected color to variable and update the buttoncolor
     */
    void on_playerOneColor_clicked();

    /**
     * @brief Open color selection, save the selected color to variable and update the buttoncolor
     */
    void on_playerTwoColor_clicked();

    /**
     * @brief Set the new name to the colorbutton
     */
    void on_playerOne_textChanged(const QString &arg1);

    /**
     * @brief Set the new name to the colorbutton
     */
    void on_playerTwo_textChanged(const QString &arg1);

signals:
    void startGame(unsigned int mapWidth, unsigned int mapHeight, QString playerOne, QString playerTwo,
                   QColor playerOneColor, QColor playerTwoColor);

private:
    Ui::StartWindow *ui;
    unsigned int mapWidth;
    unsigned int mapHeight;
    QString playerOne_;
    QString playerTwo_;
    QColor playerOneColor_ = Qt::darkBlue;
    QColor playerTwoColor_ = Qt::darkRed;
};

#endif // STARTWINDOW_HH
