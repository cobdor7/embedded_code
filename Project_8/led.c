//------------------------------------------------------------------------------
//
//  Description: This file contains the functions to control the leds
//
//
//  Andrew James
//  Sept 2018
//  Built with IAR Embedded Workbench Version: V6.5.4 (7.12.1)
//------------------------------------------------------------------------------


#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

void Init_LEDs(void);


void Init_LEDs(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on both LEDs
  P1OUT &= ~RED_LED;
  P1OUT &= ~GRN_LED;
//------------------------------------------------------------------------------
}