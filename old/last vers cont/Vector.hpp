#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
// #include <cstddef> // size_t , ?ptrdiff_t
#include <memory> // allocator
#include <exception> // exception
#include <cstring> // ?memmove
#include <limits>
# include <iostream>
#include <type_traits>
#include "enable_if.hpp"
#include <vector>
#include <iterator>
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <stdio.h>
//INSERT ##############################################################################
			// iterator insert( iterator pos, const T& value )
			// {
			// }


			// void insert( iterator pos, size_type count, const T& value )
			// {
			// }


			// template< class InputIt >
			// void insert( iterator pos, InputIt first, InputIt last )
			// {
			// }
//#################################################################################


//ERASE ###############################################################################
			// iterator erase( iterator pos )
			// {
			// }

			// iterator erase( iterator first, iterator last )
			// {
			// }
//########################################################################################

namespace ft {
// 	template <class Iterarator>
// 	class vector_iterator {
// 		public:
// 			typedef Iterator		iterator_type;
// 			typedef typename iterator_traits<Iterator *>::iterator_category	iterator_category;
// 			typedef typename iterator_traits<Iterator *>::value_type		value_type;
// 			typedef typename iterator_traits<Iterator *>::difference_type	difference_type;
// 			typedef typename iterator_traits<Iterator *>::pointer			pointer;
// 			typedef typename iterator_traits<Iterator *>::reference			reference;
// 	};
	



