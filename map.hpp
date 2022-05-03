
// #ifndef MAP_HPP
// # define MAP_HPP

// #include "utility.hpp"
// #include "rb_tree.hpp"

// namespace ft
// {
// 	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
// 	class map {
// 		public:
// 			typedef Key										key_type;
// 			typedef T										mapped_type;
// 			typedef ft::pair<const Key, T>					value_type;
// 			typedef std::size_t								size_type;
// 			typedef std::ptrdiff_t							difference_type;
// 			typedef	Compare									key_compare;
// 			typedef Allocator								allocator_type;
// 			typedef value_type&								reference;
// 			typedef const value_type&						const_reference;
// 			typedef typename allocator_type::pointer		pointer;
// 			typedef typename allocator_type::const_pointer	const_pointer;
// 			typedef ft::tree_iterator<value_type>			iterator;
// 			typedef ft::tree_const_iterator<value_type>		const_iterator;
// 			typedef ft::reverse_iterator<iterator>			reverse_iterator;
// 			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
// 			class value_compare {
// 				protected:
// 					key_compare _comp;
// 				public:
// 					value_compare() : _comp(){}
// 					value_compare(key_compare comp) : _comp(comp) {}
// 					bool operator() (const value_type& lhs, const value_type& rhs) const
// 					{
// 						return (_comp(lhs.first, rhs.first));
// 					}
// 			};
// 		private:
// 			rb_tree<Key, T, value_compare, allocator_type> _tree;
// 		public:
// 			//CONSTRUCTOR ------------------------------------------------------------------------
// 			map() : _tree() {}
// 			explicit map(const value_compare& comp, const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}
// 			template< class InputIt >
// 			map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
// 			{
// 				for (InputIt it = first; it != last; ++it)
// 					_tree.insert(*it);
// 			}
// 			map(const map& other) : _tree(other._tree){}
// 			//DESTRUCTOR ------------------------------------------------------------------------
// 			~map()
// 			{
// 				clear();
// 			}
// 			//OPERATOR= ------------------------------------------------------------------------
// 			map& operator=(const map& other)
// 			{
// 				_tree = other._tree;
// 				return (*this);
// 			}
// 			//GET_ALLOCATOR ------------------------------------------------------------------------
// 			allocator_type get_allocator() const
// 			{
// 				return (_tree.get_allocator());
// 			}
// 			//AT ------------------------------------------------------------------------
// 			mapped_type& at(const key_type& key)
// 			{
// 				iterator it = find(key);

// 				if (!it._node)
// 					throw std::out_of_range("map error: at");
// 				return (it->second);
// 			}
// 			const mapped_type& at(const key_type& key) const
// 			{
// 				const_iterator	it = find(key);
				
// 				if (!it._node)
// 					throw std::out_of_range("map error: at");
// 				return (it->second);
// 			}
// 			//OPERATOR[] ------------------------------------------------------------------------
// 			mapped_type& operator[](const key_type& key)
// 			{
// 				return (insert(ft::make_pair(key, mapped_type())).first->second);
// 			}
// 			//BEGIN, END, RBEGIN, REND ------------------------------------------------------------------------
// 			iterator begin()
// 			{
// 				return (_tree.begin());
// 			}
// 			const_iterator begin() const
// 			{
// 				return (_tree.begin());
// 			}
// 			iterator end()
// 			{
// 				return (_tree.end());
// 			}
// 			const_iterator end() const
// 			{
// 				return (_tree.end());
// 			}
// 			reverse_iterator rbegin()
// 			{
// 				return (_tree.rbegin());
// 			}
// 			const_reverse_iterator rbegin() const
// 			{
// 				return (_tree.rbegin());
// 			}
// 			reverse_iterator rend()
// 			{
// 				return (_tree.rend());
// 			}
// 			const_reverse_iterator rend() const
// 			{
// 				return (_tree.rend());
// 			}
// 			//EMPTY ------------------------------------------------------------------------
// 			bool empty() const
// 			{
// 				return (_tree.empty());
// 			}
// 			//SIZE ------------------------------------------------------------------------
// 			size_type size() const
// 			{
// 				return (_tree.size());
// 			}
// 			//MAX_SIZE ------------------------------------------------------------------------
// 			size_type max_size() const
// 			{
// 				return (_tree.max_size());
// 			}
// 			//CLEAR ------------------------------------------------------------------------
// 			void clear()
// 			{
// 				_tree.clear();
// 			}
// 			//INSERT ------------------------------------------------------------------------
// 			ft::pair<iterator,bool> insert(const value_type& value)
// 			{
// 				return (_tree.insert(value));
// 			}
// 			iterator insert(iterator hint, const value_type& value)
// 			{
// 				return (_tree.insert(hint, value));
// 			}
// 			template<class InputIt>
// 			void insert(InputIt first, InputIt last)
// 			{
// 				_tree.insert(first, last);
// 			}
// 			//ERASE ------------------------------------------------------------------------
// 			void erase(iterator pos)
// 			{
// 				_tree.erase(pos);
// 			}
// 			void erase(iterator first, iterator last)
// 			{
// 				_tree.erase(first, last);
// 			}
// 			size_type erase(const key_type& key)
// 			{
// 				return (_tree.erase(ft::make_pair(key, mapped_type())));
// 			}
// 			//SWAP ------------------------------------------------------------------------
// 			void	swap(map & other)
// 			{
// 				_tree.swap(other._tree);
// 			}
// 			//COUNT ------------------------------------------------------------------------
// 			size_type count(const key_type& key) const
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				if (_tree.find(temp) == _tree.end())
// 					return (0);
// 				return (1);
// 			}
// 			//FIND ------------------------------------------------------------------------
// 			iterator find(const key_type& key)
// 			{
// 				return (_tree.find(ft::make_pair(key, mapped_type())));
// 			}
// 			const_iterator find(const key_type& key) const
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.find(temp));
// 			}
// 			//EQUAL_RANGE ------------------------------------------------------------------------
// 			ft::pair<iterator,iterator> equal_range(const key_type& key)
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.equal_range(temp));
// 			}
// 			ft::pair<const_iterator,const_iterator> equal_range(const key_type& key) const
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.equal_range(temp));
// 			}
// 			//LOWER_BOUND ------------------------------------------------------------------------
// 			iterator lower_bound(const key_type& key)
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.lower_bound(temp)); 
// 			}

