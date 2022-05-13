#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "utility.hpp"

namespace ft {
    template <class IteratorType>
    class reverse_iterator {
        public:
            typedef IteratorType                                                     iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type          value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type     difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer             pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference           reference;
        private:
            iterator_type   _ittype;
        public:
            reverse_iterator() : _ittype() {}
            explicit reverse_iterator(iterator_type it) : _ittype(it) {}
            template <class U>
            reverse_iterator(const reverse_iterator<U>& other) : _ittype(other.base()) {}
            ~reverse_iterator() {}
            reverse_iterator& operator=(const reverse_iterator& other )
            {
                this->_ittype = other._ittype;
                return (*this);    
            }
            reverse_iterator& operator+=(difference_type n)
            {
                _ittype -= n;
                return (*this);
            }
            reverse_iterator& operator-=(difference_type n)
            {
                 _ittype += n;
                return (*this);
            }
            reverse_iterator& operator++()
            {
                --_ittype;
                return (*this);
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator temp = *this;
                ++(*this);
                return (temp);
            }
            reverse_iterator& operator--()
            {
                ++_ittype;
                return (*this);
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator temp = *this;
                --(*this);
                return (temp);
            }
            reverse_iterator operator+ (difference_type n) const
            {
                return (reverse_iterator(_ittype - n));
            }
            reverse_iterator operator- (difference_type n) const
            {
                return (reverse_iterator(_ittype + n));
            }
            reference operator*() const
            {
                iterator_type tmp = _ittype;
                return (*(--tmp));
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reference operator[] (difference_type n) const
            {
                return (this->base()[-n - 1]);
            }
            iterator_type base() const
            {
                return (_ittype);
            }
    };
    template< class Iterator1, class Iterator2 >
    bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template< class Iter >
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return (reverse_iterator<Iter>(it.base() - n));
    }
    template< class Iterator1, class Iterator2 >
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}

#endif