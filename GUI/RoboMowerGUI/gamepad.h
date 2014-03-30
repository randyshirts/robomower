#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QObject>
#include <QTimer>
#include <QList>
#include "../Joypick/source/qjoystick.h"

class Gamepad : public QObject
{
    Q_OBJECT
public:
    explicit Gamepad(QObject *parent = 0);

    ~Gamepad();

    // Structure created for each joystick encountered
    struct joydata{
        unsigned int number_axes;
        unsigned int number_btn;
        QList<int> axis;
        QList<bool> button;
    };

    // Available joystick count. Only set at initialization
    int joysavail;

    // List of joystick data
    QList<joydata*> joystick;

    // current_joystick is dynamic, set by the user selection
    int current_joystick;


private:
    QJoystick *joy;
    void init_joysticks();
    QTimer *data_timer;

signals:

public slots:
    void pollJoystick();

};

#endif // GAMEPAD_H
