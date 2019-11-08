#include "startwindow.h"
#include "ui_startwindow.h"
#include <string>

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
    emit startGame(playerAmount, mapWidth, mapHeight);
}

void StartWindow::on_spinBox_valueChanged(int value)
{
    playerAmount = value;
}

void StartWindow::on_mapSizeComboBox_currentTextChanged(const QString &value)
{
    std::string valueString = value.toUtf8().constData();
    if (valueString == "Small") {
        mapWidth = 10;
        mapHeight = 10;
    } else if (valueString == "Normal") {
        mapWidth = 20;
        mapHeight = 20;
    } else if (valueString == "Huge") {
        mapWidth = 30;
        mapHeight = 30;
    }
}
