//
//  AVRIO.h
//
//  Created by Marcus Hall on 9/11/20.
//

#ifndef AVRIO_h
#define AVRIO_h

#include <stdio.h>
#include "LibAVR.hpp"

#include "RS_m328p.h"


/// Expands to define a value-type for a register. See PortB for expansion.
#define DEF_REGBITS( N ) struct N : LibAVR::RegBits_Base {explicit N(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}};

namespace AVRIO {
    using BitOffset = uint8_t;
    
    
    // Template to perform mathmatical operations on register value-types
    
    template<class T>
    T operator<<(int A, T B) { return T(A << int(B)); }
    
    
    // Define register value-types
    
    struct PortB : LibAVR::RegBits_Base {
        explicit PortB(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
    };
    DEF_REGBITS(PortC)
    DEF_REGBITS(PortD)
    
    
    // Define hardware IO registers
    
    namespace {
        using namespace IODef;
        
        constexpr LibAVR::AVRReg<PortB,     ADDR_PINB>      PINB;
        constexpr LibAVR::AVRReg<PortB,     ADDR_DDRB>      DDRB;
        constexpr LibAVR::AVRReg<PortB,     ADDR_PORTB>     PORTB;
        constexpr LibAVR::AVRReg<PortC,     ADDR_PINC>      PINC;
        constexpr LibAVR::AVRReg<PortC,     ADDR_DDRC>      DDRC;
        constexpr LibAVR::AVRReg<PortC,     ADDR_PORTC>     PORTC;
        constexpr LibAVR::AVRReg<PortD,     ADDR_PIND>      PIND;
        constexpr LibAVR::AVRReg<PortD,     ADDR_DDRD>      DDRD;
        constexpr LibAVR::AVRReg<PortD,     ADDR_PORTD>     PORTD;
    }
}


// Register bit shortcuts

#define PB0 AVRIO::PortB(0)
#define PB1 AVRIO::PortB(1)
#define PB2 AVRIO::PortB(2)
#define PB3 AVRIO::PortB(3)
#define PB4 AVRIO::PortB(4)
#define PB5 AVRIO::PortB(5)
#define PB6 AVRIO::PortB(6)
#define PB7 AVRIO::PortB(7)

#define PC0 AVRIO::PortC(0)
#define PC1 AVRIO::PortC(1)
#define PC2 AVRIO::PortC(2)
#define PC3 AVRIO::PortC(3)
#define PC4 AVRIO::PortC(4)
#define PC5 AVRIO::PortC(5)
#define PC6 AVRIO::PortC(6)
#define PC7 AVRIO::PortC(7)

#define PD0 AVRIO::PortD(0)
#define PD1 AVRIO::PortD(1)
#define PD2 AVRIO::PortD(2)
#define PD3 AVRIO::PortD(3)
#define PD4 AVRIO::PortD(4)
#define PD5 AVRIO::PortD(5)
#define PD6 AVRIO::PortD(6)
#define PD7 AVRIO::PortD(7)


#endif /* AVRIO_h */
