#include "robotgui.h"
#include "ui_robotgui.h"
#include "heartbeattimer.h"
#include <QKeyEvent>
#include <QAbstractSlider>

RobotGui::RobotGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotGui)
{
    ui->setupUi(this);

    cHeartBeat = new HeartbeatTimer(this);
    cHeartBeat->setInterval(500);
    cHeartBeat->start();

    cTimer100ms = new QTimer(this);
    cTimer100ms->setInterval(100);
    cTimer100ms->start();

    m_cmdMsg.header1 = 0xDE;
    m_cmdMsg.header2 = 0xAD;
    m_cmdMsg.header3 = 0xFC;
    m_cmdMsg.ltMotorSpd = 0x00;
    m_cmdMsg.rtMotorSpd = 0x00;
    m_speed = 0;
    m_M1cur = 0;
    m_M2cur = 0;
    m_blades = false;
    m_bladeHeader = 0xBB;

    setLcdPallette();
    bladeToggleSettings();
    speedSliderSettings(0);

    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(setSpeed(int)));
    connect(ui->bladeToggle, SIGNAL(sliderReleased()), this, SLOT(setBladeToggle()));
    connect(ui->upButton, SIGNAL(pressed()), this, SLOT(driveCmdUp()));
    connect(ui->downButton, SIGNAL(pressed()), this, SLOT(driveCmdDown()));
    connect(ui->upButton, SIGNAL(released()), this, SLOT(driveStopCmd()));
    connect(ui->downButton, SIGNAL(released()), this, SLOT(driveStopCmd()));
    connect(ui->rightButton, SIGNAL(pressed()), this, SLOT(driveCmdRight()));
    connect(ui->leftButton, SIGNAL(pressed()), this, SLOT(driveCmdLeft()));
    connect(ui->rightButton, SIGNAL(released()), this, SLOT(driveStopCmd()));
    connect(ui->leftButton, SIGNAL(released()), this, SLOT(driveStopCmd()));
    connect(cHeartBeat, SIGNAL(HBon()), this, SLOT(lightHBled()));
    connect(cHeartBeat, SIGNAL(HBoff()), this, SLOT(darkHBled()));
    connect(cTimer100ms, SIGNAL(timeout()), this, SLOT(bladeCmd()));
    connect(cTimer100ms, SIGNAL(timeout()), this, SLOT(sendDriveCmd()));
    //connect(this, SIGNAL(Up_Button_Pressed()), this, SLOT(sendCmdUp()));
    //connect(this, SIGNAL(Up_Button_Released()), this, SLOT(stopCmd()));
    //connect(this, SIGNAL(Down_Button_Pressed()), this, SLOT(sendCmdDown()));
    //connect(this, SIGNAL(Down_Button_Released()), this, SLOT(stopCmd()));

}

RobotGui::~RobotGui()
{
    cHeartBeat->stop();
    delete ui;
}

void RobotGui::setSpeed(int newVal)
{
    m_speed = newVal;
    speedSliderSettings(newVal);
}

void RobotGui::setBladeToggle()
{
    if(ui->bladeToggle->value() < (ui->bladeToggle->maximum()/2))
    {
        ui->bladeToggle->setValue(ui->bladeToggle->minimum());
        m_blades = false;
        bladeToggleSettings();
    }
    else
    {
        ui->bladeToggle->setValue(ui->bladeToggle->maximum());
        m_blades = true;
        bladeToggleSettings();
    }

}

void RobotGui::bladeToggleSettings()
{
    QString color1;
    QString color2;

    if(m_blades == true)
    {
        color1 = "#005000";
        color2 = "#00A000";
    }
    else
    {
        color1 = "#500000";
        color2 = "#A00000";
    }

    QString sliderStyle = ""
      "QSlider::groove:vertical {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                            "stop:0 " + color1 + ", "
                            "stop:1 " + color2 + "); "
            "margin: 0 4px; "
            "border: 1px solid #999999;} "
      "QSlider::handle:vertical {"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                        "stop:0 #000000, stop:1 #888888); "
            "border: 1px solid #5c5c5c; "
            "border-radius: 3px; "
            "height: 9px; "
            "margin: 0 -4px;}";

    ui->bladeToggle->setStyleSheet(sliderStyle);

}

void RobotGui::bladeCmd()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    stream << m_cmdMsg.header1 << m_cmdMsg.header2 << m_bladeHeader;
    stream << (unsigned char)m_blades;

    emit getCommand(data);

}

