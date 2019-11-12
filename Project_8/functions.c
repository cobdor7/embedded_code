
#include "macros.h"



#include  "msp430.h"
#include  "functions.h"
#include <string.h>

extern char adc_char[CHAR10];


void WheelsForward(void)
{
  P3OUT OFF R_REVERSE;
  P3OUT OFF L_REVERSE;
  P3OUT ON R_FORWARD;
  P3OUT ON L_FORWARD;
}

void WheelsStop(void)
{
  P3OUT OFF R_FORWARD;
  P3OUT OFF L_FORWARD;
  P3OUT OFF R_REVERSE;
  P3OUT OFF L_REVERSE;
}

void WheelsReverse(void)
{
  P3OUT OFF R_FORWARD;
  P3OUT OFF L_FORWARD;
  P3OUT ON R_REVERSE;
  P3OUT ON L_REVERSE;
}

void TurnLeft(void)
{
  
  P3OUT OFF L_REVERSE;
  P3OUT OFF R_FORWARD;
  P3OUT ON R_REVERSE;
  P3OUT ON L_FORWARD;
}

void TurnRight(void)
{
  P3OUT OFF R_REVERSE;
  P3OUT OFF L_FORWARD;
  P3OUT ON L_REVERSE;
  P3OUT ON R_FORWARD;
}

void HEXtoBCD(int hex_value)
{
  int value = CASE0;
  adc_char[CASE0] = '0';
  adc_char[CASE1] = '0';
  adc_char[CASE2] = '0';
  adc_char[CASE3] = '0';
  while(hex_value > NINE3PLACE)
  {
    hex_value = hex_value - TEN3PLACE;
    value = value + CASE1;
    adc_char[CASE0] = ASCIBASE + value;
  }
  value = CASE0;
  
  while(hex_value > NINE2PLACE)
  {
    hex_value = hex_value - TEN2PLACE;
    value = value + CASE1;
    adc_char[CASE1] = ASCIBASE + value;
  }
  value = FALSE;
  while(hex_value > NINE1PLACE)
  {
    hex_value = hex_value - TEN1PLACE;
    value = value + TRUE;
    adc_char[CASE2] = ASCIBASE + value;
  }
  adc_char[CASE3] = ASCIBASE + hex_value;
}

