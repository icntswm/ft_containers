#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"
#include <iostream>
#include <limits>

namespace ft {
	template <class IteratorType>
	class tree_const_iterator {
		public:
			typedef	IteratorType													iterator_type;
			typedef std::bidirectional_iterator_tag						  			iterator_category;
			typedef typename ft::iterator_traits<const iterator_type*>::value_type         				value_type;
			typedef typename ft::iterator_traits<const iterator_type*>::difference_type   				 difference_type;
			typedef typename ft::iterator_traits<const iterator_type*>::pointer          			  pointer;
			typedef typename ft::iterator_traits<const iterator_type*>::reference       					  reference;
			typedef	node_tree<iterator_type>	node;

			const node	*_node;
			const node	*_root;
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
			tree_const_iterator() {};
			tree_const_iterator(node * n, node* r) : _node(n), _root(r) {}
			tree_const_iterator(const tree_const_iterator& it) : _node(it._node), _root(it._root) {};
			tree_const_iterator& operator=(const tree_const_iterator& it) {
				_node = it._node;
				_root = it._root;
				return *this;
			}
			reference operator*() const {
				return _node->data;
			}
			pointer operator->() const {
				return &(_node->data);
			}
			tree_const_iterator& operator++()
			{
				if (_node == nullptr && _root == nullptr)
					return (*this);
				if (_node == nullptr)
				{
					_node = _root;
					while (_node->left)
						_node = _node->left;
				}
				else
				{
					if (_node->right)
						_node = tree_min(_node->right);
					else
					{
						while (_node->parent && _node->parent->right == _node)
							_node = _node->parent;
						_node = _node->parent;
					}
				}
				return (*this);
			}
			tree_const_iterator operator++(int) {
				tree_const_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			tree_const_iterator& operator--()
			{
				if (_node == nullptr && _root == nullptr)
					return (*this);
				if (_node == nullptr)
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
			tree_const_iterator	operator--(int) {
				tree_const_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			friend bool operator==(tree_const_iterator lhs, tree_const_iterator rhs)
			{
				return lhs._node == rhs._node;
			}

			friend bool operator!=(tree_const_iterator lhs, tree_const_iterator rhs)
			{
				return lhs._node != rhs._node;
			}
	};
	template<class IteratorType>
	class tree_iterator {
		public:
			typedef	IteratorType													iterator_type;
			typedef std::bidirectional_iterator_tag						  			iterator_category;
			typedef typename ft::iterator_traits<iterator_type*>::value_type         				value_type;
			typedef typename ft::iterator_traits<iterator_type*>::difference_type   				 difference_type;
			typedef typename ft::iterator_traits<iterator_type*>::pointer          			  pointer;
			typedef typename ft::iterator_traits<iterator_type*>::reference       					  reference;
			typedef	node_tree<iterator_type>	node;

			node* _node;
			// node* _root;
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
			node* tree_next_iter(node* x)
			{
				if (x->right != nullptr)
					return (tree_min(x->right));
				while (x != x->parent->left)
					x = x->parent;
				return (x->parent);
			}
			node* tree_prev_iter(node* x)
			{
				if (x->left != nullptr)
					return (tree_max(x->left));
				node* xx = x;
				while (xx == xx->parent->left)
					xx = xx->parent;
				return (xx->parent);
			}
		public:
			tree_iterator() {}
			tree_iterator(node* n, node* r) : _node(n), _root(r) {}
			tree_iterator(const tree_iterator& it) : _node(it._node), _root(it._root) {}
			~tree_iterator() {}
			tree_iterator& operator=(const tree_iterator& it)
			{
				_node = it._node;
				// _root = it._root;
				return (*this);
			}
			reference operator*()
			{
				return (_node->data);
			}
			pointer operator->()
			{
				return (&(_node->data));
			}
			tree_iterator& operator++()
			{
				_node = tree_next_iter(_node);
				// if (_node == nullptr && _root == nullptr)
				// 	return (*this);
				// if (_node == nullptr)
				// 	_node = tree_min(_root);
				// else
				// {
				// 	if (_node->right)
				// 		_node = tree_min(_node->right);
				// 	else
				// 		_node = tree_parent(_node, false);
				// }
				return (*this);
			}
			tree_iterator operator++ (int)
			{
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			tree_iterator& operator-- ()
			{
				_node = tree_prev_iter(_node);
				// if (_node == nullptr && _root == nullptr)
				// 	return (*this);
				// if (_node == nullptr)
				// 	_node = tree_max(_root);
				// else
				// {
				// 	if (_node->left)
				// 		_node = tree_max(_node->left);
				// 	else
				// 		_node = tree_parent(_node, true);
				// }
				return (*this);
			}
			tree_iterator operator-- (int)
			{
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
			operator tree_const_iterator<IteratorType>() const {
				return tree_const_iterator<IteratorType>(_node, _root);
			}
			friend bool operator== (tree_iterator lhs, tree_iterator rhs)
			{
				return (lhs._node == rhs._node);
			}
			friend bool operator!= (tree_iterator lhs, tree_iterator rhs)
			{
				return (lhs._node != rhs._node);
			}
	};
}

#endif