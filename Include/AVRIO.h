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
#define DEF_REGBITS( N ) struct N final : LibAVR::RegBits_Base { \
explicit constexpr N(LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {} \
constexpr N operator ~() const { return static_cast<N>(this->RegBits_Base::operator~()); }};

/// Expands to define a value-type for a 16-bit composite register. See ValueTCNT1_16 for expansion.
#define DEF_REGBITS_16( N ) struct N final : LibAVR::RegBits_16_Base { \
explicit constexpr N(LibAVR::RegisterValue_16 InValue) : LibAVR::RegBits_16_Base(InValue) {} \
constexpr N operator ~() const { return static_cast<N>(this->RegBits_16_Base::operator~()); }};

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
        explicit constexpr ValuePORTB(LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
        constexpr ValuePORTB operator ~() const { return static_cast<ValuePORTB>(this->RegBits_Base::operator~()); }
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
    DEF_REGBITS(ValueOCR0)
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
    DEF_REGBITS(ValueOCR1)
    DEF_REGBITS(ValueTCCR2A)
    DEF_REGBITS(ValueTCCR2B)
    DEF_REGBITS(ValueTCNT2)
    DEF_REGBITS(ValueOCR2)
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

    // Define 16-bit composite register value-types
    
    DEF_REGBITS_16(ValueEEAR_16)
    DEF_REGBITS_16(ValueADC_16)
    struct ValueTCNT1_16 final : LibAVR::RegBits_16_Base {
        explicit constexpr ValueTCNT1_16(LibAVR::RegisterValue_16 InValue) : LibAVR::RegBits_16_Base(InValue) {}
        constexpr ValueTCNT1_16 operator ~() const { return static_cast<ValueTCNT1_16>(this->RegBits_16_Base::operator~()); }
    };
    DEF_REGBITS_16(ValueICR1_16)
    DEF_REGBITS_16(ValueOCR1_16)
    DEF_REGBITS_16(ValueUBRR0_16)

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
        constexpr LibAVR::AVRReg<ValueOCR0, ADDR_OCR0A> OCR0A;
        constexpr LibAVR::AVRReg<ValueOCR0, ADDR_OCR0B> OCR0B;
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
        constexpr LibAVR::AVRReg<ValueOCR1, ADDR_OCR1AL> OCR1AL;
        constexpr LibAVR::AVRReg<ValueOCR1, ADDR_OCR1AH> OCR1AH;
        constexpr LibAVR::AVRReg<ValueOCR1, ADDR_OCR1BL> OCR1BL;
        constexpr LibAVR::AVRReg<ValueOCR1, ADDR_OCR1BH> OCR1BH;
        constexpr LibAVR::AVRReg<ValueTCCR2A, ADDR_TCCR2A> TCCR2A;
        constexpr LibAVR::AVRReg<ValueTCCR2B, ADDR_TCCR2B> TCCR2B;
        constexpr LibAVR::AVRReg<ValueTCNT2, ADDR_TCNT2> TCNT2;
        constexpr LibAVR::AVRReg<ValueOCR2, ADDR_OCR2A> OCR2A;
        constexpr LibAVR::AVRReg<ValueOCR2, ADDR_OCR2B> OCR2B;
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
    
        // Define hardware IO 16-Bit composite registers
    
        constexpr LibAVR::AVRReg_16<ValueEEAR_16, ADDR_EEARL> EEAR_16;
        constexpr LibAVR::AVRReg_16<ValueADC_16, ADDR_ADCL> ADC_16;
        constexpr LibAVR::AVRReg_16<ValueTCNT1_16, ADDR_TCNT1L> TCNT1_16;
        constexpr LibAVR::AVRReg_16<ValueICR1_16, ADDR_ICR1L> ICR1_16;
        constexpr LibAVR::AVRReg_16<ValueOCR1_16, ADDR_OCR1AL> OCR1A_16;
        constexpr LibAVR::AVRReg_16<ValueOCR1_16, ADDR_OCR1BL> OCR1B_16;
        constexpr LibAVR::AVRReg_16<ValueUBRR0_16, ADRR_UBRR0L> UBRR0_16;
    
    }
}


// Register bit shortcuts

