
// #ifndef TREE_HPP
// # define TREE_HPP
// #include "utility.hpp"
// #include "tree_iterator.hpp"
// #include <iostream>
// #include <limits>

// namespace ft {
// 	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
// 	class tree {
// 		public:
// 			typedef T														value_type;
// 			typedef Compare													value_compare;
// 			typedef Allocator												allocator_type;
// 			typedef std::size_t												size_type;
// 			// typedef std::ptrdiff_t											difference_type;
// 			typedef node_tree<T>                                            node;
// 			typedef typename allocator_type::template rebind<node>::other	node_allocator;
            
//             typedef class ft::tree_iterator<T> iterator;
// 		private:
// 			allocator_type 	_alloc_value;
// 			node_allocator	_alloc_node;
// 			value_compare	_comp;
// 			size_type		_size;

// 			node* _root; 
// 		public:
//     /*
// 			void initializeNULLNode()
// 			{
// 				_TNULL = _alloc_node.allocate(1);
// 				_alloc_node.construct(_TNULL, node_tree<value_type>());
// 				_TNULL->data = _alloc_value.allocate(1);
// 				_alloc_value.construct(_TNULL->data, value_type());
// 				_TNULL->color = BLACK;
// 				_TNULL->left = nullptr;
// 				_TNULL->right = nullptr;
// 				_root = _TNULL;
// 			}
// 			void preOrderHelper(node* _node)
// 			{
// 				if (_node != _TNULL) {
// 					std::cout << _node->data << " ";
// 					preOrderHelper(_node->left);
// 					preOrderHelper(_node->right);
// 				}
// 			}
// 			void inOrderHelper(node* _node)
// 			{
// 				if (_node != _TNULL) {
// 					inOrderHelper(_node->left);
// 					std::cout << _node->data << " ";
// 					inOrderHelper(_node->right);
// 				}
// 			}
// 			void postOrderHelper(node* _node)
// 			{
// 				if (_node != _TNULL) {
// 					postOrderHelper(_node->left);
// 					postOrderHelper(_node->right);
// 					std::cout << _node->data << " ";
// 				}
// 			}
// 			node* searchTreeHelper(node* _node, value_type key)
// 			{
// 				if (_node == _TNULL || key == *_node->data) {
// 					return (_node);
// 				}
// 				if (key < *_node->data)
// 				{
// 					return (searchTreeHelper(_node->left, key));
// 				}
// 				return (searchTreeHelper(_node->right, key));
// 			}
// 			void deleteFix(node *_x)
// 			{
// 				node* _s;

// 				while (_x != _root && _x->color == BLACK)
// 				{
// 					if (_x == _x->parent->left)
// 					{
// 						_s = _x->parent->right;
// 						if (_s->color == RED)
// 						{
// 							_s->color = BLACK;
// 							_x->parent->color = RED;
// 							leftRotate(_x->parent);
// 							_s = _x->parent->right;
// 						}
// 						if (_s->left->color == BLACK && _s->right->color == BLACK)
// 						{
// 							_s->color = RED;
// 							_x = _x->parent;
// 						}
// 						else
// 						{
// 							if (_s->right->color == BLACK)
// 							{
// 								_s->left->color = BLACK;
// 								_s->color = RED;
// 								rightRotate(_s);
// 								_s = _x->parent->right;
// 							}
// 							_s->color = _x->parent->color;
// 							_x->parent->color = BLACK;
// 							_s->right->color = BLACK;
// 							leftRotate(_x->parent);
// 							_x = _root;
// 						}
// 					}
// 					else
// 					{
// 						_s = _x->parent->left;
// 						if (_s->color == RED)
// 						{
// 							_s->color = BLACK;
// 							_x->parent->color = RED;
// 							rightRotate(_x->parent);
// 							_s = _x->parent->left;
// 						}
// 						if (_s->right->color == BLACK && _s->right->color == BLACK)
// 						{
// 							_s->color = RED;
// 							_x = _x->parent;
// 						}
// 						else
// 						{
// 							if (_s->left->color == BLACK)
// 							{
// 								_s->right->color = BLACK;
// 								_s->color = RED;
// 								leftRotate(_s);
// 								_s = _x->parent->left;
// 							}
// 							_s->color = _x->parent->color;
// 							_x->parent->color = BLACK;
// 							_s->left->color = BLACK;
// 							rightRotate(_x->parent);
// 							_x = _root;
// 						}
// 					}
// 				}
// 				_x->color = BLACK;
// 			}
// 			void rbTransplant(node *_u, node *_v)
// 			{
// 				if (_u->parent == nullptr)
// 				{
// 					_root = _v;
// 				}
// 				else if (_u == _u->parent->left)
// 				{
// 					_u->parent->left = _v;
// 				}
// 				else
// 				{
// 					_u->parent->right = _v;
// 				}
// 				_v->parent = _u->parent;
// 			}
// 			void deleteNodeHelper(node* _node, value_type key)
// 			{
// 				node* _z = _TNULL;
// 				node* _x;
// 				node* _y;

