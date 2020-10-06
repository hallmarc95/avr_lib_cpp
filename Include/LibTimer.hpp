//
//  LibTimer.hpp
//  LibTimer
//
//  Created by Marcus Hall on 10/2/20.
//

#ifndef LibTimer_hpp
#define LibTimer_hpp

#include <AVRIO.h>
#include <CStdDef.h>
#include <Type_Traits.hpp>

namespace LibTimer {
    
    enum class ICEdge {
        Falling = 0,
        Rising = 1
    };
    
    enum class TimerPrescaler {
        Disabled = 0,
        OSCDiv_1 = 1,
        OSCDiv_8 = 2,
        OSCDiv_32 = 3,
        OSCDiv_64 = 4,
        OSCDiv_128 = 5,
        OSCDiv_256 = 6,
        OSCDiv_1024 = 7
    };
    
    enum class TimerPrescaler_EXT {
        Disabled = 0,
        OSCDiv_1 = 1,
        OSCDiv_8 = 2,
        OSCDiv_64 = 3,
        OSCDiv_256 = 4,
        OSCDiv_1024 = 5,
        EXTT0Falling = 6,
        EXTT0Rising = 7
    };
    
    enum class TimerOperationMode {
        Normal = 0,
        PWMPhaseCorrect = 1,
        CTC_OCRA = 2,
        PWMFast = 3,
        PWMPhaseCorrect_OCRA = 5,
        FastPWM_OCRA = 7
    };
    
    enum class TimerOperationModeExtended {
        Normal = 0,
        PWMPhaseCorrect_8Bit = 1,
        PWMPhaseCorrect_9Bit = 2,
        PWMPhaseCorrect_10Bit = 3,
        CTC_OCRA = 4,
        PWMFast_8Bit = 5,
        PWMFast_9Bit = 6,
        PWMFast_10Bit = 7,
        PWMPhaseFrequencyCorrect_ICR = 8,
        PWMPhaseFrequencyCorrect_OCRA = 9,
        PWMPhaseCorrect_ICR = 10,
        PWMPhaseCorrect_OCRA = 11,
        CTC_ICR = 12,
        PWMFast_ICR = 14,
        PWMFast_OCRA = 15
    };
    
    enum class OCMModule {
        A = 0,
        B = 1
    };
    
    enum class CompareOutputMode {
        Disconnected = 0,
        Toggle = 1,
        Clear = 2,
        Set = 3,
        FastPWM_Toggle = 1,
        FastPWM_Noninverting = 2,
        FastPWM_Inverting = 3,
        PCPWM_Toggle = 1,
        PCPWM_ClearUp_SetDown = 2,
        PCPWM_SetUp_ClearDown = 3
    };
    
    namespace Modules {
        
#ifdef __HAVE_TIMER0_8BITS_EXTCLK__
        struct Timer0 final {
            using WGM_Type = TimerOperationMode;
            using Prescaler_Type = TimerPrescaler_EXT;
            
            using OCM_Type = decltype(AVRIO::OCR0A)::Value_Type;
            using TimerCount_Type = decltype(AVRIO::TCNT0)::Value_Type;
            using TIMSKValue_Type = decltype(AVRIO::TIMSK0)::Value_Type;
            
            static constexpr auto& _CRA = AVRIO::TCCR0A;
            static constexpr auto& _CRB = AVRIO::TCCR0B;
            static constexpr auto& _CNT = AVRIO::TCNT0;
            static constexpr auto& _OCA = AVRIO::OCR0A;
            static constexpr auto& _OCB = AVRIO::OCR0B;
            static constexpr auto& _IM = AVRIO::TIMSK0;
            static constexpr auto& _IF = AVRIO::TIFR0;
            static constexpr auto _ICR = nullptr;
            static constexpr auto _ASY = nullptr;
            static constexpr auto& _GCR = AVRIO::GTCCR;
            
            static constexpr auto& _FOC_R = AVRIO::TCCR0B;
            
            static constexpr auto _COMA0 = COM0A0;
            static constexpr auto _COMA1 = COM0A1;
            static constexpr auto _COMB0 = COM0B0;
            static constexpr auto _COMB1 = COM0B1;
            static constexpr auto _WGM0 = WGM00;
            static constexpr auto _WGM1 = WGM01;
            
