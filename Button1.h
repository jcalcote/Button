/*************************************************** 
  This is a debounced button library.

  The pressed() method should be called each time
  through loop() in order to find a debounced state
  for the switch. That is, some pass through loop will
  have resolved the debounced state of the switch:

  #include <Button1.h>
  Button1 button(2);

  void setup() {
  }

  void loop() {
    if (button.pressed()) {
      // button was pressed
    }
  }

  Button1::pressed() gets called regularly by loop() to
  determine in a debounced fashion if the button was pressed.
  It shifts the current raw value of the switch into state_.
  Assuming the contacts return one for a closed condition,
  the pressed method returns FALSE till a dozen sequential
  closures are detected. 
 
  One bit of cleverness lurks in the algorithm. As long as the
  switch isn’t closed, ones shift through state_. When the user
  pushes on the button the stream changes to a bouncy pattern
  of ones and zeroes, but at some point there’s the last bounce
  (a one) followed by a stream of zeros. We OR in 0xe000 to
  create a “don’t care” condition in the upper bits. But as the
  button remains depressed, state_ continues to propagate zeroes.
  There’s just the one time, when the last bouncy “one” was in
  the upper bit position, that the code returns a TRUE. That bit
  of wizardry eliminates bounces and detects the edge - the
  transition from open to closed. 
 
  Change the two hex constants to accommodate different bounce
  times and timer rates.
  
  Written by John Calcote.
  Version 1.0 - July 20, 2014
  Adapted from http://www.eng.utah.edu/~cs5780/debouncing.pdf
  Creative Commons License.
 ****************************************************/

#ifndef BUTTON1_H
#define BUTTON1_H

#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"
#endif

class Button1
{
public:
  /**
   * Constructor - accepts a pin and an optional delay (default given).
   * pin - the pin to use for button input
   */
  Button1(int pin);
  
  /**
   * Return true if the button was pressed.
   */
  bool pressed();
  
private:
  int pin_;
  uint16_t state_;
};

#endif  // BUTTON1_H
