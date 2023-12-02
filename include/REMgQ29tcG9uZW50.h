#pragma once
#include <Arduino.h>

class Engine_Control
{
public:
  enum class Mode
  {
    FORWARD,
    BACKWARD,
    STOP
  };

  Engine_Control(uint8_t input1, uint8_t input2, uint8_t engine);
  virtual ~Engine_Control();

  void inputControlHandler(Mode mode, int speed);

private:
  uint8_t attachedInput1;
  uint8_t attachedInput2;
  uint8_t attachedEngine;
};