            static constexpr auto _WGM2 = WGM02;
            static constexpr auto _WGM3 = nullptr;
            static constexpr auto _CS0 = CS00;
            static constexpr auto _CS1 = CS01;
            static constexpr auto _CS2 = CS02;
            static constexpr auto _FOCA = FOC0A;
            static constexpr auto _FOCB = FOC0B;
            
            static constexpr auto _OCIA = OCIE0A;
            static constexpr auto _OCIB = OCIE0B;
            static constexpr auto _TOI = TOIE0;
            
            static constexpr auto _EXCLK = nullptr;
            static constexpr auto _AS = nullptr;
            static constexpr auto _CNTUB = nullptr;
            static constexpr auto _OCAUB = nullptr;
            static constexpr auto _OCBUB = nullptr;
            static constexpr auto _CRAUB = nullptr;
            static constexpr auto _CRBUB = nullptr;
            
            static constexpr auto _TSM = TSM;
            static constexpr auto _PRASY = nullptr;
            static constexpr auto _PRSYNC = PSRSYNC;
        };
#endif /* __HAVE_TIMER0_8BITS__*/
        
#ifdef __HAVE_TIMER1_16BITS_EXTCLK__
        struct Timer1 final {
            using WGM_Type = TimerOperationModeExtended;
            using Prescaler_Type = TimerPrescaler_EXT;
            
            using OCM_Type = decltype(AVRIO::OCR1A_16)::Value_Type;
            using TimerCount_Type = decltype(AVRIO::TCNT1_16)::Value_Type;
            using TIMSKValue_Type = decltype(AVRIO::TIMSK1)::Value_Type;
            
            static constexpr auto& _CRA = AVRIO::TCCR1A;
            static constexpr auto& _CRB = AVRIO::TCCR1B;
            static constexpr auto& _CRC = AVRIO::TCCR1C;
            static constexpr auto& _CNT = AVRIO::TCNT1_16;
            static constexpr auto& _OCA = AVRIO::OCR1A_16;
            static constexpr auto& _OCB = AVRIO::OCR1B_16;
            static constexpr auto& _IM = AVRIO::TIMSK1;
            static constexpr auto& _IF = AVRIO::TIFR1;
            static constexpr auto& _ICR = AVRIO::ICR1_16;
            static constexpr auto _ASY = nullptr;
            static constexpr auto& _GCR = AVRIO::GTCCR;
            
            static constexpr auto& _FOC_R = AVRIO::TCCR1C;
            
            static constexpr auto _COMA0 = COM1A0;
            static constexpr auto _COMA1 = COM1A1;
            static constexpr auto _COMB0 = COM1B0;
            static constexpr auto _COMB1 = COM1B1;
            static constexpr auto _WGM0 = WGM10;
            static constexpr auto _WGM1 = WGM11;
            
            static constexpr auto _WGM2 = WGM12;
            static constexpr auto _WGM3 = WGM13;
            static constexpr auto _CS0 = CS10;
            static constexpr auto _CS1 = CS11;
            static constexpr auto _CS2 = CS12;
            static constexpr auto _ICES = ICES1;
            static constexpr auto _ICNC = ICNC1;
            
            static constexpr auto _FOCA = FOC1A;
            static constexpr auto _FOCB = FOC1B;
            
            static constexpr auto _OCIA = OCIE1A;
            static constexpr auto _OCIB = OCIE1B;
            static constexpr auto _TOI = TOIE1;
            static constexpr auto _ICI = ICIE1;
            
            static constexpr auto _EXCLK = nullptr;
            static constexpr auto _AS = nullptr;
            static constexpr auto _CNTUB = nullptr;
            static constexpr auto _OCAUB = nullptr;
            static constexpr auto _OCBUB = nullptr;
            static constexpr auto _CRAUB = nullptr;
            static constexpr auto _CRBUB = nullptr;
            
            static constexpr auto _TSM = TSM;
            static constexpr auto _PRASY = nullptr;
            static constexpr auto _PRSYNC = PSRSYNC;
        };
#endif /* __HAVE_TIMER1_16BITS_EXTCLK__ */
        
#ifdef __HAVE_TIMER2_8BITS_ASY__
        struct Timer2 final {
            using WGM_Type = TimerOperationMode;
            using Prescaler_Type = TimerPrescaler;
            
