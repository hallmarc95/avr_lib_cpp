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
    
    constexpr BitOffset PB5 = 5;
    
    static LibAVR::AVRReg<0x24> DDRB;
    static LibAVR::AVRReg<0x25> PORTB;
}


#endif /* AVRIO_h */
