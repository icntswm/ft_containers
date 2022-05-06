#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"

namespace ft {
	// template <class IteratorType>
	// class tree_const_iterator {
	// 	public:
	// 		typedef	IteratorType														iterator_type;
	// 		typedef std::bidirectional_iterator_tag										iterator_category;
	// 		typedef typename ft::iterator_traits<const iterator_type*>::value_type		value_type;
	// 		typedef typename ft::iterator_traits<const iterator_type*>::difference_type	difference_type;
	// 		typedef typename ft::iterator_traits<const iterator_type*>::pointer			pointer;
	// 		typedef typename ft::iterator_traits<const iterator_type*>::reference		reference;
	// 		typedef	node_tree<iterator_type>											node;	
	// 		const node*	_node;
	// 		const node*	_root;
	// 	private:
	// 		node* tree_min(node* x)
	// 		{
	// 			while (x->left != nullptr)
	// 				x = x->left;
	// 			return (x);
	// 		}
	// 		node* tree_max(node* x)
	// 		{
	// 			while (x->right != nullptr)
	// 				x = x->right;
	// 			return (x);
	// 		}
	// 		node* tree_parent(node* x, bool is_left)
	// 		{
	// 			if (is_left)
	// 				while (x->parent && x->parent->left == x)
	// 					x = x->parent;
	// 			else
	// 				while (x->parent && x->parent->right == x)
	// 					x = x->parent;
	// 			x = x->parent;
	// 			return (x);
	// 		}
	// 	public:
	// 		tree_const_iterator() {};
	// 		tree_const_iterator(node* n, node* r) : _node(n), _root(r) {}
	// 		tree_const_iterator(const tree_const_iterator& it) : _node(it._node), _root(it._root) {};
	// 		tree_const_iterator& operator=(const tree_const_iterator& it) {
	// 			_node = it._node;
	// 			_root = it._root;
	// 			return (*this);
	// 		}
	// 		reference operator*() const {
	// 			return (_node->data);
	// 		}
	// 		pointer operator->() const {
	// 			return (&_node->data);
	// 		}
	// 		tree_const_iterator& operator++()
	// 		{
	// 			if (_node == nullptr && _root == nullptr)
	// 				return (*this);
	// 			if (_node == nullptr)
	// 			{
	// 				_node = _root;
	// 				while (_node->left)
	// 					_node = _node->left;
	// 			}
	// 			else
	// 			{
	// 				if (_node->right)
	// 					_node = tree_min(_node->right);
	// 				else
	// 				{
	// 					while (_node->parent && _node->parent->right == _node)
	// 						_node = _node->parent;
	// 					_node = _node->parent;
	// 				}
	// 			}
	// 			return (*this);
	// 		}
	// 		tree_const_iterator operator++(int) {
	// 			tree_const_iterator temp(*this);
	// 			++(*this);
	// 			return temp;
	// 		}
	// 		tree_const_iterator& operator--()
	// 		{
	// 			if (_node == nullptr && _root == nullptr)
	// 				return (*this);
	// 			if (_node == nullptr)
	// 				_node = tree_max(_root);
	// 			else
	// 			{
	// 				if (_node->left)
	// 					_node = tree_max(_node->left);
	// 				else
	// 					_node = tree_parent(_node, true);
	// 			}
	// 			return (*this);
	// 		}
	// 		tree_const_iterator	operator--(int) {
	// 			tree_const_iterator temp(*this);
	// 			--(*this);
	// 			return (temp);
	// 		}
	// 		friend bool operator==(tree_const_iterator lhs, tree_const_iterator rhs)
	// 		{
	// 			return (lhs._node == rhs._node);
	// 		}
	// 		friend bool operator!=(tree_const_iterator lhs, tree_const_iterator rhs)
	// 		{
	// 			return (lhs._node != rhs._node);
	// 		}
	// };
	template<class IteratorType>
	class tree_iterator {
		public:
			typedef	IteratorType													iterator_type;
			typedef std::bidirectional_iterator_tag									iterator_category;
			typedef typename ft::iterator_traits<iterator_type*>::value_type		value_type;
			typedef typename ft::iterator_traits<iterator_type*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type*>::pointer			pointer;
			typedef typename ft::iterator_traits<const iterator_type*>::pointer		const_pointer;
			typedef typename ft::iterator_traits<iterator_type*>::reference			reference;
			typedef typename ft::iterator_traits<const iterator_type*>::reference	const_reference;
			typedef	node_tree<iterator_type>										node;
			