// 				while (_node != _TNULL)
// 				{
// 					if (*_node->data == key)
// 					{
// 						_z = _node;
// 						_alloc_value.destroy(_node->data);
// 						_alloc_value.deallocate(_node->data, 1);
// 						break ;
// 					}
// 					if (*_node->data <= key)
// 					{
// 						_node = _node->right;
// 					}
// 					else
// 					{
// 						_node = _node->left;
// 					}
// 				}
// 				if (_z == _TNULL)
// 				{
// 					std::cout << "Key not found in the tree" << std::endl;
// 					return;
// 				}
// 				_y = _z;
// 				COLOR y_original_color = _y->color;
// 				if (_z->left == _TNULL)
// 				{
// 					_x = _z->right;
					// rbTransplant(_z, _z->right);
// 				}
// 				else if (_z->right == _TNULL)
// 				{
// 					_x = _z->left;
// 					rbTransplant(_z, _z->left);
// 				}
// 				else
// 				{
// 					_y = minimum(_z->right);
// 					y_original_color = _y->color;
// 					_x = _y->right;
// 					if (_y->parent == _z)
// 					{
// 						_x->parent = _y;
// 					}
// 					else
// 					{
// 						rbTransplant(_y, _y->right);
// 						_y->right = _z->right;
// 						_y->right->parent = _y;
// 					}
// 					rbTransplant(_z, _y);
// 					_y->left = _z->left;
// 					_y->left->parent = _y;
// 					_y->color = _z->color;
// 				}
// 				if (y_original_color == BLACK)
// 				{
// 					deleteFix(_x);
// 				}
// 				_alloc_node.deallocate(_z, 1);
// 				--_size;
// 			}

// 			void insertFix(node* _k)
// 			{
// 				node* _u;

// 				while (_k->parent->color == RED)
// 				{
// 					if (_k->parent == _k->parent->parent->right)
// 					{
// 						_u = _k->parent->parent->left;
// 						if (_u->color == RED)
// 						{
// 							_u->color = BLACK;
// 							_k->parent->color = BLACK;
// 							_k->parent->parent->color = RED;
// 							_k = _k->parent->parent;
// 						}
// 						else
// 						{
// 							if (_k == _k->parent->left)
// 							{
// 								_k = _k->parent;
// 								rightRotate(_k);
// 							}
// 							_k->parent->color = BLACK;
// 							_k->parent->parent->color = RED;
// 							leftRotate(_k->parent->parent);
// 						}
// 					}
// 					else
// 					{
// 						_u = _k->parent->parent->right;

// 						if (_u->color == RED)
// 						{
// 							_u->color = BLACK;
// 							_k->parent->color = BLACK;
// 							_k->parent->parent->color = RED;
// 							_k = _k->parent->parent;
// 						}
// 						else
// 						{
// 							if (_k == _k->parent->right)
// 							{
// 								_k = _k->parent;
// 								leftRotate(_k);
// 							}
// 							_k->parent->color = BLACK;
// 							_k->parent->parent->color = RED;
// 							rightRotate(_k->parent->parent);
// 						}
// 					}
// 					if (_k == _root)
// 						break;
// 				}
// 				_root->color = BLACK;
// 			}
// 			void printHelper(node* _root, std::string indent, bool last)
// 			{
// 				if (_root != _TNULL)
// 				{
// 					std::cout << indent;
// 					if (last)
// 					{
// 						std::cout << "R----";
// 						indent += "   ";
// 					}
// 					else
// 					{
// 						std::cout << "L----";
// 						indent += "|  ";
// 					}
// 					std::string sColor = _root->color ? "RED" : "BLACK";
// 					std::cout << *_root->data << "(" << sColor << ")" << std::endl;
// 					printHelper(_root->left, indent, false);
// 					printHelper(_root->right, indent, true);
// 				}
// 			}
// 			void preorder() {
// 				preOrderHelper(_root);
// 			}

