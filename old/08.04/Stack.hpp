#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {
	template <class T, class Container = ft::Vector<T> >
	class Stack {
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
		private:
			container_type	_c;
		public:
			//CONSTRUCTOR ---------------------------------------------------------------------------------------------------
			explicit Stack(const container_type& cont = container_type()) : _c(cont) {}
			//DESTRUCTOR ---------------------------------------------------------------------------------------------------
			~Stack(){}
			//OPERATOR= ---------------------------------------------------------------------------------------------------
			Stack& operator=(const Stack& other)
			{
				_c = other._c;
				return (*this);
			}
			//TOP ---------------------------------------------------------------------------------------------------
			reference top()
			{
				return _c.back();
			}
			const_reference top() const
			{
				return _c.back();
			}
			//EMPTY ---------------------------------------------------------------------------------------------------
			bool empty() const
			{
				return _c.empty();
			}
			//SIZE ---------------------------------------------------------------------------------------------------
			size_type size() const
			{
				return _c.size();
			}
			//PUSH ---------------------------------------------------------------------------------------------------
			void push(const value_type& value)
			{
				_c.push_back(value);
			}
			//POP ---------------------------------------------------------------------------------------------------
			void pop()
			{
				_c.pop_back();
			}
			//OPERATOR == != < <= > >= ---------------------------------------------------------------------------------------------------
			// template< class T, class Container >
			friend bool operator== (const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c == rhs._c);
			}
			// template< class T, class Container >
			friend bool operator!=(const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c != rhs._c);
			}
			// template< class T, class Container >
			friend bool operator< (const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c < rhs._c);
			}
			// template< class T, class Container >
			friend bool operator<= (const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c <= rhs._c);
			}
			// template< class T, class Container >
			friend bool operator> (const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c > rhs._c);
			}
			// template< class T, class Container >
			friend bool operator>= (const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs)
			{
				return (lhs._c >= rhs._c);
			} 
	};
}

#endif