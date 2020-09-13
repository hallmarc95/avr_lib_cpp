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
#define DEF_REGBITS( N ) struct N : LibAVR::RegBits_Base { explicit N(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {} N operator ~() { return static_cast<N>(this->RegBits_Base::operator~()); }};

namespace AVRIO {
    using BitOffset = uint8_t;
    
    
    // Template to perform mathmatical operations on register value-types
    
    template<class T>
    T operator <<(int A, T B) { return T(A << int(B)); }
    
    template<class T>
    T operator |(int A, T B) { return T(A | int(B)); }
    
    template<class T>
    T operator &(int A, T B) { return T(A & int(B)); }
    
    
    // Define register value-types
    
    struct PortB : LibAVR::RegBits_Base {
        explicit PortB(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
        PortB operator ~() { return static_cast<PortB>(this->RegBits_Base::operator~()); }
    };
    DEF_REGBITS(PortC)
    DEF_REGBITS(PortD)
    DEF_REGBITS(SPIControl)
    DEF_REGBITS(SPIStatus)
    DEF_REGBITS(SPIData)
    
    
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
        
        constexpr LibAVR::AVRReg<SPIControl,ADDR_SPCR>      SPCR;
        constexpr LibAVR::AVRReg<SPIStatus, ADDR_SPSR>      SPSR;
        constexpr LibAVR::AVRReg<SPIData,   ADDR_SPDR>      SPDR;
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



#define SPIE AVRIO::SPIControl(7)
#define SPE  AVRIO::SPIControl(6)
#define DORD AVRIO::SPIControl(5)
#define MSTR AVRIO::SPIControl(4)
#define CPOL AVRIO::SPIControl(3)
#define CPHA AVRIO::SPIControl(2)
#define SPR1 AVRIO::SPIControl(1)
#define SPR0 AVRIO::SPIControl(0)

#define SPIF AVRIO::SPIStatus(7)
#define WCOL AVRIO::SPIStatus(6)
#define SPI2X AVRIO::SPIStatus(0)


#endif /* AVRIO_h */
