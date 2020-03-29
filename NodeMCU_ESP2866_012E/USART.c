/************************************************************/
/* AUTHOR      : Omar Sameh Mahmoud                         */
/* DESCRIPTION : USART Protocol    [ USART.C ]              */
/* DATE        : 6 August 2017                              */
/************************************************************/

#include "USART.h"

/*************************************************************/
/* Description : this function Initialize USART Pheripherial */
/*************************************************************/

extern volatile u16 Sensor_Readings_Tx[3]={0}; // for many readings

void USART_Init(void)
{
	/*
	  *******USART Control and Status Register B**********
	 * -----------------------------------*
	 	 * Bit 7 – RXCIE: RX Complete Interrupt Enable
		 * 0 --> Disable
		 * 1 --> Enable
	 	 * -------------------------------*
	 	 * Bit 6 – TXCIE: TX Complete Interrupt Enable
		 * 0 --> Disable
		 * 1 --> Enable
	 	 * -------------------------------*
	 	 * Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
		 * 0 --> Disable
		 * 1 --> Enable
		 * -------------------------------*
		 * Bit 4 – RXEN: Receiver Enable
		 * 0 --> Disable
		 * 1 --> Enable
		 * -------------------------------*
		 * Bit 3 – TXEN: Transmitter Enable
		 * 0 --> Disable
		 * 1 --> Enable
		 *--------------------------------*
		 * Bit 2 – UCSZ2: Character Size
		 * 0 --> Disable : Not Take in Calculations of frame size
		 * 1 --> Enable  : Take in Calculations of frame size
	 	 * -------------------------------*
	 	 * Bit 1 – RXB8: Receive Data Bit 8
	 	 *  Must be read before reading the low bits from UDR.
		 * 0 --> Disable : Not Take in Calculations of frame format Ninth bit
		 * 1 --> Enable  : Take in Calculations of format Ninth bit
	 	 * -------------------------------*
	 	 * Bit 0 – TXB8: Transmit Data Bit 8
	 	 *  Must be written before writing the low bits to UDR.
		 * 0 --> Disable : Not Take in Calculations of frame format Ninth bit
		 * 1 --> Enable  : Take in Calculations of frame format Ninth bit
	 	 * -------------------------------*
	*/

	UCSRB_Reg = 0b00011000 ;

	/*
	  *******USART Control and Status Register C**********
	 * -----------------------------------*
	 * Bit 7 – URSEL: Register Select
	 * 0 --> Select UBRRH For Long Number in Baud Rate
	 * 1 --> Select UCSRC (Normal)
	 * -----------------------------------*
	 * Bit 6 – UMSEL Mode
	 * 0 --> Asynchronous Operation
	 * 1 --> Synchronous Operation
	 *------------------------------------*
	 * Bit 5:4 – UPM1:0: Parity Mode
	 * ---------------------------
	 * |UPM1 | UPM0 | Parity Mode|
	 * ---------------------------
	 * 0 | 0 --> Disabled
	 * 0 | 1 --> Reserved
	 * 1 | 0 --> Enabled, Even Parity
	 * 1 | 1 --> Enabled, Odd Parity
	 * -----------------------------------*
	 * Bit 3 – USBS: Stop Bit Select
	 * 0 --> 1-bit
	 * 1 --> 2-bit
	 * ----------------------------------*
	 * Bit 2:1 – UCSZ1:0: Character Size
	 * ------------------------------------------
	 * | UCSZ2 | UCSZ1 | UCSZ0 | Character Size |
	 * ------------------------------------------
	 * 0 | 0 | 0 --> 5-bit
	 * 0 | 0 | 1 --> 6-bit
	 * 0 | 1 | 0 --> 7-bit
	 * 0 | 1 | 1 --> 8-bit
	 * 1 | 0 | 0 --> Reserved
	 * 1 | 0 | 1 --> Reserved
	 * 1 | 1 | 0 --> Reserved
	 * 1 | 1 | 1 --> 9-bit
	 * ----------------------------------*
	 */
	UCSRC_Reg = 0b10000110 ;

	/*
		  ******* USART Baud Rate Registers UBRRL and UBRRH **********
		 * -----------------------------------*
		 *  Bit 15 – URSEL: Register Select
		 * 1 --> Select UBRRH For Long Number in Baud Rate
		 * 0 --> Select UCSRC (Normal)
		 * -----------------------------------*
		 *  Bit 14:12 – Reserved Bits
		 * -----------------------------------*
		 * Bit 11:0 – UBRR11:0: USART Baud Rate Register
		 * From Bit 11 to Bit 8 --> UBRRH
		 * From Bit 7  to Bit 0 --> UBRRL
		 * We Adjust Baud Rate From DataSheet Page 163 : 166 according to our frequency of MicroController and Specification
	*/
	UCSRA_Reg=0b11000000;  // The RXC Flag can be used to generate a Receive Complete interrupt ( page: 158 ) -- Enable Normal Tx
	UBRRL_Reg = 52 ;
	UBRRH_Reg = 0 ;

}

/***********************************************************************/
/* Description : this function to define USART_SendData functionality  */
/***********************************************************************/

void USART_SendData(u8 Data)
{
	/*
	  *******USART Control and Status Register A**********
	   * -----------------------------------*
	   *  Bit 5 – UDRE: USART Data Register Empty
	   * 1 --> Empty
	   * 0 --> Busy
	 */

	//in this function We check our data register if its become 1 in USCRA we can Transmit Data//

	while(GET_BIT(UCSRA_Reg,PIN5)==0); // UDRE: USART Data Register Empty , The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data.
	// when it equal zero that mean that means the register is full of data and can't send now
	UDR_Reg = Data ;
}

/*************************************************************************/
/* Description : this function to define USART_ReceiveData functionality */
/*************************************************************************/

u8  USART_ReceiveData(void)
{
	u8 RXData; // variable to receive data on it

	/*
		  *******USART Control and Status Register A**********
		   * -----------------------------------*
		   *  Bit 7 – RXC: USART Receive Complete
		   * 1 --> Data Complete
		   * 0 --> No Data
		 */

		//in this function We check our data register if its become 1 in USCRA we Receive Complete Data//
	while(GET_BIT(UCSRA_Reg,PIN7)==0);

	RXData = UDR_Reg ;

	return RXData;

}

// Addition Function if you want to Transmit many readings

void USART_SendReadings(u8*ptr)
{
	u8 i;
	for(i=0;i<2;i++)
	{
		USART_SendData(Sensor_Readings_Tx[i]);
	}
	//_delay_ms(2000);
}


