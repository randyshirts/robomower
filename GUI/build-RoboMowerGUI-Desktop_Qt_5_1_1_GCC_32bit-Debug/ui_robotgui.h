/********************************************************************************
** Form generated from reading UI file 'robotgui.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTGUI_H
#define UI_ROBOTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "qledindicator.h"

QT_BEGIN_NAMESPACE

class Ui_RobotGui
{
public:
    QSlider *speedSlider;
    QLabel *sliderLabel;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QLedIndicator *HBledIndicator;
    QLabel *label;
    QLCDNumber *M1currentLcd;
    QLCDNumber *M2currentLcd;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *bladeToggle;
    QLabel *sliderLabel_2;
    QLabel *sliderLabel_3;
    QLabel *sliderLabel_4;

    void setupUi(QWidget *RobotGui)
    {
        if (RobotGui->objectName().isEmpty())
            RobotGui->setObjectName(QStringLiteral("RobotGui"));
        RobotGui->resize(500, 500);
        QIcon icon;
        icon.addFile(QStringLiteral(":/robot.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        RobotGui->setWindowIcon(icon);
        speedSlider = new QSlider(RobotGui);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setGeometry(QRect(340, 80, 31, 161));
        speedSlider->setFocusPolicy(Qt::ClickFocus);
        speedSlider->setMaximum(100);
        speedSlider->setOrientation(Qt::Vertical);
        speedSlider->setTickPosition(QSlider::TicksAbove);
        speedSlider->setTickInterval(25);
        sliderLabel = new QLabel(RobotGui);
        sliderLabel->setObjectName(QStringLiteral("sliderLabel"));
        sliderLabel->setGeometry(QRect(340, 50, 41, 16));
        upButton = new QPushButton(RobotGui);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(220, 80, 51, 51));
        upButton->setBaseSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon1);
        upButton->setIconSize(QSize(50, 50));
        upButton->setAutoRepeat(false);
        upButton->setAutoRepeatDelay(100);
        upButton->setAutoRepeatInterval(100);
        downButton = new QPushButton(RobotGui);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(220, 180, 51, 51));
        downButton->setBaseSize(QSize(0, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/down.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon2);
        downButton->setIconSize(QSize(50, 50));
        downButton->setAutoRepeat(false);
        downButton->setAutoRepeatDelay(100);
        downButton->setAutoRepeatInterval(100);
        leftButton = new QPushButton(RobotGui);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(170, 130, 51, 51));
        leftButton->setBaseSize(QSize(0, 0));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/left.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon3);
        leftButton->setIconSize(QSize(50, 50));
        leftButton->setAutoRepeat(false);
        leftButton->setAutoRepeatDelay(100);
        leftButton->setAutoRepeatInterval(100);
        rightButton = new QPushButton(RobotGui);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(270, 130, 51, 51));
        rightButton->setBaseSize(QSize(0, 0));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/right.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon4);
        rightButton->setIconSize(QSize(50, 50));
        rightButton->setAutoRepeat(false);
        rightButton->setAutoRepeatDelay(100);
        rightButton->setAutoRepeatInterval(100);
        HBledIndicator = new QLedIndicator(RobotGui);
        HBledIndicator->setObjectName(QStringLiteral("HBledIndicator"));
        HBledIndicator->setGeometry(QRect(20, 40, 61, 71));
        HBledIndicator->setOnColor1(QColor(255, 3, 19));
        HBledIndicator->setOnColor2(QColor(220, 6, 17));
        HBledIndicator->setOffColor1(QColor(22, 1, 2));
        HBledIndicator->setOffColor2(QColor(125, 2, 11));
        label = new QLabel(RobotGui);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 41, 16));
        M1currentLcd = new QLCDNumber(RobotGui);
        M1currentLcd->setObjectName(QStringLiteral("M1currentLcd"));
        M1currentLcd->setGeometry(QRect(30, 200, 91, 31));
        M1currentLcd->setAutoFillBackground(true);
        M1currentLcd->setSmallDecimalPoint(false);
        M1currentLcd->setDigitCount(5);
        M1currentLcd->setSegmentStyle(QLCDNumber::Filled);
        M1currentLcd->setProperty("intValue", QVariant(0));
        M2currentLcd = new QLCDNumber(RobotGui);
        M2currentLcd->setObjectName(QStringLiteral("M2currentLcd"));
        M2currentLcd->setGeometry(QRect(30, 260, 91, 31));
        M2currentLcd->setAutoFillBackground(true);
        M2currentLcd->setFrameShape(QFrame::Box);
        label_2 = new QLabel(RobotGui);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 180, 91, 16));
        QFont font;
        font.setPointSize(7);
        label_2->setFont(font);
        label_3 = new QLabel(RobotGui);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 240, 91, 16));
        label_3->setFont(font);
        bladeToggle = new QSlider(RobotGui);
        bladeToggle->setObjectName(QStringLiteral("bladeToggle"));
        bladeToggle->setGeometry(QRect(310, 280, 21, 31));
        bladeToggle->setMaximum(50);
        bladeToggle->setPageStep(10);
        bladeToggle->setOrientation(Qt::Vertical);
        sliderLabel_2 = new QLabel(RobotGui);
        sliderLabel_2->setObjectName(QStringLiteral("sliderLabel_2"));
        sliderLabel_2->setGeometry(QRect(260, 280, 41, 31));
        sliderLabel_2->setWordWrap(true);
        sliderLabel_3 = new QLabel(RobotGui);
        sliderLabel_3->setObjectName(QStringLiteral("sliderLabel_3"));
        sliderLabel_3->setGeometry(QRect(300, 260, 41, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        sliderLabel_3->setFont(font1);
        sliderLabel_4 = new QLabel(RobotGui);
        sliderLabel_4->setObjectName(QStringLiteral("sliderLabel_4"));
        sliderLabel_4->setGeometry(QRect(300, 310, 41, 16));
        sliderLabel_4->setFont(font1);
        speedSlider->raise();
        sliderLabel->raise();
        downButton->raise();
        upButton->raise();
        leftButton->raise();
        rightButton->raise();
        HBledIndicator->raise();
        label->raise();
        M1currentLcd->raise();
        M2currentLcd->raise();
        label_2->raise();
        label_3->raise();
        bladeToggle->raise();
        sliderLabel_2->raise();
        sliderLabel_3->raise();
        sliderLabel_4->raise();

        retranslateUi(RobotGui);

        QMetaObject::connectSlotsByName(RobotGui);
    } // setupUi

    void retranslateUi(QWidget *RobotGui)
    {
        RobotGui->setWindowTitle(QApplication::translate("RobotGui", "RobotGUI", 0));
        sliderLabel->setText(QApplication::translate("RobotGui", "Speed", 0));
        upButton->setText(QString());
        downButton->setText(QString());
        leftButton->setText(QString());
        rightButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        HBledIndicator->setToolTip(QApplication::translate("RobotGui", "Led indicator/button", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        HBledIndicator->setWhatsThis(QApplication::translate("RobotGui", "Led indicator/button", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("RobotGui", "Signal", 0));
        label_2->setText(QApplication::translate("RobotGui", "Left Motor Current", 0));
        label_3->setText(QApplication::translate("RobotGui", "Right Motor Current", 0));
        sliderLabel_2->setText(QApplication::translate("RobotGui", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Blade Motors</span></p></body></html>", 0));
        sliderLabel_3->setText(QApplication::translate("RobotGui", "<html><head/><body><p align=\"center\"><span style=\" color:#aa0000;\">On</span></p></body></html>", 0));
        sliderLabel_4->setText(QApplication::translate("RobotGui", "<html><head/><body><p align=\"center\"><span style=\" color:#aa0000;\">Off</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class RobotGui: public Ui_RobotGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTGUI_H