			node* _node;
			node* _root;
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
			node* tree_parent(node* x, bool is_left)
			{
				if (is_left)
					while (x->parent && x->parent->left == x)
						x = x->parent;
				else
					while (x->parent && x->parent->right == x)
						x = x->parent;
				x = x->parent;
				return (x);
			}
		public:
		tree_iterator() {}
			tree_iterator(node* n, node* r) : _node(n), _root(r) {}
			tree_iterator(const tree_iterator& it) : _node(it._node), _root(it._root) {}
			~tree_iterator() {}
			tree_iterator& operator=(const tree_iterator& it)
			{
				_node = it._node;
				_root = it._root;
				return (*this);
			}
			reference operator*()
			{
				return (_node->data);
			}
			const_reference operator*() const
			{
				return (_node->data);
			}
			pointer operator->()
			{
				return (&_node->data);
			}
			const_pointer operator->() const
			{
				return (&_node->data);
			}
			tree_iterator& operator++()
			{
				if (!_node && !_root)
					return (*this);
				if (!_node)
					_node = tree_min(_root);
				else
				{
					if (_node->right)
						_node = tree_min(_node->right);
					else
						_node = tree_parent(_node, false);
				}
				return (*this);
			}
			tree_iterator operator++ (int)
			{
				tree_iterator temp(*this);
				++(*this);
				return (temp);
			}
			tree_iterator& operator-- ()
			{
				if (!_node && !_root)
					return (*this);
				if (!_node)
					_node = tree_max(_root);
				else
				{
					if (_node->left)
						_node = tree_max(_node->left);
					else
						_node = tree_parent(_node, true);
				}
				return (*this);
			}
			tree_iterator operator-- (int)
			{
				tree_iterator temp(*this);
				--(*this);
				return (temp);
			}
			friend bool operator== (const tree_iterator& lhs, const tree_iterator& rhs)
			{
				return (lhs._node == rhs._node);
			}
			friend bool operator!= (const tree_iterator& lhs, const tree_iterator& rhs)
			{
				return (lhs._node != rhs._node);
			}
	};
}








// namespace ft {
// 	template<class Val>
// 	class TreeIterator {
// 	public:
// 		typedef std::bidirectional_iterator_tag       iterator_category;
// 		typedef typename ft::iterator_traits<Val *>::value_type   value_type;
// 		typedef typename ft::iterator_traits<Val *>::reference    reference;
// 		typedef typename ft::iterator_traits<Val *>::pointer   pointer;
// 		typedef const typename ft::iterator_traits<Val *>::reference  const_reference;
// 		typedef const typename ft::iterator_traits<Val *>::pointer  const_pointer;
// 		typedef typename ft::iterator_traits<Val *>::difference_type difference_type;
// 		typedef std::size_t            size_type;
// 		typedef node_tree<Val *>*    node_pointer;
// 	protected:
// 		node_pointer root;
// 		node_pointer lol;
// 		node_pointer minimum(node_pointer ptr) const {
// 			while (ptr->left && !ptr->left->isNil)
// 				ptr = ptr->left;
// 			return ptr;
// 		}
// 		node_pointer maximum(node_pointer ptr) const {
// 			while (!ptr->right->isNil)
// 				ptr = ptr->right;
// 			return ptr;
// 		}
// 	public:
// 		// tree_const_iterator() {};
// // 			tree_const_iterator(node* n, node* r) : _node(n), _root(r) {}
// // 			tree_const_iterator(const tree_const_iterator& it) : _node(it._node), _root(it._root) {};
// // 			tree_const_iterator& operator=(const tree_const_iterator& it) {
// // 				_node = it._node;
// // 				_root = it._root;
// // 				return (*this);
// // 			}
// 		TreeIterator() {}
// 		TreeIterator(node_pointer ptr, node_pointer l) : root(ptr), lol(l) {}
// 		TreeIterator(const TreeIterator& other) : root(other.root), lol(other.lol) {}
// 		TreeIterator & operator=(const TreeIterator & other) {
// 		// if (this != &other)
// 			root = other.root;
// 		return *this;
// 		}
// 		~TreeIterator() {}
// 		reference operator*() { return *root->data; }
// 		pointer operator->() { return &operator*(); }
// 		const_reference operator*() const { return *(root->data); }
// 		const_pointer operator->() const { return &operator*(); }
// 		node_pointer getPointer() const { return root; }
// 		TreeIterator & operator++() {
// 			if (root->right && !root->right->isNil)
// 				root = minimum(root->right);
// 			else {
// 				node_pointer tmp = root->parent;
// 				while (tmp && root == tmp->right) {
// 				root = tmp;
// 				tmp = tmp->parent;
// 				}
// 				root = tmp;
// 			}
// 			return *this;
// 		}
// 		TreeIterator operator++(int) {
// 		TreeIterator<value_type> tmp(*this);
// 			if (!root->right->isNil)
// 				root = minimum(root->right);
// 			else {
// 				node_pointer tmp = root->parent;
// 				while (tmp && root == tmp->right) {
// 				root = tmp;
// 				tmp = tmp->parent;
// 				}
// 				root = tmp;
// 			}
// 			return tmp;
// 		}
// 		TreeIterator & operator--() {
// 			if (root->left && !root->left->isNil)
// 				root = maximum(root->left);
// 			else {
// 				node_pointer tmp = root->parent;
// 				while (tmp && root == tmp->left) {
// 				root = tmp;
// 				tmp = tmp->parent;
// 				}
// 				root = tmp;
// 			}
// 			return *this;
// 		}
// 			TreeIterator operator--(int) {
// 			TreeIterator<value_type> tmp(*this);
// 			*this = operator--();
// 			return tmp;
// 		}
// 		template<class T>
// 		bool operator==(const TreeIterator<T>  & other) { return root == other.root; }
// 		template<class T>
// 		bool operator!=(const TreeIterator<T>  & other) { return root != other.root; }
// 	};
// }

#endif