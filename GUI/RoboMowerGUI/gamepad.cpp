#include "gamepad.h"

Gamepad::Gamepad(QObject *parent) :
    QObject(parent)
{
    joy = new QJoystick;
    data_timer = new QTimer;

    data_timer->setInterval(50);

    // Initialize joysticks
    init_joysticks();

    // If there's a joystick present, initialize axes and buttons displays
    // and start the update timer.
    if(joysavail>0)
    {
        connect(data_timer,SIGNAL(timeout()),this,SLOT(pollJoystick()));
        data_timer->start();
    }
}

Gamepad::~Gamepad()
{
    data_timer->stop();
    joy->~QJoystick();
}

// Initialize Joystick information
// Get # of joysticks available
// Populate # of axes and buttons
void Gamepad::init_joysticks()
{
    // Find number of joysticks present
    joysavail=joy->availableJoysticks();

    // Create joysticks list
    for(int i=0;i<joysavail;i++)
    {
        joydata *tempjoy;
        tempjoy = new joydata;
        joystick.append(tempjoy);
    }

    // Populate labels depending on the number of joysticks found
    switch (joysavail)
    {
    case 0:
        break;
    default:
        // Populate data structure for all joysticks
        for(int i=0; i<joysavail;i++)
        {
            joy->setJoystick(i);

            // Axes
            joystick.at(i)->number_axes = joy->joystickNumAxes(i);

            for(unsigned int j=0; j<joystick.at(i)->number_axes;j++)
            {
                joystick.at(i)->axis.append(0);
            }

            // Buttons
            joystick.at(i)->number_btn  = joy->joystickNumButtons(i);

            for(unsigned int j=0; j<joystick.at(i)->number_btn;j++)
            {
                joystick.at(i)->button.append(false);
            }
        }

        current_joystick = 0;

        joy->setJoystick(current_joystick);

        break;
    }

}


// Extracts data from QJoystick class
void Gamepad::pollJoystick()
{
    joy->getdata();
    for(unsigned int i=0;i<joystick.at(current_joystick)->number_axes;i++)
    {
        joystick.at(current_joystick)->axis[i]=joy->axis[i];
    }

    for(unsigned int i=0;i<joystick.at(current_joystick)->number_btn;i++)
    {
        joystick.at(current_joystick)->button[i] = joy->buttons[i];
    }

}