void RobotGui::driveCmdUp()
{
    int spd;

    spd = m_speed * 4;  //Max speed is 400 for Motor Controller commands
    m_cmdMsg.ltMotorSpd = spd;
    m_cmdMsg.rtMotorSpd = spd;
}

void RobotGui::driveCmdDown()
{
    int spd;

    spd = m_speed * -4;  //Max speed is -400 for Motor Controller commands
    m_cmdMsg.ltMotorSpd = spd;
    m_cmdMsg.rtMotorSpd = spd;
}

void RobotGui::driveCmdRight()
{
    int spd;

    spd = m_speed * 4;  //Max speed is -400 for Motor Controller commands
    m_cmdMsg.ltMotorSpd = spd;
    m_cmdMsg.rtMotorSpd = -1*spd;
}

void RobotGui::driveCmdLeft()
{
    int spd;

    spd = m_speed * 4;  //Max speed is -400 for Motor Controller commands
    m_cmdMsg.ltMotorSpd = -1*spd;
    m_cmdMsg.rtMotorSpd = spd;
}

void RobotGui::driveStopCmd()
{
    int spd;

    spd = 0;
    m_cmdMsg.ltMotorSpd = spd;
    m_cmdMsg.rtMotorSpd = spd;
}

void RobotGui::sendDriveCmd()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    stream << m_cmdMsg.header1 << m_cmdMsg.header2 << m_cmdMsg.header3;
    stream << m_cmdMsg.ltMotorSpd << m_cmdMsg.rtMotorSpd;

    emit getCommand(data);
}

void RobotGui::recieveHB()
{
        cHeartBeat->setHB(true);
        lightHBled();
}

void RobotGui::recieveCurrent(QByteArray &data)
{
    QDataStream ds(data);
    unsigned char header;
    unsigned short motorCur1, motorCur2; // Since the size you're trying to read appears to be 2 bytes


    //Read header
    ds >> header >> header >> header;
    //Read current readings
    ds >> motorCur1 >> motorCur2;

    //update GUI display, convert milliamps to amps
    ui->M1currentLcd->display((double)motorCur1/1000);
    ui->M2currentLcd->display((double)motorCur2/1000);


}

void RobotGui::lightHBled()
{
    ui->HBledIndicator->setChecked(true);
}

void RobotGui::darkHBled()
{
    ui->HBledIndicator->setChecked(false);
}

void RobotGui::setLcdPallette()
{
    QPalette pal = ui->M1currentLcd->palette();
    pal.setColor(ui->M1currentLcd->backgroundRole(), Qt::black);
    pal.setColor(ui->M1currentLcd->foregroundRole(), Qt::green);
    ui->M1currentLcd->setPalette(pal);
    ui->M2currentLcd->setPalette(pal);
}



void RobotGui::speedSliderSettings(int val)
{
    QString level1 = "0.95";
    QString level2 = "0.85";

    if((val > 5) && (val < 95))
    {
        level1 = QString::number(1 - (((double)val/100)-0.05));
        level2 = QString::number(1 - (((double)val/100)+0.05));

    }
    else if(val <= 5)
    {
        level1 = "0.95";
        level2 = "0.85";
    }
    else if(val >= 95)
    {
        level1 = "0.1";
        level2 = "0.01";
    }


    QString sliderStyle = ""
      "QSlider::groove:vertical {"
            "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                            "stop:0 #000000, "
                            "stop:" + level2 + " #000000,"
                            "stop:" + level1 + " #005000,"
                            "stop:1 #00A000);"
            "margin: 0 6px;"
            "border: 3px solid #999999;}"
      "QSlider::handle:vertical {"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                            "stop:0 #888888, stop:1 #000000);"
            "border: 1px solid #5c5c5c;"
            "border-radius: 3px;"
            "height: 10px;"
            "margin: 0 -6px;}";

    ui->speedSlider->setStyleSheet(sliderStyle);

}

void RobotGui::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
        emit Up_Button_Pressed();
        break;
    case Qt::Key_Down:
        emit Down_Button_Pressed();
        break;
    default:
        break;
    }
}

void RobotGui::keyReleaseEvent(QKeyEvent *e)
{
    if(e->isAutoRepeat())
    {
        e->ignore();
        return;
    }

    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
        emit Up_Button_Released();
        break;
    case Qt::Key_Down:
        emit Down_Button_Released();
        break;
    default:
        break;
    }
}