            using OCM_Type = decltype(AVRIO::OCR2A)::Value_Type;
            using TimerCount_Type = decltype(AVRIO::TCNT2)::Value_Type;
            using TIMSKValue_Type = decltype(AVRIO::TIMSK2)::Value_Type;
            
            static constexpr auto& _CRA = AVRIO::TCCR2A;
            static constexpr auto& _CRB = AVRIO::TCCR2B;
            static constexpr auto& _CNT = AVRIO::TCNT2;
            static constexpr auto& _OCA = AVRIO::OCR2A;
            static constexpr auto& _OCB = AVRIO::OCR2B;
            static constexpr auto& _IM = AVRIO::TIMSK2;
            static constexpr auto& _IF = AVRIO::TIFR2;
            static constexpr auto _ICR = nullptr;
            static constexpr auto& _ASY = AVRIO::ASSR;
            static constexpr auto _GCR = AVRIO::GTCCR;
            
            static constexpr auto& _FOC_R = AVRIO::TCCR2B;
            
            static constexpr auto _COMA0 = COM2A0;
            static constexpr auto _COMA1 = COM2A1;
            static constexpr auto _COMB0 = COM2B0;
            static constexpr auto _COMB1 = COM2B1;
            static constexpr auto _WGM0 = WGM20;
            static constexpr auto _WGM1 = WGM21;
            
            static constexpr auto _WGM2 = WGM22;
            static constexpr auto _WGM3 = nullptr;
            static constexpr auto _CS0 = CS20;
            static constexpr auto _CS1 = CS21;
            static constexpr auto _CS2 = CS22;
            static constexpr auto _FOCA = FOC2A;
            static constexpr auto _FOCB = FOC2B;
            
            static constexpr auto _OCIA = OCIE2A;
            static constexpr auto _OCIB = OCIE2B;
            static constexpr auto _TOI = TOIE2;
            
            static constexpr auto _EXCLK = EXCLK;
            static constexpr auto _AS = AS2;
            static constexpr auto _CNTUB = TCN2UB;
            static constexpr auto _OCAUB = OCR2AUB;
            static constexpr auto _OCBUB = OCR2BUB;
            static constexpr auto _CRAUB = TCR2AUB;
            static constexpr auto _CRBUB = TCR2AUB;
            
            static constexpr auto _TSM = TSM;
            static constexpr auto _PRASY = PSRASY;
            static constexpr auto _PRSYNC = nullptr;
        };
#endif /* __HAVE_TIMER2_8BITS_ASY__ */
        
    } /* -- Modules */
    
    
    template <class M>
    class Timer final {
    public:
        Timer() = default;
        Timer(Timer&) = delete;
        
        
        void SetOperationMode(TimerOperationModeExtended const InMode) const {
            static_assert(std::Is_Same<typename M::WGM_Type, TimerOperationModeExtended>::Value, "Operation type 'LibTimer::TimerOperationModeExtended' invalid for this module");
            
            int const Value = static_cast<uint8_t const>(InMode);
            
            if ((Value & 0b0001) != 0)
                M::_CRA.SetBit(M::_WGM0);
            else
                M::_CRA.ClearBit(M::_WGM0);
            
            if ((Value & 0b0010) != 0)
                M::_CRA.SetBit(M::_WGM1);
            else
                M::_CRA.ClearBit(M::_WGM1);
            
            if ((Value & 0b0100) != 0)
                M::_CRB.SetBit(M::_WGM2);
            else
                M::_CRB.ClearBit(M::_WGM2);
            
            if ((Value & 0b1000) != 0)
                M::_CRB.SetBit(M::_WGM3);
            else
                M::_CRB.ClearBit(M::_WGM3);
        }
        void SetOperationMode(TimerOperationMode const InMode) const {
            static_assert(std::Is_Same<typename M::WGM_Type, TimerOperationMode>::Value, "Operation type 'LibTimer::TimerOperationMode' invalid for this module");
            
            int const Value = static_cast<uint8_t const>(InMode);
            
            if ((Value & 0b0001) != 0) {
                M::_CRA.SetBit(M::_WGM0);
            } else {
                M::_CRA.ClearBit(M::_WGM0);
            }
            if ((Value & 0b0010) != 0){
                M::_CRA.SetBit(M::_WGM1);
            } else {
                M::_CRA.ClearBit(M::_WGM1);
            }
            if ((Value & 0b0100) != 0){
                M::_CRB.SetBit(M::_WGM2);
            } else {
                M::_CRB.ClearBit(M::_WGM2);
            }
        }
        
