//
//  Type_Traits.hpp
//
//  Created by Marcus Hall on 10/3/20.
//  Most definitions ripped from en.cppreference.com
//

#ifndef Type_Traits_hpp
#define Type_Traits_hpp


namespace std {

//https://en.cppreference.com/w/cpp/types/integral_constant
template<class T, T v>
struct Integral_Constant {
    static constexpr T Value = v;
    using Value_Type = T;
    using Type = Integral_Constant; // using injected-class-name
    constexpr operator Value_Type() const noexcept { return Value; }
    constexpr Value_Type operator()() const noexcept { return Value; } //since c++14
};

//https://en.cppreference.com/w/cpp/types/integral_constant
typedef Integral_Constant<bool, true> True_Type;
typedef Integral_Constant<bool, false> False_Type;

//https://en.cppreference.com/w/cpp/types/is_same
template<class T, class U>
struct Is_Same : std::False_Type {};
 
//https://en.cppreference.com/w/cpp/types/is_same
template<class T>
struct Is_Same<T, T> : std::True_Type {};

}

#endif /* Type_Traits_hpp */
