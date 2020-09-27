//
//  RS_m328p.h
//
//  Created by Marcus Hall on 9/12/20.
//

#ifndef RS_m328p_h
#define RS_m328p_h

namespace IODef {
    
    // Register address definitions for atmega328p
    
    constexpr int ADDR_PINB = 0x23;
    constexpr int ADDR_DDRB = 0x24;
    constexpr int ADDR_PORTB = 0x25;
    constexpr int ADDR_PINC = 0x26;
    constexpr int ADDR_DDRC = 0x27;
    constexpr int ADDR_PORTC = 0x28;
    constexpr int ADDR_PIND = 0x29;
    constexpr int ADDR_DDRD = 0x2A;
    constexpr int ADDR_PORTD = 0x2B;
    constexpr int ADDR_TIFR0 = 0x35;
    constexpr int ADDR_TIFR1 = 0x36;
    constexpr int ADDR_TIFR2 = 0x37;
    constexpr int ADDR_PCIFR = 0x3B;
    constexpr int ADDR_EIFR = 0x3C;
    constexpr int ADDR_EIMSK = 0x3D;
    constexpr int ADDR_GPIOR0 = 0x3E;
    constexpr int ADDR_EECR = 0x3F;
    constexpr int ADDR_EEDR = 0X40;
    constexpr int ADDR_EEARL = 0x41;
//    constexpr int ADDR_EEARH = 0x42;  // atmega88P/168P only
    constexpr int ADDR_GTCCR = 0x43;
    constexpr int ADDR_TCCR0A = 0x44;
    constexpr int ADDR_TCCR0B = 0x45;
    constexpr int ADDR_TCNT0 = 0x46;
    constexpr int ADDR_OCR0A = 0x47;
    constexpr int ADDR_OCR0B = 0x48;
    constexpr int ADDR_GPIOR1 = 0x4A;
    constexpr int ADDR_GPIOR2 = 0x4B;
    constexpr int ADDR_SPCR = 0x4C;
    constexpr int ADDR_SPSR = 0x4D;
    constexpr int ADDR_SPDR = 0x4E;
    constexpr int ADDR_ACSR = 0x50;
    constexpr int ADDR_SMCR = 0x53;
    constexpr int ADDR_MCUSR = 0x54;
    constexpr int ADDR_MCUCR = 0x55;
    constexpr int ADDR_SPMCSR = 0x57;
    constexpr int ADDR_SPL = 0x5D;
    constexpr int ADDR_SPH = 0x5E;
    constexpr int ADDR_SREG = 0x5F;
    constexpr int ADDR_WDTCSR = 0x60;
    constexpr int ADDR_CLKPR = 0x61;
    constexpr int ADDR_PRR = 0x64;
    constexpr int ADDR_OSCCAL = 0x66;
    constexpr int ADDR_PCICR = 0x68;
    constexpr int ADDR_EICRA = 0x69;
    constexpr int ADDR_PCMSK0 = 0x6B;
    constexpr int ADDR_PCMSK1 = 0x6C;
    constexpr int ADDR_PCMSK2 = 0x6D;
    constexpr int ADDR_TIMSK0 = 0x6E;
    constexpr int ADDR_TIMSK1 = 0x6F;
    constexpr int ADDR_TIMSK2 = 0x70;
    constexpr int ADDR_ADCL = 0x78;
    constexpr int ADDR_ADCH = 0x79;
    constexpr int ADDR_ADCSRA = 0x7A;
    constexpr int ADDR_ADCSRB = 0x7B;
    constexpr int ADDR_ADMUX = 0x7C;
    constexpr int ADDR_DIDR0 = 0x7E;
    constexpr int ADDR_DIDR1 = 0x7F;
    constexpr int ADDR_TCCR1A = 0x80;
    constexpr int ADDR_TCCR1B = 0x81;
    constexpr int ADDR_TCCR1C = 0x82;
    constexpr int ADDR_TCNT1L = 0x84;
    constexpr int ADDR_TCNT1H = 0x85;
    constexpr int ADDR_ICR1L = 0x86;
    constexpr int ADDR_ICR1H = 0x87;
    constexpr int ADDR_OCR1AL = 0x88;
    constexpr int ADDR_OCR1AH = 0x89;
    constexpr int ADDR_OCR1BL = 0x8A;
    constexpr int ADDR_OCR1BH = 0x8B;
    constexpr int ADDR_TCCR2A = 0xB0;
    constexpr int ADDR_TCCR2B = 0xB1;
    constexpr int ADDR_TCNT2 = 0xB2;
    constexpr int ADDR_OCR2A = 0xB3;
    constexpr int ADDR_OCR2B = 0xB4;
    constexpr int ADDR_ASSR = 0xB6;
    constexpr int ADDR_TWBR = 0xB8;
    constexpr int ADDR_TWSR = 0xB9;
    constexpr int ADDR_TWAR = 0xBA;
    constexpr int ADDR_TWDR = 0xBB;
    constexpr int ADDR_TWCR = 0xBC;
    constexpr int ADDR_TWAMR = 0xBD;
    constexpr int ADDR_UCSR0A = 0xC0;
    constexpr int ADDR_UCSR0B = 0xC1;
    constexpr int ADDR_UCSR0C = 0xC2;
    constexpr int ADDR_UBRR0L = 0xC4;
    constexpr int ADDR_UBRR0H = 0xC5;
    constexpr int ADDR_UDR0 = 0xC6;
    
}


// Hardware modules possessed by atmega328p
#define __HAVE_SPI__
#define __HAVE_USART0__


#endif /* RS_m328p_h */
