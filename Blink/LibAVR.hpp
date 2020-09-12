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
    
    template <RegisterAddress A>
    struct AVRReg final {
        RegisterValue operator =(RegisterValue InValue) const { return *_as_reg(A) = InValue; }
        RegisterValue operator |=(RegisterValue InValue) const { return *_as_reg(A) |= InValue; }
        RegisterValue operator &=(RegisterValue InValue) const { return *_as_reg(A) &= InValue; }
        RegisterValue operator ^=(RegisterValue InValue) const { return *_as_reg(A) ^= InValue; }
        RegisterValue operator ~() { return ~(*_as_reg(A)); }
        
        inline operator RegisterValue() const { return *(_as_reg(A)); }
        
        static RegisterValue _operator_assign(RegisterValue InValue) { return *_as_reg(A) = InValue; }
        static RegisterValue _operator_xor_assign(RegisterValue InValue) { return *_as_reg(A) = InValue; }
    };
    
}


#endif /* LibAVR_hpp */
