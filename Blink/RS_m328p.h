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
    
    constexpr int ADDR_PINB     = 0x23;
    constexpr int ADDR_DDRB     = 0x24;
    constexpr int ADDR_PORTB    = 0x25;
    constexpr int ADDR_PINC     = 0x26;
    constexpr int ADDR_DDRC     = 0x27;
    constexpr int ADDR_PORTC    = 0x28;
    constexpr int ADDR_PIND     = 0x29;
    constexpr int ADDR_DDRD     = 0x2A;
    constexpr int ADDR_PORTD    = 0x2B;
    
}


#endif /* RS_m328p_h */
