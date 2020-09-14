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


/// Expands to define a value-type for a register. See ValuePORTB for expansion.
#define DEF_REGBITS( N ) struct N final : LibAVR::RegBits_Base { explicit N(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {} N operator ~() { return static_cast<N>(this->RegBits_Base::operator~()); }};

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
    
    struct ValuePORTB final : LibAVR::RegBits_Base {
        explicit ValuePORTB(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
        ValuePORTB operator ~() { return static_cast<ValuePORTB>(this->RegBits_Base::operator~()); }
    };
    DEF_REGBITS(ValuePORTC)
    DEF_REGBITS(ValuePORTD)
    DEF_REGBITS(ValueTIFR0)
    DEF_REGBITS(ValueTIFR1)
    DEF_REGBITS(ValueTIFR2)
    DEF_REGBITS(ValuePCIFR)
    DEF_REGBITS(ValueEIFR)
    DEF_REGBITS(ValueEIMSK)
    DEF_REGBITS(ValueGPIO)
    DEF_REGBITS(ValueEECR)
    DEF_REGBITS(ValueEEDR)
    DEF_REGBITS(ValueEEAR)
    DEF_REGBITS(ValueGTCCR)
    DEF_REGBITS(ValueTCCR0A)
    DEF_REGBITS(ValueTCCR0B)
    DEF_REGBITS(ValueTCNT0)
    DEF_REGBITS(ValueOCR0A)
    DEF_REGBITS(ValueOCR0B)
    DEF_REGBITS(ValueSPCR)
    DEF_REGBITS(ValueSPSR)
    DEF_REGBITS(ValueSPDR)
    DEF_REGBITS(ValueACSR)
    DEF_REGBITS(ValueSMCR)
    DEF_REGBITS(ValueMCUSR)
    DEF_REGBITS(ValueMCUCR)
    DEF_REGBITS(ValueSPMCSR)
    DEF_REGBITS(ValueSPL)
    DEF_REGBITS(ValueSPH)
    DEF_REGBITS(ValueSREG)
    
    
    // Define hardware IO registers
    
    namespace {
        using namespace IODef;
        
        constexpr LibAVR::AVRReg<ValuePORTB, ADDR_PINB> PINB;
        constexpr LibAVR::AVRReg<ValuePORTB, ADDR_DDRB> DDRB;
        constexpr LibAVR::AVRReg<ValuePORTB, ADDR_PORTB> PORTB;
        constexpr LibAVR::AVRReg<ValuePORTC, ADDR_PINC> PINC;
        constexpr LibAVR::AVRReg<ValuePORTC, ADDR_DDRC> DDRC;
        constexpr LibAVR::AVRReg<ValuePORTC, ADDR_PORTC> PORTC;
        constexpr LibAVR::AVRReg<ValuePORTD, ADDR_PIND> PIND;
        constexpr LibAVR::AVRReg<ValuePORTD, ADDR_DDRD> DDRD;
        constexpr LibAVR::AVRReg<ValuePORTD, ADDR_PORTD> PORTD;
        constexpr LibAVR::AVRReg<ValueTIFR0, ADDR_TIFR0> TIFR0;
        constexpr LibAVR::AVRReg<ValueTIFR1, ADDR_TIFR1> TIFR1;
        constexpr LibAVR::AVRReg<ValueTIFR2, ADDR_TIFR2> TIFR2;
        constexpr LibAVR::AVRReg<ValuePCIFR, ADDR_PCIFR> PCIFR;
        constexpr LibAVR::AVRReg<ValueEIFR, ADDR_EIFR> EIFR;
        constexpr LibAVR::AVRReg<ValueEIMSK, ADDR_EIMSK> EIMSK;
        constexpr LibAVR::AVRReg<ValueGPIO, ADDR_GPIOR0> GPIOR0;
        constexpr LibAVR::AVRReg<ValueEECR, ADDR_EECR> EECR;
        constexpr LibAVR::AVRReg<ValueEEDR, ADDR_EEDR> EEDR;
        constexpr LibAVR::AVRReg<ValueEEAR, ADDR_EEARL> EEARL;
//        constexpr LibAVR::AVRReg<ValueEEAR, ADDR_EEARH> EEARH;    // atmega88P/168P only
        constexpr LibAVR::AVRReg<ValueGTCCR, ADDR_GTCCR> GTCCR;
        constexpr LibAVR::AVRReg<ValueTCCR0A, ADDR_TCCR0A> TCCR0A;
        constexpr LibAVR::AVRReg<ValueTCCR0B, ADDR_TCCR0B> TCCR0B;
        constexpr LibAVR::AVRReg<ValueTCNT0, ADDR_TCNT0> TCNT0;
        constexpr LibAVR::AVRReg<ValueOCR0A, ADDR_OCR0A> OCR0A;
        constexpr LibAVR::AVRReg<ValueOCR0B, ADDR_OCR0B> OCR0B;
        constexpr LibAVR::AVRReg<ValueGPIO, ADDR_GPIOR1> GPIOR1;
        constexpr LibAVR::AVRReg<ValueGPIO, ADDR_GPIOR2> GPIOR2;
        constexpr LibAVR::AVRReg<ValueSPCR, ADDR_SPCR> SPCR;
        constexpr LibAVR::AVRReg<ValueSPSR, ADDR_SPSR> SPSR;
        constexpr LibAVR::AVRReg<ValueSPDR, ADDR_SPDR> SPDR;
        constexpr LibAVR::AVRReg<ValueACSR, ADDR_ACSR> ACSR;
        constexpr LibAVR::AVRReg<ValueSMCR, ADDR_SMCR> SMCR;
        constexpr LibAVR::AVRReg<ValueMCUSR, ADDR_MCUSR> MCUSR;
        constexpr LibAVR::AVRReg<ValueMCUCR, ADDR_MCUCR> MCUCR;
        constexpr LibAVR::AVRReg<ValueSPMCSR, ADDR_SPMCSR> SPMCSR;
        constexpr LibAVR::AVRReg<ValueSPL, ADDR_SPL> SPL;
        constexpr LibAVR::AVRReg<ValueSPH, ADDR_SPH> SPH;
        constexpr LibAVR::AVRReg<ValueSREG, ADDR_SREG> SREG;
    }
}


