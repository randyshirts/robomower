#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QWidget>
#include <QAbstractSlider>
#include "heartbeattimer.h"
#include "qledindicator.h"
#include "gamepad.h"

class HeartbeatTimer;
class cGamepad;

#define GP_DEADBAND_LIMIT 2000

namespace Ui {
class RobotGui;
}

class RobotGui : public QWidget
{
    Q_OBJECT

    struct cmdMsg
    {
        unsigned char header1;    //The header byte for the command message
        unsigned char header2;
        unsigned char header3;
        qint16 rtMotorSpd;
        qint16 ltMotorSpd;
    };

signals:

    void getCommand(const QByteArray &data);
    void Up_Button_Pressed();
    void Down_Button_Pressed();
    void Up_Button_Released();
    void Down_Button_Released();

public slots:
    void setSpeed(int newVal);
    void setBladeToggle();
    void bladeCmd();
    void speedSliderSettings(int val);
    void lightHBled();
    void darkHBled();
    void driveCmdUp();
    void driveCmdDown();
    void driveCmdRight();
    void driveCmdLeft();
    void driveStopCmd();
    void sendDriveCmd();
    void readGamepad();


public:
    explicit RobotGui(QWidget *parent = 0);
    ~RobotGui();
    void recieveHB();
    void recieveCurrent(QByteArray &data);
    HeartbeatTimer *cHeartBeat;

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

private:
    short int m_speed;
    cmdMsg m_cmdMsg;
    bool m_blades;
    unsigned char m_bladeHeader;
    unsigned int m_M1cur;
    unsigned int m_M2cur;
    Ui::RobotGui *ui;
    QTimer *cTimer100ms;
    Gamepad *cGamepad;
    void setLcdPallette();
    void bladeToggleSettings();


};

#endif // ROBOTGUI_H
