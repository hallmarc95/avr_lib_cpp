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
#define DEF_REGBITS( N ) struct N final : LibAVR::RegBits_Base { explicit N(LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {} N operator ~() { return static_cast<N>(this->RegBits_Base::operator~()); }};

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
        explicit ValuePORTB(LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
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
    DEF_REGBITS(ValueWDTCSR)
    DEF_REGBITS(ValueCLKPR)
    DEF_REGBITS(ValuePRR)
    DEF_REGBITS(ValueOSCCAL)
    DEF_REGBITS(ValuePCICR)
    DEF_REGBITS(ValueEICRA)
    DEF_REGBITS(ValuePCMSK0)
    DEF_REGBITS(ValuePCMSK1)
    DEF_REGBITS(ValuePCMSK2)
    DEF_REGBITS(ValueTIMSK0)
    DEF_REGBITS(ValueTIMSK1)
    DEF_REGBITS(ValueTIMSK2)
    DEF_REGBITS(ValueADC)
    DEF_REGBITS(ValueADCSRA)
    DEF_REGBITS(ValueADCSRB)
    DEF_REGBITS(ValueADMUX)
    DEF_REGBITS(ValueDIDR0)
    DEF_REGBITS(ValueDIDR1)
    DEF_REGBITS(ValueTCCR1A)
    DEF_REGBITS(ValueTCCR1B)
    DEF_REGBITS(ValueTCCR1C)
    DEF_REGBITS(ValueTCNT1)
    DEF_REGBITS(ValueICR1)
    DEF_REGBITS(ValueOCR1A)
    DEF_REGBITS(ValueOCR1B)
    DEF_REGBITS(ValueTCCR2A)
    DEF_REGBITS(ValueTCCR2B)
    DEF_REGBITS(ValueTCNT2)
    DEF_REGBITS(ValueOCR2A)
    DEF_REGBITS(ValueOCR2B)
    DEF_REGBITS(ValueASSR)
    DEF_REGBITS(ValueTWBR)
    DEF_REGBITS(ValueTWSR)
    DEF_REGBITS(ValueTWAR)
    DEF_REGBITS(ValueTWDR)
    DEF_REGBITS(ValueTWCR)
    DEF_REGBITS(ValueTWAMR)
    DEF_REGBITS(ValueUCSR0A)
    DEF_REGBITS(ValueUCSR0B)
    DEF_REGBITS(ValueUCSR0C)
    DEF_REGBITS(ValueUBRR0)
    DEF_REGBITS(ValueUDR0)
    
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
        constexpr LibAVR::AVRReg<ValueWDTCSR, ADDR_WDTCSR> WDTCSR;
        constexpr LibAVR::AVRReg<ValueCLKPR, ADDR_CLKPR> CLKPR;
        constexpr LibAVR::AVRReg<ValuePRR, ADDR_PRR> PRR;
        constexpr LibAVR::AVRReg<ValueOSCCAL, ADDR_OSCCAL> OSCCAL;
        constexpr LibAVR::AVRReg<ValuePCICR, ADDR_PCICR> PCICR;
        constexpr LibAVR::AVRReg<ValueEICRA, ADDR_EICRA> EICRA;
        constexpr LibAVR::AVRReg<ValuePCMSK0, ADDR_PCMSK0> PCMSK0;
        constexpr LibAVR::AVRReg<ValuePCMSK1, ADDR_PCMSK1> PCMSK1;
        constexpr LibAVR::AVRReg<ValuePCMSK2, ADDR_PCMSK2> PCMSK2;
        constexpr LibAVR::AVRReg<ValueTIMSK0, ADDR_TIMSK0> TIMSK0;
        constexpr LibAVR::AVRReg<ValueTIMSK1, ADDR_TIMSK1> TIMSK1;
        constexpr LibAVR::AVRReg<ValueTIMSK2, ADDR_TIMSK2> TIMSK2;
        constexpr LibAVR::AVRReg<ValueADC, ADDR_ADCL> ADCL;
        constexpr LibAVR::AVRReg<ValueADC, ADDR_ADCH> ADCH;
        constexpr LibAVR::AVRReg<ValueADCSRA, ADDR_ADCSRA> ADCSRA;
        constexpr LibAVR::AVRReg<ValueADCSRB, ADDR_ADCSRB> ADCSRB;
        constexpr LibAVR::AVRReg<ValueADMUX, ADDR_ADMUX> ADMUX;
        constexpr LibAVR::AVRReg<ValueDIDR0, ADDR_DIDR0> DIDR0;
        constexpr LibAVR::AVRReg<ValueDIDR1, ADDR_DIDR1> DIDR1;
        constexpr LibAVR::AVRReg<ValueTCCR1A, ADDR_TCCR1A> TCCR1A;
        constexpr LibAVR::AVRReg<ValueTCCR1B, ADDR_TCCR1B> TCCR1B;
        constexpr LibAVR::AVRReg<ValueTCCR1C, ADDR_TCCR1C> TCCR1C;
        constexpr LibAVR::AVRReg<ValueTCNT1, ADDR_TCNT1L> TCNT1L;
        constexpr LibAVR::AVRReg<ValueTCNT1, ADDR_TCNT1H> TCNT1H;
        constexpr LibAVR::AVRReg<ValueICR1, ADDR_ICR1L> ICR1L;
        constexpr LibAVR::AVRReg<ValueICR1, ADDR_ICR1H> ICR1H;
        constexpr LibAVR::AVRReg<ValueOCR1A, ADDR_OCR1AL> OCR1AL;
        constexpr LibAVR::AVRReg<ValueOCR1A, ADDR_OCR1AH> OCR1AH;
        constexpr LibAVR::AVRReg<ValueOCR1B, ADDR_OCR1BL> OCR1BL;
        constexpr LibAVR::AVRReg<ValueOCR1B, ADDR_OCR1BH> OCR1BH;
        constexpr LibAVR::AVRReg<ValueTCCR2A, ADDR_TCCR2A> TCCR2A;
        constexpr LibAVR::AVRReg<ValueTCCR2B, ADDR_TCCR2B> TCCR2B;
        constexpr LibAVR::AVRReg<ValueTCNT2, ADDR_TCNT2> TCNT2;
        constexpr LibAVR::AVRReg<ValueOCR2A, ADDR_OCR2A> OCR2A;
        constexpr LibAVR::AVRReg<ValueOCR2B, ADDR_OCR2B> OCR2B;
        constexpr LibAVR::AVRReg<ValueASSR, ADDR_ASSR> ASSR;
        constexpr LibAVR::AVRReg<ValueTWBR, ADDR_TWBR> TWBR;
        constexpr LibAVR::AVRReg<ValueTWSR, ADDR_TWSR> TWSR;
        constexpr LibAVR::AVRReg<ValueTWAR, ADDR_TWAR> TWAR;
        constexpr LibAVR::AVRReg<ValueTWDR, ADDR_TWDR> TWDR;
        constexpr LibAVR::AVRReg<ValueTWCR, ADDR_TWCR> TWCR;
        constexpr LibAVR::AVRReg<ValueTWAMR, ADDR_TWAMR> TWAMR;
        constexpr LibAVR::AVRReg<ValueUCSR0A, ADDR_UCSR0A> UCSR0A;
        constexpr LibAVR::AVRReg<ValueUCSR0B, ADDR_UCSR0B> UCSR0B;
        constexpr LibAVR::AVRReg<ValueUCSR0C, ADDR_UCSR0C> UCSR0C;
        constexpr LibAVR::AVRReg<ValueUBRR0, ADDR_UBRR0L> UBRR0L;
        constexpr LibAVR::AVRReg<ValueUBRR0, ADDR_UBRR0H> UBRR0H;
        constexpr LibAVR::AVRReg<ValueUDR0, ADDR_UDR0> UDR0;
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

#define WDP0 AVRIO::ValueWDTCSR(0)
#define WDP1 AVRIO::ValueWDTCSR(1)
#define WDP2 AVRIO::ValueWDTCSR(2)
#define WDE AVRIO::ValueWDTCSR(3)
#define WDCE AVRIO::ValueWDTCSR(4)
#define WDP3 AVRIO::ValueWDTCSR(5)
#define WDIE AVRIO::ValueWDTCSR(6)
#define WDIF AVRIO::ValueWDTCSR(7)

#define CLKPS0 AVRIO::ValueCLKPR(0)
#define CLKPS1 AVRIO::ValueCLKPR(1)
#define CLKPS2 AVRIO::ValueCLKPR(2)
#define CLKPS3 AVRIO::ValueCLKPR(3)
#define CLKPCE AVRIO::ValueCLKPR(7)

#define PRADC AVRIO::ValuePRR(0)
#define PRUSART0 AVRIO::ValuePRR(1)
#define PRSPI AVRIO::ValuePRR(2)
#define PRTIM1 AVRIO::ValuePRR(3)
#define PRTIM0 AVRIO::ValuePRR(5)
#define PRTIM2 AVRIO::ValuePRR(6)
#define PRTWI AVRIO::ValuePRR(7)

#define PCIE0 AVRIO::ValuePCICR(0)
#define PCIE1 AVRIO::ValuePCICR(1)
#define PCIE2 AVRIO::ValuePCICR(2)

#define ISC00 AVRIO::ValueEICRA(0)
#define ISC01 AVRIO::ValueEICRA(1)
#define ISC10 AVRIO::ValueEICRA(2)
#define ISC11 AVRIO::ValueEICRA(3)

#define PCINT0 AVRIO::ValuePCMSK0(0)
#define PCINT1 AVRIO::ValuePCMSK0(1)
#define PCINT2 AVRIO::ValuePCMSK0(2)
#define PCINT3 AVRIO::ValuePCMSK0(3)
#define PCINT4 AVRIO::ValuePCMSK0(4)
#define PCINT5 AVRIO::ValuePCMSK0(5)
#define PCINT6 AVRIO::ValuePCMSK0(6)
#define PCINT7 AVRIO::ValuePCMSK0(7)

#define PCINT8 AVRIO::ValuePCMSK1(0)
#define PCINT9 AVRIO::ValuePCMSK1(1)
#define PCINT10 AVRIO::ValuePCMSK1(2)
#define PCINT11 AVRIO::ValuePCMSK1(3)
#define PCINT12 AVRIO::ValuePCMSK1(4)
#define PCINT13 AVRIO::ValuePCMSK1(5)
#define PCINT14 AVRIO::ValuePCMSK1(6)

#define PCINT16 AVRIO::ValuePCMSK2(0)
#define PCINT17 AVRIO::ValuePCMSK2(1)
#define PCINT18 AVRIO::ValuePCMSK2(2)
#define PCINT19 AVRIO::ValuePCMSK2(3)
#define PCINT20 AVRIO::ValuePCMSK2(4)
#define PCINT21 AVRIO::ValuePCMSK2(5)
#define PCINT22 AVRIO::ValuePCMSK2(6)
#define PCINT23 AVRIO::ValuePCMSK2(7)

#define TOIE0 AVRIO::ValueTIMSK0(0)
#define OCIE0A AVRIO::ValueTIMSK0(1)
#define OCIE0B AVRIO::ValueTIMSK0(2)

#define TOIE1 AVRIO::ValueTIMSK1(0)
#define OCIE1A AVRIO::ValueTIMSK1(1)
#define OCIE1B AVRIO::ValueTIMSK1(2)
#define ICIE1 AVRIO::ValueTIMSK1(3)

#define TOIE2 AVRIO::ValueTIMSK2(0)
#define OCIE2A AVRIO::ValueTIMSK2(1)
#define OCIE2B AVRIO::ValueTIMSK2(2)

#define ADPS0 AVRIO::ValueADCSRA(0)
#define ADPS1 AVRIO::ValueADCSRA(1)
#define ADPS2 AVRIO::ValueADCSRA(2)
#define ADIE AVRIO::ValueADCSRA(3)
#define ADIF AVRIO::ValueADCSRA(4)
#define ADATE AVRIO::ValueADCSRA(5)
#define ADSC AVRIO::ValueADCSRA(6)
#define ADEN AVRIO::ValueADCSRA(7)

#define ADTS0 AVRIO::ValueADCSRB(0)
#define ADTS1 AVRIO::ValueADCSRB(1)
#define ADTS2 AVRIO::ValueADCSRB(2)
#define ACME AVRIO::ValueADCSRB(3)

#define MUX0 AVRIO::ValueADMUX(0)
#define MUX1 AVRIO::ValueADMUX(1)
#define MUX2 AVRIO::ValueADMUX(2)
#define MUX3 AVRIO::ValueADMUX(3)
#define ADLAR AVRIO::ValueADMUX(5)
#define REFS0 AVRIO::ValueADMUX(6)
#define REFS1 AVRIO::ValueADMUX(7)

#define ADC0D AVRIO::ValueDIDR0(0)
#define ADC1D AVRIO::ValueDIDR0(1)
#define ADC2D AVRIO::ValueDIDR0(2)
#define ADC3D AVRIO::ValueDIDR0(3)
#define ADC4D AVRIO::ValueDIDR0(4)
#define ADC5D AVRIO::ValueDIDR0(5)

#define AIN0D AVRIO::ValueDIDR1(0)
#define AIN1D AVRIO::ValueDIDR1(1)

#define WGM10 AVRIO::ValueTCCR1A(0)
#define WGM11 AVRIO::ValueTCCR1A(1)
#define COM1B0 AVRIO::ValueTCCR1A(4)
#define COM1B1 AVRIO::ValueTCCR1A(5)
#define COM1A0 AVRIO::ValueTCCR1A(6)
#define COM1A1 AVRIO::ValueTCCR1A(7)

#define CS10 AVRIO::ValueTCCR1B(0)
#define CS11 AVRIO::ValueTCCR1B(1)
#define CS12 AVRIO::ValueTCCR1B(2)
#define WGM12 AVRIO::ValueTCCR1B(3)
#define WGM13 AVRIO::ValueTCCR1B(4)
#define ICES1 AVRIO::ValueTCCR1B(6)
#define ICNC1 AVRIO::ValueTCCR1B(7)

#define FOC1B AVRIO::ValueTCCR1C(6)
#define FOC1A AVRIO::ValueTCCR1C(7)

#define WGM20 AVRIO::ValueTCCR2A(0)
#define WGM21 AVRIO::ValueTCCR2A(1)
#define COM2B0 AVRIO::ValueTCCR2A(4)
#define COM2B1 AVRIO::ValueTCCR2A(5)
#define COM2A0 AVRIO::ValueTCCR2A(6)
#define COM2A1 AVRIO::ValueTCCR2A(7)

#define CS20 AVRIO::ValueTCCR2B(0)
#define CS21 AVRIO::ValueTCCR2B(1)
#define CS22 AVRIO::ValueTCCR2B(2)
#define WGM22 AVRIO::ValueTCCR2B(3)
#define FOC2A AVRIO::ValueTCCR2B(6)
#define FOC2B AVRIO::ValueTCCR2B(7)

#define TCR2BUB AVRIO::ValueASSR(0)
#define TCR2AUB AVRIO::ValueASSR(1)
#define OCR2BUB AVRIO::ValueASSR(2)
#define OCR2AUB AVRIO::ValueASSR(3)
#define TCN2UB AVRIO::ValueASSR(4)
#define AS2 AVRIO::ValueASSR(5)
#define EXCLK AVRIO::ValueASSR(6)

#define TWPS0 AVRIO::ValueTWSR(0)
#define TWPS1 AVRIO::ValueTWSR(1)
#define TWS3 AVRIO::ValueTWSR(3)
#define TWS4 AVRIO::ValueTWSR(4)
#define TWS5 AVRIO::ValueTWSR(5)
#define TWS6 AVRIO::ValueTWSR(6)
#define TWS7 AVRIO::ValueTWSR(7)

#define TWGCE AVRIO::ValueTWAR(0)
#define TWA0 AVRIO::ValueTWAR(1)
#define TWA1 AVRIO::ValueTWAR(2)
#define TWA2 AVRIO::ValueTWAR(3)
#define TWA3 AVRIO::ValueTWAR(4)
#define TWA4 AVRIO::ValueTWAR(5)
#define TWA5 AVRIO::ValueTWAR(6)
#define TWA6 AVRIO::ValueTWAR(7)

#define TWIE AVRIO::ValueTWCR(0)
#define TWEN AVRIO::ValueTWCR(2)
#define TWWC AVRIO::ValueTWCR(3)
#define TWSTO AVRIO::ValueTWCR(4)
#define TWSTA AVRIO::ValueTWCR(5)
#define TWEA AVRIO::ValueTWCR(6)
#define TWINT AVRIO::ValueTWCR(7)

#define TWAM0 AVRIO::ValueTWAMR(1)
#define TWAM1 AVRIO::ValueTWAMR(2)
#define TWAM2 AVRIO::ValueTWAMR(3)
#define TWAM3 AVRIO::ValueTWAMR(4)
#define TWAM4 AVRIO::ValueTWAMR(5)
#define TWAM5 AVRIO::ValueTWAMR(6)
#define TWAM6 AVRIO::ValueTWAMR(7)

#define MPCM0 AVRIO::ValueUCSR0A(0)
#define U2X0 AVRIO::ValueUCSR0A(1)
#define UPE0 AVRIO::ValueUCSR0A(2)
#define DOR0 AVRIO::ValueUCSR0A(3)
#define FE0 AVRIO::ValueUCSR0A(4)
#define UDRE0 AVRIO::ValueUCSR0A(5)
#define TXC0 AVRIO::ValueUCSR0A(6)
#define RXC0 AVRIO::ValueUCSR0A(7)

#define TXB80 AVRIO::ValueUCSR0B(0)
#define RXB80 AVRIO::ValueUCSR0B(1)
#define UCSZ02 AVRIO::ValueUCSR0B(2)
#define TXEN0 AVRIO::ValueUCSR0B(3)
#define RXEN0 AVRIO::ValueUCSR0B(4)
#define UDRIE0 AVRIO::ValueUCSR0B(5)
#define TXCIE0 AVRIO::ValueUCSR0B(6)
#define RXCIE0 AVRIO::ValueUCSR0B(7)

#define UCPOL0 AVRIO::ValueUCSR0C(0)
#define UCSZ00 AVRIO::ValueUCSR0C(1)
#define UCSZ01 AVRIO::ValueUCSR0C(2)
#define UCPHA0 AVRIO::ValueUCSR0C(1)    // Alternate name on bit
#define UDORD0 AVRIO::ValueUCSR0C(2)    // Alternate name on bit
#define USBS0 AVRIO::ValueUCSR0C(3)
#define UPM00 AVRIO::ValueUCSR0C(4)
#define UPM01 AVRIO::ValueUCSR0C(5)
#define UMSEL00 AVRIO::ValueUCSR0C(6)
#define UMSEL01 AVRIO::ValueUCSR0C(7)


#endif /* AVRIO_h */
