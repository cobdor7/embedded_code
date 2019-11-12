//------------------------------------------------------------------------------
//
//  Description: This file initializes all ports in the board when 
//      Init_Ports() is called.
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


void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);
void Init_Port7(void);
void Init_Port8(void);
void Init_PortJ(void);

void Init_Ports(void)
//@Public
//Main function of this file, called by main(),calls every other port 
//to initilze their individual ports. 
//@returns None
{
  
  Init_Port1();
  Init_Port2();
  Init_Port3();
  Init_Port4();
  Init_Port5();
  Init_Port6();
  Init_Port7();
  Init_Port8();
  Init_PortJ(); 
}

void Init_Port1(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
 //Configure Port 1
  P1SEL0 = RESET_STATE;                       // GP I/O
  P1SEL1 = RESET_STATE;                       // GP I/O
  P1DIR = RESET_STATE;                        // Set P1 direction to input
  // P1_0
  P1SEL0 &= ~RED_LED;                  // RED_LED as GP I/O
  P1SEL1 &= ~RED_LED;                  // RED_LED as GP I/O
  P1OUT |= RED_LED;                    // Set Red LED On
  P1DIR |= RED_LED;                    // Set Red LED direction to output
  // P1_1
  P1SEL0 &= ~GRN_LED;                  // GRN_LED as GP I/O
  P1SEL1 &= ~GRN_LED;                  // GRN_LED as GP I/O
  P1OUT |= GRN_LED;                    // Set Green LED On
  P1DIR |= GRN_LED;                    // Set Green LED direction to output
  // P1_2
  P1SEL0 |= V_THUMB;                   // ADC input for Thumbwheel
  P1SEL1 |= V_THUMB;                   // ADC input for Thumbwheel
  // P1_3
  P1SEL0 &= ~TEST_PROBE;               // TEST_PROBE as GP I/O
  P1SEL1 &= ~TEST_PROBE;               // TEST_PROBE as GP I/O
  P1OUT &= ~TEST_PROBE;                // Set TEST_PROBE Off
  P1DIR |= TEST_PROBE;                 // Set TEST_PROBE direction to output
  // P1_4
  P1SEL0 |= V_DETECT_R;                 // ADC input for Right Detector
  P1SEL1 |= V_DETECT_R;                // ADC input for Right Detector
  // P1_5
  P1SEL0 |= V_DETECT_L;                // ADC input for Left Detector
  P1SEL1 |= V_DETECT_L;                // ADC input for Left Detector
  // P1_6
  P1SEL0 &= ~SD_UCB0SIMO;              // USCI_B1 MOSI pin
  P1SEL1 |= SD_UCB0SIMO;               // USCI_B1 MOSI pin
  // P1_7
  P1SEL0 &= ~SD_UCB0SOMI;              // USCI_B1 MISO pin
  P1SEL1 |= SD_UCB0SOMI;               // USCI_B1 MISO pin
}

