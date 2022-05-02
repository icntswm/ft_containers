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
	
	ft::pair<iterator,bool> insert (const value_type& val)//----------------------------------------------------------------------------------------
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
		erase_delete(pos._node);
	}
	void erase(iterator first, iterator last)
	{
		while (first != last) {
			erase_delete((first++)._node);
		}
	}
	size_type erase( const value_type& key )
	{
		iterator it = find(key);
		if (!it._node)
			return (0);
		erase_delete(it._node);
		return (1);
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
	ft::pair<iterator, iterator> equal_range( const value_type& key )
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
		node* tmp_root = _root;
		_root = other._root;
		other._root = tmp_root;

		size_type tmp_size = _size;
		_size = other._size;
		other._size = tmp_size;
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
	node*	new_node(const T& data, node *parent = nullptr, node *left = nullptr, node *right = nullptr, COLOR col = RED)
	{
		node*	tmp = _alloc_node.allocate(1);
		_alloc_node.construct(tmp, node(data, parent, left, right, col));
		++_size;
		return tmp;
	}

	void	delete_node(node *n)
	{
		_alloc_node.destroy(n);
		_alloc_node.deallocate(n, 1);
		--_size;
	}
	node* find_node(const value_type& key) const
	{
		node* tmp = _root;

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
	node* tree_next(node* n)
	{
		if (n->right != nullptr)
			return (tree_min(n->right));
		while (n != n->parent->left)
			n = n->parent;
		n = n->parent;
		return (n);
	}
	// ft::pair<iterator, bool> emplace_unique_key_args(node *r, const value_type& key) {
	// 	node* parent;

	// 	node* child = 
	// }











	ft::pair<node*, bool>	insert_node(node **tree, const value_type& key)
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





















	void	erase_delete(node* n)
	{
		node*	y = (n->left == nullptr || n->right == nullptr) ? n : tree_next(n);
		node*	x = y->left != nullptr ? y->left : y->right;
		node*	w = nullptr;

		if (x != nullptr)
			x->parent = y->parent;
		if (!y->parent) {
			_root = n->right;
			delete_node(n);
		}
		else if (y->parent && y == y->parent->left) {
			y->parent->left = x;
			if (y != _root)
				w = y->parent->right;
			else
				_root = x;
			delete_node(n);
		}
		else if (y->parent && y != y->parent->left)
		{
			y->parent->right = x;
			w = y->parent->left;
			delete_node(n);
		}
		COLOR remove_black = y->color;
		if (y != n) {
			y->parent = n->parent;
			if (n->parent && n == n->parent->left)
				y->parent->left = y;
			else
				y->parent->right = y;
			y->left = n->left;
			y->left->parent = y;
			y->right = n->right;
			if (y->right != nullptr)
				y->right->parent = y;
			y->color = n->color;
			if (_root == n)
				_root = y;
		}
		if (remove_black == BLACK && _root != nullptr)
			erase_fix(x, w);
	}
	void	erase_fix(node *x, node *w)
	{
		if (x != nullptr)
			x->color = BLACK;
		else
		{
			while (true)
			{
				if (w != w->parent->left)
				{
					if (w->color == RED)
					{
						w->color = BLACK;
						w->parent->color = RED;
						tree_left_rotate(w->parent);
						if (_root == w->left)
							_root = w;
						w = w->left->right;
					}
					if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK))
					{
						w->color = RED;
						x = w->parent;
						if (x == _root || x->color == RED)
						{
							x->color = BLACK;
							break ;
						}
						if (x == x->parent->left)
							w = x->parent->right;
						else
							w = x->parent->left;
					}
					else
					{
						if (w->right == nullptr || w->right->color == BLACK)
						{
							w->left->color = BLACK;
							w->color = RED;
							tree_right_rotate(w);
							w = w->parent;
						}
						w->color = w->parent->color;
						w->parent->color = BLACK;
						w->right->color = BLACK;
						tree_left_rotate(w->parent);
						break;
					}
				}
				else
				{
					if (w->color == RED)
					{
						w->color = BLACK;
						w->parent->color = RED;
						tree_right_rotate(w->parent);
						if (_root == w->right)
							_root = w;
						w = w->right->left;
					}
					if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK))
					{
						w->color = RED;
						x = w->parent;
						if (x->color == RED || x == _root)
						{
							x->color = BLACK;
							break;
						}
						if (x == x->parent->left)
							w = x->parent->right;
						else
							w = x->parent->left;
					}
					else
					{
						if (w->left == nullptr || w->left->color == BLACK)
						{
							w->right->color = BLACK;
							w->color = RED;
							tree_left_rotate(w);
							w = w->parent;
						}
						w->color = w->parent->color;
						w->parent->color = BLACK;
						w->left->color = BLACK;
						tree_right_rotate(w->parent);
						break;
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