#pragma once
#include "./utils.hpp"
#include <memory>

namespace ft{
	template <class T>
	struct RBT_Node{
	public:
		typedef T	value_type;

		value_type	data;
		bool 		isRed;
		RBT_Node	*parent;
		RBT_Node	*left;
		RBT_Node	*right;

		RBT_Node (): data(0), isRed(true), parent(nullptr), left(nullptr),
		right(nullptr) {}
//		RBT_Node (const RBT_Node& ar) : data(ar.data), isRed(ar.isRed), parent
//		(ar.parent), left(ar.left), right(ar.right) {}
		RBT_Node(const value_type& val, bool red = true,  RBT_Node *par = nullptr , RBT_Node
		*l = nullptr, RBT_Node *r = nullptr): data(val), isRed(red),
		parent(par), left(l), right(r) {}

		~RBT_Node() {}

		RBT_Node& operator=(const RBT_Node& ar)
		{
			if (ar == *this)
				return *this;
			data = ar.data;
			isRed = ar.isRed;
			parent = ar.parent;
			left = ar.left;
			right = ar.right;
			return *this;
		}

		bool operator==(const RBT_Node& ar) { return (data == ar.data); }
	};





	template<class T, class Compare = ft::less<T>, class Node = ft::RBT_Node<T>, class Node_Alloc = std::allocator<Node> >
	class RBT{
	public:
		typedef Node_Alloc							allocator_type;
		typedef typename allocator_type::pointer	node_ptr;
		typedef T									value_type;

		node_ptr make_node(value_type val)
		{
			node_ptr new_node = _alloc.allocate(1);
			_alloc.construct(new_node, val);
			return (new_node);
		}

		void	delete_node(node_ptr &node)
		{
			if (node)
			{
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}
		}

		void	swap_color(node_ptr node)
		{
			bool color = node->isRed;
			node->isRed = node->right->isRed;
			node->right->isRed = color;
			node->left->isRed = color;
		}

		node_ptr	min_node(node_ptr node) const
		{
			if (node)
			{
				while (node->left)
					node = node->left;
			}
			return (node);
		}

		node_ptr	max_node(node_ptr node) const
		{
			if (node)
			{
				while (node->right)
					node = node->right;
			}
			return (node);
		}

		node_ptr find_node(node_ptr node, value_type key) const
		{
			if (node)
			{
				if (_cmp(node->data, key))
					return find_node(node->right, key);
				if (_cmp(key, node->data))
					return find_node(node->left, key);
			}
			return (node);
		}

		node_ptr lower(node_ptr root, value_type key) const
		{
			node_ptr tmp = 0;

			while (root)
			{
				if (_cmp(root->data, key))
					root = root->right;
				else
				{
					if (root->left)
					{
						tmp = lower(root->left, key);
						if (tmp)
							root = tmp;
						break;
					} else
						break;
				}
			}
			return root;
		}

		void	clear(node_ptr root)
		{
			if (!root)
				return;
			if (root->left)
				clear(root->left);
			if (root->right)
				clear(root->right);
			delete_node(root);
			root = 0;
		}

		size_t	max_size() const
		{
			return _alloc.max_size();
		}

		void	leftRotate(node_ptr &root, node_ptr node)
		{
//			std::cout << "LEFTROTATE\n";
			node_ptr right = node->right;
			right->parent = node->parent;
			if (right->parent)
			{
				if (right->parent->right == node)
					right->parent->right = right;
				else
					right->parent->left = right;
			}
			node->parent = right;
			node->right = right->left;
			if (node->right)
				node->right->parent = node;
			right->left = node;
			bool color = node->isRed;
			node->isRed = right->isRed;
			right->isRed = color;
			if (!right->parent)
				root = right;
		}

		void	rightRotate(node_ptr &root, node_ptr node)
		{
//			std::cout << "RIGHTROTATE\n";
			node_ptr left = node->left;
			left->parent = node->parent;

			if (left->parent)
			{
				if (left->parent->left == node)
					left->parent->left = left;
				else
					left->parent->right = left;
			}
			node->parent = left;
			node->left = left->right;
			if (node->left)
					node->left->parent = node;
			left->right = node;
			node->isRed = true;
			left->isRed = false;
			if (!left->parent)
				root = left;
			
//			node_ptr left = node->left;
//			node->left = left->right;
//			if (left->right)
//				left->right->parent = node;
//			left->parent = node->parent;
//			if (!node->parent)
//				root = left;
//			else if (node == node->parent->right)
//				node->parent->right = left;
//			else
//				node->parent->left = left;
//			left->right = node;
//			node->parent = left;
		}

		bool	insert(node_ptr &tree, node_ptr new_node)
		{
			if (!tree)
			{
				new_node->isRed = false;
				tree = new_node;
			}
			else
			{
				node_ptr tmp = tree;
				while (tmp)
				{
					if (!_cmp(tmp->data, new_node->data) &&
						!_cmp(new_node->data, tmp->data))
					{
						if (tmp != new_node)
							delete_node(new_node);
						return false;
					}
					else if (_cmp(new_node->data, tmp->data))
					{
						if (tmp->left)
							tmp = tmp->left;
						else
						{
							tmp->left = new_node;
							new_node->parent = tmp;
							break;
						}
					}
					else
					{
						if (tmp->right)
							tmp = tmp->right;
						else
						{
							tmp->right = new_node;
							new_node->parent = tmp;
							break;
						}
					}
				}
				rbInsertFix(tree, new_node);
			}
			return true;
		}

