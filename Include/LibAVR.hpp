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

    using RegisterValue_16 = uint16_t;
    using AddressType_16 = volatile uint16_t*;
    
    
    // Reinterpretation of a numerical value as an address in memory
    constexpr auto _as_reg = [] (RegisterAddress const InAddress) -> AddressType {
        return reinterpret_cast<AddressType>(InAddress);
    };
    constexpr auto _as_reg_16 = [] (RegisterAddress const InAddress) -> AddressType_16 {
        return reinterpret_cast<AddressType_16>(InAddress);
    };
    
    
    struct RegBits_Base {
        constexpr RegBits_Base(RegisterValue const InValue) : Value(InValue) {}
        
        constexpr operator RegisterValue() const { return Value; }
        constexpr RegBits_Base operator ~() const { return ~Value; }
    private:
        RegisterValue const Value;
    };

    struct RegBits_16_Base {
        constexpr RegBits_16_Base(RegisterValue_16 const InValue) : Value(InValue) {}
        
        constexpr operator RegisterValue_16() const { return Value; }
        constexpr RegBits_16_Base operator ~() const { return ~Value; }
    private:
        RegisterValue_16 const Value;
    };
    
    
    
    template <class T, RegisterAddress const A>
    struct AVRReg final {
        typedef T Value_Type;
        static constexpr RegisterAddress Address = A;
        
        constexpr T operator =(T const InValue) const { return T((*_as_reg(A)) = InValue); }
        constexpr T operator |=(T const InValue) const { return T((*_as_reg(A)) |= InValue); }
        constexpr T operator &=(T const InValue) const { return T((*_as_reg(A)) &= InValue); }
        constexpr T operator ^=(T const InValue) const { return T((*_as_reg(A)) ^= InValue); }
        
        constexpr T operator ~() const { return T(~((*_as_reg(A)))); }
        constexpr T operator &(T InValue) const { return T((*_as_reg(A)) & InValue); }
        
        constexpr operator T() const { return T((*_as_reg(A))); }
        
        constexpr T SetBit(T InBit) const {
            return T((*this) |= (1 << InBit));
        }
        
        constexpr T ClearBit(T InBit) const {
            return T((*this) &= ~(1 << InBit));
        }
        
        // SetBits is overloaded for between 1 and 8 bit-index parameters
        constexpr T SetBits(T InBit_first) const { return T((*_as_reg(A)) |= InBit_first); }
        constexpr T SetBits(T InBit_first, T InBit_second) const { return T((*_as_reg(A)) |= ((1 << InBit_first) | (1 << InBit_second))); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third)); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth)); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth)); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth)); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth, T InBit_seventh) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth) | (1 << InBit_seventh)); }
        constexpr T SetBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth, T InBit_seventh, T InBit_eighth) const { return T((*_as_reg(A)) |= (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth) | (1 << InBit_seventh) | (1 << InBit_eighth)); }
        
        // ClearBits is overloaded for between 1 and 8 bit-index parameters
        constexpr T ClearBits(T InBit_first) const { return T((*_as_reg(A)) &= ~( InBit_first) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second) const { return T((*_as_reg(A)) &= ~( ((1 << InBit_first) | (1 << InBit_second))) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third)) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth)) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth)) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth)) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth, T InBit_seventh) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth) | (1 << InBit_seventh)) ); }
        constexpr T ClearBits(T InBit_first, T InBit_second, T InBit_third, T InBit_fourth, T InBit_fifth, T InBit_sixth, T InBit_seventh, T InBit_eighth) const { return T((*_as_reg(A)) &= ~( (1 << InBit_first) | (1 << InBit_second) | (1 << InBit_third) | (1 << InBit_fourth) | (1 << InBit_fifth) | (1 << InBit_sixth) | (1 << InBit_seventh) | (1 << InBit_eighth)) ); }
        
        constexpr bool IsBitSet(T InBit) const {
            return ((*_as_reg(A))) & (1 << InBit);
        }
        
    }; /* -- AVRReg */
    

    template <class T, RegisterAddress const A>
    struct AVRReg_16 final {
        typedef T Value_Type;
        static constexpr RegisterAddress Address = A;
        
        constexpr T operator =(T const InValue) const { return T((*_as_reg_16(A)) = InValue); }
        constexpr T operator |=(T const InValue) const { return T((*_as_reg_16(A)) |= InValue); }
        constexpr T operator &=(T const InValue) const { return T((*_as_reg_16(A)) &= InValue); }
        constexpr T operator ^=(T const InValue) const { return T((*_as_reg_16(A)) ^= InValue); }
        
        constexpr T operator ~() const { return T(~((*_as_reg_16(A)))); }
        constexpr T operator &(T InValue) const { return T((*_as_reg_16(A)) & InValue); }
        
        constexpr operator T() const { return T((*_as_reg_16(A))); }
    }; /* -- AVRReg_16 */
    
}


#endif /* LibAVR_hpp */
