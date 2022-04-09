#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
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
			explicit stack(const container_type& cont = container_type()) : _c(cont) {}
			//DESTRUCTOR ---------------------------------------------------------------------------------------------------
			~stack(){}
			//OPERATOR= ---------------------------------------------------------------------------------------------------
			stack& operator=(const stack& other)
			{
				_c = other._c;
				return (*this);
			}
			//TOP ---------------------------------------------------------------------------------------------------
			reference top()
			{
				return (_c.back());
			}
			const_reference top() const
			{
				return (_c.back());
			}
			//EMPTY ---------------------------------------------------------------------------------------------------
			bool empty() const
			{
				return (_c.empty());
			}
			//SIZE ---------------------------------------------------------------------------------------------------
			size_type size() const
			{
				return (_c.size());
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
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c == rhs._c);
			}
			friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c != rhs._c);
			}
			friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c < rhs._c);
			}
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c <= rhs._c);
			}
			friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c > rhs._c);
			}
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c >= rhs._c);
			} 
	};
}

#endif