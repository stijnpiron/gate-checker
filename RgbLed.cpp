/*
   RgbLed.cpp - Library to control RGB LED's
   Constructor accepts the RGB pin numbeers and/or the RGB pin numbers and color settings
   TODO: Provide proper documentation and test for valid input parameter values
*/

#import <Arduino.h>
#include "RgbLed.h"

/**
   Constructor acception only LED pin numbers
   @param red_pin Arduino pin for controlling the red color of the LED
   @param green_pin Arduino pin for controlling the green color of the LED
   @param blue_pin Arduino pin for controlling the blue color of the LED
*/
RgbLed::RgbLed(int red_pin, int green_pin, int blue_pin)
{
  if (_checkPinNumbers(red_pin, green_pin, blue_pin))
  {
    _setPins(red_pin, green_pin, blue_pin);
  }
  else
  {
    _printMessage("Wrong pin number definitions");
  }
}

/**
   Constructor accepting LED pin numbers and initial color values
   @param red_pin Arduino pin for controlling the red color of the LED
   @param green_pin Arduino pin for controlling the green color of the LED
   @param blue_pin Arduino pin for controlling the blue color of the LED
   @param red Value of the color red
   @param green Value of the color green
   @param blue Value of the color blue
*/
RgbLed::RgbLed(int red_pin, int green_pin, int blue_pin, int red, int green, int blue)
{
  _setPins(red_pin, green_pin, blue_pin);
  setColor(red, green, blue);

}

// Blink the led
/**
   Blink the LED by providing the time for the LED to be on and off, also possible to repeat the sequence
   FEATURE: expand for blinking patterns
   @param timeOn Time in milliseconds for the LED to be in the HIGH state
   @param timeOff Time in milliseconds for the LED to be in the LOW state
   @param repeat Number of times the blink sequence will be repeated, defaults to 1 for running the sequence at least one time
*/
void RgbLed::blinkLed(int timeOn, int timeOff, int repeat = 1)
{
  if (_checkNumberPositive(timeOn) && _checkNumberPositive(timeOff) && _checkNumberPositive(repeat))
  {
    for (int i = 0; i < repeat; i++)
    {
      setLedOn();
      delay(timeOn);
      setLedOff();
      delay(timeOff);
    }
  }
  else {
    _printMessage("Wrong timeOn, timeOff or repeat definition");
  }
}

void RgbLed::printProps()
{
  String message = "RgbLed::printProps(";
  message += "_red_pin: ";
  message += _red_pin;
  message += ", ";
  message += "_green_pin: ";
  message += _green_pin;
  message += ", ";
  message += "_blue_pin: ";
  message += _blue_pin;
  message += ", ";
  message += "_red: ";
  message += _red;
  message += ", ";
  message += "_green: ";
  message += _green;
  message += ", ";
  message += "_blue: ";
  message += _blue;
  message += ", ";
  message += ")";
  Serial.println(message);
}

/**
 * 
 */
void RgbLed::setColor(int red, int green, int blue)
{
  if (_checkColorValues(red, green, blue))
  {
    _red = red;
    _green = green;
    _blue = blue;
  }
  else
  {
    _printMessage("Wrong color values");
  }
}

/**
 * 
 */
void RgbLed::setLedOff()
{
  // reset the color of the LED so
  _led_red = 0;
  _led_green = 0;
  _led_blue = 0;
}

/**
 * 
 */
void RgbLed::setLedOn()
{
  // set color of the LED
  _led_red = _red;
  _led_green = _green;
  _led_blue = _blue;

  // activate the LED with the color set
  analogWrite(_red_pin, _led_red);
  analogWrite(_green_pin, _led_green);
  analogWrite(_blue_pin, _led_blue);
}

/**
 * 
 */
void RgbLed::_setPins(int red_pin, int green_pin, int blue_pin)
{
  if (_checkPinNumbers(red_pin, green_pin, blue_pin))
  {
    _red_pin = red_pin;
    _green_pin = green_pin;
    _blue_pin = blue_pin;
  }
  else
  {
    _printMessage("Wrong pin number definitions.");
  }
}

/**
 * 
 */
boolean RgbLed::_checkPinNumber(int pinNumber)
{
  return pinNumber > 0;
}

/**
 * 
 */
boolean RgbLed::_checkPinNumbers(int red_pin, int green_pin, int blue_pin)
{
  return _checkPinNumber(red_pin) && _checkPinNumber(green_pin) && _checkPinNumber(blue_pin);
}

/**
 * 
 */
boolean RgbLed::_checkColorValue(int value)
{
  return value > 0 && value <= 255;
}

/**
 * 
 */
boolean RgbLed::_checkColorValues(int red, int green, int blue)
{
  return _checkColorValue(red) && _checkColorValue(green) && _checkColorValue(blue);
}

/**
 * 
 */
boolean RgbLed::_checkNumberPositive(int input)
{
  return input > 0;
}

/**
 * 
 */
void RgbLed::_printMessage(String message)
{
  if (Serial.available())
  {
    Serial.println(message);
  }
}
