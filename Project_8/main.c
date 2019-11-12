//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Jim Carlson
//  Jan 2018
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.c"
#include <string.h>
#include "macros.h"



// Global Variables
extern volatile unsigned int ADC_Thumb;
extern volatile unsigned int ADC_Right_Detector;
extern volatile unsigned int ADC_Left_Detector;
volatile unsigned int UCA3_index;
volatile unsigned int UCA0_index;
char test_command[10];
volatile unsigned int usb_rx_ring_wr;
volatile unsigned int usb_tx_ring_wr;
volatile unsigned int usb_tx_ring_rd;
volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile char USBCommand[10] ;
volatile char USBTX[10] ;


volatile char slow_input_down;
extern char display_line[CASE4][CASE11];
char adc_char[10];
volatile char right_sensor[CASE4];
volatile char left_sensor[CASE4];
volatile char pot[CASE4];
extern char *display[CASE4];
unsigned char display_mode;
extern unsigned int  displaybutton2;
extern unsigned int  displaybutton1;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
volatile unsigned int Time_Sequence;
volatile unsigned int TA0CCR0counter ;
volatile unsigned int TA0CCR1counter ;
volatile unsigned int TA1CCR0counter ;
volatile unsigned int TA1CCR1counter ;
volatile unsigned int Button1DebounceCount;
volatile unsigned int Button2DebounceCount;
volatile unsigned char Button1Debounce;
volatile unsigned char Button2Debounce;
volatile unsigned char switch_LCD;
volatile unsigned int Last_Time_Sequence;
volatile unsigned char Button1Pressed;
volatile unsigned char Button2Pressed;
extern volatile char one_time;
unsigned int test_value;
char pwm_state;
char chosen_direction;
char change;
char rstate = FALSE;
int ADC_Left = 0;
int ADC_Right = 0;
unsigned int stuff1 = 4;
unsigned int stuff2 = 0x5551;
char BaudBool = 0;

volatile unsigned int usb_rx_ring_rd;
char USB_Char_Tx[LARGE_RING_SIZE];

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_LCD();   
  Init_Timer_A0();
  //Init_ADC();
  Init_Serial_UCA0(); // Initialize Serial Port for USBInit_Serial_UCA3(void
  Init_Serial_UCA3();
  //strcpy(display_line[LINE2], "   Baud   ");
  TA0CCTL0 ON CCIE;
 strcpy(display_line[LINE0], "          ");
  update_string(display_line[LINE0], LOW);
   // P8OUT ON IR_LED;
  enable_display_update();
  Display_Update(FALSE,FALSE,FALSE,FALSE);

  
  UCA3_index = 0;
  
  //UCA3IE ON UCRXIE; // Enable RX interrupt
  
//UCA3_index = 0;
UCA3IE |= UCTXIE; // Enable RX interrupt
UCA3TXBUF = test_command[0];

 // for(;;){
 //  UCA0TXBUF = 'U';
 // }
  
  strcpy(display_line[LINE0], "  Waiting ");
  strcpy(display_line[LINE3], "  115200  ");
   UCA3IE ON UCTXIE;
   //UCA3IE ON UCRXIE;
  while(ALWAYS) 
  {       
   
    // Can the Operating
    
    switch(rstate)
    {
   
    case CASE1:
    // UCA0IFG ON UCTXIFG;
     // for(int i = 0; i< 10; i++){
     //   out_character(USBTX[i]);
     // }
      UCA3_index = 0;

       UCA3IE ON UCTXIE;
       //UCA3IV ON UCTXIFG;
      rstate = 3;
      break;
    case CASE2:
      if(BaudBool)
      {
        stuff1 = 4;
        stuff2 = 0x5551;
       // strcpy(display_line[LINE0], "          ");
        Init_Serial_UCA3();
        strcpy(display_line[LINE3], "  115200  ");
        UCA3IE ON UCTXIE; // Enable TX interrupt
        //UCA3TXBUF = test_command[0];
        update_string(display_line[LINE3], LINE3);
         
      }
      if(!BaudBool)
      {
        stuff1 = 1;
        stuff2 = 0x4A11;

        //strcpy(display_line[LINE0], "          ");
        Init_Serial_UCA3();
        strcpy(display_line[LINE3], "  406800  ");
        UCA3IE ON UCTXIE; // Enable TX interrupt
        //UCA3TXBUF = test_command[0]; 
        update_string(display_line[LINE3], LINE3);
      }
      rstate = 0;
      break;
    case CASE3:
      UCA3IE ON UCTXIE;
      strcpy(display_line[LINE0], "Transmited");
      //strcpy(display_line[LINE0], " Recieved ");
      for(int i = 0; i< 10; i++){
        display_line[2][i] = test_command[i];
      }
      update_string(display_line[LINE0], LINE0);
      update_string(display_line[LINE2], LINE2);
      break;
    case CASE4:
      RecieveTransmit();
      strcpy(display_line[LINE0], " Recieved ");
      rstate = 0;
      Init_Serial_UCA3();

      break;
    default :
      update_string(display_line[LINE0], LINE0);
      update_string(display_line[LINE1], LINE1);
      update_string(display_line[LINE2], LINE2);
      update_string(display_line[LINE3], LINE3);
      break;
    }
  }
}


void out_character(char character){
//------------------------------------------------------------------------------

  while (!(UCA3IFG & UCTXIFG));
 // while (!(UCA3IFG & UCTXCPTIFG));
  UCA0TXBUF = character;
//------------------------------------------------------------------------------
}



void Init_Serial_UCA0(void){
  int i;
  for(i=0; i<SMALL_RING_SIZE; i++){
  USB_Char_Rx[i] = 0x00; // USB Rx Buffer
}
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
  for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
  USB_Char_Tx[i] = 0x00; // USB Tx Buffer
}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
  // Configure UART 0
  UCA0CTLW0 = 0; // Use word register
  UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
  UCA0CTLW0 |= UCSWRST; // Set Software reset enable
  //UCA0BRW = 52; // 9,600 Baud
  UCA0BRW = 1; //460800
  // UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
  // UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
  //UCA0MCTLW = 0x4911 ;
  UCA0MCTLW = 0x4A11 ;
  
  UCA0CTL1 &= ~UCSWRST; // Release from reset
  UCA0IE |= UCRXIE; // Enable RX interrupt
}

void Init_Serial_UCA3(void){
  int i;
  for(i=0; i<SMALL_RING_SIZE; i++){
  USB_Char_Rx[i] = 0x00; // USB Rx Buffer
}
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
  for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
  USB_Char_Tx[i] = 0x00; // USB Tx Buffer
}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
  // Configure UART 0
  UCA3CTLW0 = 0; // Use word register
  UCA3CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
  UCA3CTLW0 |= UCSWRST; // Set Software reset enable
  //UCA0BRW = 52; // 9,600 Baud
  UCA3BRW = stuff1; //460800
  // UCA0MCTLW = UCSx concatenate UCFx concatenate UCOS16;
  // UCA0MCTLW = 0x49 concatenate 1 concatenate 1;
  //UCA0MCTLW = 0x4911 ;
  UCA3MCTLW = stuff2 ;
  
  UCA3CTL1 &= ~UCSWRST; // Release from reset
  UCA3IE |= UCRXIE; // Enable RX interrupt
}

void RecieveTransmit(void)
{
  for(int i = 0; i< 10; i++){
    display_line[1][i] = USBCommand[i];
  }
   for(int i = 0; i< 10; i++){
    test_command[i] = USBCommand[i];
  }
}