// 			const_iterator lower_bound(const key_type& key) const
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.lower_bound(temp)); 
// 			}
// 			//UPPER_DOUND ------------------------------------------------------------------------
// 			iterator upper_bound(const key_type& key)
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return(_tree.upper_bound(temp)); 
// 			}
// 			const_iterator upper_bound(const key_type& key) const
// 			{
// 				ft::pair<key_type, mapped_type> temp = ft::make_pair(key, mapped_type());
// 				return (_tree.upper_bound(temp)); 
// 			}
// 			//KEY_COMP ------------------------------------------------------------------------
// 			key_compare key_comp() const
// 			{ 
// 				return (key_compare());
// 			}
// 			//VALUE_COMP ------------------------------------------------------------------------
// 			value_compare value_comp() const
// 			{ 
// 				return (value_compare(key_compare())); 
// 			}
// 	};
// 	//OPERATOR == != < <= > >= ------------------------------------------------------------------------
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		if (lhs.size() != rhs.size())
// 			return (false);
// 		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// 	}
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		if (lhs.size() != rhs.size())
// 			return (true);
// 		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// 	}
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// 	}
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
// 	}
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
// 	}
// 	template< class Key, class T, class Compare, class Allocator >
// 	bool	operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
// 	{
// 		return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// 	}
// }

// namespace std
// {
// 	template<class Key, class T, class Compare, class Alloc>
// 	void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
// 	{
// 		lhs.swap(rhs);
// 	}
// }

// #endif 








#ifndef MAP_HPP
# define MAP_HPP

#include "utility.hpp"
// #include "RBTree.hpp"
#include "rb_tree.hpp"
#include "tree_iterator.hpp"


namespace ft
{

template <class Key, class T, class Compare>
struct PairCompare
{
	bool	operator()(const ft::pair<const Key, T> & first, const ft::pair<const Key, T> & second) const
	{
		return Compare()(first.first, second.first);
	}
};

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map
{
public:
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef ft::pair<const Key, T>				value_type;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef PairCompare<Key, T, Compare>		pair_compare;
	typedef	Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;
	
	typedef ft::tree_iterator<ft::pair<const Key, T> >			iterator;
	typedef ft::tree_const_iterator<ft::pair<const Key, T> >	const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map<key_type, value_type, key_compare, Allocator>;
		
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		
		public:
			bool operator() (const value_type& x, const value_type& y) const
			{ return (comp(x.first, y.first)); }
	};
private:
	rb_tree<Key, T, pair_compare, Allocator>		__tree;
public:
	
	map() : __tree()
	{}

	explicit map( const Compare& comp,
			const Allocator& alloc = Allocator() )
			: __tree(comp, alloc)
	{}
	
	template< class InputIt >
	map( InputIt first, InputIt last,
		const Compare& comp = Compare(),
		const Allocator& alloc = Allocator() ) : __tree(comp, alloc)
	{
		for (; first != last; ++first)
			__tree.insert(*first);
	}

	map( const map& other ) : __tree(other.__tree)
	{}

	~map()
	{}

