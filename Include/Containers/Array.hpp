//
//  Array.hpp
//
//  Created by Marcus Hall on 9/27/20.
//

#ifndef Array_hpp
#define Array_hpp

#include <CStdDef.h>
#include <Iterator.hpp>
#include <Algorithm.hpp>


namespace std {

template <class T, size_t N>
struct Array {
    struct Iterator {
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;
        using iterator_category = std::random_access_iterator_tag;
        
        pointer Pos;
        
        void swap(Iterator& Other) {
            pointer temp = Pos;
            
            Pos = Other.Pos;
            Other.Pos = temp;
        }
        
        reference operator*() {
            return *Pos;
        }
        Iterator& operator++() {
            ++Pos;
            
            return (*this);
        }
        
        bool operator==(Iterator& Other) {
            return Pos == Other.Pos;
        }
        bool operator!=(Iterator& Other) {
            return Pos != Other.Pos;
        }
        
        Iterator& operator--() {
            --Pos;
            
            return (*this);
        }
        
        Iterator& operator+=(difference_type InValue) {
            Pos += InValue;
            
            return (*this);
        }
        Iterator operator+(difference_type InValue) {
            return Iterator{Pos + InValue};
        }
        Iterator& operator-=(difference_type InValue) {
            Pos -= InValue;
            
            return (*this);
        }
        Iterator operator-(difference_type InValue) {
            return Iterator{Pos - InValue};
        }
        difference_type operator-(Iterator& Other) {
            return Pos - Other.Pos;
        }
        
        reference operator[](difference_type InOffset) {
            return *(Pos + InOffset);
        }
        
        bool operator<(Iterator& Other) {
            return Pos < Other.Pos;
        }
        bool operator>(Iterator& Other) {
            return Pos > Other.Pos;
        }
        bool operator<=(Iterator& Other) {
            return Pos <= Other.Pos;
        }
        bool operator>=(Iterator& Other) {
            return Pos >= Other.Pos;
        }
    };
    
    using value_type = T;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = value_type const&;
    using pointer = value_type*;
    using const_pointer = value_type const*;
    using iterator = Iterator;
    using const_iterator = iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    
    T _arr[N];
    
    Array() = default;
    Array(Array& Other) = default;
    Array(Array&& Other) = default;
    Array& operator=(Array& Other) = default;
    Array& operator=(Array&& Other) = default;
    
    reference at(size_type Pos) {
        if ((Pos < size()) == true) {
            return _arr[Pos];
        } else {
            return _arr;
        }
    }
    const_reference at(size_type Pos) const {
        if ((Pos < size()) == true) {
            return _arr[Pos];
        } else {
            return _arr;
        }
    }
    
    reference operator[](size_type Pos) {
        return _arr[Pos];
    }
    const_reference operator[](size_type Pos) const {
        return _arr[Pos];
    }
    
    reference front() {
        return _arr[0];
    }
    const_reference front() const {
        return _arr[0];
    }
    
    reference back() {
        return _arr[max_size() - 1];
    }
    const_reference back() const {
        return _arr[max_size() - 1];
    }
    
    T* data() noexcept {
        if (size() == 0) {
            return nullptr;
        } else {
            return &_arr;
        }
    }
    T const* data() const noexcept {
        if (size() == 0) {
            return nullptr;
        } else {
            return &_arr;
        }
    }
    
    iterator begin() noexcept {
        return iterator{&_arr[0]};
    }
    const_iterator begin() const noexcept {
        return const_iterator{&_arr[0]};
    }
    const_iterator cbegin() const noexcept {
        return const_iterator{&_arr[0]};
    }
    
    iterator end() noexcept {
        return iterator{&_arr[N]};
    }
    const_iterator end() const noexcept {
        return const_iterator{&_arr[N]};
    }
    const_iterator cend() const noexcept {
        return const_iterator{&_arr[N]};
    }
    
    reverse_iterator rbegin() noexcept {
        return reverse_iterator{&_arr[N - 1]};
    }
    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator{&_arr[N - 1]};
    }
    const_reverse_iterator crbegin() const noexcept {
        return const_reverse_iterator{&_arr[N - 1]};
    }
    
    reverse_iterator rend() noexcept {
        return reverse_iterator{&_arr[1]};
    }
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator{&_arr[1]};
    }
    const_reverse_iterator crend() const noexcept {
        return const_reverse_iterator{&_arr[1]};
    }
    
    constexpr bool empty() const noexcept {
        return begin() == end();
    }
    constexpr size_type size() const noexcept {
        return std::distance(begin(), end());
    }
    constexpr size_type max_size() const noexcept {
        return N;
    }
    
    void fill(T const& Value) {
        for (auto& entry : _arr) {
            entry = Value;
        }
    }
    
    void swap(Array& Other) noexcept {
        T temp;
        
        for (size_t i=0; i < size(); i++) {
            temp = _arr[i];
            _arr[i] = Other[i];
            Other[i] = temp;
        }
    }
};

template <class T, size_t N>
typename std::Array<T, N>::iterator operator+(typename std::Array<T, N>::iterator::difference_type InValue, typename std::Array<T, N>::iterator InItr) {
    return InItr + InValue;
}

template <class T, size_t N>
bool operator==(std::Array<T, N> const& lhs, std::Array<T, N> const& rhs) {
    for (size_t i = 0; i < N; i++) {
        if (lhs[i] != rhs[i])
            return false;
    }
    
    return true;
}

template< class T, size_t N >
bool operator!=(std::Array<T,N> const& lhs, std::Array<T,N> const& rhs ) {
    for (size_t i = 0; i < N; i++) {
        if (lhs[i] != rhs[i]) {
            return true;
        }
    }
    
    return false;
}

template< class T, size_t N >
bool operator<(std::Array<T,N> const& lhs, std::Array<T,N> const& rhs ) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) && (lhs != rhs);
}

template< class T, size_t N >
bool operator<=(std::Array<T,N> const& lhs, std::Array<T,N> const& rhs ) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || (lhs == rhs);
}

template< class T, size_t N >
bool operator>(std::Array<T,N> const& lhs, std::Array<T,N> const& rhs ) {
    return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) && (lhs != rhs);
}

template< class T, size_t N >
bool operator>=(std::Array<T,N> const& lhs, std::Array<T,N> const& rhs ) {
    return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || (lhs == rhs);
}

}


#endif /* Array_hpp */
