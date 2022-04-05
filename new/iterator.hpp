#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template<class Iterator>
    class iterator {
        public:
            // typedef Iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<Iterator *>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<Iterator *>::value_type          value_type;
            typedef typename ft::iterator_traits<Iterator *>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator *>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator *>::reference           reference;
        private:
            pointer point;
        public:
            iterator() : point() {}
            iterator(pointer it) : point(it) {}
            iterator(const iterator<Iterator>& other)
            {
                *this = other;
            }
            ~iterator() {}
            bool operator== (const iterator<Iterator>& other)
            {
                return (point == other.point);
            }
            bool operator!= (const iterator<Iterator>& other)
            {
                return (point != other.point);
            }
            bool operator> (const iterator<Iterator>& other)
            {
                return (point > other.point);
            }
            bool operator>= (const iterator<Iterator>& other)
            {
                return (point >= other.point);
            }
            bool operator< (const iterator<Iterator>& other)
            {
                return (point < other.point);
            }
            bool operator<= (const iterator<Iterator>& other)
            {
                return (point <= other.point);
            }
            iterator& operator= (const iterator& ptr)
            {
                this->point = ptr.point;
                return (*this);
            }
            iterator& operator= (iterator* it)
            {
                point = it->point;
                return (*this);
            }
            
            iterator& operator+= (const difference_type& mov)
            {
                point += mov;
                return (*this);
            }
            iterator& operator-= (const difference_type& mov)
            {
                point -= mov;
                return (*this);
            }
            iterator& operator++ ()
            {
                ++point;
                return (*this);
            }
            iterator operator++ (int)
            {
                iterator temp = *this;
                ++(*this);
                return (temp);
            }
            iterator& operator-- ()
            {
                --point;
                return (*this);
            }
            iterator operator--(int)
            {
                iterator temp = *this;
                --(*this);
                return (temp);
            }
            iterator operator+ (difference_type mov)
            {
                pointer point_temp = point;
                point += mov;
                iterator temp = *this;
                point = point_temp;
                return (temp);
            }
            iterator operator- (const difference_type& mov)
            {
                pointer point_temp = point;
                point -= mov;
                iterator temp = *this;
                point = point_temp;
                return (temp);
            }
            reference operator* () const
            {
                return (*point);
            }
            pointer operator->()
            {
                return (&point);
            }
            reference operator[] (difference_type n) const
            {   
                return (*(*this + n));
            }
    };
}


#endif