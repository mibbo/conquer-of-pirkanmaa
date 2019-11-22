#ifndef STARTWINDOW_HH
#define STARTWINDOW_HH

#include <QDialog>
#include <QString>

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_playButton_clicked();

    void on_mapSizeComboBox_currentTextChanged(const QString &value);

    void on_playerOneColor_clicked();

    void on_playerTwoColor_clicked();

    void on_playerOne_textChanged(const QString &arg1);

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
