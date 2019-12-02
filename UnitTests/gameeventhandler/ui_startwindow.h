/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(389, 293);
        playButton = new QPushButton(StartWindow);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(300, 260, 84, 28));
        mapSizeLabel = new QLabel(StartWindow);
        mapSizeLabel->setObjectName(QString::fromUtf8("mapSizeLabel"));
        mapSizeLabel->setGeometry(QRect(30, 160, 111, 20));
        mapSizeComboBox = new QComboBox(StartWindow);
        mapSizeComboBox->setObjectName(QString::fromUtf8("mapSizeComboBox"));
        mapSizeComboBox->setGeometry(QRect(250, 150, 79, 28));
        playerOne = new QLineEdit(StartWindow);
        playerOne->setObjectName(QString::fromUtf8("playerOne"));
        playerOne->setGeometry(QRect(190, 20, 80, 26));
        playerTwo = new QLineEdit(StartWindow);
        playerTwo->setObjectName(QString::fromUtf8("playerTwo"));
        playerTwo->setGeometry(QRect(290, 20, 80, 26));
        playerAmountLabel_2 = new QLabel(StartWindow);
        playerAmountLabel_2->setObjectName(QString::fromUtf8("playerAmountLabel_2"));
        playerAmountLabel_2->setGeometry(QRect(30, 22, 131, 20));
        colorLabel = new QLabel(StartWindow);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setGeometry(QRect(30, 50, 141, 20));
        playerOneColor = new QPushButton(StartWindow);
        playerOneColor->setObjectName(QString::fromUtf8("playerOneColor"));
        playerOneColor->setGeometry(QRect(190, 50, 84, 28));
        playerTwoColor = new QPushButton(StartWindow);
        playerTwoColor->setObjectName(QString::fromUtf8("playerTwoColor"));
        playerTwoColor->setGeometry(QRect(290, 50, 84, 28));

        retranslateUi(StartWindow);
        QObject::connect(playButton, SIGNAL(clicked()), StartWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Dialog", nullptr));
        playButton->setText(QCoreApplication::translate("StartWindow", "Play", nullptr));
        mapSizeLabel->setText(QCoreApplication::translate("StartWindow", "Select map size:", nullptr));
        playerOne->setText(QCoreApplication::translate("StartWindow", "mibbo", nullptr));
        playerTwo->setText(QCoreApplication::translate("StartWindow", "brutus", nullptr));
        playerAmountLabel_2->setText(QCoreApplication::translate("StartWindow", "Player names:", nullptr));
        colorLabel->setText(QCoreApplication::translate("StartWindow", "Select player colors:", nullptr));
        playerOneColor->setText(QCoreApplication::translate("StartWindow", "Player1", nullptr));
        playerTwoColor->setText(QCoreApplication::translate("StartWindow", "Player2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
