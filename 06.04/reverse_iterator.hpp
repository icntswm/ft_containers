#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {
//     template< class Iter, class category = typename iterator_traits<Iter>::iterator_category>
//     class reverse_iterator
//     {
//         public:
//             typedef	Iter 	iterator_type;
//             typedef	typename iterator_traits<Iter>::iterator_category	iterator_category;
//             typedef	typename iterator_traits<Iter>::value_type			value_type;
//             typedef	typename iterator_traits<Iter>::difference_type		difference_type;
//             typedef	typename iterator_traits<Iter>::pointer				pointer;
//             typedef	typename iterator_traits<Iter>::reference			reference;

//             reverse_iterator() : __iter() {}

//             explicit reverse_iterator (iterator_type it) :
//                         __iter(it) {}
            
//             reverse_iterator(const reverse_iterator & other) :
//                         __iter(other.__iter) {}
            

//             ~reverse_iterator() {}

//             iterator_type base() const
//             { return (__iter); }

//             reference operator*() const
//             {
//                 iterator_type tmp = __iter;
//                 return (*(--tmp));
//             }

//             reverse_iterator& operator++()
//             {
//                 --__iter;
//                 return (*this);
//             }
            
//             reverse_iterator operator++(int)
//             {
//                 reverse_iterator tmp = *this;
//                 ++(*this);
//                 return (tmp);
//             }

//             reverse_iterator& operator--()
//             {
//                 ++__iter;
//                 return (*this);
//             }

//             reverse_iterator operator--(int)
//             {
//                 reverse_iterator tmp = *this;
//                 --(*this);
//                 return (tmp);
//             }
            
//             pointer operator->() const { return &(operator*()); }
            
//             friend	bool operator==(reverse_iterator lhs, reverse_iterator rhs)
//             { return lhs.__iter == rhs.__iter; }
            
//             friend	bool operator!=(reverse_iterator lhs, reverse_iterator rhs)
//             { return lhs.__iter != rhs.__iter; }

//         private:
//             iterator_type	__iter;
//     };

//     template< class Iter>
//     class reverse_iterator
//     {
//         public:
//             typedef	Iter 	iterator_type;
//             typedef	typename iterator_traits<Iter>::iterator_category	iterator_category;
//             typedef	typename iterator_traits<Iter>::value_type			value_type;
//             typedef	typename iterator_traits<Iter>::difference_type		difference_type;
//             typedef	typename iterator_traits<Iter>::pointer				pointer;
//             typedef	typename iterator_traits<Iter>::reference			reference;

//             reverse_iterator() : __iter() {}

//             explicit reverse_iterator (iterator_type it) :
//                         __iter(it) {}
            
//             reverse_iterator(const reverse_iterator & other) :
//                         __iter(other.__iter) {}
            
//             ~reverse_iterator() {}

//             reverse_iterator& operator+= (difference_type n)
//             {
//                 __iter -= n;
//                 return (*this);
//             }
            
//             reverse_iterator& operator-= (difference_type n)
//             {
//                 __iter += n;
//                 return (*this);
//             }

//             reverse_iterator& operator++()
//             {
//                 --__iter;
//                 return (*this);
//             }
            
//             reverse_iterator operator++(int)
//             {
//                 reverse_iterator tmp = *this;
//                 ++(*this);
//                 return (tmp);
//             }
//             reverse_iterator& operator--()
//             {
//                 ++__iter;
//                 return (*this);
//             }

//             reverse_iterator operator--(int)
//             {
//                 reverse_iterator tmp = *this;
//                 --(*this);
//                 return (tmp);
//             }
//             reverse_iterator operator+ (difference_type n) const
//             { return (reverse_iterator(__iter - n)); }


//             reverse_iterator operator- (difference_type n)
//             { return (reverse_iterator(__iter + n)); }
//             reference operator*() const
//             {
//                 iterator_type tmp = __iter;
//                 return (*(--tmp));
//             }
//             pointer operator->() const { return &(operator*()); }
            
//             reference operator[] (difference_type n) const
//             { return (this->base()[-n - 1]); }
            
//             iterator_type base() const
//             { return (__iter); }

//             friend	bool operator==(reverse_iterator lhs, reverse_iterator rhs)
//             { return lhs.__iter == rhs.__iter; }
            
//             friend	bool operator!=(reverse_iterator lhs, reverse_iterator rhs)
//             { return lhs.__iter != rhs.__iter; }
//         private:
//             iterator_type	__iter;
//         };
// }









    template <class Iterator>
    class reverse_iterator {
        public:
            typedef Iterator                                                iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator>::reference           reference;
        private:
            iterator_type   _ittype;
        public:
            reverse_iterator() : _ittype() {}
            explicit reverse_iterator (iterator_type it) : _ittype(it) {}
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _ittype(rev_it._ittype) {}
            ~reverse_iterator() {} //?????
            
            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other )
            {
                this->_ittype = other._ittype;
                return (*this);    
            }//??????????????????????
            
            reverse_iterator& operator+= (difference_type n)
            {
                _ittype -= n;//-=
                return (*this);
            }
            reverse_iterator& operator-= (difference_type n)
            {
                 _ittype += n;//+=
                return (*this);
            }
            reverse_iterator& operator++()
            {
                --_ittype; //--
                return (*this);
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator temp = *this;
                ++(*this); //--
                return (temp);
            }
            reverse_iterator& operator--()
            {
                ++_ittype;//++
                return (*this);
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator temp = *this;
                --(*this);//++
                return (temp);
            }
            reverse_iterator operator+ (difference_type n) const
            {
                return (reverse_iterator(_ittype - n));
            }
            reverse_iterator operator- (difference_type n)
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
                return (this->base()[- n - 1]);
            }

            iterator_type base() const
            {
                return (_ittype);
            }
            friend	bool operator==(reverse_iterator lhs, reverse_iterator rhs)
            { return lhs._ittype == rhs._ittype; }
            
            friend	bool operator!=(reverse_iterator lhs, reverse_iterator rhs)
            { return lhs._ittype != rhs._ittype; }
    };
    // template <class Iterator>
    // bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() == rhs.base());
    // }
    // template <class Iterator>
    // bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() != rhs.base());
    // }
    // template <class Iterator>
    // bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() > rhs.base());
    // }
    // template <class Iterator>
    // bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() >= rhs.base());
    // }
    // template <class Iterator>
    // bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() < rhs.base());
    // }
    // template <class Iterator>
    // bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (lhs.base() <= rhs.base());
    // }
    // template <class Iterator>
    // reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    // {
    //     return (reverse_iterator<Iterator>(rev_it._ittype.base() - n));
    // }
    // template <class Iterator>
    // typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    // {
    //     return (rhs.base() - lhs.base());
    // }
}

#endif