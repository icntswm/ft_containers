#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"
#include <iostream>
#include <limits>

namespace ft {
	template <class T>
	class	RBTreeConstIterator
	{
	public:
		typedef std::bidirectional_iterator_tag						  			iterator_category;
		typedef const T         				value_type;
		typedef std::ptrdiff_t   				 difference_type;
		typedef const T*          			  pointer;
		typedef const T&       					  reference;
		typedef	node_tree<T>	node;

		const node	*_node;
		const node	*_root;
	public:
		RBTreeConstIterator() {};
		RBTreeConstIterator(node * n, node *r) : _node(n), _root(r) {};
		RBTreeConstIterator(node * n) : _node(n), _root(NULL) {};
		RBTreeConstIterator(const RBTreeConstIterator & other) : _node(other._node), _root(other._root) {};
		RBTreeConstIterator &	operator=(const RBTreeConstIterator & other) {
			_node = other._node;
			return *this;
		}
		reference	operator*() const {
			return _node->data;
		}
		pointer	operator->() const {
			return &(_node->data);
		}
		RBTreeConstIterator &	operator++() {
			if (_node == NULL)
			{
				if (_root == NULL)
					return *this;
				_node = _root;
				while (_node->left)
					_node = _node->left;
				return *this;
			}
			if (_node->right)
			{
				_node = _node->right;
				while (_node->left)
					_node = _node->left;
			}
			else
			{
				while (_node->parent and _node->parent->right == _node)
					_node = _node->parent;
				_node = _node->parent;
			}
			return *this;
		}
		RBTreeConstIterator	operator++(int) {
			RBTreeConstIterator tmp(*this);
			++(*this);
			return tmp;
		}
		RBTreeConstIterator &	operator--() {
			if (_node == NULL)
			{
				if (_root == NULL)
					return *this;
				_node = _root;
				while (_node->right)
					_node = _node->right;
				return *this;
			}
			if (_node->left)
			{
				_node = _node->left;
				while (_node->right)
					_node = _node->right;
			}
			else
			{
				while (_node->parent and _node->parent->left == _node)
					_node = _node->parent;
				_node = _node->parent;
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
			return lhs._node == rhs._node;
		}

		friend bool operator!=(
				RBTreeConstIterator lhs,
				RBTreeConstIterator rhs)
		{
			return lhs._node != rhs._node;
		}
	};
	template<class IteratorType>
	class tree_iterator {
		public:
            typedef std::bidirectional_iterator_tag						  			iterator_category;
            typedef IteratorType         value_type;
            typedef std::ptrdiff_t    difference_type;
            typedef IteratorType*            pointer;
            typedef IteratorType&          reference;
			typedef node_tree<IteratorType> 										node;

			node* _node;
			node* _root;
		public:
			tree_iterator() {}
			tree_iterator(node* n, node* r) : _node(n), _root(r) {}
			tree_iterator(const tree_iterator& it) : _node(it._node), _root(it._root) {}
			// ~tree_iterator() {}
			tree_iterator& operator=(const tree_iterator& it)
			{
				_node = it._node;
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
				if (_node == NULL)
				{
					if (_root == NULL)
						return (*this);
					_node = _root;
					while (_node->left)
						_node = _node->left;
					return (*this);
				}
				if (_node->right)
				{
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else
				{
					while (_node->parent && _node->parent->right == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
				return (*this);
			}
			tree_iterator& operator++ (int)
			{
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			tree_iterator& operator-- ()
			{
				if (_node == NULL)
				{
					if (_root == NULL)
						return (*this);
					_node = _root;
					while (_node->right)
						_node = _node->right;
					return (*this);
				}
				if (_node->left)
				{
					_node = _node->left;
					while (_node->right)
						_node = _node->right;
				}
				else
				{
					while (_node->parent && _node->parent->left == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
				return (*this);
			}
			tree_iterator& operator-- (int)
			{
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
			operator RBTreeConstIterator<IteratorType>() const {
				return RBTreeConstIterator<IteratorType>(_node, _root);
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