constexpr auto PB0 = AVRIO::ValuePORTB(0);
constexpr auto PB1 = AVRIO::ValuePORTB(1);
constexpr auto PB2 = AVRIO::ValuePORTB(2);
constexpr auto PB3 = AVRIO::ValuePORTB(3);
constexpr auto PB4 = AVRIO::ValuePORTB(4);
constexpr auto PB5 = AVRIO::ValuePORTB(5);
constexpr auto PB6 = AVRIO::ValuePORTB(6);
constexpr auto PB7 = AVRIO::ValuePORTB(7);

constexpr auto PC0 = AVRIO::ValuePORTC(0);
constexpr auto PC1 = AVRIO::ValuePORTC(1);
constexpr auto PC2 = AVRIO::ValuePORTC(2);
constexpr auto PC3 = AVRIO::ValuePORTC(3);
constexpr auto PC4 = AVRIO::ValuePORTC(4);
constexpr auto PC5 = AVRIO::ValuePORTC(5);
constexpr auto PC6 = AVRIO::ValuePORTC(6);
constexpr auto PC7 = AVRIO::ValuePORTC(7);

constexpr auto PD0 = AVRIO::ValuePORTD(0);
constexpr auto PD1 = AVRIO::ValuePORTD(1);
constexpr auto PD2 = AVRIO::ValuePORTD(2);
constexpr auto PD3 = AVRIO::ValuePORTD(3);
constexpr auto PD4 = AVRIO::ValuePORTD(4);
constexpr auto PD5 = AVRIO::ValuePORTD(5);
constexpr auto PD6 = AVRIO::ValuePORTD(6);
constexpr auto PD7 = AVRIO::ValuePORTD(7);

constexpr auto TOV0 = AVRIO::ValueTIFR0(0);
constexpr auto OCF0A = AVRIO::ValueTIFR0(1);
constexpr auto OCF0B = AVRIO::ValueTIFR0(2);

constexpr auto TOV1 = AVRIO::ValueTIFR1(0);
constexpr auto OCF1A = AVRIO::ValueTIFR1(1);
constexpr auto OCF1B = AVRIO::ValueTIFR1(2);
constexpr auto ICF1 = AVRIO::ValueTIFR1(5);

constexpr auto TOV2 = AVRIO::ValueTIFR2(0);
constexpr auto OCF2A = AVRIO::ValueTIFR2(1);
constexpr auto OCF2B = AVRIO::ValueTIFR2(2);

constexpr auto PCIF0 = AVRIO::ValuePCIFR(0);
constexpr auto PCIF1 = AVRIO::ValuePCIFR(1);
constexpr auto PCIF2 = AVRIO::ValuePCIFR(2);

constexpr auto INTF0 = AVRIO::ValueEIFR(0);
constexpr auto INTF1 = AVRIO::ValueEIFR(1);

constexpr auto INT0 = AVRIO::ValueEIMSK(0);
constexpr auto INT1 = AVRIO::ValueEIMSK(1);

constexpr auto EERE = AVRIO::ValueEECR(0);
constexpr auto EEPE = AVRIO::ValueEECR(1);
constexpr auto EEMPE = AVRIO::ValueEECR(2);
constexpr auto EERIE = AVRIO::ValueEECR(3);
constexpr auto EEPM0 = AVRIO::ValueEECR(4);
constexpr auto EEPM1 = AVRIO::ValueEECR(5);

constexpr auto PSRSYNC = AVRIO::ValueGTCCR(0);
constexpr auto PSRASY = AVRIO::ValueGTCCR(1);
constexpr auto TSM = AVRIO::ValueGTCCR(7);

constexpr auto WGM00 = AVRIO::ValueTCCR0A(0);
constexpr auto WGM01 = AVRIO::ValueTCCR0A(1);
constexpr auto COM0B0 = AVRIO::ValueTCCR0A(4);
constexpr auto COM0B1 = AVRIO::ValueTCCR0A(5);
constexpr auto COM0A0 = AVRIO::ValueTCCR0A(6);
constexpr auto COM0A1 = AVRIO::ValueTCCR0A(7);

constexpr auto CS00 = AVRIO::ValueTCCR0B(0);
constexpr auto CS01 = AVRIO::ValueTCCR0B(1);
constexpr auto CS02 = AVRIO::ValueTCCR0B(2);
constexpr auto WGM02 = AVRIO::ValueTCCR0B(3);
constexpr auto FOC0B = AVRIO::ValueTCCR0B(6);
constexpr auto FOC0A = AVRIO::ValueTCCR0B(7);