// Register bit shortcuts

#define PB0 AVRIO::ValuePORTB(0)
#define PB1 AVRIO::ValuePORTB(1)
#define PB2 AVRIO::ValuePORTB(2)
#define PB3 AVRIO::ValuePORTB(3)
#define PB4 AVRIO::ValuePORTB(4)
#define PB5 AVRIO::ValuePORTB(5)
#define PB6 AVRIO::ValuePORTB(6)
#define PB7 AVRIO::ValuePORTB(7)

#define PC0 AVRIO::ValuePORTC(0)
#define PC1 AVRIO::ValuePORTC(1)
#define PC2 AVRIO::ValuePORTC(2)
#define PC3 AVRIO::ValuePORTC(3)
#define PC4 AVRIO::ValuePORTC(4)
#define PC5 AVRIO::ValuePORTC(5)
#define PC6 AVRIO::ValuePORTC(6)
#define PC7 AVRIO::ValuePORTC(7)

#define PD0 AVRIO::ValuePORTD(0)
#define PD1 AVRIO::ValuePORTD(1)
#define PD2 AVRIO::ValuePORTD(2)
#define PD3 AVRIO::ValuePORTD(3)
#define PD4 AVRIO::ValuePORTD(4)
#define PD5 AVRIO::ValuePORTD(5)
#define PD6 AVRIO::ValuePORTD(6)
#define PD7 AVRIO::ValuePORTD(7)

#define TOV0 AVRIO::ValueTIFR0(0)
#define OCF0A AVRIO::ValueTIFR0(1)
#define OCF0B AVRIO::ValueTIFR0(2)

#define TOV1 AVRIO::ValueTIFR1(0)
#define OCF1A AVRIO::ValueTIFR1(1)
#define OCF1B AVRIO::ValueTIFR1(2)
#define ICF1 AVRIO::ValueTIFR1(5)

#define TOV2 AVRIO::ValueTIFR2(0)
#define OCF2A AVRIO::ValueTIFR2(1)
#define OCF2B AVRIO::ValueTIFR2(2)

#define PCIF0 AVRIO::ValuePCIFR(0)
#define PCIF1 AVRIO::ValuePCIFR(1)
#define PCIF2 AVRIO::ValuePCIFR(2)

#define INTF0 AVRIO::ValueEIFR(0)
#define INTF1 AVRIO::ValueEIFR(1)

#define INT0 AVRIO::ValueEIMSK(0)
#define INT1 AVRIO::ValueEIMSK(1)

#define EERE AVRIO::ValueEECR(0)
#define EEPE AVRIO::ValueEECR(1)
#define EEMPE AVRIO::ValueEECR(2)
#define EERIE AVRIO::ValueEECR(3)
#define EEPM0 AVRIO::ValueEECR(4)
#define EEPM1 AVRIO::ValueEECR(5)

