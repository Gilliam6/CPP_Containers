#pragma once
#include "./utils.hpp"

namespace ft{
	template <typename T>
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
				while (node->left)
					node = node->left;
			return (node);
		}

		node_ptr	max_node(node_ptr node) const
		{
			if (node)
				while (node->right)
					node = node->right;
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

		node_ptr	lower(node_ptr node) const
		{
			if (node->left)
				return max_node(node->left);
			node_ptr tmp = node->parent;
			while (tmp && node == tmp->left)
			{
				node = tmp;
				tmp = tmp->parent;
			}
			return (tmp);
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
			
//			printTree(root);
//			node_ptr right = node->right;
//			node->right = right->left;
//			if (right->left)
//				right->left->parent	= node;
//			right->parent = node->parent;
//			if (!node->parent)
//				root = right;
//			else if (node == node->parent->left)
//				node->parent->left = right;
//			else
//				node->parent->right = right;
//			right->left = node;
//			node->parent = right;
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
				return true;
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
				return true;
			}
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
		
		void	rbTransplant(node_ptr &root, node_ptr x, node_ptr y)
		{
			if (!x->parent)
				root = y;
			else if (x->parent->left == x)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
		}

		bool	erase_val(node_ptr &root, const value_type val)
		{
			//printTree(root);

			node_ptr node = find_node(root, val);
			if (!node)
			{
				std::cout << val.first << std::endl;
			}
			if (node)
			{
				if (node->isRed)
				{
					if (!node->left && !node->right) //CASE1 Red node - no babies
						redNoChild(root, node);
					else if (node->left && node->right) //CASE2 Red node - 2 babies
					{
						node_ptr minimal = min_node(node->right);
						value_type tmp = minimal->data;
						minimal->data = node->data;
						node->data = tmp;
						if (minimal->isRed)
							redNoChild(root, minimal);
						else
							blackNoChild(root, minimal);
					}
					return true;
				}
				else
				{
					if (node->left && node->right)
					{
						node_ptr minimal = min_node(node->right);
						value_type tmp = minimal->data;
						minimal->data = node->data;
						node->data = tmp;
						if (minimal->isRed)
							redNoChild(root, minimal);
						else
							blackNoChild(root, minimal);
						return true;
					}
					else if ((node->left && !node->right) || (!node->left && node->right))
					{
						value_type tmp = node->data;
						if (node->left)
						{
							node->data = node->left->data;
							node->left->data = tmp;
							redNoChild(root, node->left);
						}
						else
						{
							node->data = node->right->data;
							node->right->data = tmp;
							redNoChild(root, node->right);
						}
						return true;	
					}
					else
					{
						blackNoChild(root, node);
						return true;
					}
				}
			}
			else
				return false;
		}

		void	blackNoChild(node_ptr &root, node_ptr node)
		{
			if (root == node)
			{
				std::cout << "HIIIIIIIIIIIII!\n";
				delete_node(node);
				root = 0;
				return;
			}

			node_ptr parent = node->parent;

			if (parent)
			{
				if (parent->left == node)
					parent->left = 0;
				else
					parent->right = 0;
			}
			delete_node(node);
			eraseBalanceTree(root, parent, 0);
		}

		void	redNoChild(node_ptr &root, node_ptr node)
		{
			if (node->parent)
			{
				if (node->parent->left == node)
					node->parent->left = 0;
				if (node->parent->right == node)
					node->parent->right = 0;
			}
			delete_node(node);
			node = 0;
		}
		
		void	eraseBalanceTree(node_ptr &root, node_ptr parent, node_ptr req)
		{
			
//			std::string lol;
//			std::cin >> lol;
			if (!parent->left || (req && req == parent->left))
			{
				node_ptr brother = parent->right;
				if (!brother->isRed)
				{
					if ((brother->left && brother->left->isRed) || (brother->right && brother->right->isRed))
					{
						if (brother->right && brother->right->isRed)
						{
							brother->isRed = parent->isRed;
							parent->isRed = false;
							brother->right->isRed = false;
							leftRotate(root, parent);
						}
						else if (brother->left && brother->left->isRed)
						{
							bool color = brother->isRed;
							brother->isRed = brother->left->isRed;
							brother->left->isRed = color;
							rightRotate(root, brother);
							eraseBalanceTree(root, parent, 0);
						}
					}
					else
					{
						bool color = parent->isRed;
						brother->isRed = true;
						parent->isRed = false;
						if (!color && parent->parent)
							eraseBalanceTree(root, parent->parent, parent);
					}
				}
				else
				{
					leftRotate(root, parent);
					parent->isRed = true;
					brother->isRed = false;
					eraseBalanceTree(root, parent, 0);
				}
			}
			else
			{
				node_ptr brother = parent->left;
				if (!brother->isRed)
				{
					if ((brother->left && brother->left->isRed) || (brother->right && brother->right->isRed))
					{
						if (brother->right && brother->right->isRed)
						{
							brother->isRed = parent->isRed;
							parent->isRed = false;
							brother->right->isRed = false;
							rightRotate(root, parent);
						}
						else if (brother->left && brother->left->isRed)
						{
							bool color = brother->isRed;
							brother->isRed = brother->left->isRed;
							brother->left->isRed = color;
							leftRotate(root, brother);
							eraseBalanceTree(root, parent, 0);
						}
					}
					else
					{
						bool color = parent->isRed;
						brother->isRed = true;
						parent->isRed = false;
						if (!color && parent->parent)
							eraseBalanceTree(root, parent->parent, parent);
					}
				}
				else
				{
					rightRotate(root, parent);
					parent->isRed = false;
					brother->isRed = true;
					eraseBalanceTree(root, parent, 0);
				}
			}
		}

		void	printTreeFromLeft(node_ptr root)
		{
			if (root)
			{
				printTreeFromLeft(root->left);
				node_ptr tmp = root;
				int i = 0;
				for (; tmp; i++)
					tmp = tmp->parent;
				std::cout << root->data << (root->isRed?" Red":" Black") << " level = " << i << std::endl;
				printTreeFromLeft(root->right);
			}
		}

		void	leftOrderTravers(node_ptr root, std::string *levels)
		{
			if (root)
			{
				int flat = 0;
				node_ptr tmp = root;
				while (tmp)
				{
					flat++;
					tmp = tmp->parent;
				}
				levels[flat] += std::to_string(root->data);
				levels[flat] += " ";

				leftOrderTravers(root->left, levels);
				leftOrderTravers(root->right, levels);
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
                        std::cout <<"\033[0;36m"<< nodeV->data.first<<"\033[0m"<<std::endl;
                    else
                        std::cout <<"\033[0;31m"<< nodeV->data.first << "\033[0m"<<std::endl;
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
