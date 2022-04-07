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
            typedef class ft::const_iterator<T>      					const_iterator;
           	typedef	class ft::reverse_iterator<iterator>				reverse_iterator;
            // typedef class ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			// typedef typename ft::VectorIterator<T>::difference_type		difference_type;
        private:
            allocator_type  _alloc;
            size_type       _capacity;
            size_type       _size;
			pointer			_ptr;
        public:
			explicit Vector(const allocator_type & alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _ptr(nullptr)  {}
			explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n), _ptr(nullptr)
			{
				_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(_ptr + i, val);
				}
			}
			Vector(const Vector& x) : _alloc(allocator_type()), _capacity(0), _size(0), _ptr(nullptr)
			{
				// if (_ptr)
				// 	clear();
				// if (_capacity)
				// 	_alloc.deallocate(_ptr, _capacity);
				// _ptr = _alloc.allocate(_capacity);
				// for (size_type i = 0; i < _size; i++)
				// {
				// 	_alloc.construct(_ptr + i, x[i]);
				// }
				*this = x;
			}
			~Vector()
			{
				clear();
				if (_capacity)
					_alloc.deallocate(_ptr, _capacity);
			}
			template<typename InputIt>
			Vector(InputIt first, InputIt last, const allocator_type & alloc = allocator_type(), typename  ft::enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0) :
				_alloc(alloc), _capacity(0), _size(0) {
				//исключение
				assign(first, last);
			}
			Vector & operator=(const Vector & other) {
				if (this != &other) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_ptr + i);
					_size = other._size;
					if (_size > _capacity) {
						if (_capacity)
							_alloc.deallocate(_ptr, _capacity);
						_capacity = _size;
						_ptr = _alloc.allocate(_capacity);
					}
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_ptr + i, other[i]);
				}
				return *this;
			}
			void assign(size_type count, const_reference value) {
				if (!_capacity)
					_ptr = _alloc.allocate(count);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_ptr + i);
				if (_capacity < count) {
					_alloc.deallocate(_ptr, _capacity);
					_capacity = count;
					_ptr = _alloc.allocate(_capacity);
				}
				_size = count;
				for (size_type i = 0; i < count; i++) {
					_alloc.construct(_ptr + i, value);
				}
			}
			template<class InputIt>
			void assign(InputIt first, InputIt last, typename ft::enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0) {
				size_type counter = 0;
				if (last < first) {
					throw "assign error";
				}
				for (InputIt it = first; it != last; it++) {
					counter++;
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_ptr + i);
				if (_capacity < counter) {
					_alloc.deallocate(_ptr, _capacity);
					_capacity = counter;
					_ptr = _alloc.allocate(_capacity);
				}
				_size = counter;
				for (size_type i = 0; first != last; i++, first++)
					_alloc.construct(_ptr + i, *first);
			}
			//GET_ALLOCATOR ---------------------------------------------------------------
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			//AT --------------------------------------------------------------------------
			reference at(size_type pos)
			{
				if (pos > _size - 1)
					throw "error at";
				return (_ptr[pos]);
			}
			const_reference at( size_type pos ) const
			{
				if (pos > _size - 1)
					throw "error at";
				return (_ptr[pos]);
			}
			//OPERATOR [] ------------------------------------------------------------
			reference operator[]( size_type pos )
			{
				return (_ptr[pos]);
			}
			const_reference operator[]( size_type pos ) const
			{
				return (_ptr[pos]);
			}
			//FRONT --------------------------------------------------------------------
			reference front()
			{
				return (_ptr[0]);
			}
			const_reference front() const
			{
				return (_ptr[0]);
			}
			//BACK ------------------------------------------------------------------
			reference back()
			{
				return (_ptr[_size - 1]);
			}
			const_reference back() const
			{
				return (_ptr[_size - 1]);
			}
			//DATA ----------------------------------------------------------------
			pointer data()
			{
				if (!_size)
					return (nullptr);
				return (_ptr);
			}
			const_pointer data() const
			{
				if (!_size)
					return (nullptr);
				return (_ptr);
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
					pointer temp = _alloc.allocate(n);
					size_type temp_size = _size;
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(temp + i, _ptr[i]);
					}
					clear();
					if (_capacity)
					{
						_alloc.deallocate(_ptr, _capacity);
					}
					_size = temp_size;
					_capacity = n;
					_ptr = temp;
				}
			}
			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_ptr + i);
				_size = 0;
        	}
			
			void push_back(const_reference value)
			{
				if (!_capacity)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_ptr + _size, value);
				_size++;
			}
			void pop_back() {
				if (!empty())
				{
					_alloc.destroy(_ptr + _size);
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
				pointer temp_pointer = _ptr;
				size_type temp_size = _size;
				size_type temp_capacity = _capacity;
				allocator_type temp_alloc = get_allocator();

				_ptr = other._ptr;
				_size = other._size;
				_capacity = other._capacity;
				_alloc = other._alloc;

				other._ptr = temp_pointer;
				other._size = temp_size;
				other._capacity = temp_capacity;
				other._alloc = temp_alloc;
			}
			iterator begin()
			{
				return (iterator(_ptr));
			}
			const_iterator begin() const
			{
				return (const_iterator(_ptr));
			}
			iterator end()
			{
				return(iterator(_ptr + _size));
			}
			const_iterator end() const
			{
				return (const_iterator(_ptr + _size));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			// const_reverse_iterator rbegin() const
			// {
			// 	return (cosnt_reverse_iterator(this->end()));
			// }
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}
			// const_reverse_iterator rend() const
			// {
			// 	return (const_reverse_iterator(this->begin()));
			// }

			//INSERT ##############################################################################
			iterator insert (iterator position, const_reference val)
			{
				size_type	counter = 0;
				pointer		temp = _alloc.allocate(_size);
				size_type	temp_size = _size;

				for (iterator myIter = this->begin(); myIter != position; myIter++) {
					counter++;
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(temp + i, _ptr[i]);
				if (!_capacity)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				// std::cout << "counter: " << counter << "\n";
				// std::cout << "size: " << _size <<  "\n";
				// std::cout << "capacity: " << _capacity << "\n";
				size_type j = 0;
				if (_size > 0) {
					for (size_type i = 0; i < _size; i++) {
						if (j != counter) {
							_alloc.construct(_ptr + j, temp[i]);
							++j;
						}
						if (j == counter) {
							_alloc.construct(_ptr + j, val);
							--i;
							++j;	
						}
					}
				}
				else if (_size == 0) {
					_alloc.construct(_ptr, val);
				}
				for (size_type i = 0; i < temp_size; i++) {
					_alloc.destroy(temp + i);
				}
				_alloc.deallocate(temp, _capacity);
				++_size;
				return(iterator(_ptr + counter));
			}
			void insert(iterator pos, size_type count, const_reference value)
			{
				size_type	counter = 0;
				pointer		temp = _alloc.allocate(_size);
				size_type	temp_size = _size;

				for (iterator myIter = this->begin(); myIter != pos; myIter++) {
					counter++;
				}
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(temp + i, _ptr[i]);
				if (!_capacity)
					reserve(1);
				else if (_size + count > _capacity)
					reserve(_size + count);
				size_type j = 0;
				if (_size > 0) {
					for (size_type i = 0; i < _size; i++) {

						if (j != counter) {
							_alloc.construct(_ptr + j, temp[i]);
							++j;
						}
						if (j == counter) {
							for (size_type i = 0; i < count; i++, j++) {
								_alloc.construct(_ptr + j, value);
							}
							--i;	
						}
					}
				}
				else if (_size == 0) {
					for (size_type i = 0; i < count; i++) {
						_alloc.construct(_ptr + i, value);
					}
				}
				for (size_type i = 0; i < temp_size; i++) {
					_alloc.destroy(temp + i);
				}
				_alloc.deallocate(temp, _capacity);
				_size += count;
			}




			template< class InputIt >
			void insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
			{
				size_type	counter = 0;
				size_type	raz = 0;
				pointer		temp;
				pointer		temp_input;
				size_type	temp_size = _size;

				for (iterator it = this->begin(); it != pos; it++) {
					counter++;
				}
				for (InputIt it = first; it != last; it++) {
					raz++;
				}
				temp_input = _alloc.allocate(raz);
				try {
					for (size_type i = 0; i < raz; i++, first++) {
						_alloc.construct(temp_input + i, *first);
					}
				}
				catch (...) {
					for (size_type i = 0; i < raz; i++) {
						_alloc.destroy(temp_input + i);
					}
					_alloc.deallocate(temp_input, raz);
					throw "error insert";
				}

				temp = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(temp + i, _ptr[i]);
				}
				if (_size + raz <= _capacity * 2)
					reserve(_capacity * 2);
				else
					reserve(_size + raz);
				size_type j = 0;
				if (_size > 0) {
					for (size_type i = 0; i < _size; i++) {
						if (j != counter) {
							_alloc.construct(_ptr + j, temp[i]);
							++j;
						}
						if (j == counter) {
							for (size_type i = 0; i < raz; i++, j++) {
								_alloc.construct(_ptr + j, temp_input[i]);
							}
							--i;
						}
					}
				}
				else if (_size == 0) {
					for (size_type i = 0; i < raz; i++, j++) {
						_alloc.construct(_ptr + j, temp_input[i]);
					}
				}
				for (size_type i = 0; i < raz; i++) {
					_alloc.destroy(temp_input + i);
				}
				_alloc.deallocate(temp_input, raz);
				for (size_type i = 0; i < temp_size; i++) {
					_alloc.destroy(temp + i);
				}
				_alloc.deallocate(temp, temp_size);
				_size += raz;
			}

			//ERASE ###############################################################################
			iterator erase(iterator pos )
			{
				size_type counter = 0;

				for (iterator it = this->begin(); it != pos; it++) {
					counter++;
				}
				pointer temp = _alloc.allocate(_size - 1);
				size_type j = 0;
				for (size_type i = 0; i < _size; i++) {
					if (i != counter) {
						_alloc.construct(temp + j, _ptr[i]);
						j++;
					}
				}
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_ptr + i);
				}
				_alloc.deallocate(_ptr, _capacity);
				_ptr = temp;
				--_size;
				return (iterator(_ptr + counter));

			}

			iterator erase(iterator first, iterator last)
			{
				size_type	counter = 0;
				size_type	sum = 0;

				for (iterator it = this->begin(); it != first; it++) {
					counter++;
				}
				for (iterator it = first; it != last; it++) {
					sum++;
				}
				pointer temp = _alloc.allocate(_size - sum);
				size_type j = 0;
				for (size_type i = 0; i < _size; i++) {
					if (i != counter) {
						_alloc.construct(temp + j, _ptr[i]);
						j++;
					}
					if (i == counter)
						i += sum - 1;
				}
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_ptr + i);
				}
				_alloc.deallocate(_ptr, _capacity);
				_ptr = temp;
				_size -= sum;
				return (iterator(_ptr));
			}

















			//OPERATOR == != < <= > >= -------------------------------------------------
			// template <class T, class Allocator>
			friend bool operator== (const ft::Vector<T,Allocator>& lhs, const ft::Vector<T,Allocator>& rhs)
			{
				if (lhs.size() == rhs.size())
				{
					for (size_type i = 0; i < lhs.size() && lhs[i] == rhs[i]; i++)
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

namespace std {
	template <class T, class Alloc>
	void swap (ft::Vector<T,Alloc>& x, ft::Vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif