#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "utility.hpp"
#include <iostream>
#include <limits>


namespace ft {

	template<class T>
	class tree_iterator {
		public:
			typedef typename ft::iterator_traits<T*>::value_type	value_type;
			typedef typename ft::iterator_traits<T*>::reference		reference;
			typedef typename ft::iterator_traits<T*>::pointer		pointer;
			typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<T*>::difference_type difference_type;
			typedef ft::node_tree<T> node;
		private:
			node*	_node;
			node* minimum(node* ptr) const {
				while (ptr->left && ptr->left != nullptr)
					ptr = ptr->left;
				return ptr;
			}
			node* maximum(node* ptr) const {
				while (ptr->right != nullptr)
					ptr = ptr->right;
				return ptr;
			}
		public:
			tree_iterator() : _node() {}
			tree_iterator(node* ptr) : _node(ptr) {}
			// explicit tree_iterator(const tree_iterator& x) : _node(x->_node) {}
			// tree_iterator& operator=(const tree_iterator& x)
			// {
				
			// 	this->_node = x._node;
			// 	return (*this);
			// }
			~tree_iterator() {}
			reference operator* ()
			{
				return (*_node->data); 
			}
			pointer operator-> ()
			{
				return (&(operator*()));
			}

			tree_iterator& operator++ ()
			{
				if (_node->right)
				{
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else
				{
					node* _y = _node->parent;
					while (_node == _y->right)
					{
						_node = _y;
						_y = _y->parent;
					}
					if (_node->right != _y)
						_node = _y;
				}
				return(*this);
			}
			tree_iterator operator++ (int)
			{
				tree_iterator<T> tmp = *this;

				if (_node->right)
				{
					_node = _node->right;
					while (_node->left)
						_node = _node->left;
				}
				else
				{
					node* _y = _node->parent;
					while (_node == _y->right)
					{
						_node = _y;
						_y = _y->parent;
					}
					if (_node->right != _y)
						_node = _y;
				}
				return(tmp);
			}
			tree_iterator& operator-- ()
			{
				if (_node->left)
				{
					_node = _node->left;
					while (_node->right)
						_node = _node->right;
				}
				else
				{
					node* _y = _node->parent;
					while (_node == _y->left)
					{
						_node = _y;
						_y = _y->parent;
					}
					if (_node->left != _y)
						_node = _y;
				}
				return(*this);
			}
			tree_iterator operator-- (int)
			{
				tree_iterator<T> tmp = *this;

				if (_node->left)
				{
					_node = _node->left;
					while (_node->right)
						_node = _node->right;
				}
				else
				{
					node* _y = _node->parent;
					while (_node == _y->left)
					{
						_node = _y;
						_y = _y->parent;
					}
					if (_node->left != _y)
						_node = _y;
				}
				return(tmp);
			}
		
		friend bool operator==(const tree_iterator<T>& __x, const tree_iterator<T>& __y)
		{
			return __x._node == __y._node;
		}
		friend bool operator!=(const tree_iterator<T>& __x, const tree_iterator<T>& __y)
		{
			return __x._node != __y._node;
		}
	
	};
	// template<class T>
	// bool operator==(const tree_iterator<T>  & other)
	// {
	// 	return _node == other._node;
	// }
	// template<class T>
	// bool operator!=(const tree_iterator<T>  & other)
	// {
	// 	return _node != other._node;
	// }

    //   friend bool
    //   operator!=(const _Self& __x, const _Self& __y) _GLIBCXX_NOEXCEPT
    //   { return __x._M_node != __y._M_node; }
}

#endif