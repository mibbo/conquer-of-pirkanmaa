#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // fetch git version here
    ui->hashLabel->setText(GIT_REVISION);

    ui->mapSizeComboBox->addItem("Small");
    ui->mapSizeComboBox->addItem("Normal");
    ui->mapSizeComboBox->addItem("Huge");

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_playButton_clicked()
{
    playerOne_ = ui->playerOne->text();
    playerTwo_ = ui->playerTwo->text();
    emit startGame(mapWidth, mapHeight, playerOne_, playerTwo_);
}

void StartWindow::on_mapSizeComboBox_currentTextChanged(const QString &value)
{
    std::string valueString = value.toUtf8().constData();
    if (valueString == "Small") {
        mapWidth = 10;
        mapHeight = 10;
    } else if (valueString == "Normal") {
        mapWidth = 16;
        mapHeight = 16;
    } else if (valueString == "Huge") {
        mapWidth = 20;
        mapHeight = 20;
    }
}
