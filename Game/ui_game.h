/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "hoverbutton.h"

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    Student::HoverButton *turnButton;
    QLabel *turnLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *buildingsLayout;
    Student::HoverButton *farmButton;
    Student::HoverButton *mineButton;
    Student::HoverButton *outpostButton;
    Student::HoverButton *quarryButton;
    Student::HoverButton *sawmillButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *workersLayout;
    Student::HoverButton *basicWorkerButton;
    Student::HoverButton *warriorButton;
    Student::HoverButton *constWorkerButton;
    QLabel *hoverInfo;
    QLabel *label;
    QLabel *buildingNameLabel;
    QLabel *moneyLabel;
    QLabel *woodLabel;
    QLabel *stoneLabel;
    QLabel *oreLabel;
    QLabel *foodLabel;
    QLabel *moneyProductionLabel;
    QLabel *foodProductionLabel;
    QLabel *woodProductionLabel;
    QLabel *stoneProductionLabel;
    QLabel *oreProductionLabel;
    QLabel *buildCostLabel;
    QLabel *productionLabel;
    QWidget *formLayoutWidget_7;
    QFormLayout *formLayoutPlayers;
    QFormLayout *formLayoutP2;
    QFormLayout *formLayoutResourcesP2;
    QLCDNumber *moneyP2;
    QLabel *labelFoodP2;
    QLCDNumber *foodP2;
    QLabel *labelWoodP2;
    QLCDNumber *woodP2;
    QLabel *labelStoneP2;
    QLCDNumber *stoneP2;
    QLabel *labelOreP2;
    QLCDNumber *oreP2;
    QLabel *labelMoneyP2;
    QFormLayout *formLayout_3;
    QLabel *labelMovesP2;
    QLCDNumber *movesP2;
    QLabel *labelTilesP2;
    QLCDNumber *tilesP2;
    QLabel *labelPowerP2;
    QLCDNumber *powerP2;
    QLabel *playerNameP2;
    QFormLayout *formLayoutP1;
    QFormLayout *formLayoutResourcesP1;
    QLabel *labelMoneyP1;
    QLCDNumber *moneyP1;
    QLabel *labelFoodP1;
    QLCDNumber *foodP1;
    QLabel *labelWoodP1;
    QLCDNumber *woodP1;
    QLabel *labelStoneP1;
    QLCDNumber *stoneP1;
    QLabel *labelOreP1;
    QLCDNumber *oreP1;
    QFormLayout *formLayoutOtherP1;
    QLabel *labelMovesP1;
    QLCDNumber *movesP1;
    QLabel *labelTilesP1;
    QLCDNumber *tilesP1;
    QLabel *labelPowerP1;
    QLCDNumber *powerP1;
    QLabel *playerNameP1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(2006, 882);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 691, 481));
        turnButton = new Student::HoverButton(centralwidget);
        turnButton->setObjectName(QString::fromUtf8("turnButton"));
        turnButton->setGeometry(QRect(920, 470, 151, 111));
        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName(QString::fromUtf8("turnLabel"));
        turnLabel->setGeometry(QRect(940, 430, 221, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        turnLabel->setFont(font);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(920, 60, 151, 171));
        buildingsLayout = new QGridLayout(gridLayoutWidget);
        buildingsLayout->setObjectName(QString::fromUtf8("buildingsLayout"));
        buildingsLayout->setContentsMargins(0, 0, 0, 0);
        farmButton = new Student::HoverButton(gridLayoutWidget);
        farmButton->setObjectName(QString::fromUtf8("farmButton"));

        buildingsLayout->addWidget(farmButton, 0, 0, 1, 1);

        mineButton = new Student::HoverButton(gridLayoutWidget);
        mineButton->setObjectName(QString::fromUtf8("mineButton"));

        buildingsLayout->addWidget(mineButton, 1, 0, 1, 1);

        outpostButton = new Student::HoverButton(gridLayoutWidget);
        outpostButton->setObjectName(QString::fromUtf8("outpostButton"));

        buildingsLayout->addWidget(outpostButton, 4, 0, 1, 1);

        quarryButton = new Student::HoverButton(gridLayoutWidget);
        quarryButton->setObjectName(QString::fromUtf8("quarryButton"));

        buildingsLayout->addWidget(quarryButton, 5, 0, 1, 1);

        sawmillButton = new Student::HoverButton(gridLayoutWidget);
        sawmillButton->setObjectName(QString::fromUtf8("sawmillButton"));

        buildingsLayout->addWidget(sawmillButton, 6, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(920, 250, 151, 171));
        workersLayout = new QGridLayout(gridLayoutWidget_2);
        workersLayout->setObjectName(QString::fromUtf8("workersLayout"));
        workersLayout->setContentsMargins(0, 0, 0, 0);
        basicWorkerButton = new Student::HoverButton(gridLayoutWidget_2);
        basicWorkerButton->setObjectName(QString::fromUtf8("basicWorkerButton"));

        workersLayout->addWidget(basicWorkerButton, 0, 0, 1, 1);

        warriorButton = new Student::HoverButton(gridLayoutWidget_2);
        warriorButton->setObjectName(QString::fromUtf8("warriorButton"));

        workersLayout->addWidget(warriorButton, 4, 0, 1, 1);

        constWorkerButton = new Student::HoverButton(gridLayoutWidget_2);
        constWorkerButton->setObjectName(QString::fromUtf8("constWorkerButton"));

        workersLayout->addWidget(constWorkerButton, 1, 0, 1, 1);

        hoverInfo = new QLabel(centralwidget);
        hoverInfo->setObjectName(QString::fromUtf8("hoverInfo"));
        hoverInfo->setGeometry(QRect(0, -10, 2001, 861));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 10, 911, 801));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/sprite/parchment.png")));
        buildingNameLabel = new QLabel(centralwidget);
        buildingNameLabel->setObjectName(QString::fromUtf8("buildingNameLabel"));
        buildingNameLabel->setGeometry(QRect(1190, 80, 361, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        buildingNameLabel->setFont(font1);
        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QString::fromUtf8("moneyLabel"));
        moneyLabel->setGeometry(QRect(1170, 180, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("URW Gothic"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        moneyLabel->setFont(font2);
        woodLabel = new QLabel(centralwidget);
        woodLabel->setObjectName(QString::fromUtf8("woodLabel"));
        woodLabel->setGeometry(QRect(1170, 260, 121, 31));
        woodLabel->setFont(font2);
        stoneLabel = new QLabel(centralwidget);
        stoneLabel->setObjectName(QString::fromUtf8("stoneLabel"));
        stoneLabel->setGeometry(QRect(1170, 300, 121, 31));
        stoneLabel->setFont(font2);
        oreLabel = new QLabel(centralwidget);
        oreLabel->setObjectName(QString::fromUtf8("oreLabel"));
        oreLabel->setGeometry(QRect(1170, 340, 121, 31));
        oreLabel->setFont(font2);
        foodLabel = new QLabel(centralwidget);
        foodLabel->setObjectName(QString::fromUtf8("foodLabel"));
        foodLabel->setGeometry(QRect(1170, 220, 121, 31));
        foodLabel->setFont(font2);
        moneyProductionLabel = new QLabel(centralwidget);
        moneyProductionLabel->setObjectName(QString::fromUtf8("moneyProductionLabel"));
        moneyProductionLabel->setGeometry(QRect(1330, 180, 121, 31));
        moneyProductionLabel->setFont(font2);
        foodProductionLabel = new QLabel(centralwidget);
        foodProductionLabel->setObjectName(QString::fromUtf8("foodProductionLabel"));
        foodProductionLabel->setGeometry(QRect(1330, 220, 121, 31));
        foodProductionLabel->setFont(font2);
        woodProductionLabel = new QLabel(centralwidget);
        woodProductionLabel->setObjectName(QString::fromUtf8("woodProductionLabel"));
        woodProductionLabel->setGeometry(QRect(1330, 260, 121, 31));
        woodProductionLabel->setFont(font2);
        stoneProductionLabel = new QLabel(centralwidget);
        stoneProductionLabel->setObjectName(QString::fromUtf8("stoneProductionLabel"));
        stoneProductionLabel->setGeometry(QRect(1330, 300, 121, 31));
        stoneProductionLabel->setFont(font2);
        oreProductionLabel = new QLabel(centralwidget);
        oreProductionLabel->setObjectName(QString::fromUtf8("oreProductionLabel"));
        oreProductionLabel->setGeometry(QRect(1330, 340, 121, 31));
        oreProductionLabel->setFont(font2);
        buildCostLabel = new QLabel(centralwidget);
        buildCostLabel->setObjectName(QString::fromUtf8("buildCostLabel"));
        buildCostLabel->setGeometry(QRect(1170, 140, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("URW Gothic"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        buildCostLabel->setFont(font3);
        productionLabel = new QLabel(centralwidget);
        productionLabel->setObjectName(QString::fromUtf8("productionLabel"));
        productionLabel->setGeometry(QRect(1330, 140, 121, 31));
        productionLabel->setFont(font3);
        formLayoutWidget_7 = new QWidget(centralwidget);
        formLayoutWidget_7->setObjectName(QString::fromUtf8("formLayoutWidget_7"));
        formLayoutWidget_7->setGeometry(QRect(1090, 420, 511, 211));
        formLayoutPlayers = new QFormLayout(formLayoutWidget_7);
        formLayoutPlayers->setObjectName(QString::fromUtf8("formLayoutPlayers"));
        formLayoutPlayers->setContentsMargins(0, 0, 0, 0);
        formLayoutP2 = new QFormLayout();
        formLayoutP2->setObjectName(QString::fromUtf8("formLayoutP2"));
        formLayoutP2->setFormAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        formLayoutResourcesP2 = new QFormLayout();
        formLayoutResourcesP2->setObjectName(QString::fromUtf8("formLayoutResourcesP2"));
        moneyP2 = new QLCDNumber(formLayoutWidget_7);
        moneyP2->setObjectName(QString::fromUtf8("moneyP2"));

        formLayoutResourcesP2->setWidget(1, QFormLayout::FieldRole, moneyP2);

        labelFoodP2 = new QLabel(formLayoutWidget_7);
        labelFoodP2->setObjectName(QString::fromUtf8("labelFoodP2"));

        formLayoutResourcesP2->setWidget(2, QFormLayout::LabelRole, labelFoodP2);

        foodP2 = new QLCDNumber(formLayoutWidget_7);
        foodP2->setObjectName(QString::fromUtf8("foodP2"));

        formLayoutResourcesP2->setWidget(2, QFormLayout::FieldRole, foodP2);

        labelWoodP2 = new QLabel(formLayoutWidget_7);
        labelWoodP2->setObjectName(QString::fromUtf8("labelWoodP2"));

        formLayoutResourcesP2->setWidget(3, QFormLayout::LabelRole, labelWoodP2);

        woodP2 = new QLCDNumber(formLayoutWidget_7);
        woodP2->setObjectName(QString::fromUtf8("woodP2"));

        formLayoutResourcesP2->setWidget(3, QFormLayout::FieldRole, woodP2);

        labelStoneP2 = new QLabel(formLayoutWidget_7);
        labelStoneP2->setObjectName(QString::fromUtf8("labelStoneP2"));

        formLayoutResourcesP2->setWidget(4, QFormLayout::LabelRole, labelStoneP2);

        stoneP2 = new QLCDNumber(formLayoutWidget_7);
        stoneP2->setObjectName(QString::fromUtf8("stoneP2"));

        formLayoutResourcesP2->setWidget(4, QFormLayout::FieldRole, stoneP2);

        labelOreP2 = new QLabel(formLayoutWidget_7);
        labelOreP2->setObjectName(QString::fromUtf8("labelOreP2"));

        formLayoutResourcesP2->setWidget(5, QFormLayout::LabelRole, labelOreP2);

        oreP2 = new QLCDNumber(formLayoutWidget_7);
        oreP2->setObjectName(QString::fromUtf8("oreP2"));

        formLayoutResourcesP2->setWidget(5, QFormLayout::FieldRole, oreP2);

        labelMoneyP2 = new QLabel(formLayoutWidget_7);
        labelMoneyP2->setObjectName(QString::fromUtf8("labelMoneyP2"));

        formLayoutResourcesP2->setWidget(1, QFormLayout::LabelRole, labelMoneyP2);


        formLayoutP2->setLayout(1, QFormLayout::LabelRole, formLayoutResourcesP2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelMovesP2 = new QLabel(formLayoutWidget_7);
        labelMovesP2->setObjectName(QString::fromUtf8("labelMovesP2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelMovesP2);

        movesP2 = new QLCDNumber(formLayoutWidget_7);
        movesP2->setObjectName(QString::fromUtf8("movesP2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, movesP2);

        labelTilesP2 = new QLabel(formLayoutWidget_7);
        labelTilesP2->setObjectName(QString::fromUtf8("labelTilesP2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelTilesP2);

        tilesP2 = new QLCDNumber(formLayoutWidget_7);
        tilesP2->setObjectName(QString::fromUtf8("tilesP2"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, tilesP2);

        labelPowerP2 = new QLabel(formLayoutWidget_7);
        labelPowerP2->setObjectName(QString::fromUtf8("labelPowerP2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelPowerP2);

        powerP2 = new QLCDNumber(formLayoutWidget_7);
        powerP2->setObjectName(QString::fromUtf8("powerP2"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, powerP2);


        formLayoutP2->setLayout(1, QFormLayout::FieldRole, formLayout_3);

        playerNameP2 = new QLabel(formLayoutWidget_7);
        playerNameP2->setObjectName(QString::fromUtf8("playerNameP2"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nimbus Roman"));
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        playerNameP2->setFont(font4);
        playerNameP2->setAlignment(Qt::AlignCenter);

        formLayoutP2->setWidget(0, QFormLayout::SpanningRole, playerNameP2);


        formLayoutPlayers->setLayout(0, QFormLayout::FieldRole, formLayoutP2);

        formLayoutP1 = new QFormLayout();
        formLayoutP1->setObjectName(QString::fromUtf8("formLayoutP1"));
        formLayoutP1->setLabelAlignment(Qt::AlignCenter);
        formLayoutP1->setFormAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        formLayoutResourcesP1 = new QFormLayout();
        formLayoutResourcesP1->setObjectName(QString::fromUtf8("formLayoutResourcesP1"));
        labelMoneyP1 = new QLabel(formLayoutWidget_7);
        labelMoneyP1->setObjectName(QString::fromUtf8("labelMoneyP1"));

        formLayoutResourcesP1->setWidget(1, QFormLayout::LabelRole, labelMoneyP1);

        moneyP1 = new QLCDNumber(formLayoutWidget_7);
        moneyP1->setObjectName(QString::fromUtf8("moneyP1"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        moneyP1->setFont(font5);

        formLayoutResourcesP1->setWidget(1, QFormLayout::FieldRole, moneyP1);

        labelFoodP1 = new QLabel(formLayoutWidget_7);
        labelFoodP1->setObjectName(QString::fromUtf8("labelFoodP1"));

        formLayoutResourcesP1->setWidget(2, QFormLayout::LabelRole, labelFoodP1);

        foodP1 = new QLCDNumber(formLayoutWidget_7);
        foodP1->setObjectName(QString::fromUtf8("foodP1"));

        formLayoutResourcesP1->setWidget(2, QFormLayout::FieldRole, foodP1);

        labelWoodP1 = new QLabel(formLayoutWidget_7);
        labelWoodP1->setObjectName(QString::fromUtf8("labelWoodP1"));

        formLayoutResourcesP1->setWidget(3, QFormLayout::LabelRole, labelWoodP1);

        woodP1 = new QLCDNumber(formLayoutWidget_7);
        woodP1->setObjectName(QString::fromUtf8("woodP1"));

        formLayoutResourcesP1->setWidget(3, QFormLayout::FieldRole, woodP1);

        labelStoneP1 = new QLabel(formLayoutWidget_7);
        labelStoneP1->setObjectName(QString::fromUtf8("labelStoneP1"));

        formLayoutResourcesP1->setWidget(4, QFormLayout::LabelRole, labelStoneP1);

        stoneP1 = new QLCDNumber(formLayoutWidget_7);
        stoneP1->setObjectName(QString::fromUtf8("stoneP1"));

        formLayoutResourcesP1->setWidget(4, QFormLayout::FieldRole, stoneP1);

        labelOreP1 = new QLabel(formLayoutWidget_7);
        labelOreP1->setObjectName(QString::fromUtf8("labelOreP1"));

        formLayoutResourcesP1->setWidget(5, QFormLayout::LabelRole, labelOreP1);

        oreP1 = new QLCDNumber(formLayoutWidget_7);
        oreP1->setObjectName(QString::fromUtf8("oreP1"));

        formLayoutResourcesP1->setWidget(5, QFormLayout::FieldRole, oreP1);


        formLayoutP1->setLayout(1, QFormLayout::LabelRole, formLayoutResourcesP1);

        formLayoutOtherP1 = new QFormLayout();
        formLayoutOtherP1->setObjectName(QString::fromUtf8("formLayoutOtherP1"));
        labelMovesP1 = new QLabel(formLayoutWidget_7);
        labelMovesP1->setObjectName(QString::fromUtf8("labelMovesP1"));

        formLayoutOtherP1->setWidget(0, QFormLayout::LabelRole, labelMovesP1);

        movesP1 = new QLCDNumber(formLayoutWidget_7);
        movesP1->setObjectName(QString::fromUtf8("movesP1"));

        formLayoutOtherP1->setWidget(0, QFormLayout::FieldRole, movesP1);

        labelTilesP1 = new QLabel(formLayoutWidget_7);
        labelTilesP1->setObjectName(QString::fromUtf8("labelTilesP1"));

        formLayoutOtherP1->setWidget(1, QFormLayout::LabelRole, labelTilesP1);

        tilesP1 = new QLCDNumber(formLayoutWidget_7);
        tilesP1->setObjectName(QString::fromUtf8("tilesP1"));

        formLayoutOtherP1->setWidget(1, QFormLayout::FieldRole, tilesP1);

        labelPowerP1 = new QLabel(formLayoutWidget_7);
        labelPowerP1->setObjectName(QString::fromUtf8("labelPowerP1"));

        formLayoutOtherP1->setWidget(2, QFormLayout::LabelRole, labelPowerP1);

        powerP1 = new QLCDNumber(formLayoutWidget_7);
        powerP1->setObjectName(QString::fromUtf8("powerP1"));

        formLayoutOtherP1->setWidget(2, QFormLayout::FieldRole, powerP1);


        formLayoutP1->setLayout(1, QFormLayout::FieldRole, formLayoutOtherP1);

        playerNameP1 = new QLabel(formLayoutWidget_7);
        playerNameP1->setObjectName(QString::fromUtf8("playerNameP1"));
        playerNameP1->setFont(font4);
        playerNameP1->setAlignment(Qt::AlignCenter);

        formLayoutP1->setWidget(0, QFormLayout::SpanningRole, playerNameP1);


        formLayoutPlayers->setLayout(0, QFormLayout::LabelRole, formLayoutP1);

        Game->setCentralWidget(centralwidget);
        label->raise();
        graphicsView->raise();
        turnButton->raise();
        turnLabel->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        buildingNameLabel->raise();
        moneyLabel->raise();
        woodLabel->raise();
        stoneLabel->raise();
        oreLabel->raise();
        foodLabel->raise();
        moneyProductionLabel->raise();
        foodProductionLabel->raise();
        woodProductionLabel->raise();
        stoneProductionLabel->raise();
        oreProductionLabel->raise();
        buildCostLabel->raise();
        productionLabel->raise();
        formLayoutWidget_7->raise();
        hoverInfo->raise();
        menubar = new QMenuBar(Game);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2006, 23));
        Game->setMenuBar(menubar);
        statusbar = new QStatusBar(Game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Game->setStatusBar(statusbar);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Pirkanmaan Valloitus", nullptr));
        turnButton->setText(QCoreApplication::translate("Game", "End Turn", nullptr));
        turnLabel->setText(QCoreApplication::translate("Game", "Turn: ", nullptr));
        farmButton->setText(QCoreApplication::translate("Game", "Farm", nullptr));
        mineButton->setText(QCoreApplication::translate("Game", "Mine", nullptr));
        outpostButton->setText(QCoreApplication::translate("Game", "Outpost", nullptr));
        quarryButton->setText(QCoreApplication::translate("Game", "Quarry", nullptr));
        sawmillButton->setText(QCoreApplication::translate("Game", "Sawmill", nullptr));
        basicWorkerButton->setText(QCoreApplication::translate("Game", "Basic Worker", nullptr));
        warriorButton->setText(QCoreApplication::translate("Game", "Warrior", nullptr));
        constWorkerButton->setText(QCoreApplication::translate("Game", "Construction Worker", nullptr));
        hoverInfo->setText(QString());
        label->setText(QString());
        buildingNameLabel->setText(QString());
        moneyLabel->setText(QString());
        woodLabel->setText(QString());
        stoneLabel->setText(QString());
        oreLabel->setText(QString());
        foodLabel->setText(QString());
        moneyProductionLabel->setText(QString());
        foodProductionLabel->setText(QString());
        woodProductionLabel->setText(QString());
        stoneProductionLabel->setText(QString());
        oreProductionLabel->setText(QString());
        buildCostLabel->setText(QString());
        productionLabel->setText(QString());
        labelFoodP2->setText(QCoreApplication::translate("Game", "Food", nullptr));
        labelWoodP2->setText(QCoreApplication::translate("Game", "Wood", nullptr));
        labelStoneP2->setText(QCoreApplication::translate("Game", "Stone", nullptr));
        labelOreP2->setText(QCoreApplication::translate("Game", "Ore", nullptr));
        labelMoneyP2->setText(QCoreApplication::translate("Game", "Money", nullptr));
        labelMovesP2->setText(QCoreApplication::translate("Game", "Moves", nullptr));
        labelTilesP2->setText(QCoreApplication::translate("Game", "Tiles", nullptr));
        labelPowerP2->setText(QCoreApplication::translate("Game", "Power%", nullptr));
        playerNameP2->setText(QString());
        labelMoneyP1->setText(QCoreApplication::translate("Game", "Money", nullptr));
        labelFoodP1->setText(QCoreApplication::translate("Game", "Food", nullptr));
        labelWoodP1->setText(QCoreApplication::translate("Game", "Wood", nullptr));
        labelStoneP1->setText(QCoreApplication::translate("Game", "Stone", nullptr));
        labelOreP1->setText(QCoreApplication::translate("Game", "Ore", nullptr));
        labelMovesP1->setText(QCoreApplication::translate("Game", "Moves", nullptr));
        labelTilesP1->setText(QCoreApplication::translate("Game", "Tiles", nullptr));
        labelPowerP1->setText(QCoreApplication::translate("Game", "Power%", nullptr));
        playerNameP1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
