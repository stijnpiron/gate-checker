/*
   RgbLed.h - Library to control RGB LED's
*/

#ifndef RgbLed_h
#define RgbLed_h

#import <Arduino.h>

class RgbLed
{
  public:
    RgbLed(int red_pin, int green_pin, int blue_pin);
    RgbLed(int red_pin, int green_pin, int blue_pin, int red, int green, int blue);
    void blinkLed(int timeOn, int timeOff, int repeat);
    void printProps();
    void setColor(int red, int green, int blue);
    void setLedOff();
    void setLedOn();
    void setState(boolean state);
  private:
    int _red_pin;
    int _green_pin;
    int _blue_pin;
    int _led_red;
    int _led_green;
    int _led_blue;
    int _red;
    int _green;
    int _blue;
    boolean _checkColorValue(int value);
    boolean _checkColorValues(int red, int green, int blue);
    boolean _checkNumberPositive(int input);
    boolean _checkPinNumber(int pin);
    boolean _checkPinNumbers(int red_pin, int green_pin, int blue_pin);
    void _printMessage(String message);
    void _setPins(int red_pin, int green_pin, int blue_pin);
};

#endif