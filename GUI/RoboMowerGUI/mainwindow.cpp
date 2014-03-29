#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "robotgui.h"
#include "../Joypick/source/joypick.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new Console;
    serial = new QSerialPort(this);
    settings = new SettingsDialog;
    cRobot = new RobotGui;
    joystickTest = new Joypick;
    console->setEnabled(false);
    setCentralWidget(cRobot);


    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    ui->actionTerminal->setEnabled(true);
    ui->actionJoystickTest->setEnabled(true);
    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    connect(cRobot, SIGNAL(getCommand(QByteArray)), this, SLOT(writeData(QByteArray)));
    connect(cRobot->cHeartBeat, SIGNAL(getHB(QByteArray)), this, SLOT(writeData(QByteArray)), Qt::UniqueConnection);
    connect(cRobot, SIGNAL(getCommand(QByteArray)), this, SLOT(writeData(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    if (serial->open(QIODevice::ReadWrite)) {
        if (serial->setBaudRate(p.baudRate)
                && serial->setDataBits(p.dataBits)
                && serial->setParity(p.parity)
                && serial->setStopBits(p.stopBits)
                && serial->setFlowControl(p.flowControl)) {

            console->setEnabled(true);
            console->setLocalEchoEnabled(p.localEchoEnabled);
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));

        } else {
            serial->close();
            QMessageBox::critical(this, tr("Error"), serial->errorString());

            ui->statusBar->showMessage(tr("Open error"));
        }
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Configure error"));
    }
}

void MainWindow::closeSerialPort()
{
    serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();

    rxBuf.append(data);

    if(rxBuf.size() >= 6)
        parseData(rxBuf);
    console->putData(data);
}

void MainWindow::parseData(QByteArray &msg)
{
    //Find header
    while(!msg.isEmpty() && ((unsigned char)(msg[0]) != 0xDE))
    {
        if(((unsigned char)(msg[0]) != 0xDE))
        {
            msg.remove(0,1);
            if(msg.size() == 1)
                return;
        }
    }

    if(((unsigned char)(msg[0]) == 0xDE) && ((unsigned char)(msg[1]) == 0xAD))
    {
        //Heartbeat message
        if(((unsigned char)(msg[2]) == 0xA1))
        {
            cRobot->recieveHB();
            msg.remove(0,3);
        }
        //Current reading
        else if(((unsigned char)(msg[2]) == 0xC1) && (msg.size() >= 7))
        {
            cRobot->recieveCurrent(msg);
            msg.remove(0,7);
        }
        else if(((unsigned char)(msg[2]) == 0xDD) && (msg.size() >= 7))
        {
            msg.remove(0,7);
        }
        else
            msg.remove(0,2);

    }
    else if(msg.size() > 7)
        msg.remove(0,2);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionTerminal, SIGNAL(triggered()), console, SLOT(show()));
    connect(ui->actionJoystickTest, SIGNAL(triggered()), joystickTest, SLOT(show()));
}
