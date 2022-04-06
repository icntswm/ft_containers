#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

// namespace ft {
// 	template<class T>
//     class VectorIterator {
//         public:
//             typedef typename ft::iterator_traits<T *>::value_type 			value_type;
// 			typedef typename ft::iterator_traits<T *>::reference 			reference;
// 			typedef typename ft::iterator_traits<T *>::pointer				pointer;
// 			typedef typename ft::iterator_traits<T *>::difference_type		difference_type;
// 			typedef typename ft::iterator_traits<T *>::iterator_category	iterator_category;
// 			typedef typename ft::iterator_traits<T *>::pointer				iterator_type;
//         protected:
//             pointer p;
//         public:
//             VectorIterator() {}
//             ~VectorIterator() {}
//             VectorIterator(pointer _ptr) : p(_ptr) {}
//             VectorIterator(const VectorIterator & other) {*this = other;}
//             VectorIterator & operator=(const VectorIterator & other) {
//                 if (this != &other)
//                     p = other.p;
//                 return *this;
//             }
//             bool operator>(const VectorIterator & other) const {return p > other.p;}
//             bool operator>=(const VectorIterator & other) const {return p >= other.p;}
//             bool operator<(const VectorIterator & other) const {return p < other.p;}
//             bool operator<=(const VectorIterator & other) const {return p <= other.p;}
//             bool operator==(const VectorIterator & other) const {return p == other.p;}
//             bool operator!=(const VectorIterator & other) const {return p != other.p;}
//             reference operator*() {return *this->p;}
//             pointer operator->() {return &p;}
//             VectorIterator & operator++() {p++; return *this;}
//             VectorIterator & operator--() {p--; return *this;}
//             VectorIterator operator++(int) {
//                 VectorIterator  res(*this);

//                 *this = operator++();
//                 return res;
//             }
//             VectorIterator operator--(int) {
//                 VectorIterator res(*this);

//                 *this = operator--();
//                 return res;
//             }
//             VectorIterator operator+(int n) {
//                 VectorIterator temp(*this);

//                 temp += n;
//                 return temp;
//             }
//             VectorIterator operator-(int n) {
//                 VectorIterator temp(*this);

//                 temp -= n;
//                 return temp;
//             }
//             VectorIterator & operator+=(int n) {
//                 if (n >= 0)
//                     while (n--)
//                         (*this)++;
//                 else
//                     while (n++)
//                         (*this)++;
// 				return *this;
//             }
//             VectorIterator & operator-=(int n) {
//                 if (n >= 0)
//                     while (n--)
//                         (*this)--;
//                 else
//                     while (n++)
//                         (*this)--;
// 				return *this;
//             }
//             reference operator[](int i) {return *(*this + i);}
//     };
    
//     template<class T>
//     class ConstVectorIterator: public VectorIterator<T> {
//         public:
// 		 	typedef typename VectorIterator<T>::reference     		reference;
//             typedef typename VectorIterator<T>::pointer       		pointer;   
//             typedef const typename VectorIterator<T>::reference     const_reference;
//             typedef const typename VectorIterator<T>::pointer       const_pointer;   
//             ConstVectorIterator() {}
//             ~ConstVectorIterator() {}
//             ConstVectorIterator(pointer _p) : VectorIterator<T>(_p) {}
//             ConstVectorIterator(const ConstVectorIterator & other) {*this = other;}
//             ConstVectorIterator & operator=(const ConstVectorIterator & other) {
//                 if (this != &other)
//                     this->p = other.p;
//                 return *this;
//             }
//             const_reference operator*() {return *this->p;}
//             const_pointer operator->() {return this->p;}
//             const_reference operator[](int i) {return *(*this + i);}
//     };
// }

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
        protected:
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
            iterator operator+ (const difference_type& mov)
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

    template<class Iterator>
    class const_iterator : public iterator<Iterator>
    {
        public:
            // typedef typename iterator<Iterator>::reference     		reference;
            // typedef typename iterator<Iterator>::pointer       		pointer;   
            typedef const typename iterator<Iterator>::reference     const_reference;
            typedef const typename iterator<Iterator>::pointer       const_pointer;   
            const_iterator() {}
            ~const_iterator() {}
            const_iterator(pointer p) : iterator<Iterator>(p) {}
            const_iterator(const const_iterator & other)
            {
                *this = other;
            }
            const_iterator & operator=(const_iterator & other)
            {
                this->point = other.point;
                return (*this);
            }
            const_reference operator*()
            {
                return (*this->point);
            }
            const_pointer operator->()
            {
                return (this->point);
            }   
            const_reference operator[](int i) 
            {
                return *(*this + i);
            }
    };
}


#endif