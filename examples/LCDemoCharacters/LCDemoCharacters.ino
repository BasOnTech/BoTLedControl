//We always have to include the library
#include "BoTLedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
  We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 11, 10, 1);

int i = 0;

String charString = "0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy,-/\[]._";
char charArray[58];

void setup()
{
    charString.toCharArray(charArray, 58);

    /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
    */
    lc.shutdown(0, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0, 8);
    /* and clear the display */
    lc.clearDisplay(0);
}

void loop()
{
    setChar(0, 7 - (i % 8), charArray[i % 58], false);
    i++;
    delay(250);
}