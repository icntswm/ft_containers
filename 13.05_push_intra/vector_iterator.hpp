#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "utility.hpp"

namespace ft {
    template<class IteratorType>
    class vector_iterator {
        public:
            typedef IteratorType                                                     iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type          value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type     difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer             pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference           reference;
        private:
            iterator_type _ittype;
        public:
            vector_iterator() : _ittype() {}
            vector_iterator(iterator_type it) : _ittype(it) {}
            template <class U>
            vector_iterator(const vector_iterator<U>& other) : _ittype(other.base()) {}
            ~vector_iterator() {}
            vector_iterator& operator= (const vector_iterator& it)
            {
                this->_ittype = it._ittype;
                return (*this);
            }
            vector_iterator& operator+= (difference_type mov)
            {
                _ittype += mov;
                return (*this);
            }
            vector_iterator& operator-= (difference_type mov)
            {
                _ittype += -mov;
                return (*this);
            }
            vector_iterator& operator++ ()
            {
                ++_ittype;
                return (*this);
            }
            vector_iterator operator++ (int)
            {
                vector_iterator temp = *this;
                ++(*this);
                return (temp);
            }
            vector_iterator& operator-- ()
            {
                --_ittype;
                return (*this);
            }
            vector_iterator operator--(int)
            {
                vector_iterator temp = *this;
                --(*this);
                return (temp);
            }
            vector_iterator operator+ (difference_type mov) const
            {
                return (vector_iterator(_ittype + mov));
            }
            vector_iterator operator- (difference_type mov) const
            {
                return (vector_iterator(_ittype + (-mov)));
            }
            reference operator* ()  const 
            {
                return (*_ittype);
            }
            pointer operator->()
            {
                return (_ittype);
            }
            reference operator[] (difference_type n) const
            {   
                return (*(*this + n));
            }
            iterator_type base() const
            {
                return (_ittype);
            }
    };
    template <class Iterator1, class Iterator2>
    bool operator== (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator< (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator!= (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class Iterator1, class Iterator2>
    bool operator> (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (lhs > rhs);
    }
    template <class Iterator1, class Iterator2>
    bool operator>= (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class Iterator1, class Iterator2>
    bool operator<= (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (!(lhs > rhs));
    }
    template <class Iterator>
    bool operator!= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class Iterator>
    bool operator> (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (lhs > rhs);
    }
    template <class Iterator>
    bool operator>= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class Iterator>
    bool operator<= (const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs)
    {
        return (!(lhs > rhs));
    }
    template <class Iterator>
    vector_iterator<Iterator> operator+ (typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& rev_it)
    {
        return (vector_iterator<Iterator>(rev_it.base() + n));
    }
    template <class Iterator1, class Iterator2>
    typename vector_iterator<Iterator1>::difference_type operator- (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs)
    {
        return (lhs.base() - rhs.base());
    }
}


#endif