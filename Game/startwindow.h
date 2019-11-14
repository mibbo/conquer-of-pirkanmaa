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

    void on_spinBox_valueChanged(int value);

    void on_mapSizeComboBox_currentTextChanged(const QString &value);

signals:
    void startGame(int playerAmount, unsigned int mapWidth, unsigned int mapHeight, QString playerOne, QString playerTwo);

private:
    Ui::StartWindow *ui;
    int playerAmount;
    unsigned int mapWidth;
    unsigned int mapHeight;
    QString playerOne_;
    QString playerTwo_;
};

#endif // STARTWINDOW_HH
