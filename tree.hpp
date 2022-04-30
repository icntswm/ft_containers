#ifndef TREE_HPP
# define TREE_HPP

#include "utility.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include <algorithm>

namespace ft
{
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class RBTree
{
public:
	typedef	T						value_type;
	typedef std::size_t				size_type;
	typedef Compare					comparator_type;
	typedef Allocator				allocator_type;
	typedef node_tree<T>			node;
	typedef typename allocator_type::template rebind<node>::other	node_allocator;
	typedef ft::tree_iterator<value_type>		iterator;
	typedef ft::tree_const_iterator<value_type>	const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
private:
	size_type		_size;
	allocator_type	_alloc_value;
	node_allocator	_alloc_node;
	comparator_type	_comp;
	node *			_root;
public:
	RBTree() : _size(0), _alloc_value(), _alloc_node(), _comp(), _root(nullptr){}

	explicit RBTree( const Compare& comp, const Allocator& alloc = Allocator() )
			: _size(0), _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _root(nullptr) {}

	RBTree( const RBTree& other )
		: _alloc_value(other._alloc_value), _alloc_node(other._alloc_node), _comp(other._comp), _root(nullptr)
	{
		copy_tree(_root, nullptr, other._root);
		_size = other._size;
	}
	~RBTree()
	{
		clear_tree(_root);
	}

	RBTree& operator=( const RBTree& other )
	{
		node	*tmp_tree = nullptr;

		copy_tree(tmp_tree, nullptr, other._root);
		clear_tree(_root);
		_root = tmp_tree;
		_size = other._size;
		return *this;
	}

	allocator_type get_allocator() const { return _alloc_value; }

	bool		empty() const{ return _root == nullptr; }

	size_type	size() const { return _size; }

	size_type	max_size() const { return (_alloc_node.max_size()); }

	iterator		begin()
	{
		node    *tmp = _root;

		if (tmp)
		{
			while (tmp->left)
				tmp = tmp->left;
		}
		return (iterator(tmp, _root));
	}

	const_iterator	begin() const
	{
		node    *tmp = _root;

		if (tmp)
		{
			while (tmp->left)
				tmp = tmp->left;
		}
		return const_iterator(tmp, _root);
	}

	iterator		end()
	{
		return iterator(nullptr, _root);
	}

	const_iterator	end() const
	{
		return const_iterator(nullptr, _root);
	}

	reverse_iterator		rbegin()
	{
		return reverse_iterator(end());
	}
	
	const_reverse_iterator	rbegin() const
	{
		return const_reverse_iterator(end());
	}
	
	reverse_iterator		rend()
	{
		return reverse_iterator(begin());
	}
	
	const_reverse_iterator	rend() const
	{
		return const_reverse_iterator(begin());
	}
	ft::pair<iterator,bool> insert (const value_type& val)
	{
		ft::pair<node *, bool>	tmp = insert_node(&_root, val);
		return ft::make_pair(iterator(tmp.first, _root), tmp.second);
	}

	iterator insert( iterator hint, const value_type& value )
	{
		ft::pair<node *, bool>	tmp = insert_node(&_root, value);
		return iterator(tmp.first, _root);
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
		for (InputIt it = first; it != last; ++it)
			insert(*it);
	}

	void erase( iterator pos )
	{
		erase_node(pos._node);
	}
	void erase( iterator first, iterator last )
	{
		for (; first != last;)
			erase_node((first++)._node);
	}
	size_type erase( const value_type& key )
	{
		iterator it = find(key);
		if (it._node)
		{
			erase_node(it._node);
			return (1);
		}
		return (0);
	}

	iterator find( const value_type& key )
	{
		iterator p = lower_bound(key);
		if (p != end() && !_comp(key, *p))
			return (p);
		return (end());
	}
	const_iterator find( const value_type& key ) const
	{
		const_iterator p = lower_bound(key);
		if (p != end() && !_comp(key, *p))
			return (p);
		return (end());
	}
	ft::pair<iterator,iterator> equal_range( const value_type& key )
	{
		typedef ft::pair<iterator, iterator> pp;
		node* res = nullptr;
		node* rt = _root;
		while (rt != nullptr)
		{
			if (_comp(key, rt->data))
			{
				res = rt;
				rt = rt->left;
			}
			else if (_comp(rt->data, key))
				rt = rt->right;
			else
				return (pp(iterator(rt, _root), iterator(rt->right != nullptr ? tree_min(rt->right) : res, _root)));
		}
		return (pp(iterator(res, _root), iterator(res, _root)));
	}
	ft::pair<const_iterator,const_iterator> equal_range( const value_type& key ) const
	{
		typedef ft::pair<iterator, iterator> pp;
		node* res = nullptr;
		node* rt = _root;
		while (rt != nullptr)
		{
			if (_comp(key, rt->data))
			{
				res = rt;
				rt = rt->left;
			}
			else if (_comp(rt->data, key))
				rt = rt->right;
			else
				return (pp(iterator(rt, _root), iterator(rt->right != nullptr ? tree_min(rt->right) : res, _root)));
		}
		return (pp(iterator(res, _root), iterator(res, _root)));
	}

	iterator lower_bound( const value_type& key )
	{
		node *curr = _root;
		node *res = nullptr;

		while (curr != nullptr)
		{
			if (!_comp(curr->data, key))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return iterator(res, _root);
	}
	const_iterator lower_bound( const value_type& key ) const
	{
		node *curr = _root;
		node *res = nullptr;

		while (curr != nullptr)
		{
			if (!_comp(curr->data, key))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return const_iterator(res, _root);
	}

	iterator upper_bound( const value_type& key )
	{
		node *curr = _root;
		node *res = nullptr;

		while (curr != nullptr)
		{
			if (_comp(key, curr->data))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return iterator(res, _root);
	}
	const_iterator upper_bound( const value_type& key ) const
	{
		node *curr = _root;
		node *res = nullptr;

		while (curr != nullptr)
		{
			if (_comp(key, curr->value))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return const_iterator(res, _root);
	}

	void	swap(RBTree& other)
	{
		swaper(_root, other._root);
		swaper(_size, other._size);
	}

	void clear()
	{
		clear_tree(_root);
		_root = nullptr;
	}
private:
	node* tree_min(node* x)
	{
		while (x->left != nullptr)
			x = x->left;
		return (x);
	}
	node* tree_max(node* x)
	{
		while (x->right != nullptr)
			x = x->right;
		return (x);
	}
	template<class L>
	void	swaper(L & a, L & b)
	{
		L tmp = a;
		a = b;
		b = tmp;
	}
	node*	new_node(const T& data, node *parent = nullptr, node *left = nullptr, node *right = nullptr, COLOR col = RED)
	{
		node	* tmp = _alloc_node.allocate(1);
		_alloc_node.construct(tmp, node(data, parent, left, right, col));
		_size++;
		return tmp;
	}

	void	delete_node(node	*n)
	{
		_alloc_node.destroy(n);
		_alloc_node.deallocate(n, 1);
		_size--;
	}

	COLOR	is_color(node *n)
	{
		if (n == nullptr)
			return (BLACK);
		return (n->color);
	}

	node *	find_node(const T & key) const
	{
		node	* tmp = _root;

		while (tmp != nullptr)
		{
			if (_comp(key, tmp->data))
				tmp = tmp->left;
			else if (_comp(tmp->data, key))
				tmp = tmp->right;
			else
				return tmp;
		}
		return nullptr;
	}
	ft::pair<node*, bool>	insert_node(node **tree, const T & key)
	{
		node	*parent = *tree == nullptr ? nullptr : (*tree)->parent;
		while (*tree != nullptr)
		{
			if (_comp(key, (*tree)->data))
			{
				parent = *tree;
				tree = &((*tree)->left);
			}
			else if (_comp((*tree)->data, key))
			{
				parent = *tree;
				tree = &((*tree)->right);
			}
			else
				return ft::make_pair(*tree, false);
		}
		*tree = new_node(key, parent);
		insert_fix(*tree);
		return ft::make_pair(*tree, true);
	}
	void	insert_fix(node *n)
	{
		if (n == _root)
			n->color = BLACK;
		else
			n->color = RED;
		while (n != _root && n->parent &&  n->parent->color == RED)
		{
			if (n->parent == n->parent->parent->left)
			{
				node* y = n->parent->parent->right;
				if (y != nullptr && y->color == RED)
				{
					n = n->parent;
					n->color = BLACK;
					n = n->parent;
					if (n == _root)
						n->color = BLACK;
					else
						n->color = RED;
					y->color = BLACK;
				}
				else
				{
					if (n != n->parent->left)
					{
						n = n->parent;
						tree_left_rotate(n);
					}
					n = n->parent;
					n->color = BLACK;
					n = n->parent;
					n->color = RED;
					tree_right_rotate(n);
					break ;
				}
			}
			else
			{
				node* y = n->parent->parent->left;
				if (y != nullptr && y->color == RED)
				{
					n = n->parent;
					n->color = BLACK;
					n = n->parent;
					if (n == _root)
						n->color = BLACK;
					else
						n->color = RED;
					y->color = BLACK;
				}
				else
				{
					if (n == n->parent->left)
					{
						n = n->parent;
						tree_right_rotate(n);
					}
					n = n->parent;
					n->color = BLACK;
					n = n->parent;
					n->color = RED;
					tree_left_rotate(n);
					break ;
				}
			}
		}
	}

	void	copy_tree(node *&current, node *curr_parent, node *other_node)
	{
		if (other_node == nullptr)
			return ;
		current = new_node(other_node->data, curr_parent);
		copy_tree(current->left, current, other_node->left);
		copy_tree(current->right, current, other_node->right);
	}
	void	clear_tree(node *current)
	{
		if (current == nullptr)
			return ;
		clear_tree(current->left);
		clear_tree(current->right);
		delete_node(current);
	}

	void	node_swap(node *nd1, node *nd2)
	{
		swaper(nd1->color, nd2->color);
		if (nd1->left)
			nd1->left->parent = nd2;
		if (nd2->left)
			nd2->left->parent = nd1;
		swaper(nd1->left, nd2->left);

		if (nd1->right)
			nd1->right->parent = nd2;
		if (nd2->right)
			nd2->right->parent = nd1;
		swaper(nd1->right, nd2->right);

		if (nd1->parent)
		{
			if (nd1->parent->left == nd1)
				nd1->parent->left = nd2;
			else
				nd1->parent->right = nd2;
		}
		else
			_root = nd2;
		if (nd2->parent)
		{
			if (nd2->parent->left == nd2)
				nd2->parent->left = nd1;
			else
				nd2->parent->right = nd1;
		}
		else
			_root = nd1;
		swaper(nd1->parent, nd2->parent);
	}
	void	erase_node(node *n)
	{
		// node	*to_del = n;

		// if (n->left and n->right)
		// {
		// 	to_del = n->right;
		// 	while (to_del->left)
		// 		to_del = to_del->left;
		// 	node_swap(n, to_del);
		// 	erase_node(n);
		// }
		// else if (n->left)
		// {
		// 	n->left->color = BLACK;
		// 	n->left->parent = n->parent;
		// 	if (n->parent)
		// 	{
		// 		if (n->parent->left == n)
		// 			n->parent->left = n->left;
		// 		else
		// 			n->parent->right = n->left;
		// 	}
		// 	else
		// 		_root = n->left;
		// 	delete_node(to_del);
		// 	return ;
		// }
		// else if (n->right)
		// {
		// 	n->right->color = BLACK;
		// 	n->right->parent = n->parent;
		// 	if (n->parent)
		// 	{
		// 		if (n->parent->right == n)
		// 			n->parent->right = n->right;
		// 		else
		// 			n->parent->left = n->right;
		// 	}
		// 	else
		// 		_root = n->right;
		// 	delete_node(to_del);
		// 	return ;
		// }
		// else
		// {
		// 	if (n->color == RED)
		// 	{
		// 		node	**tmp;
		// 		if (n->parent->right == n)
		// 			tmp = &n->parent->right;
		// 		else
		// 			tmp = &n->parent->left;
		// 		delete_node(*tmp);
		// 		*tmp = nullptr;
		// 	}
		// 	else
		// 	{
		// 		node	**tmp;
		// 		node    *parent = n->parent;
		// 		if (n->parent)
		// 		{
		// 			if (n->parent->right == n)
		// 				tmp = &n->parent->right;
		// 			else
		// 				tmp = &n->parent->left;
		// 		}
		// 		else
		// 			tmp = &_root;
		// 		delete_node(*tmp);
		// 		*tmp = nullptr;
		// 		erase_fix(tmp, parent);
		// 	}
		// }
	}
	void	erase_fix(node **removed, node *parent)
	{
		while (parent != nullptr)
		{
			if (&parent->right == removed) 
			{
				if (is_color(parent) == RED) 
				{
					if (is_color(parent->left->right) == RED) 
					{
						parent->color = BLACK;
						tree_left_rotate(parent->left);
					}
					tree_right_rotate(parent);
					return ;
				}
				else 
				{
					if (is_color(parent->left) == RED) 
					{
						if (is_color(parent->left->right->left) == RED)
						{
							parent->left->right->left->color = BLACK;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
						}
						else if (is_color(parent->left->right->right) == RED)
						{
							swaper(parent->left->right->color, parent->left->right->right->color);
							tree_left_rotate(parent->left->right);
							parent->left->right->left->color = BLACK;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
						}
						else
						{
							parent->left->color = BLACK;
							parent->left->right->color = RED;
							tree_right_rotate(parent);
						}
						return;
					}
					else 
					{
						if (is_color(parent->left->right) == RED)
						{
							parent->left->right->color = BLACK;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
							return ;
						}
						else if (is_color(parent->left->left) == RED)
						{
							parent->left->left->color = BLACK;
							tree_right_rotate(parent);
							return ;
						}
						parent->left->color = RED;
						if (parent->parent)
						{
							if (parent->parent->left == parent)
								removed = &parent->parent->left;
							else
								removed = &parent->parent->right;
						}
						parent = parent->parent;
					}
				}
			}
			else 
			{
				if (is_color(parent) == RED)
				{
					if (is_color(parent->right->left) == RED)
					{
						parent->color = BLACK;
						tree_right_rotate(parent->right);
					}
					tree_left_rotate(parent);
					return ;
				}
				else 
				{
					if (is_color(parent->right) == RED) 
					{
						if (is_color(parent->right->left->right) == RED)
						{
							parent->right->left->right->color = BLACK;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
						}
						else if (is_color(parent->right->left->left) == RED)
						{
							swaper(parent->right->left->color, parent->right->left->left->color);
							tree_right_rotate(parent->right->left);
							parent->right->left->right->color = BLACK;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
						}
						else
						{
							parent->right->color = BLACK;
							parent->right->left->color = RED;
							tree_left_rotate(parent);
						}
						return;
					}
					else 
					{
						if (is_color(parent->right->left) == RED)
						{
							parent->right->left->color = BLACK;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
							return ;
						}
						else if (is_color(parent->right->right) == RED)
						{
							parent->right->right->color = BLACK;
							tree_left_rotate(parent);
							return ;
						}
						parent->right->color = RED;
						if (parent->parent)
						{
							if (parent->parent->right == parent)
								removed = &parent->parent->right;
							else
								removed = &parent->parent->left;
						}
						parent = parent->parent;
					}
				}
			}
		}
	}
	void	tree_left_rotate(node * n)
	{
		node* y = n->right;
		n->right = y->left;

		if (n->right != nullptr)
			n->right->parent = n;
		y->parent = n->parent;
		if (n->parent == nullptr)
			_root = y;
		else if (n == n->parent->right)
			n->parent->right = y;
		else
			n->parent->left = y;
		y->left = n;
		n->parent = y;
	}
	void	tree_right_rotate(node * n)
	{
		node* y = n->left;
		n->left = y->right;

		if (n->left != nullptr)
			n->left->parent = n;
		y->parent = n->parent;
		if (n->parent == nullptr)
			_root = y;
		else if (n == n->parent->left)
			n->parent->left = y;
		else
			n->parent->right = y;
		y->right = n;
		n->parent = y;
	}

};


} 

#endif