#include "startwindow.h"
#include "ui_startwindow.h"
#include <QColorDialog>

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // Setup the combobox
    ui->mapSizeComboBox->addItem("Small");
    ui->mapSizeComboBox->addItem("Normal");
    ui->mapSizeComboBox->addItem("Huge");

    // Set colorselection buttons
    ui->playerOneColor->setStyleSheet(QString("background-color: %1").arg(playerOneColor_.name()));
    ui->playerTwoColor->setStyleSheet(QString("background-color: %1").arg(playerTwoColor_.name()));
    ui->playerOneColor->setText(ui->playerOne->text());
    ui->playerTwoColor->setText(ui->playerTwo->text());
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_playButton_clicked()
{
    playerOne_ = ui->playerOne->text();
    playerTwo_ = ui->playerTwo->text();
    emit startGame(mapWidth, mapHeight, playerOne_, playerTwo_, playerOneColor_, playerTwoColor_);
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

void StartWindow::on_playerOneColor_clicked()
{
    // Open color selection, save the selected color to variable and update the buttoncolor
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose player 1 color");
    if(color.isValid()) {
        playerOneColor_ = color;
        ui->playerOneColor->setStyleSheet(QString("background-color: %1").arg(color.name()));
    }
}

void StartWindow::on_playerTwoColor_clicked()
{
    // Open color selection, save the selected color to variable and update the buttoncolor
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose player 2 color");
    if(color.isValid()) {
        playerTwoColor_ = color;
        ui->playerTwoColor->setStyleSheet(QString("background-color: %1").arg(color.name()));
    }
}

void StartWindow::on_playerOne_textChanged(const QString &text)
{
    // Set the new name to the colorbutton
    ui->playerOneColor->setText(text);
}

void StartWindow::on_playerTwo_textChanged(const QString &text)
{
    // Set the new name to the colorbutton
    ui->playerTwoColor->setText(text);
}