	map& operator=( const map& other )
	{
		__tree = other.__tree;
		return *this;
	}
	
	allocator_type get_allocator() const
	{ return __tree.get_allocator(); }

	T& at( const Key& key )
	{
		iterator	it = find(key);
		if (it == end())
			throw std::out_of_range("map");
		return	it->second;
	}
	
	const T& at( const Key& key ) const
	{
		const_iterator	it = find(key);
		if (it == end())
			throw std::out_of_range("map");
		return	it->second;
	}

	T& operator[]( const Key& key )
	{
		ft::pair<iterator, bool>	it = insert(ft::make_pair(key, T()));
		return	(it.first)->second;
	}

	bool		empty() const
	{ return __tree.empty(); }

	size_type	size() const
	{ return __tree.size(); }

	size_type	max_size() const
	{ return __tree.max_size(); }

	iterator	begin()
	{ return __tree.begin(); }

	const_iterator	begin() const
	{ return __tree.begin(); }

	iterator	end()
	{ return __tree.end(); }

	const_iterator	end() const
	{ return __tree.end(); }

	reverse_iterator		rbegin()
	{ return __tree.rbegin(); }
	
	const_reverse_iterator	rbegin() const
	{ return __tree.rbegin(); }
	
	reverse_iterator		rend()
	{ return __tree.rend(); }
	
	const_reverse_iterator	rend() const
	{ return __tree.rend(); }

	void clear()
	{ __tree.clear(); }

	ft::pair<iterator,bool> insert( const value_type& value )
	{ return __tree.insert(value); }

	iterator insert( iterator hint, const value_type& value )
	{ return __tree.insert(hint, value); }

	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{ __tree.insert(first, last); }

	void erase( iterator pos )
	{ __tree.erase(pos); }

	void erase( iterator first, iterator last )
	{ __tree.erase(first, last); }

	size_type erase( const Key& key )
	{ return __tree.erase(ft::make_pair(key, T())); }

	void	swap(map & other)
	{ __tree.swap(other.__tree); }

	size_type count( const Key& key ) const
	{ return __tree.find(ft::make_pair(key, T())) == __tree.end() ? 0 : 1; }

	iterator find( const Key& key )
	{ return __tree.find(ft::make_pair(key, T())); }

	const_iterator find( const Key& key ) const
	{ return __tree.find(ft::make_pair(key, T())); }

	ft::pair<iterator,iterator> equal_range( const Key& key )
	{ return __tree.equal_range(ft::make_pair(key, T())); }

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
	{ return __tree.equal_range(ft::make_pair(key, T())); }

	iterator lower_bound( const Key& key )
	{ return __tree.lower_bound(ft::make_pair(key, T())); }

	const_iterator lower_bound( const Key& key ) const
	{ return __tree.lower_bound(ft::make_pair(key, T())); }

	iterator upper_bound( const Key& key )
	{ return __tree.upper_bound(ft::make_pair(key, T())); }

	const_iterator upper_bound( const Key& key ) const
	{ return __tree.upper_bound(ft::make_pair(key, T())); }

	key_compare key_comp() const
	{ return key_compare(); }

	value_compare value_comp() const
	{ return value_compare(key_compare()); }
};

template< class Key, class T, class Compare, class Allocator >
bool	operator==(const map<Key, T, Compare, Allocator> & lhs,
					const map<Key, T, Compare, Allocator> & rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template< class Key, class T, class Compare, class Allocator >
bool	operator!=(const map<Key, T, Compare, Allocator> & lhs,
					const map<Key, T, Compare, Allocator> & rhs)
{
	return !(lhs == rhs);
}

template< class Key, class T, class Compare, class Allocator >
bool	operator<(const map<Key, T, Compare, Allocator>& lhs,
					const map<Key, T, Compare, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
										rhs.begin(), rhs.end()
										));
}

template< class Key, class T, class Compare, class Allocator >
bool	operator<=(const map<Key, T, Compare, Allocator>& lhs,
					const map<Key, T, Compare, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template< class Key, class T, class Compare, class Allocator >
bool	operator>(const map<Key, T, Compare, Allocator>& lhs,
					const map<Key, T, Compare, Allocator>& rhs)
{
	return (rhs < lhs);
}

template< class Key, class T, class Compare, class Allocator >
bool	operator>=(const map<Key, T, Compare, Allocator>& lhs,
					const map<Key, T, Compare, Allocator>& rhs)
{
	return (!(lhs < rhs));
}


} // namespace ft

namespace std
{
	template< class Key, class T, class Compare, class Allocator >
	void	swap( ft::map<Key, T, Compare, Allocator> & lhs,
				ft::map<Key, T, Compare, Allocator> & rhs)
	{
		lhs.swap(rhs);
	}
}

#endif // FT_MAP_HPP