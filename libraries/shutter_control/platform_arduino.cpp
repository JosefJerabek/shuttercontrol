#include "platform_arduino.h"

//#include "io_state_name.h"

#ifdef ARDUINO // aby přeložitelné na PC
#include <Arduino.h>
#endif

PlatformArduino::PlatformArduino(PlatformIf::Pinout pinout) : PlatformIf(pinout)
{
};


void PlatformArduino::Setup()
{
#ifdef ARDUINO
  _SetupPin(_pinout.SwitchUpPin, INPUT_PULLUP);
  _SetupPin(_pinout.SwitchDownPin, INPUT_PULLUP);
  _SetupPin(_pinout.PowerUpPin, OUTPUT);
  _SetupPin(_pinout.PowerDownPin, OUTPUT);
  _SetupPin(_pinout.StatePin0, OUTPUT);
  _SetupPin(_pinout.StatePin1, OUTPUT);
  _SetupPin(_pinout.StatePin2, OUTPUT);
  _SetupPin(_pinout.EventPin0, OUTPUT);
  _SetupPin(_pinout.EventPin1, OUTPUT);
#endif
};


unsigned long PlatformArduino::GetTimeMs() {
#ifdef ARDUINO
    return millis();
#endif
};


void PlatformArduino::_SetupPin(int number, int type){
    if (number >= 0) {
#ifdef ARDUINO
        pinMode(number, type);
#endif
    }
};


void PlatformArduino::_WritePin(int number, int value) {
    if (number >= 0) {
#ifdef ARDUINO
        digitalWrite(number, value);
#endif
    }
};


int PlatformArduino::_ReadPin(int number) {
    if (number >= 0) {
#ifdef ARDUINO
        return digitalRead(number);
#endif
    }
    return -1;
};
