/*************************************************** 
  Button debounce example using Button1.

  Written by John Calcote.
  Version 1.0 - July 20, 2014
  Adapted from http://arduino.cc/en/Tutorial/Debounce
  Creative Commons License.
 ****************************************************/

#include <Button1.h>

const int buttonPin = 2;
const int ledPin = 13;

Button1 button(buttonPin);
int ledState = HIGH;

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop()
{
  if (button.pressed())
  {
    ledState = !ledState;
  }
  digitalWrite(ledPin, ledState);
}