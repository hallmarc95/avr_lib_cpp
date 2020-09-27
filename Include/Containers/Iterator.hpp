//
//  Iterator.h
//
//  Created by Marcus Hall on 9/27/20.
//

#ifndef Iterator_h
#define Iterator_h


namespace std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Itr>
struct iterator_traits {
    using difference_type = typename Itr::difference_type;
    using value_type = typename Itr::value_type;
    using pointer = typename Itr::pointer;
    using reference = typename Itr::reference;
    using iterator_category = typename Itr::iterator_category;
};

template <class Itr>
class reverse_iterator {
public:
    using iterator_type = Itr;
    using iterator_category = typename std::iterator_traits<Itr>::iterator_category;
    using value_type = typename std::iterator_traits<Itr>::value_type;
    using difference_type = typename std::iterator_traits<Itr>::difference_type;
    using pointer = typename std::iterator_traits<Itr>::pointer;
    using reference = typename std::iterator_traits<Itr>::reference;
    
protected:
    iterator_type Current;
    
public:
    reverse_iterator() = default;
    explicit reverse_iterator(iterator_type InItr) : Current(InItr) {};
    template <class U>
    reverse_iterator(reverse_iterator<U> const& Other) : Current(Other.base()) {};
    template <class U>
    reverse_iterator& operator=(reverse_iterator<U> const& Other) {
        Current = Other.base();
        
        return (*this);
    }
    
    iterator_type base() const {
        return Current;
    }
    
    reference operator*() {
        return *(Current - 1);
    }
    pointer operator->() {
        return *(Current - 1);
    }
    
    reference operator[](difference_type InOffset) {
        return base()[InOffset - 1];
    }
    
    reverse_iterator& operator++() {
        --Current;
        
        return (*this);
    }
    reverse_iterator& operator--() {
        ++Current;
        
        return (*this);
    }
    reverse_iterator operator++(int) {
        Current--;
        
        return (*this);
    }
    reverse_iterator operator--(int) {
        Current++;
        
        return (*this);
    }
    
    reverse_iterator operator+(difference_type InValue) const {
        return reverse_iterator{base() - InValue};
    }
    reverse_iterator operator-(difference_type InValue) const {
        return reverse_iterator{base() + InValue};
    }
    
    reverse_iterator& operator+=(difference_type InValue) {
        Current -= InValue;
        
        return (*this);
    }
    reverse_iterator& operator-=(difference_type InValue) {
        Current += InValue;
        
        return (*this);
    }
};


template <class Itr1, class Itr2>
bool operator==(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() == rhs.base();
}
template <class Itr1, class Itr2>
bool operator!=(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() != rhs.base();
}
template <class Itr1, class Itr2>
bool operator<(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() < rhs.base();
}
template <class Itr1, class Itr2>
bool operator>(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() > rhs.base();
}
template <class Itr1, class Itr2>
bool operator<=(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() <= rhs.base();
}
template <class Itr1, class Itr2>
bool operator>=(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) {
    return lhs.base() >= rhs.base();
}

template <class Itr>
reverse_iterator<Itr> operator+(typename reverse_iterator<Itr>::difference_type, reverse_iterator<Itr> const& InItr) {
    return reverse_iterator<Itr>{InItr.base() - 1};
}
template <class Itr1, class Itr2>
auto operator-(reverse_iterator<Itr1> const& lhs, reverse_iterator<Itr2> const& rhs) -> decltype(rhs.base() - lhs.base()) {
    return rhs.base() - lhs.base();
}


namespace detail {

template <class InputIt>
typename std::iterator_traits<InputIt>::difference_type __distance(InputIt first, InputIt last, std::input_iterator_tag) {
    typename std::iterator_traits<InputIt>::difference_type result = 0;
    while (first != last) {
        ++first;
        ++result;
    }
    
    return result;
}

template <class InputIt>
typename std::iterator_traits<InputIt>::difference_type __distance(InputIt first, InputIt last, std::random_access_iterator_tag) {
    return last - first;
}

}

template <class InputIt>
typename std::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
    return std::detail::__distance(first, last, typename std::iterator_traits<InputIt>::iterator_category());
}
    
}


#endif /* Iterator_h */
