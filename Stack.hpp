#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> >
    class Stack {
        public:
            typedef Container                       containter_type;
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;
            typedef typename Container::reference   reference;
            typedef typename Container::const_reference const_reference;
        protected:
            containter_type c;
        public:
        explicit Stack( const containter_type& cont = containter_type()) : c(cont) {}
        ~Stack(){}
        Stack& operator=( const Stack& other )
        {
            c = other.c;
            return (*this);
        }
        reference top()
        {
            return c.back();
        }
        const_reference top() const
        {
            return c.back();
        }
        bool empty() const
        {
            return c.empty();
        }
        size_type size() const
        {
            return c.size();
        }
        void push( const value_type& value )
        {
            c.push_back(value);
        }
        void pop()
        {
            c.pop_back();
        }
        // template< class T, class Container >
        friend bool operator==( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c == rhs.c);
        }
        // template< class T, class Container >
        friend bool operator!=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c != rhs.c);
        }
        // template< class T, class Container >
        friend bool operator<( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c < rhs.c);
        }
        // template< class T, class Container >
        friend bool operator<=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c <= rhs.c);
        }
        // template< class T, class Container >
        friend bool operator>( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c > rhs.c);
        }
        // template< class T, class Container >
        friend bool operator>=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs )
        {
            return (lhs.c >= rhs.c);
        }  
    };
}

#endif