        template <OCMModule OCM = OCMModule::A>
        void SetCompareMatchOutputMode(CompareOutputMode const InMode) const {
            constexpr auto COM0 = (OCM == OCMModule::A) ? M::_COMA0 : M::_COMB0;
            constexpr auto COM1 = (OCM == OCMModule::A) ? M::_COMA1 : M::_COMB1;
            
            switch (InMode) {
                case CompareOutputMode::Disconnected: {
                    M::_CRA.ClearBits(COM0, COM1);
                    break;
                }
                case CompareOutputMode::Toggle: {
                    M::_CRA.SetBit(COM0);
                    M::_CRA.ClearBit(COM1);
                    break;
                }
                case CompareOutputMode::Clear: {
                    M::_CRA.ClearBit(COM0);
                    M::_CRA.SetBit(COM1);
                    break;
                }
                case CompareOutputMode::Set: {
                    M::_CRA.SetBits(COM0, COM1);
                    break;
                }
                default:
                    break;
            }
            
        }
        
        template <OCMModule OCM = OCMModule::A>
        void SetCompareMatchValue(typename M::OCM_Type InValue) const {
            if (OCM == OCMModule::A)
                M::_OCA = InValue;
            else if (OCM == OCMModule::B)
                M::_OCB = InValue;
        }
        template <OCMModule OCM = OCMModule::A>
        void SetCompareMatchValue(int const InValue) const {
            if (OCM == OCMModule::A)
                M::_OCA = (typename M::OCM_Type)(InValue);
            else if (OCM == OCMModule::B)
                M::_OCB = (typename M::OCM_Type)(InValue);
        }
        
        void SetCount(typename M::TimerCount_Type InCount) const {
            M::_CNT = InCount;
        }
        void SetCount(int const InCount) {
            M::_CNT = (typename M::TimerCount_Type)(InCount);
        }
        
        void SetPrescaler(TimerPrescaler_EXT const InScaler) const {
            static_assert(std::Is_Same<typename M::Prescaler_Type, TimerPrescaler_EXT>::Value, "Prescaler type 'LibTimer::TimerPrescaler_EXT' invalid for this module");
            
            switch (InScaler) {
                case TimerPrescaler_EXT::Disabled: {
                    M::_CRB.ClearBits(M::_CS0, M::_CS1, M::_CS2);
                    break;
                }
                case TimerPrescaler_EXT::OSCDiv_1: {
                    M::_CRB.SetBits(M::_CS0);
                    M::_CRB.ClearBits(M::_CS1, M::_CS2);
                    break;
                }
                case TimerPrescaler_EXT::OSCDiv_8: {
                    M::_CRB.SetBits(M::_CS1);
                    M::_CRB.ClearBits(M::_CS0, M::_CS2);
                    break;
                }
                case TimerPrescaler_EXT::OSCDiv_64: {
                    M::_CRB.SetBits(M::_CS0, M::_CS1);
                    M::_CRB.ClearBits(M::_CS2);
                    break;
                }
                case TimerPrescaler_EXT::OSCDiv_256: {
                    M::_CRB.SetBits(M::_CS2);
                    M::_CRB.ClearBits(M::_CS0, M::_CS1);
                    break;
                }
                case TimerPrescaler_EXT::OSCDiv_1024: {
                    M::_CRB.SetBits(M::_CS2, M::_CS0);
                    M::_CRB.ClearBits(M::_CS1);
                    break;
                }
                case TimerPrescaler_EXT::EXTT0Falling: {
                    M::_CRB.SetBits(M::_CS2, M::_CS1);
                    M::_CRB.ClearBits(M::_CS0);
                    break;
                }
                case TimerPrescaler_EXT::EXTT0Rising: {
                    M::_CRB.SetBits(M::_CS2, M::_CS1, M::_CS0);
                    break;
                }
                default:
                    break;
            }
        }
        void SetPrescaler(TimerPrescaler const InScaler) const {
            static_assert(std::Is_Same<typename M::Prescaler_Type, TimerPrescaler>::Value, "Prescaler type 'LibTimer::TimerPrescaler' invalid for this module");
            
            uint8_t const Value = static_cast<uint8_t const>(InScaler);
            
            if ((Value & 0b001) != 0) {
                M::_CRB.SetBit(M::_CS0);
            } else {
                M::_CRB.ClearBit(M::_CS0);
            }
            
            if ((Value & 0b010) != 0) {
                M::_CRB.SetBit(M::_CS1);
            } else {
                M::_CRB.ClearBit(M::_CS1);
            }
            
            if ((Value & 0b100) != 0) {
                M::_CRB.SetBit(M::_CS2);
            } else {
                M::_CRB.ClearBit(M::_CS2);
            }
        }
        
