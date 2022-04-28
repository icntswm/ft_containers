#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"
#include <iostream>
#include <limits>

namespace ft {

	template<class IteratorType>
	class tree_iterator {
		public:
            typedef std::bidirectional_iterator_tag						  			iterator_category;
            typedef typename ft::iterator_traits<IteratorType*>::value_type         value_type;
            typedef typename ft::iterator_traits<IteratorType*>::difference_type    difference_type;
            typedef typename ft::iterator_traits<IteratorType*>::pointer            pointer;
            typedef typename ft::iterator_traits<IteratorType*>::reference          reference;
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
				if (_node == nullptr)
				{
					if (_root == nullptr)
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
				if (_node == nullptr)
				{
					if (_root == nullptr)
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