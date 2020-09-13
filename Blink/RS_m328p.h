//
//  RS_m328p.h
//  AVRIO
//
//  Created by Marcus Hall on 9/12/20.
//  Copyright © 2020 Marcus Hall. All rights reserved.
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
    constexpr int ADDR_EEARH = 0x42;
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
    
}


#endif /* RS_m328p_h */