// 			void inorder()
// 			{
// 				inOrderHelper(_root);
// 			}

// 			void postorder()
// 			{
// 				postOrderHelper(_root);
// 			}

// 			node* searchTree(value_type k) {
// 				return (searchTreeHelper(_root, k));
// 			}
// 			node* minimum(node* _node)
// 			{
// 				while (_node->left != _TNULL)
// 				{
// 					_node = _node->left;
// 				}
// 				return (_node);
// 			}
// 			node* maximum(node* _node) {
// 				while (_node->right != _TNULL)
// 				{
// 					_node = _node->right;
// 				}
// 				return (_node);
// 			}
// 			node* successor(node* _x)
// 			{
// 				if (_x->right != _TNULL)
// 				{
// 					return (minimum(_x->right));
// 				}
// 				node* _y = _x->parent;
// 				while (_y != _TNULL && _x == _y->right)
// 				{
// 					_x = _y;
// 					_y = _y->parent;
// 				}
// 				return (_y);
// 			}
// 			node* predecessor(node* _x)
// 			{
// 				if (_x->left != _TNULL)
// 				{
// 					return (maximum(_x->left));
// 				}
// 				node* _y = _x->parent;
// 				while (_y != _TNULL && _x == _y->left)
// 				{
// 					_x = _y;
// 					_y = _y->parent;
// 				}
// 				return (_y);
// 			}
// 			void leftRotate(node* _x)
// 			{
// 				node* _y = _x->right;
// 				_x->right = _y->left;
// 				if (_y->left != _TNULL)
// 				{
// 					_y->left->parent = _x;
// 				}
// 				_y->parent = _x->parent;
// 				if (_x->parent == nullptr)
// 				{
// 					_root = _y;
// 				}
// 				else if (_x == _x->parent->left)
// 				{
// 					_x->parent->left = _y;
// 				}
// 				else
// 				{
// 					_x->parent->right = _y;
// 				}
// 				_y->left = _x;
// 				_x->parent = _y;
// 			}
// 			void rightRotate(node* _x)
// 			{
// 				node* _y = _x->left;
// 				_x->left = _y->right;
// 				if (_y->right != _TNULL)
// 				{
// 					_y->right->parent = _x;
// 				}
// 				_y->parent = _x->parent;
// 				if (_x->parent == nullptr)
// 				{
// 					_root = _y;
// 				}
// 				else if (_x == _x->parent->right)
// 				{
// 					_x->parent->right = _y;
// 				}
// 				else {
// 					_x->parent->left = _y;
// 				}
// 				_y->right = _x;
// 				_x->parent = _y;
// 			}
// 			void insert(value_type key)
// 			{
// 				node* _node = _alloc_node.allocate(1);
// 				_alloc_node.construct(_node, node_tree<value_type>());
// 				_node->data = _alloc_value.allocate(1);
// 				_alloc_value.construct(_node->data, key);
// 				_node->parent = nullptr;
// 				_node->left = _TNULL;
// 				_node->right = _TNULL;
// 				_node->color = RED;

// 				node* _y = nullptr;
// 				node* _x = _root;

// 				while (_x != _TNULL)
// 				{
// 					_y = _x;
// 					if (*_node->data < *_x->data)
// 					{
// 						_x = _x->left;
// 					}
// 					else
// 					{
// 						_x = _x->right;
// 					}
// 				}
// 				_node->parent = _y;
// 				if (_y == nullptr)
// 				{
// 					_root = _node;
// 				}
// 				else if (*_node->data < *_y->data)
// 				{
// 					_y->left = _node;
// 				}
// 				else
// 				{
// 					_y->right = _node;
// 				}
// 				++_size;
// 				if (_node->parent == nullptr)
// 				{
// 					_node->color = BLACK;
// 					return;
// 				}
// 				if (_node->parent->parent == nullptr)
// 				{
// 					return;
// 				}
// 				insertFix(_node);
// 			}
// 			node* getRoot()
// 			{
// 				return (_root);
// 			}
// 			void deleteNode(value_type data)
// 			{
// 				deleteNodeHelper(_root, data);
// 			}
// 			void printTree()
// 			{
// 				if (_root)
// 				{
// 					printHelper(_root, "", true);
// 				}
// 			}
// 			void	clearChilds(node* child)
// 			{
// 				if (child != _TNULL)
// 				{
// 					clearChilds(child->left);
// 					clearChilds(child->right);
// 					clearNode(child);
// 				}	
				
