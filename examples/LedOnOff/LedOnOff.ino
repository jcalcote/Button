/*************************************************** 
  Button debounce example.

  Written by John Calcote.
  Version 1.0 - July 19, 2014
  Adapted from http://arduino.cc/en/Tutorial/Debounce
  Creative Commons License.
 ****************************************************/

#include <Button.h>

const int buttonPin = 2;
const int ledPin = 13;

Button button(buttonPin);
int ledState = HIGH;

void setup()
{
  button.init();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop()
{
  bool changed;
  if (button.state(changed) == HIGH && changed)
  {
    ledState = !ledState;
  }
  digitalWrite(ledPin, ledState);
}
