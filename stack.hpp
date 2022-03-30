#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> >
    class stack {
        public:
            typedef Container                       containter_type;
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;
            typedef typename Container::reference   reference;
            typedef typename Container::const_reference const_reference;
        private:
            containter_type _c;
        public:
            explicit stack( const containter_type& cont = containter_type()) : _c(cont) {}
            ~stack(){}
            stack& operator=( const stack& other )
            {
                _c = other._c;
                return (*this);
            }
            reference top()
            {
                return _c.back();
            }
            const_reference top() const
            {
                return _c.back();
            }
            bool empty() const
            {
                return _c.empty();
            }
            size_type size() const
            {
                return _c.size();
            }
            void push( const value_type& value )
            {
                _c.push_back(value);
            }
            void pop()
            {
                _c.pop_back();
            }
            // template< class T, class Container >
            friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c == rhs._c);
            }
            // template< class T, class Container >
            friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c != rhs._c);
            }
            // template< class T, class Container >
            friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c < rhs._c);
            }
            // template< class T, class Container >
            friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c <= rhs._c);
            }
            // template< class T, class Container >
            friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c > rhs._c);
            }
            // template< class T, class Container >
            friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
            {
                return (lhs._c >= rhs._c);
            }  
    };
}

#endif