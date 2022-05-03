#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include "utility.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class rb_tree {
		public:
			typedef	ft::pair<const Key, T>									value_type;
			typedef std::size_t												size_type;
			typedef Compare													compare_type;
			typedef Allocator												allocator_type;
			typedef node_tree<value_type>									node;
			typedef typename allocator_type::template rebind<node>::other	node_allocator;
			typedef ft::tree_iterator<value_type>							iterator;
			typedef ft::tree_const_iterator<value_type>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		private:
			size_type		_size;
			allocator_type	_alloc_value;
			node_allocator	_alloc_node;
			compare_type	_comp;
			node*			_root;
		public:
			//CONSTRUCTOR ------------------------------------------------------------------------
			rb_tree() : _size(0), _alloc_value(allocator_type()), _alloc_node(node_allocator()), _comp(compare_type()), _root(nullptr){}
			explicit rb_tree(const compare_type& comp, const allocator_type& alloc = allocator_type()) : _size(0), _alloc_value(alloc), _alloc_node(node_allocator()), _comp(comp), _root(nullptr) {}
			rb_tree(const rb_tree& other) : _alloc_value(other._alloc_value), _alloc_node(other._alloc_node), _comp(other._comp), _root(nullptr)
			{
				copy_tree(&_root, nullptr, other._root);
				_size = other._size;
			}
			//DESTRUCTOR ------------------------------------------------------------------------
			~rb_tree()
			{
				clear_tree(_root);
			}
			//OPERATOR= ------------------------------------------------------------------------
			rb_tree& operator=(const rb_tree& other)
			{
				node* temp;

				copy_tree(&temp, nullptr, other._root);
				clear_tree(_root);
				_root = temp;
				_size = other._size;
				return (*this);
			}
			//GET_ALLOCATOR ------------------------------------------------------------------------
			allocator_type get_allocator() const
			{
				return (_alloc_value);
			}
			//EMPTY ------------------------------------------------------------------------
			bool empty() const
			{
				return (!_root);
			}
			//SIZE ------------------------------------------------------------------------	
			size_type size() const
			{
				return (_size);
			}
			//MAX_SIZE ------------------------------------------------------------------------
			size_type max_size() const
			{
				return (std::numeric_limits<std::ptrdiff_t>::max() / sizeof(std::ptrdiff_t));
			}
			//CLEAR ------------------------------------------------------------------------
			void clear()
			{
				clear_tree(_root);
			}
			//INSERT ------------------------------------------------------------------------
			ft::pair<iterator,bool> insert (const value_type& value)
			{
				ft::pair<node*, bool> tmp = insert_node(&_root, value);
				return (ft::make_pair(iterator(tmp.first, _root), tmp.second));
			}
			iterator insert(iterator hint, const value_type& value)
			{
				insert_node(&_root, value);
				return (iterator(hint._node, _root));
			}
			template<class InputIt>
			void insert(InputIt first, InputIt last)
			{
				for (InputIt it = first; it != last; ++it)
					insert(*it);
			}
			//ERASE ------------------------------------------------------------------------
			void erase(iterator pos)
			{
				node* n = pos._node;
				node* y = (n->left == nullptr || n->right == nullptr) ? n : tree_next(n);
				node* x = y->left != nullptr ? y->left : y->right;
				node* w = nullptr;

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
			void erase(iterator first, iterator last)
			{
				while (first != last) {
					erase(first++);
				}
			}
			size_type erase(const value_type& key)
			{
				iterator it = find(key);

				if (!it._node)
					return (0);
				erase(it);
				return (1);
			}
			//SWAP ------------------------------------------------------------------------
			void swap(rb_tree& other)
			{
				node* temp_root = _root;
				size_type temp_size = this->size();

				_root = other._root;
				_size = other._size;
				other._root = temp_root;
				other._size = temp_size;
			}
			//BEGIN, END, RBEGIN, REND ------------------------------------------------------------------------
			iterator begin()
			{
				node* temp = _root;

				if (temp)
					while (temp->left)
						temp = temp->left;
				return (iterator(temp, _root));
			}
			const_iterator begin() const
			{
				node* temp = _root;

				if (temp)
					while (temp->left)
						temp = temp->left;
				return (const_iterator(temp, _root));
			}
			iterator end()
			{
				return (iterator(nullptr, _root));
			}
			const_iterator end() const
			{
				return (const_iterator(nullptr, _root));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			//FIND ------------------------------------------------------------------------
			iterator find(const value_type& key)
			{
				iterator it = lower_bound(key);
				if (it != end() && !_comp(key, *it))
					return (it);
				return (end());
			}
			const_iterator find(const value_type& key) const
			{
				const_iterator it = lower_bound(key);
				if (it != end() && !_comp(key, *it))
					return (it);
				return (end());
			}
			//EQUAL_RANGE ------------------------------------------------------------------------
			ft::pair<iterator, iterator> equal_range(const value_type& key)
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
			ft::pair<const_iterator, const_iterator> equal_range(const value_type& key) const
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
			//LOWER_BOUND ------------------------------------------------------------------------
			iterator lower_bound(const value_type& key)
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
				return (iterator(res, _root));
			}
			const_iterator lower_bound(const value_type& key) const
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
				return (const_iterator(res, _root));
			}
			//UPPER_BOUND ------------------------------------------------------------------------
			iterator upper_bound(const value_type& key)
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
				return (iterator(res, _root));
			}
			const_iterator upper_bound(const value_type& key) const
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
				return (const_iterator(res, _root));
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
			node* tree_next(node* n)
			{
				if (n->right != nullptr)
					return (tree_min(n->right));
				while (n != n->parent->left)
					n = n->parent;
				n = n->parent;
				return (n);
			}
			node*	new_node(const value_type& data, node *parent = nullptr, node *left = nullptr, node *right = nullptr, COLOR col = RED)
			{
				node* temp = _alloc_node.allocate(1);
				_alloc_node.construct(temp, node(data, parent, left, right, col));
				++_size;
				return (temp);
			}
			void	copy_tree(node** old_n, node* old_n_par, node* new_n)
			{
				if (new_n) {
					*old_n = new_node(new_n->data, old_n_par);
					copy_tree(&(*old_n)->left, *old_n, new_n->left);
					copy_tree(&(*old_n)->right, *old_n, new_n->right);
				}
				else
					return ;
			}
			void	delete_node(node *n)
			{
				_alloc_node.destroy(n);
				_alloc_node.deallocate(n, 1);
				--_size;
			}
			void	clear_tree(node *n)
			{
				if (n) {
					clear_tree(n->left);
					clear_tree(n->right);
					delete_node(n);
				}
				else
				{
					_root = nullptr;
					return ;
				}
			}
			
			ft::pair<node*, bool> insert_node(node **tree, const value_type& key)
			{
				node* n;

				if (!(*tree))
					n = nullptr;
				else
					n = (*tree)->parent;
				while (*tree)
				{
					if (_comp(key, (*tree)->data))
					{
						n = *tree;
						tree = &((*tree)->left);
					}
					else if (_comp((*tree)->data, key))
					{
						n = *tree;
						tree = &((*tree)->right);
					}
					else
						return (ft::make_pair(*tree, false));
				}
				*tree = new_node(key, n);
				insert_fix(*tree);
				return (ft::make_pair(*tree, true));
			}
			void insert_fix(node *n)
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
			void erase_fix(node *x, node *w)
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
			void tree_left_rotate(node * n)
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
			void tree_right_rotate(node * n)
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