#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#pragma config WDT= OFF
#define BAUDRATE 9600

char UART_RxChar()
{
    while(RCIF==0);    // Wait till the data is received 
    RCIF=0;            // Clear receiver flag
    return(RCREG);     // Return the received data to calling function
}
int main()
{ char ch;
    OSCCON=0x72;
    TRISCbits.RC6=0;
    TRISCbits.RC7=1;
    TXSTAbits.TX9=0;
    TXSTAbits.TXEN=1;
    TXSTAbits.SYNC=0;
    TXSTAbits.BRGH=1;
    PIE1bits.TXIE=0;
    PIE1bits.RCIE=0;
    RCSTAbits.SPEN=1;
    RCSTAbits.RX9=0;
    RCSTAbits.CREN=0;
   
    SPBRG=52;
    
     while(1)
    {
        ch = UART_RxChar();
    }
}

