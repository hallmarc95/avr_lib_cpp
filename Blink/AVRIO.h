//
//  AVRIO.h
//
//  Created by Marcus Hall on 9/11/20.
//

#ifndef AVRIO_h
#define AVRIO_h

#include <stdio.h>
#include "LibAVR.hpp"


namespace AVRIO {
    using BitOffset = uint8_t;
    
    template<class T>
    T operator<<(int A, T B) { return T(A << int(B)); }
    
    struct PortB : LibAVR::RegBits_Base {
        explicit PortB(volatile LibAVR::RegisterValue InValue) : LibAVR::RegBits_Base(InValue) {}
    };

    constexpr LibAVR::AVRReg<PortB, 0x24> DDRB;
    constexpr LibAVR::AVRReg<PortB, 0x25> PORTB;
}

#define PB5 AVRIO::PortB(5)


#endif /* AVRIO_h */
