#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"


unsigned int  displaybutton2;
unsigned int  displaybutton1;
extern char rstate;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
extern volatile unsigned int Time_Sequence;
extern char BaudBool;


volatile unsigned int ADC_Thumb;
volatile unsigned int ADC_Right_Detector;
volatile unsigned int ADC_Left_Detector;
extern volatile unsigned int UCA3_index;
extern volatile unsigned int UCA0_index;
extern char test_command[];
extern volatile char USBCommand[];

extern volatile unsigned int TA0CCR0counter;
extern volatile unsigned int TA0CCR1counter;
extern volatile unsigned int TA1CCR0counter;
extern volatile unsigned int TA1CCR1counter;
extern volatile unsigned int Button1DebounceCount;
extern volatile unsigned int Button2DebounceCount;
extern volatile unsigned char Button1Debounce;
extern volatile unsigned char Button2Debounce;
extern volatile unsigned char switch_LCD;
extern volatile unsigned int Last_Time_Sequence;
extern volatile unsigned char Button1Pressed;
extern volatile unsigned char Button2Pressed;


#pragma vector=PORT5_VECTOR
__interrupt void BUTTON_interrupt(void)
{
  //Button 1
  if((P5IFG & BUTTON1))
  { 
    rstate = 2;
    Button1Pressed = TRUE;
    Button1Debounce = TRUE;
    TA0CCTL1 ON CCIE;
    TA0CTL OFF TAIFG;
    switch(BaudBool){
  case 0:
    BaudBool = 1;
    break;
  case 1:
    BaudBool = 0;
    break;
    }
    //BaudBool = !BaudBool;
    
    P5IFG OFF BUTTON1;
    P5IE OFF BUTTON1;
   
    
  }
  if((P5IFG & BUTTON2))
  {
    Button2Pressed = TRUE;
    Button2Debounce = TRUE;
    
    rstate = 1;
   // TA0CCTL0 ON CCIE;
    TA0CCTL1 ON CCIE;
    TA0CTL OFF TAIFG;
    //P5OUT ON LCD_BACKLITE;
    
    P5IFG OFF BUTTON2;        // Clear all P5.5 interrupt flags
    P5IE OFF BUTTON2;          // P5.6 interrupt enable
  }
  
}


#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer0_A1_Interrupt(void)
{
  

  
  switch(__even_in_range(TA0IV,OVERFLOW))
  {
    
    case NOINTERRUPT: break; //no interrupt
    case CHECKDEBOUNCE: 
      
        if(Button1Debounce == TRUE)
        {
          Button1DebounceCount++;
          if(Button1DebounceCount == DEBOUNCEPERIOD)
          {
            P5IFG OFF BUTTON1;
            P5IE ON BUTTON1;
            Button1Debounce = FALSE;  
            Button1DebounceCount = FALSE;
          }
          
        }
        
        if(Button2Debounce == TRUE)
        {
          Button2DebounceCount++;
          if(Button2DebounceCount >= DEBOUNCEPERIOD)
          {
            P5IFG OFF BUTTON2;
            P5IE ON BUTTON2;
            Button2Debounce = FALSE;
            Button2DebounceCount = FALSE;
          }
        }
        TA0CCR1 += TA0CCR1_INTERVAL;
        break;
  case  TA0CCR1ADD:
    
    break;
  case OVERFLOW:
    break;
  default: break;
  }
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void) {
  TA0CCR0 += TA0CCR0_INTERVAL;
  TA0CCR0counter++;
    
      update_display = TRUE;
      //display_changed = TRUE;
      
      Display_Update(FALSE,FALSE,FALSE,FALSE);
  

    if( switch_LCD == FALSE)
    {
      switch_LCD = TRUE;
      P1OUT ON GRN_LED;
    }
    else if( switch_LCD)
    {
      P1OUT OFF GRN_LED;
      switch_LCD = FALSE;
    }

}

void Init_Timer_A0(void)
{
   
  TA0CTL = TASSEL__SMCLK;
  TA0CTL ON TACLR;
  TA0CTL ON MC__CONTINUOUS;
  TA0CTL ON ID__8;
 
  TA0EX0 = TAIDEX_7;
 
  TA0CCR0 = TA0CCR0_INTERVAL;
  TA0CCTL0 ON CCIE;
  
  TA0CCR1 = TA0CCR1_INTERVAL;
  TA0CCTL1 OFF CCIE;
  
  TA0CTL OFF TAIE;
  TA0CTL OFF TAIFG;
}

