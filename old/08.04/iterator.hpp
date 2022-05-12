#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template<class Iterator>
    class iterator {
        public:
            typedef Iterator                                                         iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type          value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type     difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer             pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference           reference;
        protected:
            iterator_type _ittype;
        public:
            iterator() : _ittype() {}
            iterator(iterator_type it) : _ittype(it) {}
            template <class U>
            iterator(const iterator<U>& other) : _ittype(other.base()) {}
            ~iterator() {}
            bool operator== (const iterator& other)
            {
                return (_ittype == other._ittype);
            }
            bool operator!= (const iterator& other)
            {
                return (_ittype != other._ittype);
            }
            bool operator> (const iterator& other)
            {
                return (_ittype > other._ittype);
            }
            bool operator>= (const iterator& other)
            {
                return (_ittype >= other._ittype);
            }
            bool operator< (const iterator& other)
            {
                return (_ittype < other._ittype);
            }
            bool operator<= (const iterator& other)
            {
                return (_ittype <= other._ittype);
            }
            iterator& operator= (const iterator& it) //++++++++
            {
                this->_ittype = it._ittype;
                return (*this);
            }
            iterator& operator+= (difference_type mov) //++++++++
            {
                _ittype += mov;
                return (*this);
            }
            iterator& operator-= (difference_type mov) //+++++++
            {
                _ittype += -mov;
                return (*this);
            }
            iterator& operator++ () //++++
            {
                ++_ittype;
                return (*this);
            }
            iterator operator++ (int) //++++++++
            {
                iterator temp = *this;
                ++(*this);
                return (temp);
            }
            iterator& operator-- () //++++++++
            {
                --_ittype;
                return (*this);
            }
            iterator operator--(int) //++++++++
            {
                iterator temp = *this;
                --(*this);
                return (temp);
            }
            iterator operator+ (difference_type mov) const///+++++++
            {
                return (iterator(_ittype + mov));
            }
            iterator operator- (difference_type mov) const//+++++
            {
                return (iterator(_ittype + (-mov)));
            }
            reference operator* ()  const //++++
            {
                return (*_ittype);
            }
            pointer operator->() //++++
            {
                return (_ittype);
            }
            reference operator[] (difference_type n) const //+++++++
            {   
                return (*(*this + n));
            }
            iterator_type base() const
            {
                return (_ittype);
            }
    };

    template <class Iterator>
    bool operator== (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<  (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator<= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    bool operator>  (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator>= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    iterator<Iterator> operator+ (typename iterator<Iterator>::difference_type n, const iterator<Iterator>& rev_it)
    {
        return (iterator<Iterator>(rev_it._ittype.base() - n));
    }
    template <class Iterator>
    typename iterator<Iterator>::difference_type operator- (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base());
    }

    // template <class Iter1, class Iter2>
    // bool operator== (const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (x.base() == y.base());
    // }
    // template <class Iter1, class Iter2>
    // bool operator< (const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (x.base() < y.base());
    // }
    // template <class Iter1, class Iter2>
    // bool operator!= (const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (!(x == y));
    // }
    // template <class Iter1, class Iter2>
    // bool operator> (const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (x > y);
    // }
    // template <class Iter1, class Iter2>
    // bool operator>= (const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (!(x < y));
    // }
    // template <class Iter1, class Iter2>
    // bool operator<=(const iterator<Iter1>& x, const iterator<Iter2>& y)
    // {
    //     return (!(x > y));
    // }

    // template <class Iter>
    // bool operator!= (const iterator<Iter>& x, const iterator<Iter>& y)
    // {
    //     return (!(x == y));
    // }
    // template <class Iter>
    // bool operator> (const iterator<Iter>& x, const iterator<Iter>& y)
    // {
    //     return (x > y);
    // }
    // template <class Iter>
    // bool operator>= (const iterator<Iter>& x, const iterator<Iter>& y)
    // {
    //     return (!(x < y));
    // }
    // template <class Iter>
    // bool operator<= (const iterator<Iter>& x, const iterator<Iter>& y)
    // {
    //     return (!(x > y));
    // }
}


#endif