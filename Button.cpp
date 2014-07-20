/*************************************************** 
  This is a debounced button library.

  The state() method should be called multiple times
  in loop() to check for both current state and state
  change before considering the button to be either
  pushed or released:

  #include <Button.h>
  Button button(2);

  void setup() {
    button.init();
  }

  void loop() {
    bool changed;
    if (button.state(changed) == HIGH && changed) {
      // button was pressed
    }
    if (button.state(changed) == LOW && changed) {
      // button was released
    }
  }

  Written by John Calcote.
  Version 1.0 - July 19, 2014
  Adapted from http://arduino.cc/en/Tutorial/Debounce
  Creative Commons License.
 ****************************************************/

#include <Button.h>

Button::Button(int pin, unsigned long delay)
: pin_(pin), delay_(delay), state_(LOW), lastState_(LOW), timer_(0)
{
}

void Button::init()
{
  pinMode(pin_, INPUT);
}

int Button::state(bool& changed)
{
  changed = false;
  int reading = digitalRead(pin_);
  unsigned long clock = millis();
  if (reading != lastState_)
  {
    timer_ = clock;  // state changed - reset timer
  }
  if (clock - timer_ > delay_)
  {
    if (reading != state_)
    {
      changed = true;
      state_ = reading;
    }
  }
  lastState_ = reading;
  return state_;
}
