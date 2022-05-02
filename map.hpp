
#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include "utility.hpp"
#include "tree.hpp"


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

template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<const Key, T>				value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef PairCompare<Key, T, Compare>		pair_compare;
		typedef	Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef T&									reference;
		typedef const T&							const_reference;
		typedef T*									pointer;
		typedef const T*							const_pointer;
		
		typedef ft::tree_iterator<ft::pair<const Key, T> >			iterator;
		typedef ft::tree_const_iterator<ft::pair<const Key, T> >	const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;


		class value_compare {
				protected:
					key_compare _comp;
				public:
					value_compare() : _comp(){}
					value_compare(key_compare comp) : _comp(comp) {}
					bool operator() (const  value_type & x, const value_type & y) const
					{
						return (_comp(x.first, y.first));
					}
			};
		// class `value_compare : std::binary_function<value_type, value_type, bool>
		// {
		// 	friend class map<key_type, value_type, key_compare, Allocator>;
			
		// 	protected:
		// 		Compare comp;
		// 		value_compare (Compare c) : comp(c) {}
			
		// 	public:
		// 		bool operator() (const value_type& x, const value_type& y) const
		// 		{
		// 			return (comp(x.first, y.first));
		// 		}
		// };
	private:
		RBTree<Key, T, value_compare, allocator_type> _tree;
		// RBTree<ft::pair<const Key, T>, pair_compare, Allocator>		_tree;
	public:
		
		map() : _tree() {}

		explicit map(const value_compare& comp, const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}
		
		template< class InputIt >
		map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() )
		{
			for (; first != last; ++first)
				_tree.insert(*first);
		}

		map(const map& other) : _tree(other._tree){}

		~map(){}

		map& operator=(const map& other)
		{
			_tree = other._tree;
			return (*this);
		}
		
		allocator_type get_allocator() const
		{
			return (_tree.get_allocator());
		}

		mapped_type& at(const key_type& key)
		{
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map");
			return (it->second);
		}
		
		const mapped_type& at(const key_type& key) const
		{
			const_iterator	it = find(key);
			if (it == end())
				throw std::out_of_range("map");
			return (it->second);
		}

		mapped_type& operator[](const key_type& key)
		{
			ft::pair<iterator, bool> it = insert(ft::make_pair(key, mapped_type()));
			return	((it.first)->second);
		}

		bool		empty() const
		{
			return (_tree.empty());
		}

		size_type	size() const
		{
			return (_tree.size());
		}

		size_type	max_size() const
		{
			return (_tree.max_size());
		}

		iterator	begin()
		{
			return (_tree.begin());
		}

		const_iterator	begin() const
		{
			return (_tree.begin());
		}

		iterator	end()
		{
			return (_tree.end());
		}

		const_iterator	end() const
		{
			return (_tree.end());
		}

		reverse_iterator rbegin()
		{
			return (_tree.rbegin());
		}
		
		const_reverse_iterator	rbegin() const
		{
			return (_tree.rbegin());
		}
		
		reverse_iterator		rend()
		{
			return (_tree.rend());
		}
		
		const_reverse_iterator	rend() const
		{
			return (_tree.rend());
		}

		void clear()
		{
			_tree.clear();
		}

		ft::pair<iterator,bool> insert(const value_type& value)
		{
			return (_tree.insert(value));
		}

		iterator insert(iterator hint, const value_type& value)
		{
			return (_tree.insert(hint, value));
		}

		template< class InputIt >
		void insert(InputIt first, InputIt last)
		{
			_tree.insert(first, last);
		}

		void erase(iterator pos)
		{
			_tree.erase(pos);
		}

		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}

		size_type erase(const key_type& key)
		{
			return (_tree.erase(ft::make_pair(key, mapped_type())));
		}

		void	swap(map & other)
		{
			_tree.swap(other._tree);
		}

		size_type count(const key_type& key) const
		{
			return (_tree.find(ft::make_pair(key, mapped_type())) == _tree.end() ? 0 : 1);
		}

		iterator find(const key_type& key)
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find(const key_type& key) const
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		ft::pair<iterator,iterator> equal_range(const key_type& key)
		{ 
			return (_tree.equal_range(ft::make_pair(key, mapped_type()))); }

		ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
		{
			return (_tree.equal_range(ft::make_pair(key, mapped_type())));
		}

		iterator lower_bound(const key_type& key)
		{ 
			return (_tree.lower_bound(ft::make_pair(key, mapped_type()))); 
		}

		const_iterator lower_bound(const key_type& key) const
		{ 
			return (_tree.lower_bound(ft::make_pair(key, mapped_type()))); 
		}

		iterator upper_bound(const key_type& key)
		{ 
			return(_tree.upper_bound(ft::make_pair(key, mapped_type()))); 
		}

		const_iterator upper_bound(const key_type& key) const
		{ 
			return (_tree.upper_bound(ft::make_pair(key, mapped_type()))); 
		}

		key_compare key_comp() const
		{ 
			return (key_compare());
		}

		value_compare value_comp() const
		{ 
			return (value_compare(key_compare())); 
		}
	};

	template< class Key, class T, class Compare, class Allocator >
	bool	operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (!(rhs < lhs));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
	{
		return (!(lhs < rhs));
	}
}

namespace std
{
	template< class Key, class T, class Compare, class Allocator >
	void	swap( ft::map<Key, T, Compare, Allocator> & lhs, ft::map<Key, T, Compare, Allocator> & rhs)
	{
		lhs.swap(rhs);
	}
}

#endif 