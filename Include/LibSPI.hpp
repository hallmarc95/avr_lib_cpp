//
//  LibSPI.hpp
//
//  Created by Marcus Hall on 9/14/20.
//

#ifndef LibSPI_hpp
#define LibSPI_hpp

#include <stdio.h>
#include <AVRIO.h>
//#include "Function.hpp"

namespace LibSPI {
    
    /*
     
     SPI Modules are used to connect the general SPI class to the correct
     hardware registers. Multiple SPI instances can use different modules
     if the AVR device has such hardware.
     
     */
    namespace Modules {

#ifdef __HAVE_SPI__
        /**
         Hardware registers used to operate devices with a single SPI module.
         */
        struct SPISingle {
            static constexpr auto& _CR = AVRIO::SPCR;
            static constexpr auto& _SR = AVRIO::SPSR;
            static constexpr auto& _DR = AVRIO::SPDR;
            static constexpr auto& _SSDDR = AVRIO::DDRB;
            
            typedef decltype(AVRIO::SPDR)::Value_Type _DT;
            
            static constexpr auto _SSPin = PB2;

            static constexpr auto _SPE = SPE;
            static constexpr auto _SPIE = SPIE;
            static constexpr auto _MSTR = MSTR;
            static constexpr auto _CPOL = CPOL;
            static constexpr auto _CPHA = CPHA;
            static constexpr auto _DORD = DORD;
            static constexpr auto _SPR0 = SPR0;
            static constexpr auto _SPR1 = SPR1;
            
            static constexpr auto _SPI2X = SPI2X;
            static constexpr auto _SPIF = SPIF;
            static constexpr auto _WCOL = WCOL;
            
            // Note: Used to make a lot of use of decltype(...)
            //  in this struct, then I remembered "auto" and
            //  hated myself for it.
            //
            // But I learned a lot first. So take some time using
            //  decltype(...) to get exactly the type you desire.
            //  Then once you understand what's going on switch
            //  over to auto to avoid future headaches.
        };
#endif // __HAVE_SPI__
        
    }
    
    /// Roll of this endpoint on the SPI bus
    enum class SPIRole {
        Master=1,
        Slave=0
    };
    
    /// Direction of change on the SCK clock signal
    enum class SCKEdge {
        Rising=0,
        Falling=1
    };
    
    /// Edge of the periodic SCK clock signal
    enum class SCKPhase {
        Leading=0,
        Trailing=1
    };
    
    /// Endianness of the SPI bus
    enum class SPIDirection {
        MSBFirst=1,
        LSBFirst=0
    };
    
    /// Prescaler used to generate the SCK from the system CLK
    enum class SCKPrescaler {
        OSCDiv_4,
        OSCDiv_16,
        OSCDiv_64,
        OSCDiv_128,
        OSCDiv_2,
        OSCDiv_8,
        OSCDiv_32,
        OSCDiv_64_X,
    };
    
    /**
     Generalized interface for operation of an SPI bus module.
     
     Define pre-processor symbol USE_SPI_DELEGATES to enable delegate handling functionality.
     */
    template <class M>
    class SPI final {
#ifdef USE_SPI_DELEGATES
//        Function<void> AssertSS_delegate;
//        Function<void> ReleaseSS_delegate;
//        Function<void> WriteCollision_delegate;
        void OnAssertSS();
        void OnReleaseSS();
        void OnWriteCollision();
        
        /*
         Delegate function definitions must be provided if USE_SPI_DELEGATES is defined:
         
         template <>
         void SPI<... Module used ...>::OnAssertSS() {
            ... insert code here...
         }
         
         template <>
         void SPI<... Module used ...>::OnReleaseSS() {
            ... insert code here ...
         }
         
         template <>
         void SPI<... Module used ...>::OnWriteCollision() {
            ... insert code here ...
         }
         
         */
        
    public:
        
//        void BindAssertSS(Function<void>::FType&& InFunc) {
//            AssertSS_delegate = InFunc;
//        }
//
//        void BindReleaseSS(Function<void>::FType&& InFunc) {
//            ReleaseSS_delegate = InFunc;
//        }
//
//        void BindWriteCollision(Function<void>::FType&& InFunc) {
//            WriteCollision_delegate = InFunc;
//        }
        
        void AssertSS() const {
//            if (AssertSS_delegate.IsValid() == true)
//                AssertSS_delegate();
            OnAssertSS();
        }
        
        void ReleaseSS() const {
//            if (ReleaseSS_delegate.IsValid() == true)
//                ReleaseSS_delegate();
            OnReleaseSS();
        }
        
        void DoCheckWriteCollision() const {
//            if (WriteCollision_delegate.IsValid() == true && IsWriteCollisionFlagSet() == true)
//                WriteCollision_delegate();
            if (IsWriteCollisionFlagSet() == true)
                OnWriteCollision();
        }
#endif
        
    public:
        using DataType = typename M::_DT;
        
        
        SPI() = delete;
        SPI(SPIRole const InMode = SPIRole::Master) {
            SetRole(InMode);
            SetEnabled(true);
        }
        
        
        void Write(DataType const InByte) const {
            M::_DR = InByte;
        }
        
        DataType Read() const {
            return M::_DR;
        }
        
        void WaitForTransaction() const {
            while (IsTransactionCompleteFlagSet() == false);
        }
        
        DataType DoTransactBlocking(DataType const& InByte) const {
#ifdef USE_SPI_DELEGATES
            AssertSS();
#endif
            Write(InByte);
            WaitForTransaction();
#ifdef USE_SPI_DELEGATES
            ReleaseSS();
#endif
            
            return Read();
        }
        
        
        void SetSCKLeadingEdge(SCKEdge const InEdgeDirection) const {
            M::_CR.WriteBit(M::_CPOL, InEdgeDirection == SCKEdge::Falling);
        }
        
        void SetSampleEdge(SCKPhase const InPhaseEdge) const {
            M::_CR.WriteBit(M::_CPHA, InPhaseEdge == SCKPhase::Trailing);
        }
        
        void SetTransferDirection(SPIDirection const InTransferDirection) const {
            M::_CR.WriteBit(M::_DORD, InTransferDirection == SPIDirection::MSBFirst);
        }
        
        void SetEnabled(bool const bEnable) const {
            M::_CR.WriteBit(M::_SPE, bEnable);
        }
        
        void SetClockRate(SCKPrescaler const InPrescaler) const {
            uint8_t const Val = static_cast<int const>(InPrescaler);
            
            M::_CR.WriteBit(M::_SPR0, (Val & 0b001) != 0);
            M::_CR.WriteBit(M::_SPR1, (Val & 0b010) != 0);
            M::_SR.WriteBit(M::_SPR2X, (Val & 0b100) != 0);
        }
        
        void SetTransactionCompleteInterruptEnable(bool const bEnable) const {
            M::_CR.WriteBit(M::_SPIE, bEnable);
        }
        
        void SetRole(SPIRole const InRole) const {
            M::_SSDDR.WriteBit(M::_SSPin, InRole == SPIRole::Master);
            M::_CR.WriteBit(M::_MSTR, InRole == SPIRole::Master);
        }
        
        
        bool IsWriteCollisionFlagSet() const {
            return (M::_SR.IsBitSet(M::_WCOL) == true);
        }
        
        bool IsTransactionCompleteFlagSet() const {
            return M::_SR.IsBitSet(M::_SPIF) == true;
        }
        
    };
    
}

#endif /* LibSPI_hpp */
