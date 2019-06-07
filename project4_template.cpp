// Course CECS #269:
// Lab #4:
// Programmers:
// A detailed description of the system	here

#include <reg51.h>

#define LED P1
#define SW P0
#define UP 1
#define DOWN 0
#define INIT_COUNTING_VAL P2
#define HALF_SECOND_DELAY 100

// define the 4 mode1 control pins
sbit mode1_switch=P0^0; 
sbit mode2_switch=P0^1; 
sbit mode3_switch=P0^2; 
sbit mode4_switch=P0^3; 

// define 4 speed control pins 
sbit half_sec_switch=P0^4; // define half second speed control pin
sbit one_sec_switch=P0^5; // define one second speed control pin
sbit onenhalf_sec_switch=P0^6; // define one and half second speed control pin
// define other speed control pins here

bit chg_mode_flag;

// =================================================================================================
// This function performs the following initialization for the system
// 1. set P0, P2 as input port
// 2. initialize interrupt: enable of interrupt and external interrupt 0, setup external interrpt 0
// 3. clear the mode change user flag CHG_MODE_FLAG
// 4. enable timer 0 overflow interrupt and setup timer 0
// =================================================================================================
void init_system(void);

// =================================================================================================
// This function implement the bouncing mode on the on-board LEDs:
// add more explanation on what a bouncing mode is here.
// =================================================================================================
void bouncing(void);

// =================================================================================================
// This function counts up/down from a initial value given on external dip-switch
// More details on your implementation here
// =================================================================================================
void count(void);

// =================================================================================================
// This function display the cyclic patterns. Explain cyclic patterns here.
// More details on your implementation here
// =================================================================================================
void cyclic(void);

// =================================================================================================
// This function will generate a delay according to the speed setting on the upper 4 bit of port 0
// More details on your implementation here
// =================================================================================================
void delay(void);

void double_bouncing(void);

void main(void)
{
  init_system();

  while (1) {
		chg_mode_flag = 0;
    // explain mode setting rules here
    if (mode1_switch==1) 
	    bouncing();
	  else if (mode2_switch==1)
	    count();
	  else if (mode3_switch==1)
	    double_bouncing();
	  else if (mode4_switch==1)
	    cyclic();
	  else { // last case: no mode pin is on, flash the LEDs here
			LED = 0;
			delay();
			LED = 0xFF;
			delay();
	  }
	}
}

// =================================================================================================
// This function performs the following initialization for the system
// 1. set P0, P2 as input port
// 2. initialize interrupt: enable of interrupt and external interrupt 0, setup external interrpt 0
// 3. clear the mode change user flag chg_mode_flag
// 4. enable timer 0 overflow interrupt and setup timer 0
// =================================================================================================
void init_system(void)
{
  SW=0xFF; // set P0 to be input
  INIT_COUNTING_VAL=0xFF; // set P2 to be input
  IT0=1;  // set INT0 to be edge trigerred
  EX0=1; // enable INT0
  EA=1; // enable interrupt
  chg_mode_flag = 0; // initialize interrupt flag

  // enable timer 0 interrupt and setup timer 0 here
}

// =================================================================================================
// This function implement the bouncing mode on the on-board LEDs:
// add more explanation on what a bouncing mode is here.
// =================================================================================================
void bouncing()
{
  LED=1;
  while (1) {
    if (chg_mode_flag) {
	  chg_mode_flag=0;
	  return;
	}
	delay();

	// update the LED with the next pattern here

  }
}

// =================================================================================================
// This function counts up/down from a initial value given on external dip-switch
// More details on your implementation here
// =================================================================================================
void count(void)
{
  // get the initial counting value and display it one the LEDs here
    // check the direction setting here
	  if () { // if count up       
			while (1) {
        if (chg_mode_flag) {
	        chg_mode_flag=0;
	        return;
	      }
        //count up
        delay();
			}
	  }
	  else { // if count down
	  }  
}

// =================================================================================================
// This function display the cyclic patterns. Explain cyclic patterns here.
// More details on your implementation here
// =================================================================================================
void cyclic()
{
  LED=1;
  while (1) {
    if (chg_mode_flag) {
	  chg_mode_flag=0;
	  return;
	}
	delay();

	// update the LED with the next pattern here
  }
}

// =================================================================================================
// This function will generate a delay according to the speed setting on the upper 4 bit of port 0
// More details on your implementation here
// =================================================================================================
void delay(void)
{ // the default delay is half second
  unsigned char count=HALF_SECOND_DELAY;
  // check speed setting here
  if (one_sec_switch==1) //assume dip-switch has positive logic
  {
  	count = 2*count;
  }
  else if (onenhalf_sec_switch==1)
  {
  }

  // generate delay here according to the count setting
}

// =================================================================================================
// This is the interrupt service routine for external interrup 0
// Explain the functionality of this ISR 
// =================================================================================================
void change_mode(void) interrupt 0
{
  chg_mode_flag=1;
}
