//
//  AVRRegister.hpp
//
//  Created by Marcus Hall on 9/11/20.
//

#ifndef LibAVR_hpp
#define LibAVR_hpp

#include <stdio.h>


namespace LibAVR {

    using RegisterAddress = int;
    using RegisterValue = uint8_t;
    using AddressType = volatile uint8_t*;
    
    auto _as_reg = [] (RegisterAddress const InAddress) -> AddressType {
        return reinterpret_cast<AddressType>(InAddress);
    };
    
    struct RegBits_Base {
        RegBits_Base(RegisterValue const InValue) : Value(InValue) {}
        operator RegisterValue() const { return Value; }
    private:
        uint8_t const Value;
    };
    
    template <class T, RegisterAddress A>
    struct AVRReg final {
        T operator =(T InValue) const { return T(*_as_reg(A) = InValue); }
        T operator |=(T InValue) const { return T(*_as_reg(A) |= InValue); }
        T operator &=(T InValue) const { return T(*_as_reg(A) &= InValue); }
        T operator ^=(T InValue) const { return T(*_as_reg(A) ^= InValue); }
        T operator ~() const { return T(~(*_as_reg(A))); }
        
        inline operator T() const { return T(*_as_reg(A)); }
    };
    
}


#endif /* LibAVR_hpp */