constexpr auto SPIE = AVRIO::ValueSPCR(7);
constexpr auto SPE  = AVRIO::ValueSPCR(6);
constexpr auto DORD = AVRIO::ValueSPCR(5);
constexpr auto MSTR = AVRIO::ValueSPCR(4);
constexpr auto CPOL = AVRIO::ValueSPCR(3);
constexpr auto CPHA = AVRIO::ValueSPCR(2);
constexpr auto SPR1 = AVRIO::ValueSPCR(1);
constexpr auto SPR0 = AVRIO::ValueSPCR(0);

constexpr auto SPIF = AVRIO::ValueSPSR(7);
constexpr auto WCOL = AVRIO::ValueSPSR(6);
constexpr auto SPI2X = AVRIO::ValueSPSR(0);

constexpr auto ACIS0 = AVRIO::ValueACSR(0);
constexpr auto ACIS1 = AVRIO::ValueACSR(1);
constexpr auto ACIC = AVRIO::ValueACSR(2);
constexpr auto ACIE = AVRIO::ValueACSR(3);
constexpr auto ACI = AVRIO::ValueACSR(4);
constexpr auto ACO = AVRIO::ValueACSR(5);
constexpr auto ACBG = AVRIO::ValueACSR(6);
constexpr auto ACD = AVRIO::ValueACSR(7);

constexpr auto SE = AVRIO::ValueSMCR(0);
constexpr auto SM0 = AVRIO::ValueSMCR(1);
constexpr auto SM1 = AVRIO::ValueSMCR(2);
constexpr auto SM2 = AVRIO::ValueSMCR(3);

constexpr auto PORF = AVRIO::ValueMCUSR(0);
constexpr auto EXTRF = AVRIO::ValueMCUSR(1);
constexpr auto BORF = AVRIO::ValueMCUSR(2);
constexpr auto WDRF = AVRIO::ValueMCUSR(3);

constexpr auto IVCE = AVRIO::ValueMCUCR(0);
constexpr auto IVSEL = AVRIO::ValueMCUCR(1);
constexpr auto PUD = AVRIO::ValueMCUCR(4);
constexpr auto BODSE = AVRIO::ValueMCUCR(5);
constexpr auto BODS = AVRIO::ValueMCUCR(6);

constexpr auto SELFPRGEN = AVRIO::ValueSPMCSR(0);
constexpr auto PGERS = AVRIO::ValueSPMCSR(1);
constexpr auto PGWRT = AVRIO::ValueSPMCSR(2);
constexpr auto BLBSET = AVRIO::ValueSPMCSR(3);
//constexpr auto RWWSRE = AVRIO::ValueSPMCSR(4);  // atmega88P/168P only
//constexpr auto RWWSB = AVRIO::ValueSPMCSR(6);   // atmega88P/168P only
constexpr auto SPMIE = AVRIO::ValueSPMCSR(7);

constexpr auto SP0 = AVRIO::ValueSPL(0);
constexpr auto SP1 = AVRIO::ValueSPL(1);
constexpr auto SP2 = AVRIO::ValueSPL(2);
constexpr auto SP3 = AVRIO::ValueSPL(3);
constexpr auto SP4 = AVRIO::ValueSPL(4);
constexpr auto SP5 = AVRIO::ValueSPL(5);
constexpr auto SP6 = AVRIO::ValueSPL(6);
constexpr auto SP7 = AVRIO::ValueSPL(7);

constexpr auto SP8 = AVRIO::ValueSPH(0);
constexpr auto SP9 = AVRIO::ValueSPH(1);
//constexpr auto AVRIO::ValueSPH(2)   // atmega88P/168P only

constexpr auto C_Bit = AVRIO::ValueSREG(0);
constexpr auto Z_Bit = AVRIO::ValueSREG(1);
constexpr auto N_Bit = AVRIO::ValueSREG(2);
constexpr auto V_Bit = AVRIO::ValueSREG(3);
constexpr auto S_Bit = AVRIO::ValueSREG(4);
constexpr auto H_Bit = AVRIO::ValueSREG(5);
constexpr auto T_Bit = AVRIO::ValueSREG(6);
constexpr auto I_Bit = AVRIO::ValueSREG(7);

constexpr auto WDP0 = AVRIO::ValueWDTCSR(0);
constexpr auto WDP1 = AVRIO::ValueWDTCSR(1);
constexpr auto WDP2 = AVRIO::ValueWDTCSR(2);
constexpr auto WDE = AVRIO::ValueWDTCSR(3);
constexpr auto WDCE = AVRIO::ValueWDTCSR(4);
constexpr auto WDP3 = AVRIO::ValueWDTCSR(5);
constexpr auto WDIE = AVRIO::ValueWDTCSR(6);
constexpr auto WDIF = AVRIO::ValueWDTCSR(7);

