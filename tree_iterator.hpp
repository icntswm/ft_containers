#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"

namespace ft {
	template<class IteratorType>
	class tree_iterator {
		public:
			typedef	IteratorType													iterator_type;
			typedef std::bidirectional_iterator_tag									iterator_category;
			typedef typename ft::iterator_traits<iterator_type*>::value_type		value_type;
			typedef typename ft::iterator_traits<iterator_type*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type*>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type*>::reference			reference;
			typedef typename ft::iterator_traits<const iterator_type*>::pointer		const_pointer;
			typedef typename ft::iterator_traits<const iterator_type*>::reference	const_reference;
			typedef	node_tree<iterator_type>										node;
			
			node* _node;
			node* _root;
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
			reference operator*() const
			{
				return (_node->data);
			}
			pointer operator->()
			{
				return (&_node->data);
			}
			pointer operator->() const
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

#endif