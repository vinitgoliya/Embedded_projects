#include <global.h>
#include <lpc2148.h>
#include <pll0.h>


/*
	PLL -Phase locked Loop
	
	In PLL0 we have four registers
	
	1. PLL0CON  - phase locked loop control register
	2. PLL0CFG  - phase locked loop configure register
	3. PLL0STAT - phase locked loop status register
	4. PLL0FEED - phase locked loop FEED register

*/

void Init_PLL0(void)
{
	/* Set Multiplier and Divider of PLL0 to give 60MHz */
	PLL0CFG  = 0x24;
	
		/*	0   11    00100
	
 	0	0	1	0	0	1	0	0
			-----		-----------------
			  |				|	
			  |				|
			  V				|
			labled as		|
			PSEL Which 		|
			is a divisor	|
			value			|
						    V
					labed as MSEL which is a multiplier value
					CCLK = M * FOSC,M-1;
					where
					FOSC is the frequency from the crystal oscillator/external oscillator
					CCLK the PLL output frequency (also the processor clock frequency)
					
					
					
	*/
		
	
	

	/* Enable PLL0 */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	/*
	
	Correct FEED sequence should be given to the PLL0FEED in order
	Affect the changes that are done in the PLL0CON and PLL0CFG register
	The feed sequence is 
	1. Write the value 0xAA to PLLFEED.
    2. Write the value 0x55 to PLLFEED.
	
	*/
	
	PLL0CON  = 0x01;
	
	/* 

		0	0	0	0	0	0	0	1
									|
									|
									V
								PLLE - Phase locked loop enable bit
								When one, and after a valid PLL feed, 
								this bit will activate the PLL and allow 
								it to lock to the requested frequency
	
	*/
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	/* Update PLL Registers with Feed Sequence */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	// Check the Lock Bit
	while(Is_Bit_Clr(PLL0STAT,BIT10));
	/* Bit 10 in the PLL0STAT register is PLOCK BIT
		Reflects the PLL Lock status. When zero, the PLL is not locked.
		When one, the PLL is locked onto the requested frequency.
	*/

	PLL0CON  = 0x03;
	/*
	
	0	0	0	0	0	0	1	1
							|	|
							|	 ------------------------------------
							V										|	
						  PLLC = Phased locked loop Connect			V
																	PLLE = phase locked loop enable
																	
When PLLC and PLLE are both set to one, and after a
valid PLL feed, connects the PLL as the clock source for the
microcontroller. Otherwise, the oscillator clock is used directly by the
microcontroller.
						  
	*/
	
	
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	
	
	
	
	MAMCR    = 0x02; 
	/*
	MAMCR = Memory Accelerator Module Control Register
	
	0	0	0	0	0	0	1	0
							|	|
							|	|
							|	|	
						   \|	|/
							\	/
							 \ /
							  V	
	
							00 MAM functions disabled 0
							01 MAM functions partially enabled
							10 MAM functions fully enabled
							11 Reserved. Not to be used in the application.
	
	*/
	
	MAMTIM   = 0x04; 
	
	/*
	MAMTIM = Memory Accelerator Module Timing control.
			Determines the number of clocks used for Flash
			memory fetches
			
			000 0 - Reserved
			001 1 - MAM fetch cycles are 1 processor clock (CCLK) in duration
			010 2 - MAM fetch cycles are 2 CCLKs in duration
			011 3 - MAM fetch cycles are 3 CCLKs in duration
			100 4 - MAM fetch cycles are 4 CCLKs in duration
			101 5 - MAM fetch cycles are 5 CCLKs in duration
			110 6 - MAM fetch cycles are 6 CCLKs in duration
			111 7 - MAM fetch cycles are 7 CCLKs in duration
	
	When changing MAM timing, the MAM must first be turned off by writing a zero to
MAMCR. A new value may then be written to MAMTIM. Finally, the MAM may be turned
on again by writing a value (1 or 2) corresponding to the desired operating mode to
MAMCR.
For system clock slower than 20 MHz, MAMTIM can be 001. For system clock between
20 MHz and 40 MHz, Flash access time is suggested to be 2 CCLKs, while in systems
with system clock faster than 40 MHz, 3 CCLKs are proposed.
				
	*/
	
	VPBDIV   = 0x01;
	
	/* its APBDIV not VPBDIV
	APBDIV = Advanced periferal Bus Divisor
	
	00 	APB bus clock is one fourth of the processor clock.
	01 	APB bus clock is the same as the processor clock.
	10 	APB bus clock is one half of the processor clock.
	11 	Reserved. If this value is written to the APBDIV register, it
		has no effect (the previous setting is retained). */
	
	
}

