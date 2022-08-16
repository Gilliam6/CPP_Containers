
#pragma once
#include "iterator.hpp"
#include <iterator>
#include "../utils/red_black_tree.hpp"
#include "../utils/utils.hpp"
#include "../utils/pair.hpp"
namespace ft
{

	template<class T>
	class BidirectionalmapIterator:
		ft::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator_traits<T *>::difference_type difference_type;
		typedef typename ft::iterator_traits<T *>::value_type value_type;
		typedef typename ft::iterator_traits<T *>::pointer pointer;
		typedef typename ft::iterator_traits<T *>::reference reference;
		typedef ft::RBT_Node<typename ft::switch_const<T>::type> *node_ptr;
		typedef std::bidirectional_iterator_tag iterator_category;

		BidirectionalmapIterator(): _root(0), _ptr(0) {}
	//	BidirectionalmapIterator(const pointer a, const pointer b): _root(a), _ptr(b) {}
		explicit BidirectionalmapIterator(const node_ptr &root, const node_ptr &node): _root(root), _ptr(node) {}
		BidirectionalmapIterator(const BidirectionalmapIterator &ar): _root(ar._root), _ptr(ar._ptr) {}
//		BidirectionalmapIterator& operator=(const BidirectionalmapIterator &ar)
//		{
//			if (this == &ar)
//				return (*this);
//			_ptr = ar._ptr;
//			_root = ar._root;
//			return (*this);
//		}
		~BidirectionalmapIterator() {};

		template <class Type>
			operator BidirectionalmapIterator<const Type>() const 
			{
				return BidirectionalmapIterator<const Type>(_root, _ptr);
			}
		reference operator*() const { return (_ptr->data); }
		pointer operator->() const { return (&(_ptr->data)); }

		BidirectionalmapIterator& operator++()
		{
			if (!_ptr)
				return *this;
			else if (_ptr->right)
				_ptr = min_node(_ptr->right);
			else if (_ptr == max_node(_root))
				_ptr = 0;
			else 
			{
				while (_ptr == _ptr->parent->right)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return (*this);
		}
		
		BidirectionalmapIterator operator++(int)
		{
			BidirectionalmapIterator<T> tmp(*this);
			++(*this);
			return tmp;
		}
		
		BidirectionalmapIterator operator--(int)
		{
			BidirectionalmapIterator<T> tmp(*this);
			--(*this);
			return tmp;
		}

		BidirectionalmapIterator& operator--()
		{
			if (!_ptr)
				_ptr = max_node(_root);
			else if (_ptr->left)
				_ptr = max_node(_ptr->left);
			else 
			{
				while (_ptr->parent && _ptr == _ptr->parent->left)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
			return (*this);
		}

		bool operator==(const BidirectionalmapIterator& it) const
		{ return (it._ptr == _ptr); }

		bool operator!=(const BidirectionalmapIterator& it) const
		{ return (it._ptr != _ptr); }

	private:
		node_ptr _root;
		node_ptr _ptr;

		node_ptr min_node(node_ptr node)
		{
			if (node)
			{
				while (node->left)
					node = node->left;
			}
			return (node);
		}
		
		node_ptr max_node(node_ptr node)
		{
			if (node)
			{
				while (node->right)
					node = node->right;
			}
			return (node);
		}
	};
}
