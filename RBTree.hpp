
#ifndef FT_RBTREE
# define FT_RBTREE

#include "utility.hpp"
#include "reverse_iterator.hpp"
// #include "tree_iterator.hpp"
#include <algorithm>

namespace ft
{

template <class T>
class	RBTreeIterator;

template <class T>
class	RBTreeConstIterator;

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

// template<
//     class Category,
//     class T,
//     class Distance = std::ptrdiff_t,
//     class Pointer = T*,
//     class Reference = T&>
// struct iterator
// {
// 	typedef Category		iterator_category;	
// 	typedef T				value_type;
// 	typedef Distance		difference_type;
// 	typedef Pointer			pointer;
// 	typedef Reference		reference;
// };

template <class T>
struct _Node
{
	T		value;
	_Node	*parent;
	_Node	*left;
	_Node	*right;
	bool	is_red;
	// COLOR color;
	_Node(const T& value, _Node *parent = NULL, _Node *left = NULL,
			_Node *right = NULL, bool col = true) :
			value(value), parent(parent), left(left), right(right),
			is_red(col)
	{}
	bool getColor()
	{
		return is_red;
	}
};

template<class T>
void	swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
const T&	min( const T& a, const T& b )
{
	if (a < b)
		return a;
	return b;
}

template <class T>
const T&	max( const T& a, const T& b )
{
	if (a > b)
		return a;
	return b;
}


template <class Key, class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class RBTree
{
public:
	typedef	ft::pair<const Key, T>	value_type;
	typedef unsigned long			size_type;
	typedef Allocator				allocator_type;
	typedef Compare					comparator_type;

	typedef _Node<value_type>					Node;
	typedef	RBTreeIterator<value_type>		iterator;
	typedef RBTreeConstIterator<value_type>	const_iterator;

	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	typedef typename allocator_type::template rebind<Node>::other	node_allocator_type;
private:
	Node *			__root;
	size_type		__size;
	allocator_type	__alloc;
	comparator_type	__comp;
public:
	RBTree() : __root(NULL), __size(0), __alloc(allocator_type()), __comp(comparator_type())
	{}

	explicit RBTree( const Compare& comp,
						const Allocator& alloc = Allocator() )
			: __comp(comp), __alloc(alloc), __root(NULL), __size(0)
	{}

	RBTree( const RBTree& other ) :
		__alloc(other.__alloc), __comp(other.__comp), __root(NULL)
	{
		_copy_tree(&__root, NULL, other.__root);
		__size = other.__size;
	}

	~RBTree()
	{
		_clear_tree(__root);
	}

	RBTree& operator=( const RBTree& other )
	{
		Node	*tmp_tree;

		_copy_tree(&tmp_tree, NULL, other.__root);
		_clear_tree(__root);
		__root = tmp_tree;
		__size = other.__size;
		return *this;
	}

	allocator_type get_allocator() const
	{ return __alloc; }

	bool		empty() const
	{ return !__root; }

	size_type	size() const
	{ return __size; }

	size_type	max_size() const
	{ return (std::numeric_limits<std::ptrdiff_t>::max() / sizeof(std::ptrdiff_t));
 }
//--------------------------------------------
	iterator		begin()
	{
		Node* temp = __root;

		if (temp)
			while (temp->left)
				temp = temp->left;
		return (iterator(temp, __root));
	}

	const_iterator	begin() const
	{
		Node* temp = __root;

		if (temp)
			while (temp->left)
				temp = temp->left;
		return const_iterator(temp, __root);
	}

	iterator		end()
	{ return iterator(NULL, __root); }

	const_iterator	end() const
	{ return const_iterator(NULL, __root); }

	reverse_iterator		rbegin()
	{ return reverse_iterator(end()); }
	
	const_reverse_iterator	rbegin() const
	{ return const_reverse_iterator(end()); }
	
	reverse_iterator		rend()
	{ return reverse_iterator(begin()); }
	
	const_reverse_iterator	rend() const
	{ return const_reverse_iterator(begin()); }

	ft::pair<iterator,bool> insert( const value_type& value )
	{
		ft::pair<Node *, bool>	tmp = _insert_to_tree(&__root, value);
		return ft::make_pair(iterator(tmp.first, __root), tmp.second);
		// ft::pair<Node*, bool> tmp = insert_node(&__root, value);
		// return (ft::make_pair(iterator(tmp.first, __root), tmp.second));
	}

	iterator insert( iterator hint, const value_type& value )
	{
		ft::pair<Node *, bool>	tmp = _insert_to_tree(&__root, value);
		return iterator(tmp.first, __root);
		// insert_node(&__root, value);
		// return (iterator(hint._node, __root));
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
		for (InputIt it = first; it != last; ++it)
			insert(*it);
		// for (InputIt it = first; it != last; ++it)
		// 	insert(*it);
	}
	void	delete_node(Node *n)
	{
		node_allocator_type().destroy(n);
		node_allocator_type().deallocate(n, 1);
		--__size;
	}
	void erase( iterator pos )
	{
		Node* n = pos._node;
		Node* y = (n->left == nullptr || n->right == nullptr) ? n : tree_next(n);
		Node* x = y->left != nullptr ? y->left : y->right;
		Node* w = nullptr;

		if (x != nullptr)
			x->parent = y->parent;
		if (!y->parent) {
			__root = n->right;
			delete_node(n);
		}
		else if (y->parent && y == y->parent->left) {
			y->parent->left = x;
			if (y != __root)
				w = y->parent->right;
			else
				__root = x;
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
			if (__root == n)
				__root = y;
		}
		if (remove_black == BLACK && __root != nullptr)
			erase_fix(x, w);
	}
	void erase( iterator first, iterator last )
	{
		while (first != last) {
			erase(first++);
		}
	}
	size_type erase( const value_type& key )
	{
		iterator it = find(key);

		if (!it._node)
			return (0);
		erase(it);
		return (1);
	}

	iterator find( const value_type& key )
	{
		return iterator(_find_node(key), __root);
	}
	const_iterator find( const value_type& key ) const
	{
		return const_iterator(_find_node(key), __root);
	}

	ft::pair<iterator,iterator> equal_range( const value_type& key )
	{
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}
	ft::pair<const_iterator,const_iterator> equal_range( const value_type& key ) const
	{
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	iterator lower_bound( const value_type& key )
	{
		Node *curr = __root;
		Node *res = NULL;

		while (curr)
		{
			if (__comp(key, curr->value))
			{
				res = curr;
				curr = curr->left;
			} 
			else if (not __comp(curr->value, key)) // equals
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return iterator(res, __root);
	}
	const_iterator lower_bound( const value_type& key ) const
	{
		Node *curr = __root;
		Node *res = NULL;

		while (curr)
		{
			if (__comp(key, curr->value))
			{
				res = curr;
				curr = curr->left;
			} 
			else if (not __comp(curr->value, key)) // equals
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return const_iterator(res, __root);
	}	

	iterator upper_bound( const value_type& key )
	{
		Node *curr = __root;
		Node *res = NULL;

		while (curr)
		{
			if (__comp(key, curr->value))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return iterator(res, __root);
	}
	const_iterator upper_bound( const value_type& key ) const
	{
		Node *curr = __root;
		Node *res = NULL;

		while (curr)
		{
			if (__comp(key, curr->value))
			{
				res = curr;
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		return const_iterator(res, __root);
	}

	void	swap(RBTree& other)
	{
		ft::swap(other.__root, __root);
		ft::swap(other.__size, __size);
	}

	void clear()
	{ _clear_tree(__root); }
private:
	Node*	new_node(const value_type& data, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr, bool col = true)
	{
		Node* temp = node_allocator_type().allocate(1);
		node_allocator_type().construct(temp, Node(data, parent, left, right, col));
		++__size;
		return (temp);
	}
	ft::pair<Node*, bool>	_insert_to_tree(Node **tree, const value_type& key)
	{
		Node	*parent = *tree == NULL ? NULL : (*tree)->parent;

		while (*tree != NULL)
		{
			if (__comp(key, (*tree)->value))
			{
				parent = *tree;
				tree = &((*tree)->left);
			}
			else if (__comp((*tree)->value, key))
			{
				parent = *tree;
				tree = &((*tree)->right);
			}
			else
				return ft::make_pair(*tree, false);
		}
		*tree = new_node(key, parent);
		// _fix_node_after_inserting(*tree);
		insert_fix(*tree);
		return ft::make_pair(*tree, true);
	}
	void	_remove_node(Node	*node)
	{
		node_allocator_type().destroy(node);
		node_allocator_type().deallocate(node, 1);
		__size--;
	}

	bool	_is_red(Node *node)
	{ return node == NULL ? false : node->is_red; }

	Node *	_find_node(const value_type& key) const
	{
		Node	* tmp = __root;

		while (tmp != NULL)
		{
			if (__comp(key, tmp->value))
				tmp = tmp->left;
			else if (__comp(tmp->value, key))
				tmp = tmp->right;
			else
				return tmp;
		}
		return NULL;
	}
	ft::pair<Node*, bool> insert_node(Node **tree, const value_type& key)
	{
		Node* n;

		if (!(*tree))
			n = nullptr;
		else
			n = (*tree)->parent;
		while (*tree)
		{
			if (__comp(key, (*tree)->value))
			{
				n = *tree;
				tree = &((*tree)->left);
			}
			else if (__comp((*tree)->value, key))
			{
				n = *tree;
				tree = &((*tree)->right);
			}
			else
				return (ft::make_pair(*tree, false));
		}
		*tree = new_node(key, n);
		_fix_node_after_inserting(*tree);
		return (ft::make_pair(*tree, true));
	}
	void insert_fix(Node *n)
	{
		if (n == __root)
			n->is_red = false;
		else
			n->is_red = true;
		while (n && n->parent && n->parent->is_red == true)
		{
			if (n == n->parent->left)
			{
				// Node* y = n->parent->parent->right;
				if (_is_red(n->parent->parent->right))
				{
					n->parent->is_red = false;
					n->parent->parent->right->is_red = false;
					n->parent->parent->is_red = true;
					n = n->parent->parent;
					// n = n->parent;
					// n->is_red = false;
					// n = n->parent;
					// if (n == __root)
					// 	n->is_red = false;
					// else
					// 	n->is_red = true;
					// y->is_red = false;
				}
				else
				{
					n->parent->is_red = false;
					n->parent->parent->is_red = true;
					// n = n->parent;
					// n->is_red = false;
					// n = n->parent;
					// n->is_red = true;
					tree_right_rotate(n->parent->parent);
					break ;
				}
			}
			else
			{
				// Node* y = n->parent->parent->left;
				if (_is_red(n->parent->parent->left))
				{
					// n = n->parent;
					n->parent->is_red = false;
					n->parent->parent->is_red = true;
					n->parent->parent->left->is_red = false;
					// n = n->parent;
					// if (n == __root)
					// 	n->is_red = false;
					// else
					// 	n->is_red = true;
					// y->is_red = false;
				}
				else
				{
					// n = n->parent;
					n->parent->is_red = false;
					// n = n->parent;
					n->parent->is_red = true;
					tree_left_rotate(n->parent->parent);
					break ;
				}
			}
		}
		__root->is_red = false;
		std::cout << "LOL2\n";
	}
	void	_fix_node_after_inserting(Node *node)
	{
		while (_is_red(node->parent))
		{
			if (node == node->parent->left)
			{
				if (_is_red(node->parent->parent->right)) // red uncle
				{
					node->parent->is_red = false;
					node->parent->parent->right->is_red = false;
					node->parent->parent->is_red = true;
					node = node->parent->parent;
					continue;
				}
				else // black uncle
				{
					node->parent->is_red = false;
					node->parent->parent->is_red = true;
					tree_right_rotate(node->parent->parent);
					break ;
				}
			}
			else
			{
				if (_is_red(node->parent->parent->left)) // red uncle
				{
					node->parent->is_red = false;
					node->parent->parent->left->is_red = false;
					node->parent->parent->is_red = true;
					node = node->parent->parent;
					continue;
				}
				else // black uncle
				{
					node->parent->is_red = false;
					node->parent->parent->is_red = true;
					tree_left_rotate(node->parent->parent);
					break ;
				}
			}
		}
		__root->is_red = false;
	}

	void	_copy_tree(Node **current, Node *curr_parent, Node *other_node)
	{
		if (other_node == NULL)
			return ;
		*current = new_node(other_node->value, curr_parent);
		_copy_tree(&(*current)->left, *current, other_node->left);
		_copy_tree(&(*current)->right, *current, other_node->right);
	}
	void	_clear_tree(Node *current)
	{
		if (current == NULL) {
			__root = NULL;
			return ;
		}
		_clear_tree(current->left);
		_clear_tree(current->right);
		_remove_node(current);
	}


	void erase_fix(Node *x, Node *w)
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
						if (__root == w->left)
							__root = w;
						w = w->left->right;
					}
					if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK))
					{
						w->color = RED;
						x = w->parent;
						if (x == __root || x->color == RED)
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
						if (__root == w->right)
							__root = w;
						w = w->right->left;
					}
					if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK))
					{
						w->color = RED;
						x = w->parent;
						if (x->color == RED || x == __root)
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
	void tree_left_rotate(Node * n)
	{
		Node* y = n->right;
		n->right = y->left;

		if (n->right != nullptr)
			n->right->parent = n;
		y->parent = n->parent;
		if (n->parent == nullptr)
			__root = y;
		else if (n == n->parent->right)
			n->parent->right = y;
		else
			n->parent->left = y;
		y->left = n;
		n->parent = y;
	}
	void tree_right_rotate(Node * n)
	{
		Node* y = n->left;
		n->left = y->right;

		if (n->left != nullptr)
			n->left->parent = n;
		y->parent = n->parent;
		if (n->parent == nullptr)
			__root = y;
		else if (n == n->parent->left)
			n->parent->left = y;
		else
			n->parent->right = y;
		y->right = n;
		n->parent = y;
	}
};
















template <class T>
class	RBTreeIterator
{
public:
	typedef	T													iterator_type;
	typedef std::bidirectional_iterator_tag						  			iterator_category;
	typedef typename ft::iterator_traits<iterator_type*>::value_type         				value_type;
	typedef typename ft::iterator_traits<iterator_type*>::difference_type   				 difference_type;
	typedef typename ft::iterator_traits<iterator_type*>::pointer          			  pointer;
	typedef typename ft::iterator_traits<iterator_type*>::reference       					  reference;
	typedef	_Node<T>	Node;

	Node	*node;
	Node	*root;
	RBTreeIterator(Node * node, Node *root) : node(node), root(root) {};
public:
	RBTreeIterator() {}
	RBTreeIterator(const RBTreeIterator & other) : node(other.node), root(other.root) {};

	RBTreeIterator &	operator=(const RBTreeIterator & other) {
		node = other.node;
		return *this;
	}
	T &	operator*() {
		return node->value;
	}
	T *	operator->() {
		return &(node->value);
	}
	RBTreeIterator &	operator++() {
		if (node == NULL)
		{
			if (root == NULL)
				return *this;
			node = root;
			while (node->left)
				node = node->left;
			return *this;
		}
		if (node->right)
		{
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else
		{
			while (node->parent and node->parent->right == node)
				node = node->parent;
			node = node->parent;
		}
		return *this;
	}
	RBTreeIterator	operator++(int) {
		RBTreeIterator tmp(*this);
		++(*this);
		return tmp;
	}
	RBTreeIterator &	operator--() {
		if (node == NULL)
		{
			if (root == NULL)
				return *this;
			node = root;
			while (node->right)
				node = node->right;
			return *this;
		}
		if (node->left)
		{
			node = node->left;
			while (node->right)
				node = node->right;
		}
		else
		{
			while (node->parent and node->parent->left == node)
				node = node->parent;
			node = node->parent;
		}
		return *this;
	}
	RBTreeIterator	operator--(int) {
		RBTreeIterator tmp(*this);
		--(*this);
		return tmp;
	}
	operator RBTreeConstIterator<T>() const {
		return RBTreeConstIterator<T>(node, root);
	}
	friend bool operator==(
			RBTreeIterator lhs,
			RBTreeIterator rhs)
	{
		return lhs.node == rhs.node;
	}

	friend bool operator!=(
			RBTreeIterator lhs,
			RBTreeIterator rhs)
	{
		return lhs.node != rhs.node;
	}
};




template <class T>
class	RBTreeConstIterator
{
public:
	typedef	T													iterator_type;
	typedef std::bidirectional_iterator_tag						  			iterator_category;
	typedef typename ft::iterator_traits<const iterator_type*>::value_type         				value_type;
	typedef typename ft::iterator_traits<const iterator_type*>::difference_type   				 difference_type;
	typedef typename ft::iterator_traits<const iterator_type*>::pointer          			  pointer;
	typedef typename ft::iterator_traits<const iterator_type*>::reference       					  reference;
	typedef	_Node<T>	Node;

	const Node	*node;
	const Node	*root;
	RBTreeConstIterator(Node * node, Node *root) : node(node), root(root) {};
public:
	RBTreeConstIterator() {};
	RBTreeConstIterator(const RBTreeConstIterator & other) : node(other.node), root(other.root) {};
	RBTreeConstIterator &	operator=(const RBTreeConstIterator & other) {
		node = other.node;
		return *this;
	}
	const T &	operator*() const {
		return node->value;
	}
	const T *	operator->() const {
		return &(node->value);
	}
	RBTreeConstIterator &	operator++() {
		if (node == NULL)
		{
			if (root == NULL)
				return *this;
			node = root;
			while (node->left)
				node = node->left;
			return *this;
		}
		if (node->right)
		{
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else
		{
			while (node->parent and node->parent->right == node)
				node = node->parent;
			node = node->parent;
		}
		return *this;
	}
	RBTreeConstIterator	operator++(int) {
		RBTreeConstIterator tmp(*this);
		++(*this);
		return tmp;
	}
	RBTreeConstIterator &	operator--() {
		if (node == NULL)
		{
			if (root == NULL)
				return *this;
			node = root;
			while (node->right)
				node = node->right;
			return *this;
		}
		if (node->left)
		{
			node = node->left;
			while (node->right)
				node = node->right;
		}
		else
		{
			while (node->parent and node->parent->left == node)
				node = node->parent;
			node = node->parent;
		}
		return *this;
	}
	RBTreeConstIterator	operator--(int) {
		RBTreeConstIterator tmp(*this);
		--(*this);
		return tmp;
	}

	friend bool operator==(
			RBTreeConstIterator lhs,
			RBTreeConstIterator rhs)
	{
		return lhs.node == rhs.node;
	}

	friend bool operator!=(
			RBTreeConstIterator lhs,
			RBTreeConstIterator rhs)
	{
		return lhs.node != rhs.node;
	}
};

} // namespace ft

#endif