// 			}
// 			void	clearNode(node* _node)
// 			{
// 				// std::cout << "clear node: " << *_node->data << "\n";
// 				if (_node)
// 				{
// 					_alloc_value.destroy(_node->data);
// 					_alloc_value.deallocate(_node->data, 1);
// 					_alloc_node.deallocate(_node, 1);
// 				}
// 			}
// 			void	clearAll()
// 			{
// 				clearChilds(_root);
// 				_alloc_value.destroy(_TNULL->data);
// 				_alloc_value.deallocate(_TNULL->data, 1);
// 				_alloc_node.deallocate(_TNULL, 1);
// 			}
// 			size_type getSize()
// 			{
// 				return (_size);
// 			}
// 			*/
// 		public:
// 			explicit tree(const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type())
// 				: _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _size(0), _root(nullptr) {}

// 			// template <class InputIt>
//   			// tree (InputIt first, InputIt last, const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
// 			// 	: _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _size(0)
// 			// {
// 			// 	initializeNULLNode();
// 			// 	//insert(first, last);	
// 			// }
// 			tree (const tree& x);
// 			~tree()
// 			{
// 				// clearAll();
// 			}
// 			tree& operator= (const tree& x) {}
//             allocator_type get_allocator() const
//             {
//                 return (_alloc_value);
//             }
//             bool empty() const
//             {
//                 return (_size == 0);
//             }
//             size_type size() const
//             {
//                 return (_size);
//             }
//             // size_type max_size() const
//             // {
//             //     return (_alloc_node.max_size());
//             // }
// 			iterator begin()
// 			{
// 				node* tmp = _root;
//                 if (tmp)
//                 {
//                     while (tmp->left)
//                         tmp = tmp->left;
//                 }
//                 return (iterator(tmp, _root));
// 			}
// 			iterator end()
// 			{
// 				return iterator(nullptr, _root);
//             }
// 		};
// }
			
// #endif




#ifndef FT_RBTREE
# define FT_RBTREE

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
	typedef Allocator				allocator_type;
	typedef Compare					comparator_type;

	typedef node_tree<T>			node;
	typedef tree_iterator<T>		iterator;
	typedef RBTreeConstIterator<T>	const_iterator;

	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	typedef typename allocator_type::template rebind<node>::other	node_allocator;
private:
	size_type		_size;
	allocator_type	_alloc_value;
	node_allocator	_alloc_node;
	comparator_type	_comp;
	node *			_root;
public:
	RBTree() : _size(0), _alloc_value(), _alloc_node(), _comp(), _root(NULL){}

	explicit RBTree( const Compare& comp, const Allocator& alloc = Allocator() )
			: _size(0), _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _root(NULL) {}

	RBTree( const RBTree& other )
		: _alloc_value(other._alloc_value), _alloc_node(other._alloc_node), _comp(other._comp), _root(NULL)
	{
		copy_tree(_root, NULL, other._root);
		_size = other._size;
	}
	~RBTree()
	{
		clear_tree(_root);
	}

	RBTree& operator=( const RBTree& other )
	{
		node	*tmp_tree = NULL;

		copy_tree(tmp_tree, NULL, other._root);
		clear_tree(_root);
		_root = tmp_tree;
		_size = other._size;
		return *this;
	}

	allocator_type get_allocator() const { return _alloc_value; }

	bool		empty() const{ return _root == NULL; }

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
		return iterator(tmp, _root);
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
		return iterator(NULL, _root);
	}

	const_iterator	end() const
	{
		return const_iterator(NULL, _root);
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
		node* res = NULL;
		node* rt = _root;
		while (rt != NULL)
		{
			if (_comp(key, rt->data))
			{
				res = rt;
				rt = rt->left;
			}
			else if (_comp(rt->data, key))
				rt = rt->right;
			else
				return (pp(iterator(rt, _root), iterator(rt->right != NULL ? tree_min(rt->right) : res, _root)));
		}
		return (pp(iterator(res, _root), iterator(res, _root)));
	}
	ft::pair<const_iterator,const_iterator> equal_range( const value_type& key ) const
	{
		typedef ft::pair<iterator, iterator> pp;
		node* res = NULL;
		node* rt = _root;
		while (rt != NULL)
		{
			if (_comp(key, rt->data))
			{
				res = rt;
				rt = rt->left;
			}
			else if (_comp(rt->data, key))
				rt = rt->right;
			else
				return (pp(iterator(rt, _root), iterator(rt->right != NULL ? tree_min(rt->right) : res, _root)));
		}
		return (pp(iterator(res, _root), iterator(res, _root)));
	}

	iterator lower_bound( const value_type& key )
	{
		node *curr = _root;
		node *res = NULL;

		while (curr != NULL)
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
		node *res = NULL;

		while (curr != NULL)
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
		node *res = NULL;

		while (curr != NULL)
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
		node *res = NULL;

		while (curr != NULL)
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
		_root = NULL;
	}
