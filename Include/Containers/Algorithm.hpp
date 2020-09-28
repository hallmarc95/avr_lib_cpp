//
//  Algorithm.hpp
//
//  Created by Marcus Hall on 9/27/20.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp


namespace std {

template <class InItr1, class InItr2>
bool lexicographical_compare(InItr1 First1, InItr1 Last1, InItr2 First2, InItr2 Last2) {
    for (; (First1 != Last1) && (First2 != Last2); ++First1, (void)++First2) {
        if (*First1 < *First2) return true;
        if (*First2 < *First1) return false;
    }
    return (First1 == Last1) && (First2 != Last2);
}

}


#endif /* Algorithm_hpp */
