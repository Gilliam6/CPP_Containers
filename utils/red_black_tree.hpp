#pragma once
#include "utils.hpp"


namespace ft{
	template <typename T>
	struct RBT_Node{
	public:
		typedef T	value_type;

		value_type	data;
		bool 		color;
		RBT_Node	*parent;
		RBT_Node	*left;
		RBT_Node	*right;

		RBT_Node (): data(), color(false), parent(u_nullptr), left(u_nullptr),
		right
		(u_nullptr) {}
		RBT_Node (const RBT_Node& ar) : data(ar.data), color(false), parent
		(ar.parent), left(ar.left), right(ar.right) {}
		RBT_Node(const value_type& val, RBT_Node *par = u_nullptr , RBT_Node
		*l = u_nullptr, RBT_Node *r = u_nullptr): data(val), color(false),
		parent(par), left(l), right(r) {}

		~RBT_Node() {}

		RBT_Node& operator=(const RBT_Node& ar)
		{
			if (ar == *this)
				return *this;
			data = ar.data;
			color = ar.color;
			parent = ar.parent;
			left = ar.left;
			right = ar.right;
			return *this;
		}

		bool operator==(const RBT_Node& ar) { return (data == ar.data); }
	}




	template<class T, class Compare = ft::less<T>, class Node = ft::RBT_Node<T>,
			class Type_Alloc = std::allocator<T>, class Node_Alloc =
					std::allocator<Node> >
	class RBT{
	public:
		RBT() :
	};
}