    template<class T,class Allocator = std::allocator<T> >
    class Vector {
        public:
            typedef T                                 					value_type;
            typedef Allocator                         					allocator_type;
            typedef std::size_t                       					size_type;
            typedef T&                            						reference;
            typedef const T&                          					const_reference;
            typedef T*                                					pointer;
            typedef const T*                          					const_pointer;
            typedef class ft::iterator<T>								iterator;
            typedef class ft::iterator<const T>      					const_iterator;
            typedef class ft::reverse_iterator<T>     	reverse_iterator;
            // typedef class ft::ConstReverseVectorIterator<T>  			const_reverse_iterator;
			// typedef typename ft::VectorIterator<T>::difference_type		difference_type;
        private:
            allocator_type  alloc;
            size_type       _capacity;
            size_type       _size;
			pointer			ptr;
        public:
			explicit Vector(const allocator_type & _alloc = allocator_type()) : alloc(_alloc), _capacity(0), _size(0), ptr(nullptr)  {}
			explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& _alloc = allocator_type()) : alloc(_alloc), _size(n), _capacity(n), ptr(nullptr)
			{
				ptr = alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					alloc.construct(ptr + i, val);
				}
			}
			Vector(const Vector& x) : alloc(allocator_type()), _capacity(0), _size(0), ptr(nullptr)
			{
				// if (ptr)
				// 	clear();
				// if (_capacity)
				// 	alloc.deallocate(ptr, _capacity);
				// ptr = alloc.allocate(_capacity);
				// for (size_type i = 0; i < _size; i++)
				// {
				// 	alloc.construct(ptr + i, x[i]);
				// }
				*this = x;
			}



			// vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity), _ptr(nullptr)
			// {
			// 	ptr = _alloc.allocate(x._capacity);
			// 	for (size_type i = 0; i < _size; i++)
			// 	{
			// 		alloc.construct(ptr + i, x[i]);
			// 	}
			// }
			~Vector()
			{
				clear();
				if (_capacity)
					alloc.deallocate(ptr, _capacity);
			}
			template<typename InputIt>
			Vector(InputIt first, InputIt last, const allocator_type & _alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0) :
				alloc(_alloc), _capacity(20), _size(0) {
				if (first > last)
					throw std::length_error("vector");
				ptr = alloc.allocate(_capacity);
				assign(first, last);
			}
			Vector & operator=(const Vector & other) {
				if (this != &other) {
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ptr + i);
					_size = other._size;
					if (_size > _capacity) {
						if (_capacity)
							alloc.deallocate(ptr, _capacity);
						_capacity = _size;
						ptr = alloc.allocate(_capacity);
					}
					for (int i = 0; i < _size; i++)
						alloc.construct(ptr + i, other[i]);
				}
				return *this;
			}
			void assign(size_type count, const_reference value) {
				if (!_capacity)
					ptr = alloc.allocate(count);
				for (size_type i = 0; i < _size; i++)
					alloc.destroy(ptr + i);
				if (_capacity < count) {
					alloc.deallocate(ptr, _capacity);
					_capacity = count;
					ptr = alloc.allocate(_capacity);
				}
				_size = count;
				for (size_type i = 0; i < count; i++) {
					alloc.construct(ptr + i, value);
				}
			}
			template<class InputIt>
			void assign(InputIt first, InputIt last, typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0) {
				if (first > last)
					throw std::length_error("vector");
				for (size_type i = 0; i < _size; i++)
					alloc.destroy(ptr + i);
				int count = 0;
				for (InputIt it = first; it != last; ++it, ++count);
				if (_capacity < count) {
					alloc.deallocate(ptr, _capacity);
					_capacity = count;
					ptr = alloc.allocate(_capacity);
				}
				_size = count;
				for (int i = 0; first != last; ++first, ++i)
					alloc.construct(ptr + i, *first);
			}
			//GET_ALLOCATOR ---------------------------------------------------------------
			allocator_type get_allocator() const
			{
				return (alloc);
			}
			//AT --------------------------------------------------------------------------
			reference at( size_type pos )
			{
				//исключение
				return (ptr[pos]);
			}
			const_reference at( size_type pos ) const
			{
				//исключение
				return (ptr[pos]);
			}
			//OPERATOR [] ------------------------------------------------------------
			reference operator[]( size_type pos )
			{
				return (ptr[pos]);
			}
			const_reference operator[]( size_type pos ) const
			{
				return (ptr[pos]);
			}
			//FRONT --------------------------------------------------------------------
			reference front()
			{
				return (ptr[0]);
			}
			const_reference front() const
			{
				return (ptr[0]);
			}
			//BACK ------------------------------------------------------------------
			reference back()
			{
				return (ptr[_size - 1]);
			}
			const_reference back() const
			{
				return (ptr[_size - 1]);
			}
			//DATA ----------------------------------------------------------------
			pointer data()
			{
				if (!_size)
					return (nullptr);
				return (ptr);
			}
			const_pointer data() const
			{
				if (!_size)
					return (nullptr);
				return (ptr);
			}
			//EMPTY -----------------------------------------------------------------
			bool empty() const
			{
				return (!_size);
			}
			//SIZE --------------------------------------------------------------------
			size_type size() const
			{
				return (_size);
			}
			//MAX_SIZE ------------------------------------------------------------
			size_type max_size() const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(size_type));
			}
			//CAPACITY --------------------------------------------------------------
			size_type capacity() const
			{
				return (_capacity);
			}
			void reserve(size_type n) {
				if (n > _capacity)
				{
					pointer temp = alloc.allocate(n);
					size_type temp_size = _size;
					for (size_type i = 0; i < _size; i++)
					{
						alloc.construct(temp + i, ptr[i]);
					}
					clear();
					if (_capacity)
					{
						alloc.deallocate(ptr, _capacity);
					}
					_size = temp_size;
					_capacity = n;
					ptr = temp;
				}
			}
			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					alloc.destroy(ptr + i);
				_size = 0;
        	}
			
			void push_back(const_reference value )
			{
				if (!_capacity)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				alloc.construct(ptr + _size, value);
				_size++;
			}
			void pop_back() {
				if (!empty())
				{
					alloc.destroy(ptr + _size);
					_size--;
				}
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type i = _size; i != n; i--)
					{
						pop_back();
					}
				}
				else
				{
					for (size_type i = _size; i != n; i++)
					{
						push_back(val);
					}
				}
			}
			void swap(Vector & other) {
				pointer temp_pointer = ptr;
				size_type temp_size = _size;
				size_type temp_capacity = _capacity;
				allocator_type temp_alloc = get_allocator();

				ptr = other.ptr;
				_size = other._size;
				_capacity = other._capacity;
				alloc = other.alloc;

				other.ptr = temp_pointer;
				other._size = temp_size;
				other._capacity = temp_capacity;
				other.alloc = temp_alloc;
			}
			iterator begin()
			{
				// printf("++++++++\n");
				return (iterator(ptr));
			}
			const_iterator begin() const
			{
				// printf("++++++++\n");
				return (const_iterator(ptr));
			}
			iterator end()
			{
				return(iterator(ptr + _size));
			}
			const_iterator end() const
			{
				// printf("++++++++\n");
				return (const_iterator(ptr + _size));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(ptr + _size - 1));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(ptr - 1));
			}




			//OPERATOR == != < <= > >= -------------------------------------------------
			// template <class T, class Allocator>
			friend bool operator== (const ft::Vector<T,Allocator>& lhs, const ft::Vector<T,Allocator>& rhs)
			{
				if (lhs.size() == rhs.size())
				{
					for (int i = 0; i < lhs.size() && lhs[i] == rhs[i]; i++)
					{
						if (i == lhs.size() - 1)
							return (true);
					}
				}
				return (false);
			}
			// template <class T, class Allocator>
			friend bool operator!= (const ft::Vector<T,Allocator>& lhs, const ft::Vector<T,Allocator>& rhs)
			{
				return (!(lhs == rhs));
			}

			// template <class T, class Allocator>
			friend bool operator< (const ft::Vector<T,Allocator>& lhs, const ft::Vector<T,Allocator>& rhs)
			{
				int size;
				if (lhs.size() > rhs.size())
					size = rhs.size();
				else
					size = lhs.size();
				for (int i = 0; i < size; i++)
				{
					if (rhs[i] != lhs[i])
						return (lhs[i] < rhs[i]);
				}
				return (lhs.size() < rhs.size());	
			}

			// template<class T, class Allocator>
			friend bool operator<=(const ft::Vector<T, Allocator> & lhs, const ft::Vector<T, Allocator> & rhs)
			{
				return (lhs == rhs || lhs < rhs);
			}

			// template<class T, class Allocator>
			friend bool operator>(const ft::Vector<T, Allocator> & lhs, const ft::Vector<T, Allocator> & rhs)
			{
				return !(lhs <= rhs);
			}

			// template <class T, class Allocator>
			friend bool operator>= (const ft::Vector<T,Allocator>& lhs, const ft::Vector<T,Allocator>& rhs)
			{
				return (lhs == rhs || lhs > rhs);
			}
    };
}

// namespace std {
// 	template<class T, class Allocator>
// 	void swap(ft::Vector<T, Allocator> & lhs, ft::Vector<T, Allocator> & rhs) { lhs.swap(rhs); }
// }

#endif