#ifndef UTILITIES_HPP
# define UTILITIES_HPP

#include <iostream>

namespace ft {
    enum COLOR{BLACK, RED};

    // template<class T>
	// struct node_tree {
	// 	typedef T	data_type;
	// 	data_type   data;
	// 	node_tree*	parent;
	// 	node_tree*  left;
	// 	node_tree*	right;
	// 	COLOR       color;
		
	// 	explicit node_tree(data_type& d = nullptr) : data(d), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
	// 	node_tree(const node_tree& nt)
	// 	{
	// 		*this = nt;
	// 	}
	// 	node_tree& operator=(const node_tree& nt) {
	// 		data = nt.data;
	// 		right = nt.right;
	// 		left = nt.left;
	// 		parent = nt.parent;
	// 		color = nt.color;
	// 		return (*this);
	// 	}
	// };



    template<class T>
    struct node_tree {
        typedef T	data_type;
        data_type   data;
        node_tree*	parent;
        node_tree*  left;
        node_tree*	right;
        COLOR       color;
        // bool		is_red;
        
        explicit node_tree(const data_type& d = nullptr) : data(d), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
        node_tree(const data_type& d, node_tree* par, node_tree* lft, node_tree* rght, COLOR col) : data(d), parent(par), left(lft), right(rght), color(col) {}
        // node_tree(const node_tree& nt)
        // {
        // 	*this = nt;
        // }
        // node_tree& operator=(const node_tree& nt) {
        // 	data = nt.data;
        // 	right = nt.right;
        // 	left = nt.left;
        // 	parent = nt.parent;
        // 	is_red = nt.is_red;
        // 	return (*this);
        // }
    };

    template <class Iterator>
    class iterator_traits {
        public:
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::value_type           value_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;
            typedef typename Iterator::iterator_category    iterator_category;
    };
    template <class T>
    class iterator_traits<T*> {
        public:
            typedef ptrdiff_t                          difference_type;
            typedef T                                  value_type;
            typedef T*                                 pointer;
            typedef T&                                 reference;
            typedef std::random_access_iterator_tag    iterator_category;
    };
    template <class T>
    class iterator_traits<const T*> {
        public:
            typedef std::ptrdiff_t                     difference_type;
            typedef T                                  value_type;
            typedef const T*                           pointer;
            typedef const T&                           reference;
            typedef std::random_access_iterator_tag    iterator_category;
    };


    template<bool Cond, class T = void>
    struct enable_if {};
    template<class T>
    struct enable_if<true, T>
    { 
        typedef T type;
    };


    template <class T, bool v>
    struct integral_constant {
        typedef T type;
        static const bool value = v;
        operator type()
        {
            return (value);
        }
    };
    template <class T>
    struct is_integral : public integral_constant <bool, false> {};
    template <>
    struct is_integral<bool> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<char> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<char16_t> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<char32_t> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<wchar_t> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<signed char> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<short int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<long int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<long long int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<unsigned char> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<unsigned short int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<unsigned int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<unsigned long int> : public integral_constant <bool, true> {};
    template <>
    struct is_integral<unsigned long long int> : public integral_constant <bool, true> {};


    template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2))
                return (false);
        }
        return (true);
    }
    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2))
                return (false);
        }
        return (true);
    }

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
            if (*first1 < *first2) 
                return (true);
            if (*first2 < *first1)
                return (false);
        }
        return ((first1 == last1) && (first2 != last2));
    }
    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
            if (comp(*first1, *first2))
                return (true);
            if (comp(*first2, *first1))
                return (false);
        }
        return ((first1 == last1) && (first2 != last2));
    }


    template <class T1, class T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;
        first_type first;
        second_type second;

        pair() : first(), second() {}
        template<class U, class V>
        pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        // pair(const pair& p) : first(p.first), second(p.second) {} //?????????????????

        // pair& operator= (const pair& pr)
        // {
        //     if (this != &pr) {
        //         first = pr.first;
        //         second = pr.second;
        //     }
        //     return (*this);
        // }
    };









    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x, y));
    }

    
}

#endif