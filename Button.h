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

#ifndef BUTTON_H
#define BUTTON_H

#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"
#endif

class Button
{
public:
  static const unsigned long defaultDelay = 50;  // milliseconds

  /**
   * Constructor - accepts a pin and an optional delay (default given).
   * pin - the pin to use for button input
   * delay - the delay in milliseconds to ensure debounce when reading the button pin.
   */
  Button(int pin, unsigned long delay = defaultDelay);
  
  /**
   * Initializer - call in setup(). Sets pin state to INPUT.
   */
  void init();
  
  /**
   * Get current button state and whether the state has changed since the
   * last debounced read.
   * changed - returns true if the given state represents a change from the 
   * last time this method was called.
   * returns the current state of the button - HIGH or LOW.
   */
  int state(bool& changed);
  
private:
  int pin_;
  unsigned long delay_;
  int state_;
  int lastState_;
  unsigned long timer_;
};

#endif  // BUTTON_H