void Init_Port2(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{	
  //P2.0
  P2SEL0 &= ~UCA0TXD;
  P2SEL1 |= UCA0TXD;
  //P2.1
  P2SEL0 &= ~UCA0RXD;
  P2SEL1 |= UCA0RXD;
  //P2.2
  P2SEL0 &= ~SD_SPICLK;
  P2SEL1 |= SD_SPICLK;
  //P2.3
  P2SEL0 &= ~P2_3;
  P2SEL1 &= ~P2_3;
  P2DIR  &= ~P2_3;
  //P2.4
  P2SEL0 &= ~P2_4;
  P2SEL1 &= ~P2_4;
  P2DIR  &= ~P2_4;
  //P2.5
  P2SEL0 &= ~UCA1TXD;
  P2SEL1 |= UCA1TXD;
  //P2.6
  P2SEL0 &= ~UCA1RXD;
  P2SEL1 |= UCA1RXD;
  //P2.4
  P2SEL0 &= ~P2_7;
  P2SEL1 &= ~P2_7;
  P2DIR  &= ~P2_7;
}
  
void Init_Port3(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //------------------------------------------------------------------------------
  P3DIR = FULL_STATE;                   // Set P1 direction to output
  P3OUT = RESET_STATE;                   // P1 set Low
  P3SEL0 &= ~IOT_RESET;           // Set to GP I/O
  P3SEL1 &= ~IOT_RESET;           // Set to GP I/O
  P3OUT &= ~IOT_RESET;            // Set out value Low [active]
  P3DIR |= IOT_RESET;             // Set direction to output
  P3SEL0 &= ~IOT_PROG_MODE;       // Set to GP I/O
  P3SEL1 &= ~IOT_PROG_MODE;       // Set to GP I/O
  P3DIR &= ~IOT_PROG_MODE;        // Set direction to input
  P3SEL0 &= ~IOT_LINK;            // Set to GP I/O
  P3SEL1 &= ~IOT_LINK;            // Set to GP I/O
  P3DIR &= ~IOT_LINK;             // Set direction to inpuT
  P3SEL0 &= ~IOT_PROG_SEL;        // Set to GP I/O
  P3SEL1 &= ~IOT_PROG_SEL;        // Set to GP I/O
  P3DIR &= ~IOT_PROG_SEL;        // Set direction to input
  P3SEL0 &= ~L_REVERSE;           // Set to GP I/O
  P3SEL1 &= ~L_REVERSE;           // Set to GP I/O
  P3OUT &= ~L_REVERSE;            // Set out value Low [off]
  P3DIR |= L_REVERSE;             // Set direction to output
  P3SEL0 &= ~L_FORWARD;           // Set to GP I/O
  P3SEL1 &= ~L_FORWARD;           // Set to GP I/O
  P3OUT &= ~L_FORWARD;            // Set out value Low [off]
  P3DIR |= L_FORWARD;             // Set direction to output
  P3SEL0 &= ~R_REVERSE;           // Set to GP I/O
  P3SEL1 &= ~R_REVERSE;           // Set to GP I/O
  P3OUT &= ~R_REVERSE;            // Set out value Low [off]
  P3DIR |= R_REVERSE;             // Set direction to output
  P3SEL0 &= ~R_FORWARD;           // Set to GP I/O
  P3SEL1 &= ~R_FORWARD;           // Set to GP I/O
  P3OUT &= ~R_FORWARD;            // Set out value Low [off]
  P3DIR |= R_FORWARD;             // Set direction to output
  //------------------------------------------------------------------------------
}

void Init_Port4(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //P4.0
  P4SEL0 OFF SD_CS;
  P4SEL1 OFF SD_CS;
  P4DIR POUT SD_CS;
  P4OUT OFF SD_CS;
  //P4.1
  P4SEL0 OFF J4_31;
  P4SEL1 OFF J4_31;
  P4DIR  IN  J4_31;
  //P4.2
  P4SEL0 OFF J4_32;
  P4SEL1 OFF J4_32;
  P4DIR  IN  J4_32;
  //P4.3
  P4SEL0 OFF J4_33;
  P4SEL1 OFF J4_33;
  P4DIR  IN  J4_33;
  //P4.4
  P4SEL0 OFF UCB1_CS_LCD;
  P4SEL1 OFF UCB1_CS_LCD;
  P4DIR POUT UCB1_CS_LCD;
  P4OUT OFF UCB1_CS_LCD;
  //P4.5
  P4SEL0 OFF P4_4;
  P4SEL1 OFF P4_4;
  P4DIR  IN  P4_4;
  //P4.6
  P4SEL0 OFF P4_5;
  P4SEL1 OFF P4_5;
  P4DIR  IN  P4_5;
  //P4.7
  P4SEL0 OFF J3_29;
  P4SEL1 OFF J3_29;
  P4DIR  POUT J3_29;
}


void Init_Port5(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //--------------------------------------------------------------------
  // Configure PORT 5
  // SPI_UCB1SIMO         (0x01)    // UCB1SIMO
  // SPI_UCB1SOMI         (0x02)    // UCB1SOMI
  // SPI_UCB1CLK          (0x04)    // SPI mode -clock output—UCB1CLK
  // RESET_LCD            (0x08)    // LCD Reset
  // BUTTON2              (0x20)    // Button 2
  // BUTTON1              (0x40)    // Button 1
  // LCD_BACKLITE         (0x80)    // LCD Backlight
  P5SEL0 = RESET_STATE;                  // GP I/O
  P5SEL1 = RESET_STATE;                  // GP I/O
  //P5_0
  P5SEL0 |= SPI_UCB1SIMO;         // USCI_B1 SIMO pin
  P5SEL1 &= ~SPI_UCB1SIMO;        // USCI_B1 SIMO pin
  //P5_1
  P5SEL0 |= SPI_UCB1SOMI;         // USCI_B1 SOMI pin
  P5SEL1 &= ~SPI_UCB1SOMI;        // USCI_B1 SOMI pin
  //P5_2
  P5SEL0 |= SPI_UCB1CLK;          // USCI_B1 SCLK pin
  P5SEL1 &= ~SPI_UCB1CLK;         // USCI_B1 SCLK pin
  //P5_3
  P5SEL0 &= ~RESET_LCD;           // Set GP I/O for RESET_LCD
  P5SEL1 &= ~RESET_LCD;           // Set GP I/O for RESET_LCD
  P5OUT |= RESET_LCD;             // Set RESET_LCD Off [High]
  P5DIR |= RESET_LCD;             // Set RESET_LCD direction to output
  //P5_4
  P5SEL0 &= ~P5_4;         // Set GP I/O for P5_4_UNUSED
  P5SEL1 &= ~P5_4;         // Set GP I/O for P5_4_UNUSED
  P5DIR &= ~P5_4;           // Set RESET_LCD direction to input
  //P5_5
  P5SEL0 &= ~BUTTON2;            // Set GP I/O for BUTTON2
  P5SEL1 &= ~BUTTON2;             // Set GP I/O for BUTTON2
  P5OUT |= BUTTON2;              // Configure pullup resistor
  P5DIR &= ~BUTTON2;             // Direction = input
  P5REN |= BUTTON2;              // Enable pullup resistor
  P5IES |= BUTTON2;          // P5.5 Hi/Lo edge interrupt
  P5IFG &= ~BUTTON2;           // Clear all P5.6 interrupt flags
  P5IE |= BUTTON2;             // P5.5 interrupt enabled
  //P5_6
  P5SEL0 &= ~BUTTON1;         // Set GP I/O for BUTTON1
  P5SEL1 &= ~BUTTON1;         // Set GP I/O for BUTTON1
  P5OUT |= BUTTON1;           // Configure pullup resistor
  P5DIR &= ~BUTTON1;          // Direction = input
  P5REN |= BUTTON1;           // Enable pullup resistor
  P5IES |= BUTTON1;         // P5.6 Hi/Lo edge interrupt
  P5IFG &= ~BUTTON1;        // Clear all P5.5 interrupt flags
  P5IE |= BUTTON1;          // P5.6 interrupt enabled
  //P5_7
  P5SEL0 &= ~LCD_BACKLITE;   // Set GP I/O for LCD_BACKLITE
  P5SEL1 &= ~LCD_BACKLITE;   // Set GP I/O for LCD_BACKLITE
  P5OUT |= LCD_BACKLITE;     // Set LCD_BACKLITE On [High]
  P5DIR |= LCD_BACKLITE;     // Set LCD_BACKLITE direction to output
  //--------------------------------------------------------------------
}

void Init_Port6(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //6.0
  P6SEL0 ON UCA3TXD;
  P6SEL1 OFF UCA3TXD;
  //6.1
  P6SEL0 ON UCA3RXD;
  P6SEL1 OFF UCA3RXD;
  //6.2
  P6SEL0 OFF J1_5;
  P6SEL1 OFF J1_5;
  P6DIR  POUT J1_5;
  //6.3
  P6SEL0 OFF MAG_INT;
  P6SEL1 OFF MAG_INT;
  P6DIR IN MAG_INT;
  //6.4
  P6SEL0 OFF P6_4;
  P6SEL1 OFF P6_4;
  P6DIR IN P6_4;
  //6.5
  P6SEL0 OFF P6_5;
  P6SEL1 OFF P6_5;
  P6DIR IN P6_5;
  //6.6
  P6SEL0 OFF P6_6;
  P6SEL1 OFF P6_6;
  P6DIR IN P6_6;
  //6.7
  P6SEL0 OFF P6_7;
  P6SEL1 OFF P6_7;
  P6DIR IN P6_7;
}

void Init_Port7(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //7.0
  P7SEL0 ON I2CSDA;
  P7SEL1 OFF I2CSDA;
  //7.1
  P7SEL0 ON I2CSCL;
  P7SEL1 OFF I2CSCL;
  //7.2
  P7SEL0 OFF SD_DETECT;
  P7SEL1 OFF SD_DETECT;
  P7DIR OFF SD_DETECT;
  //7.3
  P7SEL0 OFF J4_36;
  P7SEL1 OFF J4_36;
  P7DIR OFF J4_36;
  //7.4
  P7SEL0 OFF P7_4;
  P7SEL1 OFF P7_4;
  P7DIR OFF P7_4;
  //7.5
  P7SEL0 OFF P7_5;
  P7SEL1 OFF P7_5;
  P7DIR OFF P7_5;
  //7.6
  P7SEL0 OFF P7_6;
  P7SEL1 OFF P7_6;
  P7DIR OFF P7_6;
  //7.7
  P7SEL0 OFF P7_7;
  P7SEL1 OFF P7_7;
  P7DIR OFF P7_7;
}

void Init_Port8(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //P8.0
  P8SEL0 OFF IR_LED;
  P8SEL1 OFF IR_LED;
  P8DIR POUT IR_LED;
  P8OUT OFF IR_LED;
  //P8.1
  P8SEL0 OFF OPT_INT;
  P8SEL1 OFF OPT_INT;
  P8DIR IN OPT_INT;
  //P8.2
  P8SEL0 OFF TMP_INT;
  P8SEL1 OFF TMP_INT;
  P8DIR IN TMP_INT;
  //P8.3
  P8SEL0 OFF INT2;
  P8SEL1 OFF INT2;
  P8DIR IN INT2;
}	

void Init_PortJ(void)
//@Public
//Secondary function of this file, called by Init_Ports(),calls none. 
//Initilizes all P# macros to the correct SEL0, SEL1, DIR, and OUT.
//@returns None
{
  //PJ.0
  PJSEL0 OFF PJ_0;
  PJSEL1 OFF PJ_0;
  PJDIR IN PJ_0;
  //PJ.1
  PJSEL0 OFF PJ_1;
  PJSEL1 OFF PJ_1;
  PJDIR IN PJ_1;
  //PJ.2
  PJSEL0 OFF PJ_2;
  PJSEL1 OFF PJ_2;
  PJDIR IN PJ_2;
  //PJ.3
  PJSEL0 OFF PJ_3;
  PJSEL1 OFF PJ_3;
  PJDIR IN PJ_3;
  //PJ.4
  PJSEL0 ON LFXIN;
  PJSEL1 OFF LFXIN;
  //PJ.5
  PJSEL0 ON LFXOUT;
  PJSEL1 OFF LFXOUT;
  //PJ.6
  PJSEL0 ON HFXIN;
  PJSEL1 OFF HFXIN;
  //PJ.7
  PJSEL0 ON HFXOUT;
  PJSEL1 OFF HFXOUT;
  
}