private:
	node* tree_min(node* x)
	{
		while (x->left != NULL)
			x = x->left;
		return (x);
	}
	node* tree_max(node* x)
	{
		while (x->right != NULL)
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
	node*	new_node(const T& data, node *parent = NULL, node *left = NULL, node *right = NULL, bool is_red = true)
	{
		node	* tmp = _alloc_node.allocate(1);
		_alloc_node.construct(tmp, node(data,parent, left, right, is_red));
		_size++;
		return tmp;
	}

	void	delete_node(node	*n)
	{
		_alloc_node.destroy(n);
		_alloc_node.deallocate(n, 1);
		_size--;
	}

	bool	_is_red(node *n)
	{
		if (n == NULL)
			return (false);
		return (n->is_red);
	}

	node *	find_node(const T & key) const
	{
		node	* tmp = _root;

		while (tmp != NULL)
		{
			if (_comp(key, tmp->data))
				tmp = tmp->left;
			else if (_comp(tmp->data, key))
				tmp = tmp->right;
			else
				return tmp;
		}
		return NULL;
	}
	ft::pair<node*, bool>	insert_node(node **tree, const T & key)
	{
		node	*parent = *tree == NULL ? NULL : (*tree)->parent;
		while (*tree != NULL)
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
		while (_is_red(n->parent))
		{
			if (n == n->parent->left)
			{
				if (_is_red(n->parent->parent->right))
				{
					n->parent->is_red = false;
					n->parent->parent->right->is_red = false;
					n->parent->parent->is_red = true;
					n = n->parent->parent;
					continue;
				}
				else 
				{
					n->parent->is_red = false;
					n->parent->parent->is_red = true;
					tree_right_rotate(n->parent->parent);
					break ;
				}
			}
			else
			{
				if (_is_red(n->parent->parent->left))
				{
					n->parent->is_red = false;
					n->parent->parent->left->is_red = false;
					n->parent->parent->is_red = true;
					n = n->parent->parent;
					continue;
				}
				else
				{
					n->parent->is_red = false;
					n->parent->parent->is_red = true;
					tree_left_rotate(n->parent->parent);
					break ;
				}
			}
		}
		_root->is_red = false;
	}

	void	copy_tree(node *&current, node *curr_parent, node *other_node)
	{
		if (other_node == NULL)
			return ;
		current = new_node(other_node->data, curr_parent);
		copy_tree(current->left, current, other_node->left);
		copy_tree(current->right, current, other_node->right);
	}
	void	clear_tree(node *current)
	{
		if (current == NULL)
			return ;
		clear_tree(current->left);
		clear_tree(current->right);
		delete_node(current);
	}

	void	_swap_nodes(node *nd1, node *nd2)
	{
		swaper(nd1->is_red, nd2->is_red);
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
		node	*to_del = n;

		if (n->left and n->right)
		{
			to_del = n->right;
			while (to_del->left)
				to_del = to_del->left;
			_swap_nodes(n, to_del);
			erase_node(n);
		}
		else if (n->left)
		{
			n->left->is_red = false;
			n->left->parent = n->parent;
			if (n->parent)
			{
				if (n->parent->left == n)
					n->parent->left = n->left;
				else
					n->parent->right = n->left;
			}
			else
				_root = n->left;
			delete_node(to_del);
			return ;
		}
		else if (n->right)
		{
			n->right->is_red = false;
			n->right->parent = n->parent;
			if (n->parent)
			{
				if (n->parent->right == n)
					n->parent->right = n->right;
				else
					n->parent->left = n->right;
			}
			else
				_root = n->right;
			delete_node(to_del);
			return ;
		}
		else
		{
			if (n->is_red)
			{
				node	**tmp;
				if (n->parent->right == n)
					tmp = &n->parent->right;
				else
					tmp = &n->parent->left;
				delete_node(*tmp);
				*tmp = NULL;
			}
			else
			{
				node	**tmp;
				node    *parent = n->parent;
				if (n->parent)
				{
					if (n->parent->right == n)
						tmp = &n->parent->right;
					else
						tmp = &n->parent->left;
				}
				else
					tmp = &_root;
				delete_node(*tmp);
				*tmp = NULL;
				erase_fix(tmp, parent);
			}
		}
	}
	void	erase_fix(node **removed, node *parent)
	{
		while (parent != NULL)
		{
			if (&parent->right == removed) 
			{
				if (_is_red(parent)) 
				{
					if (_is_red(parent->left->right)) 
					{
						parent->is_red = false;
						tree_left_rotate(parent->left);
					}
					tree_right_rotate(parent);
					return ;
				}
				else 
				{
					if (_is_red(parent->left)) 
					{
						if (_is_red(parent->left->right->left))
						{
							parent->left->right->left->is_red = false;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
						}
						else if (_is_red(parent->left->right->right))
						{
							swaper(parent->left->right->is_red,
										parent->left->right->right->is_red);
							tree_left_rotate(parent->left->right);
							parent->left->right->left->is_red = false;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
						}
						else
						{
							parent->left->is_red = false;
							parent->left->right->is_red = true;
							tree_right_rotate(parent);
						}
						return;
					}
					else 
					{
						if (_is_red(parent->left->right))
						{
							parent->left->right->is_red = false;
							tree_left_rotate(parent->left);
							tree_right_rotate(parent);
							return ;
						}
						else if (_is_red(parent->left->left))
						{
							parent->left->left->is_red = false;
							tree_right_rotate(parent);
							return ;
						}
						parent->left->is_red = true;
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
				if (_is_red(parent))
				{
					if (_is_red(parent->right->left))
					{
						parent->is_red = false;
						tree_right_rotate(parent->right);
					}
					tree_left_rotate(parent);
					return ;
				}
				else 
				{
					if (_is_red(parent->right)) 
					{
						if (_is_red(parent->right->left->right))
						{
							parent->right->left->right->is_red = false;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
						}
						else if (_is_red(parent->right->left->left))
						{
							swaper(parent->right->left->is_red,
										parent->right->left->left->is_red);
							tree_right_rotate(parent->right->left);
							parent->right->left->right->is_red = false;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
						}
						else
						{
							parent->right->is_red = false;
							parent->right->left->is_red = true;
							tree_left_rotate(parent);
						}
						return;
					}
					else 
					{
						if (_is_red(parent->right->left))
						{
							parent->right->left->is_red = false;
							tree_right_rotate(parent->right);
							tree_left_rotate(parent);
							return ;
						}
						else if (_is_red(parent->right->right))
						{
							parent->right->right->is_red = false;
							tree_left_rotate(parent);
							return ;
						}
						parent->right->is_red = true;
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
		node* tmp = n->right;

		n->right = tmp->left;
		if (tmp->left != NULL)
		{
			tmp->left->parent = n;
		}
		tmp->parent = n->parent;
		if (n->parent == NULL)
		{
			_root = tmp;
		}
		else if (n == n->parent->left)
		{
			n->parent->left = tmp;
		}
		else {
			n->parent->right = tmp;
		}
		tmp->left = n;
		n->parent = tmp;
	}
	void	tree_right_rotate(node * n)
	{
		node* tmp = n->left;

		n->left = tmp->right;
		if (tmp->right != NULL)
		{
			tmp->right->parent = n;
		}
		tmp->parent = n->parent;
		if (n->parent == NULL)
		{
			_root = tmp;
		}
		else if (n == n->parent->right)
		{
			n->parent->right = tmp;
		}
		else {
			n->parent->left = tmp;
		}
		tmp->right = n;
		n->parent = tmp;
	}

};


} 

#endif