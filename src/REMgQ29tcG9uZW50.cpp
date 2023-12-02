#include "REMgQ29tcG9uZW50.h"

Engine_Control::Engine_Control(
    uint8_t input1,
    uint8_t input2,
    uint8_t engine) : attachedInput1(input1),
                      attachedInput2(input2),
                      attachedEngine(engine)
{
    pinMode(attachedInput1, INPUT);
    pinMode(attachedInput2, INPUT);
    pinMode(attachedEngine, OUTPUT);
}

Engine_Control::~Engine_Control() {}

void Engine_Control::inputControlHandler(Mode mode, int speed)
{
    digitalWrite(attachedInput1, (uint8_t)mode);
    if (speed != 0 && mode != Mode::STOP && mode != Mode::FORWARD)
    {
        speed = -speed;
    }
    else if (speed != 0 && mode != Mode::STOP)
    {
        analogWrite(attachedEngine, speed);
    }
    else
    {
        analogWrite(attachedEngine, 0);
    }
}
