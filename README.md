Button
======

Arduino debounced button library

How hard can it be to press a button and toggle the state of an LED on your Arduino? Harder than you might think. When you press a button tied to an INPUT GPIO pin, the pin actually experiences several milliseconds of on/off state changes due to an effect in the mechanical button called "bounce". Electrons travel so much faster than your finger as it presses down on the button that the input pin experiences several dozen to several hundred transitions from ON to OFF and back again before it settles down and decides to maintain the current state of the circuit.

The Button library consolidates information from several example programs found on the Internet to debounce a button connected to an input pin on an Arduino. The library provides a class called 'Button' which has a constructor that takes the input pin number, an 'init' method that configures the specified pin, and a 'state' method that should be called each time through the loop() function to determine if the button has been pressed. 

The 'state' method returns HIGH or LOW to indicate the current state of the button. But it also accepts a 'changed' reference parameter that is returned as 'true' if the Button detected that state actually changed since the last time the 'state' method was called.

There's a simple example in the examples directory called LedOnOff.ino which demonstrates this use.