constexpr auto CLKPS0 = AVRIO::ValueCLKPR(0);
constexpr auto CLKPS1 = AVRIO::ValueCLKPR(1);
constexpr auto CLKPS2 = AVRIO::ValueCLKPR(2);
constexpr auto CLKPS3 = AVRIO::ValueCLKPR(3);
constexpr auto CLKPCE = AVRIO::ValueCLKPR(7);

constexpr auto PRADC = AVRIO::ValuePRR(0);
constexpr auto PRUSART0 = AVRIO::ValuePRR(1);
constexpr auto PRSPI = AVRIO::ValuePRR(2);
constexpr auto PRTIM1 = AVRIO::ValuePRR(3);
constexpr auto PRTIM0 = AVRIO::ValuePRR(5);
constexpr auto PRTIM2 = AVRIO::ValuePRR(6);
constexpr auto PRTWI = AVRIO::ValuePRR(7);

constexpr auto PCIE0 = AVRIO::ValuePCICR(0);
constexpr auto PCIE1 = AVRIO::ValuePCICR(1);
constexpr auto PCIE2 = AVRIO::ValuePCICR(2);

constexpr auto ISC00 = AVRIO::ValueEICRA(0);
constexpr auto ISC01 = AVRIO::ValueEICRA(1);
constexpr auto ISC10 = AVRIO::ValueEICRA(2);
constexpr auto ISC11 = AVRIO::ValueEICRA(3);

constexpr auto PCINT0 = AVRIO::ValuePCMSK0(0);
constexpr auto PCINT1 = AVRIO::ValuePCMSK0(1);
constexpr auto PCINT2 = AVRIO::ValuePCMSK0(2);
constexpr auto PCINT3 = AVRIO::ValuePCMSK0(3);
constexpr auto PCINT4 = AVRIO::ValuePCMSK0(4);
constexpr auto PCINT5 = AVRIO::ValuePCMSK0(5);
constexpr auto PCINT6 = AVRIO::ValuePCMSK0(6);
constexpr auto PCINT7 = AVRIO::ValuePCMSK0(7);

constexpr auto PCINT8 = AVRIO::ValuePCMSK1(0);
constexpr auto PCINT9 = AVRIO::ValuePCMSK1(1);
constexpr auto PCINT10 = AVRIO::ValuePCMSK1(2);
constexpr auto PCINT11 = AVRIO::ValuePCMSK1(3);
constexpr auto PCINT12 = AVRIO::ValuePCMSK1(4);
constexpr auto PCINT13 = AVRIO::ValuePCMSK1(5);
constexpr auto PCINT14 = AVRIO::ValuePCMSK1(6);

constexpr auto PCINT16 = AVRIO::ValuePCMSK2(0);
constexpr auto PCINT17 = AVRIO::ValuePCMSK2(1);
constexpr auto PCINT18 = AVRIO::ValuePCMSK2(2);
constexpr auto PCINT19 = AVRIO::ValuePCMSK2(3);
constexpr auto PCINT20 = AVRIO::ValuePCMSK2(4);
constexpr auto PCINT21 = AVRIO::ValuePCMSK2(5);
constexpr auto PCINT22 = AVRIO::ValuePCMSK2(6);
constexpr auto PCINT23 = AVRIO::ValuePCMSK2(7);

constexpr auto TOIE0 = AVRIO::ValueTIMSK0(0);
constexpr auto OCIE0A = AVRIO::ValueTIMSK0(1);
constexpr auto OCIE0B = AVRIO::ValueTIMSK0(2);

constexpr auto TOIE1 = AVRIO::ValueTIMSK1(0);
constexpr auto OCIE1A = AVRIO::ValueTIMSK1(1);
constexpr auto OCIE1B = AVRIO::ValueTIMSK1(2);
constexpr auto ICIE1 = AVRIO::ValueTIMSK1(3);

constexpr auto TOIE2 = AVRIO::ValueTIMSK2(0);
constexpr auto OCIE2A = AVRIO::ValueTIMSK2(1);
constexpr auto OCIE2B = AVRIO::ValueTIMSK2(2);

