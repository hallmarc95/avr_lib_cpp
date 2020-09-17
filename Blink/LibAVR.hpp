//
//  AVRRegister.hpp
//
//  Created by Marcus Hall on 9/11/20.
//

#ifndef LibAVR_hpp
#define LibAVR_hpp

#include <stdio.h>
//#include <stdarg.h>


namespace LibAVR {

    using RegisterAddress = int;
    using RegisterValue = uint8_t;
    using AddressType = volatile uint8_t*;
    
    
    auto _as_reg = [] (RegisterAddress const InAddress) -> AddressType {
        return reinterpret_cast<AddressType>(InAddress);
    };
    
    
    struct RegBits_Base {
        RegBits_Base(RegisterValue const InValue) : Value(InValue) {}
        RegBits_Base(RegBits_Base const Other) : Value(Other.Value) {}
        operator RegisterValue() const { return Value; }
        RegBits_Base operator ~() const { return ~Value; }
    private:
        uint8_t const Value;
    };
    
    
    
    template <class T, RegisterAddress const A>
    struct AVRReg final {
        typedef T ValueType;
        static constexpr RegisterAddress Address = A;
        
        T operator =(T InValue) const { return T(*_as_reg(A) = InValue); }
        T operator |=(T InValue) const { return T(*_as_reg(A) |= InValue); }
        T operator &=(T InValue) const { return T(*_as_reg(A) &= InValue); }
        T operator ^=(T InValue) const { return T(*_as_reg(A) ^= InValue); }
        
        T operator ~() const { return T(~(*_as_reg(A))); }
        T operator &(T InValue) const { return T(*_as_reg(A) & InValue); }
        
        operator T() const { return T(*_as_reg(A)); }
        
        void SetBit(T InBit) const {
            (*this) |= (1 << InBit);
        }
        
        void ClearBit(T InBit) const {
            (*this) &= ~(1 << InBit);
        }
        
//        void SetBits(... InBits) const;
//
//        void ClearBits(... InBits) const;
        
        bool IsBitSet(T InBit) const {
            return (*_as_reg(A)) & (1 << InBit);
        }
        
    };
    
    
    
    
}


#endif /* LibAVR_hpp */
