#ifndef MYTREE_HPP
# define MYTREE_HPP

#define BLACK   1
#define RED     0

#include <iostream>

namespace ft {

    template<class T>
	struct node_tree {
	    typedef T	data_type;
        data_type*  data;
		node_tree*	right;
		node_tree*  left;
		node_tree*	parent;
		int color;
		
		explicit node_tree(data_type* d = nullptr) : data(d), right(nullptr), left(nullptr), parent(nullptr), color(RED) {}
		node_tree(const node_tree& nt)
        {
            *this = nt;
        }
		node_tree& operator=(const node_tree& nt) {
            data = nt.data;
            right = nt.right;
            left = nt.left;
            parent = nt.parent;
            color = nt.color;
			return (*this);
		}
	};
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
		private:
			allocator_type 	_alloc_value;
			node_allocator	_alloc_node;
			value_compare	_compare;
			node*   		_root;
			size_type		_size;
        public:
            node*    initNULLNode()
            {
                node* new_node;
                new_node = _alloc_node.allocate(1);
                _alloc_node.construct(new_node, node_tree<value_type>());
                new_node->data = _alloc_value.allocate(1);
                _alloc_value.construct(new_node->data, value_type());
                new_node->color = BLACK;
                return (new_node);
            }
			
			void leftRotate(node* x)
			{
				node*	y = x->right;

				x->right = y->left;
				if (y->left != nullptr) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) {
					this->_root = y;
				}
				else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}
			void rightRotate(node* x)
			{
				node*	y = x->left;

				x->left = y->right;
				if (y->right != nullptr) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) {
					this->_root = y;
				}
				else if (x == x->parent->right) {
					x->parent->right = y;
				}
				else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}
			void insertFix(node* k)
			{
				node* u;

				while (k->parent->color == 1) {
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
						if (u->color == 1) {
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->left) {
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					}
					else {
						u = k->parent->parent->right;

						if (u->color == 1) {
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->right) {
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == _root) {
						break;
					}
				}
				_root->color = RED;
			}
			void insert(int key) {
				node* nodet;

				nodet = _alloc_node.allocator(1);
				_alloc_node.construct(nodet, key);
				nodet->color = BLACK;

				node* y = nullptr;
				node* x = this->_root;

				while (x != nullptr) {
					y = x;
					if (nodet->data < x->data) {
						x = x->left;
					} else {
						x = x->right;
					}
				}

				nodet->parent = y;
				if (y == nullptr) {
					_root = nodet;
				}
				else if (nodet->data < y->data) {
					y->left = nodet;
				}
				else {
					y->right = nodet;
				}

				if (nodet->parent == nullptr) {
					nodet->color = 0;
					return;
				}

				if (nodet->parent->parent == nullptr) {
					return;
				}
				insertFix(nodet);
			}



			explicit tree(const allocator_type& alloc_v = allocator_type(), const node_allocator& alloc_n = node_allocator(), const value_compare& comp = value_compare())
			: _alloc_value(alloc_v), _alloc_node(alloc_n), _compare(comp), _size(0) {
				_root = initNULLNode();
			}
    };
}
			
#endif