constexpr auto ADPS0 = AVRIO::ValueADCSRA(0);
constexpr auto ADPS1 = AVRIO::ValueADCSRA(1);
constexpr auto ADPS2 = AVRIO::ValueADCSRA(2);
constexpr auto ADIE = AVRIO::ValueADCSRA(3);
constexpr auto ADIF = AVRIO::ValueADCSRA(4);
constexpr auto ADATE = AVRIO::ValueADCSRA(5);
constexpr auto ADSC = AVRIO::ValueADCSRA(6);
constexpr auto ADEN = AVRIO::ValueADCSRA(7);

constexpr auto ADTS0 = AVRIO::ValueADCSRB(0);
constexpr auto ADTS1 = AVRIO::ValueADCSRB(1);
constexpr auto ADTS2 = AVRIO::ValueADCSRB(2);
constexpr auto ACME = AVRIO::ValueADCSRB(3);

constexpr auto MUX0 = AVRIO::ValueADMUX(0);
constexpr auto MUX1 = AVRIO::ValueADMUX(1);
constexpr auto MUX2 = AVRIO::ValueADMUX(2);
constexpr auto MUX3 = AVRIO::ValueADMUX(3);
constexpr auto ADLAR = AVRIO::ValueADMUX(5);
constexpr auto REFS0 = AVRIO::ValueADMUX(6);
constexpr auto REFS1 = AVRIO::ValueADMUX(7);

constexpr auto ADC0D = AVRIO::ValueDIDR0(0);
constexpr auto ADC1D = AVRIO::ValueDIDR0(1);
constexpr auto ADC2D = AVRIO::ValueDIDR0(2);
constexpr auto ADC3D = AVRIO::ValueDIDR0(3);
constexpr auto ADC4D = AVRIO::ValueDIDR0(4);
constexpr auto ADC5D = AVRIO::ValueDIDR0(5);

constexpr auto AIN0D = AVRIO::ValueDIDR1(0);
constexpr auto AIN1D = AVRIO::ValueDIDR1(1);

constexpr auto WGM10 = AVRIO::ValueTCCR1A(0);
constexpr auto WGM11 = AVRIO::ValueTCCR1A(1);
constexpr auto COM1B0 = AVRIO::ValueTCCR1A(4);
constexpr auto COM1B1 = AVRIO::ValueTCCR1A(5);
constexpr auto COM1A0 = AVRIO::ValueTCCR1A(6);
constexpr auto COM1A1 = AVRIO::ValueTCCR1A(7);

constexpr auto CS10 = AVRIO::ValueTCCR1B(0);
constexpr auto CS11 = AVRIO::ValueTCCR1B(1);
constexpr auto CS12 = AVRIO::ValueTCCR1B(2);
constexpr auto WGM12 = AVRIO::ValueTCCR1B(3);
constexpr auto WGM13 = AVRIO::ValueTCCR1B(4);
constexpr auto ICES1 = AVRIO::ValueTCCR1B(6);
constexpr auto ICNC1 = AVRIO::ValueTCCR1B(7);

constexpr auto FOC1B = AVRIO::ValueTCCR1C(6);
constexpr auto FOC1A = AVRIO::ValueTCCR1C(7);

constexpr auto WGM20 = AVRIO::ValueTCCR2A(0);
constexpr auto WGM21 = AVRIO::ValueTCCR2A(1);
constexpr auto COM2B0 = AVRIO::ValueTCCR2A(4);
constexpr auto COM2B1 = AVRIO::ValueTCCR2A(5);
constexpr auto COM2A0 = AVRIO::ValueTCCR2A(6);
constexpr auto COM2A1 = AVRIO::ValueTCCR2A(7);

constexpr auto CS20 = AVRIO::ValueTCCR2B(0);
constexpr auto CS21 = AVRIO::ValueTCCR2B(1);
constexpr auto CS22 = AVRIO::ValueTCCR2B(2);
constexpr auto WGM22 = AVRIO::ValueTCCR2B(3);
constexpr auto FOC2A = AVRIO::ValueTCCR2B(6);
constexpr auto FOC2B = AVRIO::ValueTCCR2B(7);

constexpr auto TCR2BUB = AVRIO::ValueASSR(0);
constexpr auto TCR2AUB = AVRIO::ValueASSR(1);
constexpr auto OCR2BUB = AVRIO::ValueASSR(2);
constexpr auto OCR2AUB = AVRIO::ValueASSR(3);
constexpr auto TCN2UB = AVRIO::ValueASSR(4);
constexpr auto AS2 = AVRIO::ValueASSR(5);
constexpr auto EXCLK = AVRIO::ValueASSR(6);