        void SetInputCaptureEdge(ICEdge const InEdge) const {
            static_assert(std::Is_Same<typename M::_ICR, std::nullptr_t>::Value == false, "Timer module does not possess an Input Capture unit");
            
            if (InEdge == ICEdge::Falling)
                M::_CRB.ClearBit(M::_ICES);
            else
                M::_CRB.SetBit(M::_ICES);
        }
        
        
        void EnableInputCaptureNoiseCanceler(bool const Enable) const {
            static_assert(std::Is_Same<typename M::_ICR, std::nullptr_t>::Value == false, "Timer module does not possess an Input Capture unit");
            
            if (Enable == true)
                M::_CRB.SetBit(M::_ICNC);
            else
                M::_CRB.ClearBit(M::_ICNC);
        }
        
        void EnableExtClk(bool const Enable) const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            if (Enable == true)
                M::_ASY.SetBit(M::_EXCLK);
            else
                M::_ASY.ClearBit(M::_EXCLK);
        }
        
        void EnableAsyncronousOperation(bool const Enable) const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            if (Enable == true)
                M::_ASY.SetBit(M::_AS);
            else
                M::_ASY.ClearBit(M::_AS);
        }
        
        void EnableTimerSyncMode(bool const Enable) const {
            if (Enable == true)
                M::_GCR.SetBit(M::_TSM);
            else
                M::_GCR.ClearBit(M::_TSM);
        }
        
        void EnableSyncPrescalerReset() const {
            static_assert(std::Is_Same<_PRSYNC, std::nullptr_t>::Value == false, "Timer module does not support syncronous prescaler reset");
            
            M::_GCR.SetBit(M::_PRSYNC);
            // Cleared by hardware...
        }
        
        void EnableAsyncPrescalerReset() const {
            static_assert(std::Is_Same<_PRASY, std::nullptr_t>::Value == false, "Timer module does not support asyncronous prescaler reset");
            
            M::_GCR.SetBit(M::_PRASY);
            // Cleared by hardware...
        }
        
        template <typename... Bits>
        void EnableInterrupts(Bits... InBits) const {
            M::_IM.SetBits(InBits...);
        }
        
        template <typename... Bits>
        void DisableInterrupts(Bits... InBits) const {
            M::_IM.ClearBits(InBits...);
        }
        
        
        bool IsCountUpdateBusy() const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            return M::_ASY.IsBitSet(M::_CNTUB);
        }
        
        template <OCMModule OCM = OCMModule::A>
        bool IsOutputCompareUpdateBusy() const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            constexpr auto Bit = (OCM == OCMModule::A) ? M::_OCAUB : M::_OCBUB;
            
            return M::_ASY.IsBitSet(Bit);
        }
        
        bool IsControlRegisterAUpdateBusy() const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            return M::_ASY.IsBitSet(M::_CRAUB);
        }
        
        bool IsControlRegisterBUpdateBusy() const {
            static_assert(std::Is_Same<typename M::_ASY, std::nullptr_t>::Value, "Timer module does not support ayncronous operation");
            
            return M::_ASY.IsBitSet(M::_CRBUB);
        }
        
        
        template <OCMModule OCM = OCMModule::A>
        void DoForceOutputCompare() const {
            constexpr auto FOC = (OCM == OCMModule::A) ? M::_FOCA : M::_FOCB;
            
            M::_FOC_R.SetBit(FOC);
        }
    };
    
} /* -- LibTimer */


#endif /* LibTimer_hpp */
