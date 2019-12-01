/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "hoverbutton.h"

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *turnButton;
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
    QPlainTextEdit *log;
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
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(2006, 882);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(410, 10, 691, 481));
        turnButton = new QPushButton(centralwidget);
        turnButton->setObjectName(QStringLiteral("turnButton"));
        turnButton->setGeometry(QRect(240, 50, 80, 26));
        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));
        turnLabel->setGeometry(QRect(243, 28, 100, 18));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(1270, 10, 151, 171));
        buildingsLayout = new QGridLayout(gridLayoutWidget);
        buildingsLayout->setObjectName(QStringLiteral("buildingsLayout"));
        buildingsLayout->setContentsMargins(0, 0, 0, 0);
        farmButton = new Student::HoverButton(gridLayoutWidget);
        farmButton->setObjectName(QStringLiteral("farmButton"));

        buildingsLayout->addWidget(farmButton, 0, 0, 1, 1);

        mineButton = new Student::HoverButton(gridLayoutWidget);
        mineButton->setObjectName(QStringLiteral("mineButton"));

        buildingsLayout->addWidget(mineButton, 1, 0, 1, 1);

        outpostButton = new Student::HoverButton(gridLayoutWidget);
        outpostButton->setObjectName(QStringLiteral("outpostButton"));

        buildingsLayout->addWidget(outpostButton, 4, 0, 1, 1);

        quarryButton = new Student::HoverButton(gridLayoutWidget);
        quarryButton->setObjectName(QStringLiteral("quarryButton"));

        buildingsLayout->addWidget(quarryButton, 5, 0, 1, 1);

        sawmillButton = new Student::HoverButton(gridLayoutWidget);
        sawmillButton->setObjectName(QStringLiteral("sawmillButton"));

        buildingsLayout->addWidget(sawmillButton, 6, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1270, 200, 151, 171));
        workersLayout = new QGridLayout(gridLayoutWidget_2);
        workersLayout->setObjectName(QStringLiteral("workersLayout"));
        workersLayout->setContentsMargins(0, 0, 0, 0);
        basicWorkerButton = new Student::HoverButton(gridLayoutWidget_2);
        basicWorkerButton->setObjectName(QStringLiteral("basicWorkerButton"));

        workersLayout->addWidget(basicWorkerButton, 0, 0, 1, 1);

        warriorButton = new Student::HoverButton(gridLayoutWidget_2);
        warriorButton->setObjectName(QStringLiteral("warriorButton"));

        workersLayout->addWidget(warriorButton, 4, 0, 1, 1);

        constWorkerButton = new Student::HoverButton(gridLayoutWidget_2);
        constWorkerButton->setObjectName(QStringLiteral("constWorkerButton"));

        workersLayout->addWidget(constWorkerButton, 1, 0, 1, 1);

        log = new QPlainTextEdit(centralwidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(240, 400, 61, 51));
        hoverInfo = new QLabel(centralwidget);
        hoverInfo->setObjectName(QStringLiteral("hoverInfo"));
        hoverInfo->setGeometry(QRect(1720, 70, 63, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1410, 10, 511, 261));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/sprite/parchment.png")));
        buildingNameLabel = new QLabel(centralwidget);
        buildingNameLabel->setObjectName(QStringLiteral("buildingNameLabel"));
        buildingNameLabel->setGeometry(QRect(1450, 120, 71, 18));
        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));
        moneyLabel->setGeometry(QRect(1550, 70, 81, 18));
        woodLabel = new QLabel(centralwidget);
        woodLabel->setObjectName(QStringLiteral("woodLabel"));
        woodLabel->setGeometry(QRect(1550, 110, 81, 18));
        stoneLabel = new QLabel(centralwidget);
        stoneLabel->setObjectName(QStringLiteral("stoneLabel"));
        stoneLabel->setGeometry(QRect(1550, 130, 81, 18));
        oreLabel = new QLabel(centralwidget);
        oreLabel->setObjectName(QStringLiteral("oreLabel"));
        oreLabel->setGeometry(QRect(1550, 150, 81, 18));
        foodLabel = new QLabel(centralwidget);
        foodLabel->setObjectName(QStringLiteral("foodLabel"));
        foodLabel->setGeometry(QRect(1550, 90, 81, 18));
        moneyProductionLabel = new QLabel(centralwidget);
        moneyProductionLabel->setObjectName(QStringLiteral("moneyProductionLabel"));
        moneyProductionLabel->setGeometry(QRect(1640, 70, 81, 18));
        foodProductionLabel = new QLabel(centralwidget);
        foodProductionLabel->setObjectName(QStringLiteral("foodProductionLabel"));
        foodProductionLabel->setGeometry(QRect(1640, 90, 81, 18));
        woodProductionLabel = new QLabel(centralwidget);
        woodProductionLabel->setObjectName(QStringLiteral("woodProductionLabel"));
        woodProductionLabel->setGeometry(QRect(1640, 110, 81, 18));
        stoneProductionLabel = new QLabel(centralwidget);
        stoneProductionLabel->setObjectName(QStringLiteral("stoneProductionLabel"));
        stoneProductionLabel->setGeometry(QRect(1640, 130, 81, 18));
        oreProductionLabel = new QLabel(centralwidget);
        oreProductionLabel->setObjectName(QStringLiteral("oreProductionLabel"));
        oreProductionLabel->setGeometry(QRect(1640, 150, 81, 18));
        buildCostLabel = new QLabel(centralwidget);
        buildCostLabel->setObjectName(QStringLiteral("buildCostLabel"));
        buildCostLabel->setGeometry(QRect(1560, 50, 71, 20));
        productionLabel = new QLabel(centralwidget);
        productionLabel->setObjectName(QStringLiteral("productionLabel"));
        productionLabel->setGeometry(QRect(1640, 50, 81, 20));
        formLayoutWidget_7 = new QWidget(centralwidget);
        formLayoutWidget_7->setObjectName(QStringLiteral("formLayoutWidget_7"));
        formLayoutWidget_7->setGeometry(QRect(1260, 380, 511, 211));
        formLayoutPlayers = new QFormLayout(formLayoutWidget_7);
        formLayoutPlayers->setObjectName(QStringLiteral("formLayoutPlayers"));
        formLayoutPlayers->setContentsMargins(0, 0, 0, 0);
        formLayoutP2 = new QFormLayout();
        formLayoutP2->setObjectName(QStringLiteral("formLayoutP2"));
        formLayoutP2->setFormAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        formLayoutResourcesP2 = new QFormLayout();
        formLayoutResourcesP2->setObjectName(QStringLiteral("formLayoutResourcesP2"));
        moneyP2 = new QLCDNumber(formLayoutWidget_7);
        moneyP2->setObjectName(QStringLiteral("moneyP2"));

        formLayoutResourcesP2->setWidget(1, QFormLayout::FieldRole, moneyP2);

        labelFoodP2 = new QLabel(formLayoutWidget_7);
        labelFoodP2->setObjectName(QStringLiteral("labelFoodP2"));

        formLayoutResourcesP2->setWidget(2, QFormLayout::LabelRole, labelFoodP2);

        foodP2 = new QLCDNumber(formLayoutWidget_7);
        foodP2->setObjectName(QStringLiteral("foodP2"));

        formLayoutResourcesP2->setWidget(2, QFormLayout::FieldRole, foodP2);

        labelWoodP2 = new QLabel(formLayoutWidget_7);
        labelWoodP2->setObjectName(QStringLiteral("labelWoodP2"));

        formLayoutResourcesP2->setWidget(3, QFormLayout::LabelRole, labelWoodP2);

        woodP2 = new QLCDNumber(formLayoutWidget_7);
        woodP2->setObjectName(QStringLiteral("woodP2"));

        formLayoutResourcesP2->setWidget(3, QFormLayout::FieldRole, woodP2);

        labelStoneP2 = new QLabel(formLayoutWidget_7);
        labelStoneP2->setObjectName(QStringLiteral("labelStoneP2"));

        formLayoutResourcesP2->setWidget(4, QFormLayout::LabelRole, labelStoneP2);

        stoneP2 = new QLCDNumber(formLayoutWidget_7);
        stoneP2->setObjectName(QStringLiteral("stoneP2"));

        formLayoutResourcesP2->setWidget(4, QFormLayout::FieldRole, stoneP2);

        labelOreP2 = new QLabel(formLayoutWidget_7);
        labelOreP2->setObjectName(QStringLiteral("labelOreP2"));

        formLayoutResourcesP2->setWidget(5, QFormLayout::LabelRole, labelOreP2);

        oreP2 = new QLCDNumber(formLayoutWidget_7);
        oreP2->setObjectName(QStringLiteral("oreP2"));

        formLayoutResourcesP2->setWidget(5, QFormLayout::FieldRole, oreP2);

        labelMoneyP2 = new QLabel(formLayoutWidget_7);
        labelMoneyP2->setObjectName(QStringLiteral("labelMoneyP2"));

        formLayoutResourcesP2->setWidget(1, QFormLayout::LabelRole, labelMoneyP2);


        formLayoutP2->setLayout(1, QFormLayout::LabelRole, formLayoutResourcesP2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        labelMovesP2 = new QLabel(formLayoutWidget_7);
        labelMovesP2->setObjectName(QStringLiteral("labelMovesP2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelMovesP2);

        movesP2 = new QLCDNumber(formLayoutWidget_7);
        movesP2->setObjectName(QStringLiteral("movesP2"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, movesP2);

        labelTilesP2 = new QLabel(formLayoutWidget_7);
        labelTilesP2->setObjectName(QStringLiteral("labelTilesP2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelTilesP2);

        tilesP2 = new QLCDNumber(formLayoutWidget_7);
        tilesP2->setObjectName(QStringLiteral("tilesP2"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, tilesP2);

        labelPowerP2 = new QLabel(formLayoutWidget_7);
        labelPowerP2->setObjectName(QStringLiteral("labelPowerP2"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelPowerP2);

        powerP2 = new QLCDNumber(formLayoutWidget_7);
        powerP2->setObjectName(QStringLiteral("powerP2"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, powerP2);


        formLayoutP2->setLayout(1, QFormLayout::FieldRole, formLayout_3);

        playerNameP2 = new QLabel(formLayoutWidget_7);
        playerNameP2->setObjectName(QStringLiteral("playerNameP2"));
        QFont font;
        font.setFamily(QStringLiteral("Nimbus Roman"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        playerNameP2->setFont(font);
        playerNameP2->setAlignment(Qt::AlignCenter);

        formLayoutP2->setWidget(0, QFormLayout::SpanningRole, playerNameP2);


        formLayoutPlayers->setLayout(0, QFormLayout::FieldRole, formLayoutP2);

        formLayoutP1 = new QFormLayout();
        formLayoutP1->setObjectName(QStringLiteral("formLayoutP1"));
        formLayoutP1->setLabelAlignment(Qt::AlignCenter);
        formLayoutP1->setFormAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        formLayoutResourcesP1 = new QFormLayout();
        formLayoutResourcesP1->setObjectName(QStringLiteral("formLayoutResourcesP1"));
        labelMoneyP1 = new QLabel(formLayoutWidget_7);
        labelMoneyP1->setObjectName(QStringLiteral("labelMoneyP1"));

        formLayoutResourcesP1->setWidget(1, QFormLayout::LabelRole, labelMoneyP1);

        moneyP1 = new QLCDNumber(formLayoutWidget_7);
        moneyP1->setObjectName(QStringLiteral("moneyP1"));

        formLayoutResourcesP1->setWidget(1, QFormLayout::FieldRole, moneyP1);

        labelFoodP1 = new QLabel(formLayoutWidget_7);
        labelFoodP1->setObjectName(QStringLiteral("labelFoodP1"));

        formLayoutResourcesP1->setWidget(2, QFormLayout::LabelRole, labelFoodP1);

        foodP1 = new QLCDNumber(formLayoutWidget_7);
        foodP1->setObjectName(QStringLiteral("foodP1"));

        formLayoutResourcesP1->setWidget(2, QFormLayout::FieldRole, foodP1);

        labelWoodP1 = new QLabel(formLayoutWidget_7);
        labelWoodP1->setObjectName(QStringLiteral("labelWoodP1"));

        formLayoutResourcesP1->setWidget(3, QFormLayout::LabelRole, labelWoodP1);

        woodP1 = new QLCDNumber(formLayoutWidget_7);
        woodP1->setObjectName(QStringLiteral("woodP1"));

        formLayoutResourcesP1->setWidget(3, QFormLayout::FieldRole, woodP1);

        labelStoneP1 = new QLabel(formLayoutWidget_7);
        labelStoneP1->setObjectName(QStringLiteral("labelStoneP1"));

        formLayoutResourcesP1->setWidget(4, QFormLayout::LabelRole, labelStoneP1);

        stoneP1 = new QLCDNumber(formLayoutWidget_7);
        stoneP1->setObjectName(QStringLiteral("stoneP1"));

        formLayoutResourcesP1->setWidget(4, QFormLayout::FieldRole, stoneP1);

        labelOreP1 = new QLabel(formLayoutWidget_7);
        labelOreP1->setObjectName(QStringLiteral("labelOreP1"));

        formLayoutResourcesP1->setWidget(5, QFormLayout::LabelRole, labelOreP1);

        oreP1 = new QLCDNumber(formLayoutWidget_7);
        oreP1->setObjectName(QStringLiteral("oreP1"));

        formLayoutResourcesP1->setWidget(5, QFormLayout::FieldRole, oreP1);


        formLayoutP1->setLayout(1, QFormLayout::LabelRole, formLayoutResourcesP1);

        formLayoutOtherP1 = new QFormLayout();
        formLayoutOtherP1->setObjectName(QStringLiteral("formLayoutOtherP1"));
        labelMovesP1 = new QLabel(formLayoutWidget_7);
        labelMovesP1->setObjectName(QStringLiteral("labelMovesP1"));

        formLayoutOtherP1->setWidget(0, QFormLayout::LabelRole, labelMovesP1);

        movesP1 = new QLCDNumber(formLayoutWidget_7);
        movesP1->setObjectName(QStringLiteral("movesP1"));

        formLayoutOtherP1->setWidget(0, QFormLayout::FieldRole, movesP1);

        labelTilesP1 = new QLabel(formLayoutWidget_7);
        labelTilesP1->setObjectName(QStringLiteral("labelTilesP1"));

        formLayoutOtherP1->setWidget(1, QFormLayout::LabelRole, labelTilesP1);

        tilesP1 = new QLCDNumber(formLayoutWidget_7);
        tilesP1->setObjectName(QStringLiteral("tilesP1"));

        formLayoutOtherP1->setWidget(1, QFormLayout::FieldRole, tilesP1);

        labelPowerP1 = new QLabel(formLayoutWidget_7);
        labelPowerP1->setObjectName(QStringLiteral("labelPowerP1"));

        formLayoutOtherP1->setWidget(2, QFormLayout::LabelRole, labelPowerP1);

        powerP1 = new QLCDNumber(formLayoutWidget_7);
        powerP1->setObjectName(QStringLiteral("powerP1"));

        formLayoutOtherP1->setWidget(2, QFormLayout::FieldRole, powerP1);


        formLayoutP1->setLayout(1, QFormLayout::FieldRole, formLayoutOtherP1);

        playerNameP1 = new QLabel(formLayoutWidget_7);
        playerNameP1->setObjectName(QStringLiteral("playerNameP1"));
        playerNameP1->setFont(font);
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
        log->raise();
        hoverInfo->raise();
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
        menubar = new QMenuBar(Game);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2006, 25));
        Game->setMenuBar(menubar);
        statusbar = new QStatusBar(Game);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Game->setStatusBar(statusbar);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "MainWindow", Q_NULLPTR));
        turnButton->setText(QApplication::translate("Game", "End Turn", Q_NULLPTR));
        turnLabel->setText(QApplication::translate("Game", "Turn: ", Q_NULLPTR));
        farmButton->setText(QApplication::translate("Game", "Farm", Q_NULLPTR));
        mineButton->setText(QApplication::translate("Game", "Mine", Q_NULLPTR));
        outpostButton->setText(QApplication::translate("Game", "Outpost", Q_NULLPTR));
        quarryButton->setText(QApplication::translate("Game", "Quarry", Q_NULLPTR));
        sawmillButton->setText(QApplication::translate("Game", "Sawmill", Q_NULLPTR));
        basicWorkerButton->setText(QApplication::translate("Game", "Basic Worker", Q_NULLPTR));
        warriorButton->setText(QApplication::translate("Game", "Warrior", Q_NULLPTR));
        constWorkerButton->setText(QApplication::translate("Game", "Construction Worker", Q_NULLPTR));
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
        labelFoodP2->setText(QApplication::translate("Game", "Food", Q_NULLPTR));
        labelWoodP2->setText(QApplication::translate("Game", "Wood", Q_NULLPTR));
        labelStoneP2->setText(QApplication::translate("Game", "Stone", Q_NULLPTR));
        labelOreP2->setText(QApplication::translate("Game", "Ore", Q_NULLPTR));
        labelMoneyP2->setText(QApplication::translate("Game", "Money", Q_NULLPTR));
        labelMovesP2->setText(QApplication::translate("Game", "Moves", Q_NULLPTR));
        labelTilesP2->setText(QApplication::translate("Game", "Tiles", Q_NULLPTR));
        labelPowerP2->setText(QApplication::translate("Game", "Power%", Q_NULLPTR));
        playerNameP2->setText(QString());
        labelMoneyP1->setText(QApplication::translate("Game", "Money", Q_NULLPTR));
        labelFoodP1->setText(QApplication::translate("Game", "Food", Q_NULLPTR));
        labelWoodP1->setText(QApplication::translate("Game", "Wood", Q_NULLPTR));
        labelStoneP1->setText(QApplication::translate("Game", "Stone", Q_NULLPTR));
        labelOreP1->setText(QApplication::translate("Game", "Ore", Q_NULLPTR));
        labelMovesP1->setText(QApplication::translate("Game", "Moves", Q_NULLPTR));
        labelTilesP1->setText(QApplication::translate("Game", "Tiles", Q_NULLPTR));
        labelPowerP1->setText(QApplication::translate("Game", "Power%", Q_NULLPTR));
        playerNameP1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