#define PSRSYNC AVRIO::ValueGTCCR(0)
#define PSRASY AVRIO::ValueGTCCR(1)
#define TSM AVRIO::ValueGTCCR(7)

#define WGM00 AVRIO::ValueTCCR0A(0)
#define WGM01 AVRIO::ValueTCCR0A(1)
#define COM0B0 AVRIO::ValueTCCR0A(4)
#define COM0B1 AVRIO::ValueTCCR0A(5)
#define COM0A0 AVRIO::ValueTCCR0A(6)
#define COM0A1 AVRIO::ValueTCCR0A(7)

#define CS00 AVRIO::ValueTCCR0B(0)
#define CS01 AVRIO::ValueTCCR0B(1)
#define CS02 AVRIO::ValueTCCR0B(2)
#define WGM02 AVRIO::ValueTCCR0B(3)
#define FOC0B AVRIO::ValueTCCR0B(6)
#define FOC0A AVRIO::ValueTCCR0B(7)

#define SPIE AVRIO::ValueSPCR(7)
#define SPE  AVRIO::ValueSPCR(6)
#define DORD AVRIO::ValueSPCR(5)
#define MSTR AVRIO::ValueSPCR(4)
#define CPOL AVRIO::ValueSPCR(3)
#define CPHA AVRIO::ValueSPCR(2)
#define SPR1 AVRIO::ValueSPCR(1)
#define SPR0 AVRIO::ValueSPCR(0)

#define SPIF AVRIO::ValueSPSR(7)
#define WCOL AVRIO::ValueSPSR(6)
#define SPI2X AVRIO::ValueSPSR(0)

#define ACIS0 AVRIO::ValueACSR(0)
#define ACIS1 AVRIO::ValueACSR(1)
#define ACIC AVRIO::ValueACSR(2)
#define ACIE AVRIO::ValueACSR(3)
#define ACI AVRIO::ValueACSR(4)
#define ACO AVRIO::ValueACSR(5)
#define ACBG AVRIO::ValueACSR(6)
#define ACD AVRIO::ValueACSR(7)

#define SE AVRIO::ValueSMCR(0)
#define SM0 AVRIO::ValueSMCR(1)
#define SM1 AVRIO::ValueSMCR(2)
#define SM2 AVRIO::ValueSMCR(3)

#define PORF AVRIO::ValueMCUSR(0)
#define EXTRF AVRIO::ValueMCUSR(1)
#define BORF AVRIO::ValueMCUSR(2)
#define WDRF AVRIO::ValueMCUSR(3)

#define IVCE AVRIO::ValueMCUCR(0)
#define IVSEL AVRIO::ValueMCUCR(1)
#define PUD AVRIO::ValueMCUCR(4)
#define BODSE AVRIO::ValueMCUCR(5)
#define BODS AVRIO::ValueMCUCR(6)

#define SELFPRGEN AVRIO::ValueSPMCSR(0)
#define PGERS AVRIO::ValueSPMCSR(1)
#define PGWRT AVRIO::ValueSPMCSR(2)
#define BLBSET AVRIO::ValueSPMCSR(3)
//#define RWWSRE AVRIO::ValueSPMCSR(4)  // atmega88P/168P only
//#define RWWSB AVRIO::ValueSPMCSR(6)   // atmega88P/168P only
#define SPMIE AVRIO::ValueSPMCSR(7)

#define SP0 AVRIO::ValueSPL(0)
#define SP1 AVRIO::ValueSPL(1)
#define SP2 AVRIO::ValueSPL(2)
#define SP3 AVRIO::ValueSPL(3)
#define SP4 AVRIO::ValueSPL(4)
#define SP5 AVRIO::ValueSPL(5)
#define SP6 AVRIO::ValueSPL(6)
#define SP7 AVRIO::ValueSPL(7)

#define SP8 AVRIO::ValueSPH(0)
#define SP9 AVRIO::ValueSPH(1)
//#define SP10 AVRIO::ValueSPH(2)   // atmega88P/168P only

#define C_Bit AVRIO::ValueSREG(0)
#define Z_Bit AVRIO::ValueSREG(1)
#define N_Bit AVRIO::ValueSREG(2)
#define V_Bit AVRIO::ValueSREG(3)
#define S_Bit AVRIO::ValueSREG(4)
#define H_Bit AVRIO::ValueSREG(5)
#define T_Bit AVRIO::ValueSREG(6)
#define I_Bit AVRIO::ValueSREG(7)


#endif /* AVRIO_h */
