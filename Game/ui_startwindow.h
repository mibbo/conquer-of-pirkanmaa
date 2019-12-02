/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *playButton;
    QLabel *mapSizeLabel;
    QComboBox *mapSizeComboBox;
    QLineEdit *playerOne;
    QLineEdit *playerTwo;
    QLabel *playerAmountLabel_2;
    QLabel *colorLabel;
    QPushButton *playerOneColor;
    QPushButton *playerTwoColor;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(389, 293);
        playButton = new QPushButton(StartWindow);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(300, 260, 84, 28));
        mapSizeLabel = new QLabel(StartWindow);
        mapSizeLabel->setObjectName(QStringLiteral("mapSizeLabel"));
        mapSizeLabel->setGeometry(QRect(30, 160, 111, 20));
        mapSizeComboBox = new QComboBox(StartWindow);
        mapSizeComboBox->setObjectName(QStringLiteral("mapSizeComboBox"));
        mapSizeComboBox->setGeometry(QRect(250, 150, 79, 28));
        playerOne = new QLineEdit(StartWindow);
        playerOne->setObjectName(QStringLiteral("playerOne"));
        playerOne->setGeometry(QRect(190, 20, 80, 26));
        playerTwo = new QLineEdit(StartWindow);
        playerTwo->setObjectName(QStringLiteral("playerTwo"));
        playerTwo->setGeometry(QRect(290, 20, 80, 26));
        playerAmountLabel_2 = new QLabel(StartWindow);
        playerAmountLabel_2->setObjectName(QStringLiteral("playerAmountLabel_2"));
        playerAmountLabel_2->setGeometry(QRect(30, 22, 131, 20));
        colorLabel = new QLabel(StartWindow);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setGeometry(QRect(30, 50, 141, 20));
        playerOneColor = new QPushButton(StartWindow);
        playerOneColor->setObjectName(QStringLiteral("playerOneColor"));
        playerOneColor->setGeometry(QRect(190, 50, 84, 28));
        playerTwoColor = new QPushButton(StartWindow);
        playerTwoColor->setObjectName(QStringLiteral("playerTwoColor"));
        playerTwoColor->setGeometry(QRect(290, 50, 84, 28));

        retranslateUi(StartWindow);
        QObject::connect(playButton, SIGNAL(clicked()), StartWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Dialog", Q_NULLPTR));
        playButton->setText(QApplication::translate("StartWindow", "Play", Q_NULLPTR));
        mapSizeLabel->setText(QApplication::translate("StartWindow", "Select map size:", Q_NULLPTR));
        playerOne->setText(QApplication::translate("StartWindow", "mibbo", Q_NULLPTR));
        playerTwo->setText(QApplication::translate("StartWindow", "brutus", Q_NULLPTR));
        playerAmountLabel_2->setText(QApplication::translate("StartWindow", "Player names:", Q_NULLPTR));
        colorLabel->setText(QApplication::translate("StartWindow", "Select player colors:", Q_NULLPTR));
        playerOneColor->setText(QApplication::translate("StartWindow", "Player1", Q_NULLPTR));
        playerTwoColor->setText(QApplication::translate("StartWindow", "Player2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