constexpr auto TWPS0 = AVRIO::ValueTWSR(0);
constexpr auto TWPS1 = AVRIO::ValueTWSR(1);
constexpr auto TWS3 = AVRIO::ValueTWSR(3);
constexpr auto TWS4 = AVRIO::ValueTWSR(4);
constexpr auto TWS5 = AVRIO::ValueTWSR(5);
constexpr auto TWS6 = AVRIO::ValueTWSR(6);
constexpr auto TWS7 = AVRIO::ValueTWSR(7);

constexpr auto TWGCE = AVRIO::ValueTWAR(0);
constexpr auto TWA0 = AVRIO::ValueTWAR(1);
constexpr auto TWA1 = AVRIO::ValueTWAR(2);
constexpr auto TWA2 = AVRIO::ValueTWAR(3);
constexpr auto TWA3 = AVRIO::ValueTWAR(4);
constexpr auto TWA4 = AVRIO::ValueTWAR(5);
constexpr auto TWA5 = AVRIO::ValueTWAR(6);
constexpr auto TWA6 = AVRIO::ValueTWAR(7);

constexpr auto TWIE = AVRIO::ValueTWCR(0);
constexpr auto TWEN = AVRIO::ValueTWCR(2);
constexpr auto TWWC = AVRIO::ValueTWCR(3);
constexpr auto TWSTO = AVRIO::ValueTWCR(4);
constexpr auto TWSTA = AVRIO::ValueTWCR(5);
constexpr auto TWEA = AVRIO::ValueTWCR(6);
constexpr auto TWINT = AVRIO::ValueTWCR(7);

constexpr auto TWAM0 = AVRIO::ValueTWAMR(1);
constexpr auto TWAM1 = AVRIO::ValueTWAMR(2);
constexpr auto TWAM2 = AVRIO::ValueTWAMR(3);
constexpr auto TWAM3 = AVRIO::ValueTWAMR(4);
constexpr auto TWAM4 = AVRIO::ValueTWAMR(5);
constexpr auto TWAM5 = AVRIO::ValueTWAMR(6);
constexpr auto TWAM6 = AVRIO::ValueTWAMR(7);

constexpr auto MPCM0 = AVRIO::ValueUCSR0A(0);
constexpr auto U2X0 = AVRIO::ValueUCSR0A(1);
constexpr auto UPE0 = AVRIO::ValueUCSR0A(2);
constexpr auto DOR0 = AVRIO::ValueUCSR0A(3);
constexpr auto FE0 = AVRIO::ValueUCSR0A(4);
constexpr auto UDRE0 = AVRIO::ValueUCSR0A(5);
constexpr auto TXC0 = AVRIO::ValueUCSR0A(6);
constexpr auto RXC0 = AVRIO::ValueUCSR0A(7);

constexpr auto TXB80 = AVRIO::ValueUCSR0B(0);
constexpr auto RXB80 = AVRIO::ValueUCSR0B(1);
constexpr auto UCSZ02 = AVRIO::ValueUCSR0B(2);
constexpr auto TXEN0 = AVRIO::ValueUCSR0B(3);
constexpr auto RXEN0 = AVRIO::ValueUCSR0B(4);
constexpr auto UDRIE0 = AVRIO::ValueUCSR0B(5);
constexpr auto TXCIE0 = AVRIO::ValueUCSR0B(6);
constexpr auto RXCIE0 = AVRIO::ValueUCSR0B(7);

constexpr auto UCPOL0 = AVRIO::ValueUCSR0C(0);
constexpr auto UCSZ00 = AVRIO::ValueUCSR0C(1);
constexpr auto UCSZ01 = AVRIO::ValueUCSR0C(2);
constexpr auto UCPHA0 = AVRIO::ValueUCSR0C(1);    // Alternate name on bit
constexpr auto UDORD0 = AVRIO::ValueUCSR0C(2);    // Alternate name on bit
constexpr auto USBS0 = AVRIO::ValueUCSR0C(3);
constexpr auto UPM00 = AVRIO::ValueUCSR0C(4);
constexpr auto UPM01 = AVRIO::ValueUCSR0C(5);
constexpr auto UMSEL00 = AVRIO::ValueUCSR0C(6);
constexpr auto UMSEL01 = AVRIO::ValueUCSR0C(7);


#endif /* AVRIO_h */
