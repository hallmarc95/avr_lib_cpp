#include <stdio.h>
#include <util/delay.h>


#include "AVRIO.h"


void initIO() {
    AVRIO::DDRB = (1 << AVRIO::PB5);
    AVRIO::PORTB = 0x00;
}

int main() {
	initIO();

	while (1) {
        AVRIO::DDRB ^= (1 << AVRIO::PB5);
        _delay_ms(100);
	}
	return 0; // never reached
}
