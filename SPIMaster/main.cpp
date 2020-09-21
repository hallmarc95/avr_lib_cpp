//#define USE_SPI_DELEGATES

#include <stdio.h>
#include "AVRIO.h"
#include "LibSPI.hpp"
#include <util/delay.h>

LibSPI::SPI<LibSPI::Modules::SPISingle> MySPI(LibSPI::SPIRole::Master);


void initIO(void) {
    AVRIO::DDRB.SetBits(PB0, PB1);
    
//    MySPI.BindAssertSS([]() { AVRIO::PORTB.SetBit(PB0); });
//    MySPI.BindReleaseSS([]() { AVRIO::PORTB.SetBit(PB0); });
    MySPI.SetClockRate(LibSPI::SCKPrescaler::OSCDiv_64);
}

int main(void) {
	initIO();

	while (1) {
        decltype(MySPI)::DataType const DataOut(0xAF);
        MySPI.DoTransactBlocking(DataOut);
        
        _delay_ms(100);
	}
	return 0; // never reached
}
