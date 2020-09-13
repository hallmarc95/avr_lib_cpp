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
    DEF_REGBITS(TIFlag0)
    DEF_REGBITS(TIFlag1)
    DEF_REGBITS(TIFlag2)
    DEF_REGBITS(PCIFlag)
    DEF_REGBITS(EIFlag)
    DEF_REGBITS(EIMask)
    DEF_REGBITS(GPurposeIO)
    DEF_REGBITS(EEControl)
    DEF_REGBITS(EEData)
    DEF_REGBITS(EEAddress)
    DEF_REGBITS(GTCControl)
    DEF_REGBITS(TCControl0A)
    DEF_REGBITS(TCControl0B)
    DEF_REGBITS(TCount0)
    DEF_REGBITS(OCompare0A)
    DEF_REGBITS(OCompare0B)
    DEF_REGBITS(SPIControl)
    DEF_REGBITS(SPIStatus)
    DEF_REGBITS(SPIData)
    
    
    // Define hardware IO registers
    
    namespace {
        using namespace IODef;
        
        constexpr LibAVR::AVRReg<PortB, ADDR_PINB> PINB;
        constexpr LibAVR::AVRReg<PortB, ADDR_DDRB> DDRB;
        constexpr LibAVR::AVRReg<PortB, ADDR_PORTB> PORTB;
        constexpr LibAVR::AVRReg<PortC, ADDR_PINC> PINC;
        constexpr LibAVR::AVRReg<PortC, ADDR_DDRC> DDRC;
        constexpr LibAVR::AVRReg<PortC, ADDR_PORTC> PORTC;
        constexpr LibAVR::AVRReg<PortD, ADDR_PIND> PIND;
        constexpr LibAVR::AVRReg<PortD, ADDR_DDRD> DDRD;
        constexpr LibAVR::AVRReg<PortD, ADDR_PORTD> PORTD;
        constexpr LibAVR::AVRReg<TIFlag0, ADDR_TIFR0> TIFR0;
        constexpr LibAVR::AVRReg<TIFlag1, ADDR_TIFR1> TIFR1;
        constexpr LibAVR::AVRReg<TIFlag2, ADDR_TIFR2> TIFR2;
        constexpr LibAVR::AVRReg<PCIFlag, ADDR_PCIFR> PCIFR;
        constexpr LibAVR::AVRReg<EIFlag, ADDR_EIFR> EIFR;
        constexpr LibAVR::AVRReg<EIMask, ADDR_EIMSK> EIMSK;
        constexpr LibAVR::AVRReg<GPurposeIO, ADDR_GPIOR0> GPIOR0;
        constexpr LibAVR::AVRReg<EEControl, ADDR_EECR> EECR;
        constexpr LibAVR::AVRReg<EEData, ADDR_EEDR> EEDR;
        constexpr LibAVR::AVRReg<EEAddress, ADDR_EEARL> EEARL;
        constexpr LibAVR::AVRReg<EEAddress, ADDR_EEARH> EEARH;
        constexpr LibAVR::AVRReg<GTCControl, ADDR_GTCCR> GTCCR;
        constexpr LibAVR::AVRReg<TCControl0A, ADDR_TCCR0A> TCCR0A;
        constexpr LibAVR::AVRReg<TCControl0B, ADDR_TCCR0B> TCCR0B;
        constexpr LibAVR::AVRReg<TCount0, ADDR_TCNT0> TCNT0;
        constexpr LibAVR::AVRReg<OCompare0A, ADDR_OCR0A> OCR0A;
        constexpr LibAVR::AVRReg<OCompare0B, ADDR_OCR0B> OCR0B;
        constexpr LibAVR::AVRReg<GPurposeIO, ADDR_GPIOR1> GPIOR1;
        constexpr LibAVR::AVRReg<GPurposeIO, ADDR_GPIOR2> GPIOR2;
        constexpr LibAVR::AVRReg<SPIControl, ADDR_SPCR> SPCR;
        constexpr LibAVR::AVRReg<SPIStatus, ADDR_SPSR> SPSR;
        constexpr LibAVR::AVRReg<SPIData, ADDR_SPDR> SPDR;
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

#define TOV0 AVRIO::TIFlag0(0)
#define OCF0A AVRIO::TIFlag0(1)
#define OCF0B AVRIO::TIFlag0(2)

#define TOV1 AVRIO::TIFlag1(0)
#define OCF1A AVRIO::TIFlag1(1)
#define OCF1B AVRIO::TIFlag1(2)
#define ICF1 AVRIO::TIFlag1(5)

#define TOV2 AVRIO::TIFlag2(0)
#define OCF2A AVRIO::TIFlag2(1)
#define OCF2B AVRIO::TIFlag2(2)

#define PCIF0 AVRIO::PCIFlag(0)
#define PCIF1 AVRIO::PCIFlag(1)
#define PCIF2 AVRIO::PCIFlag(2)

#define INTF0 AVRIO::EIFlag(0)
#define INTF1 AVRIO::EIFlag(1)

#define INT0 AVRIO::EIMask(0)
#define INT1 AVRIO::EIMask(1)

#define EERE AVRIO::EEControl(0)
#define EEPE AVRIO::EEControl(1)
#define EEMPE AVRIO::EEControl(2)
#define EERIE AVRIO::EEControl(3)
#define EEPM0 AVRIO::EEControl(4)
#define EEPM1 AVRIO::EEControl(5)

#define PSRSYNC AVRIO::GTCControl(0)
#define PSRASY AVRIO::GTCControl(1)
#define TSM AVRIO::GTCControl(7)

#define WGM00 AVRIO::TCControl0A(0)
#define WGM01 AVRIO::TCControl0A(1)
#define COM0B0 AVRIO::TCControl0A(4)
#define COM0B1 AVRIO::TCControl0A(5)
#define COM0A0 AVRIO::TCControl0A(6)
#define COM0A1 AVRIO::TCControl0A(7)

#define CS00 AVRIO::TCControl0B(0)
#define CS01 AVRIO::TCControl0B(1)
#define CS02 AVRIO::TCControl0B(2)
#define WGM02 AVRIO::TCControl0B(3)
#define FOC0B AVRIO::TCControl0B(6)
#define FOC0A AVRIO::TCControl0B(7)

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