#pragma vector = ADC12_B_VECTOR
__interrupt void ADC12_ISR(void){
switch(__even_in_range(ADC12IV, ADC12IV__ADC12RDYIFG)){
case ADC12IV__NONE: break; // Vector 0: No interrupt
case ADC12IV__ADC12OVIFG: break; // Vector 2: ADC12MEMx Overflow
case ADC12IV__ADC12TOVIFG: break; // Vector 4: Conversion time overflow
case ADC12IV__ADC12HIIFG: break; // Vector 6: ADC12BHI
case ADC12IV__ADC12LOIFG: break; // Vector 8: ADC12BLO
case ADC12IV__ADC12INIFG: break; // Vector 10: ADC12BIN
case ADC12IV__ADC12IFG0: break; // Vector 12: ADC12MEM0 Interrupt
case ADC12IV__ADC12IFG1: break; // Vector 14: ADC12MEM1 Interrupt
case ADC12IV__ADC12IFG2: // Vector 16: ADC12MEM2 Interrupt
ADC_Thumb = ADC12MEM0; // A02 ADC10INCH_2
ADC_Right_Detector = ADC12MEM1; // A05 ADC10INCH_4
ADC_Left_Detector = ADC12MEM2; // A04 ADC10INCH_5
break;
case ADC12IV__ADC12IFG3: break; // Vector 18: ADC12MEM3
case ADC12IV__ADC12IFG4: break; // Vector 20: ADC12MEM4
case ADC12IV__ADC12IFG5: break; // Vector 22: ADC12MEM5
case ADC12IV__ADC12IFG6: break; // Vector 24: ADC12MEM6
case ADC12IV__ADC12IFG7: break; // Vector 26: ADC12MEM7
case ADC12IV__ADC12IFG8: break; // Vector 28: ADC12MEM8

case ADC12IV__ADC12IFG9: break; // Vector 30: ADC12MEM9
case ADC12IV__ADC12IFG10: break; // Vector 32: ADC12MEM10
case ADC12IV__ADC12IFG11: break; // Vector 34: ADC12MEM11
case ADC12IV__ADC12IFG12: break; // Vector 36: ADC12MEM12
case ADC12IV__ADC12IFG13: break; // Vector 38: ADC12MEM13
case ADC12IV__ADC12IFG14: break; // Vector 40: ADC12MEM14
case ADC12IV__ADC12IFG15: break; // Vector 42: ADC12MEM15
case ADC12IV__ADC12IFG16: break; // Vector 44: ADC12MEM16
case ADC12IV__ADC12IFG17: break; // Vector 46: ADC12MEM17
case ADC12IV__ADC12IFG18: break; // Vector 48: ADC12MEM18
case ADC12IV__ADC12IFG19: break; // Vector 50: ADC12MEM19
case ADC12IV__ADC12IFG20: break; // Vector 52: ADC12MEM20
case ADC12IV__ADC12IFG21: break; // Vector 54: ADC12MEM21
case ADC12IV__ADC12IFG22: break; // Vector 56: ADC12MEM22
case ADC12IV__ADC12IFG23: break; // Vector 58: ADC12MEM23
case ADC12IV__ADC12IFG24: break; // Vector 60: ADC12MEM24
case ADC12IV__ADC12IFG25: break; // Vector 62: ADC12MEM25
case ADC12IV__ADC12IFG26: break; // Vector 64: ADC12MEM26
case ADC12IV__ADC12IFG27: break; // Vector 66: ADC12MEM27
case ADC12IV__ADC12IFG28: break; // Vector 68: ADC12MEM28
case ADC12IV__ADC12IFG29: break; // Vector 70: ADC12MEM29
case ADC12IV__ADC12IFG30: break; // Vector 72: ADC12MEM30
case ADC12IV__ADC12IFG31: break; // Vector 74: ADC12MEM31
case ADC12IV__ADC12RDYIFG: break; // Vector 76: ADC12RDY
default: break;
}
}

//------------------------------------------------------------------------------

// global variables
extern volatile unsigned int usb_rx_ring_wr;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
//------------------------------------------------------------------------------
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
unsigned int temp;
switch(__even_in_range(UCA0IV,0x08)){
case 0: // Vector 0 - no interrupt
break;
case 2: // Vector 2 - RXIFG
temp = usb_rx_ring_wr;
USB_Char_Rx[temp] = UCA0RXBUF; // RX -> USB_Char_Rx character
if (++usb_rx_ring_wr >= (SMALL_RING_SIZE)){
usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
}
break;
case 4: // Vector 4 – TXIFG
  switch(UCA0_index++){
    case 0: //
    case 1: //
    case 2: //
    case 3: //
    case 4: //
    case 5: //
    case 6: //
    case 7: //
    case 8: //
    case 9: //
    UCA0TXBUF = test_command[UCA3_index];
    break;
    case 10: //
    UCA0TXBUF = 0x0D;
    break;
    case 11: // Vector 0 - no interrupt
    UCA0TXBUF = 0x0A;
    break;
    default:
    UCA0IE &= ~UCTXIE; // Disable TX interrupt
    break;
}
break;
default: break;
}
}

 int countChar;
char readFlag = 0;


//------------------------------------------------------------------------------
#pragma vector=USCI_A3_VECTOR
__interrupt void USCI_A3_ISR(void){
unsigned int temp;
switch(__even_in_range(UCA3IV,0x08)){
case 0: // Vector 0 - no interrupt
break;
case 2: // Vector 2 - RXIFG
temp = usb_rx_ring_wr;



if(UCA3RXBUF == '$'){
    
    readFlag = 1;
}
 
if(UCA3RXBUF == '\n'){
    rstate = 4;
    readFlag = 0;
    countChar = 0;
}


if(readFlag)
{
   USBCommand[countChar] = UCA3RXBUF;
   countChar++;
}
USB_Char_Rx[temp] = UCA3RXBUF; // RX -> USB_Char_Rx character
if (++usb_rx_ring_wr >= (SMALL_RING_SIZE))
{
  usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
}
break;
case 4: // Vector 4 – TXIFG
  
    switch(UCA3_index++)
    {
      case 0: //
      case 1: //
      case 2: //
      case 3: //
      case 4: //
      case 5: //
      case 6: //
      case 7: //
      case 8: //
      case 9: //
      UCA3TXBUF = test_command[UCA3_index - 1];
      break;
      case 10: //
      UCA3TXBUF = 0x0D;
      break;
      case 11: // Vector 0 - no interrupt
      UCA3TXBUF = 0x0A;
      break;
      default:
      UCA3IE &= ~UCTXIE; // Disable TX interrupt
      break;
    }     
  
break;
default: break;
}
}
//------------------------------------------------------------------------------
