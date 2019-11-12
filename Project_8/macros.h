//------------------------------------------------------------------------------
//
//  Description: This file contains the Macros for all files
//
//
//  Andrew James
//  Sept 2018
//  Built with IAR Embedded Workbench Version: V6.5.4 (7.12.1)
//------------------------------------------------------------------------------
#define CHAR10  10
#define LINE0   0
#define LINE1   1
#define LINE2   2
#define LINE3   3
#define HIGH    1
#define LOW     0
#define STEP1   125
#define STEP2   100
#define STEP3   75
#define STEP4   50
#define STEP5   25
#define INBUTTON1       (0x02)
#define INBUTTON2       (0x04)
#define WAIT1000        1000
#define WAIT200         200

#define NINE3PLACE   999
#define NINE2PLACE   99
#define NINE1PLACE   9
#define FULL_STATE 0xFF
#define TEN3PLACE 1000
#define TEN2PLACE 100
#define TEN1PLACE 10

#define ASCIBASE (0x30)

#define INTERVALTA1CCR0 25000
#define DEBOUNCEPERIOD  5

#define TRUE   1
#define FALSE   0
#define OFF     &=~
#define ON      |=
#define IN      &=~
#define POUT     |=

//PROJECT 5

#define CASE0   0
#define CASE1   1
#define CASE2   2
#define CASE3   3
#define CASE4   4
#define CASE5   5
#define CASE6   6
#define CASE7   7
#define CASE8   8
#define CASE9   9
#define CASE11   11
#define CASE13   13
#define CASE16   16


//iNTERUPTS ===================

#define NOINTERRUPT     0
#define CHECKDEBOUNCE   2
#define TA0CCR1ADD      4
#define OVERFLOW        14

//MACROS========================================================================
#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)
#define CSLOCK                  (0x01) // Any incorrect password locks registers

// Port J Pins
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR
#define CLEAR_REGISTER     (0X0000)

#define TA1CCR0_INTERVAL        25000
#define TA0CCR0_INTERVAL        25000
#define TA0CCR1_INTERVAL        25000
#define TWENTYINTERRUPTS        (20)
#define TENINTERRUPTS           (10)
#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define PORTS                (0x00) // PORTS
#define PWM_MODE             (0x01) // PWM_MODE

// Port 1 Pins
#define RED_LED         (0x01) //RED LED - P1_0_LED1
#define GRN_LED         (0x02) //Green LED -P1_1_LED2
#define V_THUMB         (0x04) // ADC for Thumb Wheel
#define TEST_PROBE       (0x08) // GPI Pin
#define V_DETECT_R      (0x10) //ADC for Right Dectector
#define V_DETECT_L      (0x20) //ADC for Left Detector
#define SD_UCB0SIMO     (0x40) // SPI mode - slave in/master out for SD Card
#define SD_UCB0SOMI     (0x80) // SPI mode - slave out/master in for SD Card

// Port 2 Pins
#define UCA0TXD         (0x01) //
#define UCA0RXD         (0x02) //
#define SD_SPICLK       (0x04) //
#define P2_3            (0x08) //
#define P2_4            (0x10) //
#define UCA1TXD         (0x20) //
#define UCA1RXD         (0x40) //
#define P2_7            (0x80) //

//Port 3 pines
#define IOT_RESET       (0x01)  //Reset
#define IOT_PROG_MODE   (0x02) //Iot_Prog_Mode
#define IOT_LINK        (0x04) // Iot_link
#define IOT_PROG_SEL    (0x08) //IOT_Prog_sel
#define L_REVERSE       (0x10) //Left Reverse
#define L_FORWARD       (0x20) //Left Forward
#define R_REVERSE       (0x40) //Right Reverse
#define R_FORWARD       (0x80) //Right Forward

//Port 4
#define SD_CS           (0X01)
#define J4_31           (0x02)
#define J4_32           (0x04)
#define J4_33           (0x08)
#define UCB1_CS_LCD     (0x10)
#define P4_4            (0x20)
#define P4_5            (0x40)
#define J3_29           (0x80)

// Port 5 Pins
#define SPI_UCB1SIMO         (0x01) // UCB1SIMO
#define SPI_UCB1SOMI         (0x02) // UCB1SOMI
#define SPI_UCB1CLK          (0x04) // SPI mode -clock output—UCB1CLK
#define RESET_LCD            (0x08) // LCD Reset
#define P5_4                 (0x10) // UNUSED
#define BUTTON2              (0x20) // Button 2
#define BUTTON1              (0x40) // Button 1
#define LCD_BACKLITE         (0x80) // LCD Backlite

// Port 6 Pins
#define UCA3TXD         (0x01)
#define UCA3RXD         (0x02)
#define J1_5            (0x04)
#define MAG_INT         (0x08)
#define P6_4            (0x10)
#define P6_5            (0x20)
#define P6_6            (0x40)
#define P6_7            (0x80)

//Ports 7
#define I2CSDA          (0x01)
#define I2CSCL          (0x02)
#define SD_DETECT       (0x04)
#define J4_36           (0x08)
#define P7_4            (0x10)
#define P7_5            (0x20)
#define P7_6            (0x40)
#define P7_7            (0x80)

//MACROS========================================================================
#define FLLN_BITS          (0x03ffu)
#define FLLN_255           (0x00ffu)
#define CSLOCK                  (0x01) // Any incorrect password locks registers

// Port J Pins
#define XINR                 (0x10) // XINR
#define XOUTR                (0x20) // XOUTR
#define CLEAR_REGISTER     (0X0000)


//Ports 8
#define IR_LED          (0x01)
#define OPT_INT         (0x02)
#define TMP_INT         (0x04)
#define INT2            (0x08)

//Ports J
#define PJ_0            (0x01)
#define PJ_1            (0x02)
#define PJ_2            (0x04)
#define PJ_3            (0x08)
#define LFXIN           (0x10)
#define LFXOUT          (0x20)
#define HFXIN           (0x40)
#define HFXOUT          (0x80)

// #defines
#define BEGINNING (0)
#define SMALL_RING_SIZE (16)
#define LARGE_RING_SIZE (16)
#define BEGINNING (0)