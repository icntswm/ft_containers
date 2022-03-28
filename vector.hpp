#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <limits>
# include <iostream>
# include <iterator>


namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T					        	value_type;
			typedef Allocator			            allocator_type;
			typedef std::size_t                     size_type;
			typedef std::ptrdiff_t                  difference_type;
			typedef T&                           	reference;
			typedef const T&                    	const_reference;
			typedef T*                     			 pointer;
			typedef const T* 			               const_pointer;
			// typedef std::iterator<T>                iterator;
			// typedef const std::iterator<T>          const_iterator;
			// typedef std::reverse_iterator<T>        reverse_iterator;
			// typedef const std::reverse_iterator<T>  const_reverse_iterator;
		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_ptr;
		public:
			//КОНСТРУКТОРЫ----------------------------------------
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0), _ptr(0) {}
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n), _ptr(0)
			{
				_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(_ptr + i, val);
				}
			}
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0), _ptr(0)
			{
				_size, _capacity = std::distance(first, last);
				_ptr = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_ptr + i, *first++);
				}

			}
			vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity), _ptr(x._ptr)
			{
				_ptr = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_ptr + i, x[i]);
				}
			}
			//ДЕСТРУКТОР--------------------------------------------
			~vector()
			{
				clear();
				_alloc.dealocate(_ptr, _capacity);
				_capacity, _ptr = 0;
			}
			//OPERATOR = -----------------------------------------------
			vector& operator= (const vector& x)
			{
				if (_ptr)
				{
					clear();
					_alloc.dealocate(_ptr, _size);
					_size, _capacity, _ptr = 0;
				}
				_ptr = _alloc.allocate(x._size);
				_size = x._size;
				_capacity = x._capacity;
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_ptr + i, x[i]);
				}
				return (*this);
			}
			//ASSIGN ------------------------------------------------------------
			void assign (size_type n, const value_type& val)
			{
				clear();
				if (_capacity < n)
				{
					_alloc.dealocate(_ptr, _capacity);
					_capacity = n;
					_alloc.allocate(_capacity);
				}
				for (size_type i = 0; i < n; i++)
				{
					_ptr = _alloc.construct(_ptr + i, val);
				}
				_size = n;
			}
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
			{
				//исключение
				clear();
				int counter = 0;
				for (InputIterator i = first; i != last; i++)
					counter++;
				if (_capacity < counter)
				{
					_alloc.dealocate(_ptr, _capacity);
					_capacity = counter;
					_alloc.allocate(_capacity);
				}
				for (size_type i = 0; first != last; i++)
				{
					_ptr = _alloc.construct(_ptr + i, *first++);
				}
				_size = counter;
			}
			//GET_ALLOCATOR ---------------------------------------------------------------
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			//AT --------------------------------------------------------------------------
			reference at( size_type pos )
			{
				//исключение
				return (_ptr[pos]);
			}
			const_reference at( size_type pos ) const
			{
				//исключение
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
			//REVERSE ------------------------------------------------------------------
			void reserve (size_type n)
			{
				//исключение
				if (n > _capacity)
				{
					pointer temp = _alloc.allocate(n);
					size_type temp_size = _size;
					for (size_type i = 0; i < _size; i++)
					{
						temp = _alloc.construct(temp + i, _ptr[i]);
					}
					clear();
					_alloc.dealocate(_ptr, _capacity);
					_capacity = n;
					_size = temp_size;
					_ptr = temp;
				}
			}
			//CLEAR ----------------------------
			void clear()
			{
				if (_ptr) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_ptr + i);
				}
				_size = 0;
        	}
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

			//PUSH_BACK ----------------------------------------------------------------
			void push_back(const_reference value )
			{
				if (_size == _capacity)
				{
					reserve(_capacity * 2);
				}
				_alloc.construct(_ptr + size, value);
				size++;
			}
			//POP_BACK ----------------------------------------------------------------
			void pop_back()
			{
				if (empty() != 0)
				{
					_alloc.destroy(_ptr + (_size - 1));
				}
			}
			//RESIZE ---------------------------------------------------------------
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
			//SWAP ---------------------------------------------------------------------
			void swap( vector& other )
			{
				pointer temp_pointer = _ptr;
				size_type temp_size = _size;
				size_type temp_capacity = _capacity;
				allocator_type temp_alloc = _alloc;

				_ptr = other._ptr;
				_size = other._size;
				_capacity = other._capacity;
				_alloc = other._alloc;

				other._ptr = temp_pointer;
				other._size = temp_size;
				other._capacity = temp_capacity;
				other._alloc = temp_alloc;
			}
	};
	//OPERATOR == != < <= > >= -------------------------------------------------
	template <class T, class Allocator>
	bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
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

	template <class T, class Allocator>
	bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		return (lhs != rhs);
	}

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
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

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));	
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif