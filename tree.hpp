
#ifndef TREE_HPP
# define TREE_HPP
#include "utility.hpp"
#include "tree_iterator.hpp"
#include <iostream>
#include <limits>

namespace ft {
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class tree {
		public:
			typedef T														value_type;
			typedef Compare													value_compare;
			typedef Allocator												allocator_type;
			typedef std::size_t												size_type;
			typedef std::ptrdiff_t											difference_type;
			typedef node_tree<T>                                            node;
			typedef typename allocator_type::template rebind<node>::other	node_allocator;
			typedef class ft::tree_iterator<T> iterator;
		private:
			allocator_type 	_alloc_value;
			node_allocator	_alloc_node;
			value_compare	_comp;
			size_type		_size;

			node* _TNULL; // Сторожевой узел
			node* _root; //корень дерева 
		public:

			void initializeNULLNode()
			{
				_TNULL = _alloc_node.allocate(1);
				_alloc_node.construct(_TNULL, node_tree<value_type>());
				_TNULL->data = _alloc_value.allocate(1);
				_alloc_value.construct(_TNULL->data, value_type());
				_TNULL->color = BLACK;
				_TNULL->left = nullptr;
				_TNULL->right = nullptr;
				_root = _TNULL;
			}
			void preOrderHelper(node* _node)
			{
				if (_node != _TNULL) {
					std::cout << _node->data << " ";
					preOrderHelper(_node->left);
					preOrderHelper(_node->right);
				}
			}
			void inOrderHelper(node* _node)
			{
				if (_node != _TNULL) {
					inOrderHelper(_node->left);
					std::cout << _node->data << " ";
					inOrderHelper(_node->right);
				}
			}
			void postOrderHelper(node* _node)
			{
				if (_node != _TNULL) {
					postOrderHelper(_node->left);
					postOrderHelper(_node->right);
					std::cout << _node->data << " ";
				}
			}
			node* searchTreeHelper(node* _node, value_type key)
			{
				if (_node == _TNULL || key == *_node->data) {
					return (_node);
				}
				if (key < *_node->data)
				{
					return (searchTreeHelper(_node->left, key));
				}
				return (searchTreeHelper(_node->right, key));
			}
			void deleteFix(node *_x)
			{
				node* _s;

				while (_x != _root && _x->color == BLACK)
				{
					if (_x == _x->parent->left)
					{
						_s = _x->parent->right;
						if (_s->color == RED)
						{
							_s->color = BLACK;
							_x->parent->color = RED;
							leftRotate(_x->parent);
							_s = _x->parent->right;
						}
						if (_s->left->color == BLACK && _s->right->color == BLACK)
						{
							_s->color = RED;
							_x = _x->parent;
						}
						else
						{
							if (_s->right->color == BLACK)
							{
								_s->left->color = BLACK;
								_s->color = RED;
								rightRotate(_s);
								_s = _x->parent->right;
							}
							_s->color = _x->parent->color;
							_x->parent->color = BLACK;
							_s->right->color = BLACK;
							leftRotate(_x->parent);
							_x = _root;
						}
					}
					else
					{
						_s = _x->parent->left;
						if (_s->color == RED)
						{
							_s->color = BLACK;
							_x->parent->color = RED;
							rightRotate(_x->parent);
							_s = _x->parent->left;
						}
						if (_s->right->color == BLACK && _s->right->color == BLACK)
						{
							_s->color = RED;
							_x = _x->parent;
						}
						else
						{
							if (_s->left->color == BLACK)
							{
								_s->right->color = BLACK;
								_s->color = RED;
								leftRotate(_s);
								_s = _x->parent->left;
							}
							_s->color = _x->parent->color;
							_x->parent->color = BLACK;
							_s->left->color = BLACK;
							rightRotate(_x->parent);
							_x = _root;
						}
					}
				}
				_x->color = BLACK;
			}
			void rbTransplant(node *_u, node *_v)
			{
				if (_u->parent == nullptr)
				{
					_root = _v;
				}
				else if (_u == _u->parent->left)
				{
					_u->parent->left = _v;
				}
				else
				{
					_u->parent->right = _v;
				}
				_v->parent = _u->parent;
			}
			void deleteNodeHelper(node* _node, value_type key)
			{
				node* _z = _TNULL;
				node* _x;
				node* _y;

				while (_node != _TNULL)
				{
					if (*_node->data == key)
					{
						_z = _node;
						_alloc_value.destroy(_node->data);
						_alloc_value.deallocate(_node->data, 1);
						break ;
					}
					if (*_node->data <= key)
					{
						_node = _node->right;
					}
					else
					{
						_node = _node->left;
					}
				}
				if (_z == _TNULL)
				{
					std::cout << "Key not found in the tree" << std::endl;
					return;
				}
				_y = _z;
				COLOR y_original_color = _y->color;
				if (_z->left == _TNULL)
				{
					_x = _z->right;
					rbTransplant(_z, _z->right);
				}
				else if (_z->right == _TNULL)
				{
					_x = _z->left;
					rbTransplant(_z, _z->left);
				}
				else
				{
					_y = minimum(_z->right);
					y_original_color = _y->color;
					_x = _y->right;
					if (_y->parent == _z)
					{
						_x->parent = _y;
					}
					else
					{
						rbTransplant(_y, _y->right);
						_y->right = _z->right;
						_y->right->parent = _y;
					}
					rbTransplant(_z, _y);
					_y->left = _z->left;
					_y->left->parent = _y;
					_y->color = _z->color;
				}
				if (y_original_color == BLACK)
				{
					deleteFix(_x);
				}
				_alloc_node.deallocate(_z, 1);
				--_size;
			}

			void insertFix(node* _k)
			{
				node* _u;

				while (_k->parent->color == RED)
				{
					if (_k->parent == _k->parent->parent->right)
					{
						_u = _k->parent->parent->left;
						if (_u->color == RED)
						{
							_u->color = BLACK;
							_k->parent->color = BLACK;
							_k->parent->parent->color = RED;
							_k = _k->parent->parent;
						}
						else
						{
							if (_k == _k->parent->left)
							{
								_k = _k->parent;
								rightRotate(_k);
							}
							_k->parent->color = BLACK;
							_k->parent->parent->color = RED;
							leftRotate(_k->parent->parent);
						}
					}
					else
					{
						_u = _k->parent->parent->right;

						if (_u->color == RED)
						{
							_u->color = BLACK;
							_k->parent->color = BLACK;
							_k->parent->parent->color = RED;
							_k = _k->parent->parent;
						}
						else
						{
							if (_k == _k->parent->right)
							{
								_k = _k->parent;
								leftRotate(_k);
							}
							_k->parent->color = BLACK;
							_k->parent->parent->color = RED;
							rightRotate(_k->parent->parent);
						}
					}
					if (_k == _root)
						break;
				}
				_root->color = BLACK;
			}
			void printHelper(node* _root, std::string indent, bool last)
			{
				if (_root != _TNULL)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
					}
					std::string sColor = _root->color ? "RED" : "BLACK";
					std::cout << *_root->data << "(" << sColor << ")" << std::endl;
					printHelper(_root->left, indent, false);
					printHelper(_root->right, indent, true);
				}
			}
			void preorder() {
				preOrderHelper(_root);
			}

			void inorder()
			{
				inOrderHelper(_root);
			}

			void postorder()
			{
				postOrderHelper(_root);
			}

			node* searchTree(value_type k) {
				return (searchTreeHelper(_root, k));
			}
			node* minimum(node* _node)
			{
				while (_node->left != _TNULL)
				{
					_node = _node->left;
				}
				return (_node);
			}
			node* maximum(node* _node) {
				while (_node->right != _TNULL)
				{
					_node = _node->right;
				}
				return (_node);
			}
			node* successor(node* _x)
			{
				if (_x->right != _TNULL)
				{
					return (minimum(_x->right));
				}
				node* _y = _x->parent;
				while (_y != _TNULL && _x == _y->right)
				{
					_x = _y;
					_y = _y->parent;
				}
				return (_y);
			}
			node* predecessor(node* _x)
			{
				if (_x->left != _TNULL)
				{
					return (maximum(_x->left));
				}
				node* _y = _x->parent;
				while (_y != _TNULL && _x == _y->left)
				{
					_x = _y;
					_y = _y->parent;
				}
				return (_y);
			}
			void leftRotate(node* _x)
			{
				node* _y = _x->right;
				_x->right = _y->left;
				if (_y->left != _TNULL)
				{
					_y->left->parent = _x;
				}
				_y->parent = _x->parent;
				if (_x->parent == nullptr)
				{
					_root = _y;
				}
				else if (_x == _x->parent->left)
				{
					_x->parent->left = _y;
				}
				else
				{
					_x->parent->right = _y;
				}
				_y->left = _x;
				_x->parent = _y;
			}
			void rightRotate(node* _x)
			{
				node* _y = _x->left;
				_x->left = _y->right;
				if (_y->right != _TNULL)
				{
					_y->right->parent = _x;
				}
				_y->parent = _x->parent;
				if (_x->parent == nullptr)
				{
					_root = _y;
				}
				else if (_x == _x->parent->right)
				{
					_x->parent->right = _y;
				}
				else {
					_x->parent->left = _y;
				}
				_y->right = _x;
				_x->parent = _y;
			}
			void insert(value_type key)
			{
				node* _node = _alloc_node.allocate(1);
				_alloc_node.construct(_node, node_tree<value_type>());
				_node->data = _alloc_value.allocate(1);
				_alloc_value.construct(_node->data, key);
				_node->parent = nullptr;
				_node->left = _TNULL;
				_node->right = _TNULL;
				_node->color = RED;

				node* _y = nullptr;
				node* _x = _root;

				while (_x != _TNULL)
				{
					_y = _x;
					if (*_node->data < *_x->data)
					{
						_x = _x->left;
					}
					else
					{
						_x = _x->right;
					}
				}
				_node->parent = _y;
				if (_y == nullptr)
				{
					_root = _node;
				}
				else if (*_node->data < *_y->data)
				{
					_y->left = _node;
				}
				else
				{
					_y->right = _node;
				}
				++_size;
				if (_node->parent == nullptr)
				{
					_node->color = BLACK;
					return;
				}
				if (_node->parent->parent == nullptr)
				{
					return;
				}
				insertFix(_node);
			}
			node* getRoot()
			{
				return (_root);
			}
			void deleteNode(value_type data)
			{
				deleteNodeHelper(_root, data);
			}
			void printTree()
			{
				if (_root)
				{
					printHelper(_root, "", true);
				}
			}
			void	clearChilds(node* child)
			{
				if (child != _TNULL)
				{
					clearChilds(child->left);
					clearChilds(child->right);
					clearNode(child);
				}	
				
			}
			void	clearNode(node* _node)
			{
				// std::cout << "clear node: " << *_node->data << "\n";
				if (_node)
				{
					_alloc_value.destroy(_node->data);
					_alloc_value.deallocate(_node->data, 1);
					_alloc_node.deallocate(_node, 1);
				}
			}
			void	clearAll()
			{
				clearChilds(_root);
				_alloc_value.destroy(_TNULL->data);
				_alloc_value.deallocate(_TNULL->data, 1);
				_alloc_node.deallocate(_TNULL, 1);
			}
			size_type getSize()
			{
				return (_size);
			}
			
		public:
			// tree() : _alloc_value(allocator_type()), _alloc_node(node_allocator()), _comp(value_compare())
			// {
			// 	initializeNULLNode();
			// }
			explicit tree(const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type())
				: _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _size(0)
			{
				initializeNULLNode();
			}
			template <class InputIt>
  			tree (InputIt first, InputIt last, const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
				: _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _size(0)
			{
				initializeNULLNode();
				//insert(first, last);	
			}
			tree (const tree& x) : _alloc_value(x._alloc_value), _alloc_node(x._alloc_node), _comp(x._comp), _size(x._size)
			{
				*this = x;
			}
			~tree()
			{
				clearAll();
			}
			tree& operator= (const tree& x)
			{
				if (getSize() > 0 && _root)
					clearAll();
				else
					initializeNULLNode();
				// for (iterator it = x.begin(); it != x.end(); it++) {
				// 	insert(*it);
				// }
				return (*this);
			}
			iterator begin()
			{
				return iterator(_root);
			}
			iterator end()
			{
				return iterator(_TNULL);
			}
			bool empty() const
			{
				return (!_size);
			}
			

		};
}
			
#endif