		void	rbInsertFix(node_ptr &root, node_ptr node)//ver2
		{
			node_ptr parent;
			node_ptr grand;
			node_ptr tmp;

			while (node)
			{
				parent = node->parent;
				grand = 0;
				tmp = parent;
				if (parent)
				{
					grand = parent->parent;
					if (node->isRed == true)
					{
						if (parent->isRed == false)
							node = parent;
						else if (grand)
						{
							if (grand->left && grand->right && grand->right->isRed == true && grand->left->isRed == true)
							{
								swap_color(grand);
								node = grand;
							}
							else if (grand->right == parent)
							{
								if (parent->left == node)
								{
									rightRotate(root, parent);
									parent = node;
								}
								if (parent->right == node)
								{
									leftRotate(root, grand);
								}
								node = parent->parent;
							}
							else
							{
								if (parent->right == node)
								{
									leftRotate(root, parent);
									parent = node;
								}
								if (parent->left == node)
									rightRotate(root, grand);
								node = parent->parent;
							}
						}
					}
					else
						node = parent;
				}
				else
				{
					node->isRed = false;
					node = node->parent;
				}
			}		
		}
		
		
		void swap_p(node_ptr remove, node_ptr replace)
		{
			if (remove->parent)
			{
				if (remove->parent->left == remove)
					remove->parent->left = replace;
				else
					remove->parent->right = replace;
			}
			replace->parent = remove->parent;
			if (remove->left)
			{
				remove->left->parent = replace;
			}
			replace->left = remove->left;
			if (remove->right)
			{
				remove->right->parent = replace;
			}
			replace->right = remove->right;
			replace->isRed = remove->isRed;
		}

		bool erase_val(node_ptr &root, value_type key)
		{
			node_ptr remove = find_node(root, key);

			if (remove)
			{
				node_ptr replace = 0;
				if (remove->left)
					replace = erase_left(remove, root);
				else if (remove->right)
					replace = erase_right(remove, root);
				else
					erase_not_child(remove, root);
				if (replace)
					swap_p(remove, replace);
				if (remove == root)
				{
					if (replace)
						root = replace;
					else
						root = 0;
				}
				delete_node(remove);
				return true;
			}
			return false;
		}

		node_ptr erase_left(node_ptr some, node_ptr &root)
		{
			node_ptr replace = max_node(some->left);

			if (replace)
			{
				if (replace == some->left)
				{
					some->left = replace->left;
					if (replace->left)
						replace->left->parent = some;
				} else
				{
					replace->parent->right = replace->left;
					if (replace->left)
						replace->left->parent = replace->parent;
				}
				if (replace->isRed == false)
				{
					if (replace->left && replace->left->isRed == true)
						replace->left->isRed = false;
					erase_balance(root, replace->parent);
				}
			}
			return replace;
		}

		node_ptr erase_right(node_ptr some, node_ptr &root)
		{
			node_ptr replace = min_node(some->right);

			if (replace)
			{
				if (replace == some->right)
				{
					some->right = replace->right;
					if (replace->right)
						replace->right->parent = some;
				} else
				{
					replace->parent->left = replace->right;
					if (replace->right)
						replace->right->parent = replace->parent;
				}
				if (replace->isRed == false)
				{
					if (replace->right && replace->right->isRed == true)
						replace->right->isRed = false;
					erase_balance(root, replace->parent);
				}
			}
			return replace;
		}

		node_ptr erase_not_child(node_ptr some, node_ptr &root)
		{
			node_ptr replace = some;

			if (replace && replace->parent)
			{
				if (replace->parent->right == replace)
					replace->parent->right = 0;
				else
					replace->parent->left = 0;
				if (replace->isRed == false)
				{
					if (replace->right && replace->right->isRed == true)
						replace->right->isRed = false;
					erase_balance(root, replace->parent);
				}
			}
			return replace;
		}

		void erase_balance(node_ptr &root, node_ptr some)
		{
			node_ptr right;
			node_ptr left;
			node_ptr brother;

			while (some != root && some->isRed == false)
			{
				brother = some->right;
				if (brother)
				{
					right = brother->right;
					left = brother->left;
					if ((right || left) && (!right || right->isRed == false) &&
						(!left || left->isRed == false))
					{
						if (brother->isRed == false)
						{
							brother->isRed = true;
							some->isRed = false;
							leftRotate(root, some);
						} else
							some = some->parent;
					} else if (right && brother->isRed == false)
					{
						if (left && left->isRed == true &&
							right->isRed == false)
						{
							rightRotate(root, brother);
							right = brother;
							brother = left;
						}
						if (right->isRed == true &&
							(!left || left->isRed == false || !some->left))
							leftRotate(root, some);
						else
							some = some->parent;
					} else if (brother->isRed == false &&
							   some->isRed == true)
					{
						some->isRed = false;
						brother->isRed = true;
						some = some->parent;
					} else
						some = some->parent;
				} else
					break;
			}
		}
		void printBT(const std::string& prefix, const node_ptr nodeV, bool isLeft) const
		{
				std::cout << prefix;
				std::cout << (isLeft ? "├──" : "└──" );
				if (!nodeV){
					std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
					return ;
				}
				// print the value of the node
				if (nodeV->isRed == 0)
					std::cout <<"\033[0;36m"<< nodeV->data << "\033[0m"<<std::endl;
				else
					std::cout <<"\033[0;31m"<< nodeV->data << "\033[0m"<<std::endl;
				printBT( prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), nodeV->right, false);
		}

		void printTree(node_ptr root){
			printBT("", root, false);
		}
		private:
			allocator_type	_alloc;
			Compare			_cmp;
	};
}
