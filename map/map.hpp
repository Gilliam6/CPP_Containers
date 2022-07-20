#pragma once

#include <iostream>
#include "../iter/iterator.hpp"
#include "../iter/reverse_iterator.hpp"
#include "../utils/red_black_tree.hpp"
#include "../iter/BidirectionalMapIterator.hpp"
namespace ft{
	template<
			class Key,
			class T,
			class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::pair<Key, T> >
	> class map{
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef	ft::pair<Key, T>									value_type;
		typedef size_t													size_type;
		typedef ptrdiff_t												difference_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef typename ft::BidirectionalmapIterator<value_type>		iterator;
		typedef typename ft::BidirectionalmapIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
//		typedef ft::RBT <value_type, pair_compare>							tree_type;
		typedef ft::RBT_Node<value_type>*								node_ptr;

		map() : _size(0), _alloc(Allocator()), _k_cmp(Compare()), _root(0) {}
		template< class InputIt >
		map( InputIt first, InputIt last,
			 const Compare& comp = Compare(),
			 const Allocator& alloc = Allocator() ): _size(0), _alloc(alloc), _k_cmp(comp), _root(0)
		{
			_root = _tree.make_node(value_type());
			insert(first, last);
		}
		explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() ): _size(0), _alloc(alloc), _k_cmp(comp), _root(0) { _root = _tree.make_node(value_type()); }

		map( const map& other ): _size(0), _alloc(other._alloc), _k_cmp(other._k_cmp), _v_cmp(other._v_cmp), _tree(other._tree), _root(0) 
		{
			_root = _tree.make_node(value_type());
			*this = other;
		}
		~map() { _tree.clear(_root); }
		map& operator=( const map& other ) 
		{
			clear();
			_alloc = other._alloc;
			_k_cmp = other._k_cmp;
			_v_cmp = other._v_cmp;
			insert(other.begin(), other.end());
			return *this;
		}

		allocator_type get_allocator() const { return _alloc;}

		mapped_type& at( const key_type& key )
		{
			node_ptr tmp = (_tree.find_node(_root, bind(key)));
			if (!tmp)
				throw std::out_of_range("Key is out of range");
			return (tmp->data.second);
		}

		mapped_type& at( const key_type& key ) const 		
		{
			node_ptr tmp = (_tree.find_node(_root, bind(key)));
			if (!tmp)
				throw std::out_of_range("Key is out of range");
			return (tmp->data.second);
		}

		mapped_type& operator[]( const Key& key )
		{
			node_ptr tmp = _tree.find_node(_root, bind(key));
			if (tmp)
				return (tmp->data.second);
			bool res = _tree.insert(_root,_tree.make_node(ft::make_pair(key, mapped_type())));
			if (res)
			{
				_size++;
				return ((_tree.find_node(_root, bind(key))->data.second));
			}
		}

		ft::pair<iterator, bool> insert(const value_type& val)
		{
			bool res = _tree.insert(_root, _tree.make_node(val));
			_size += res;
			return (ft::pair<iterator, bool>(iterator(_root, _tree.find_node(_root, val)), res));
		}

		iterator insert(iterator, const value_type& val)
		{
			_size += _tree.insert(_root, _tree.make_node(val));
			return (iterator(_root, _tree.find_node(_root, val)));
		}

		template <class InputIt>
			void	insert(InputIt begin, InputIt last)
			{
				for (;begin != last; begin++)
					insert(*begin);
			}

		void	erase(iterator pos)
		{
			_size -= _tree.erase_val(_root, *pos);
		}

		bool	erase(const key_type &key)
		{
			bool res = _tree.erase_val(_root, bind(key));
			std::cout << (res?"TRUE\n":"FALSE\n");
			_size -= res;
			return (res);
		}

		void	erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}

		void	swap(map &x)
		{
			ft::swap(x._root, _root);
			ft::swap(x._alloc, _alloc);
			ft::swap(x._k_cmp, _k_cmp);
			ft::swap(x._v_cmp, _v_cmp);
			ft::swap(x._size, _size);
		}

		void	clear()
		{
			_tree.clear(_root);
			_root = 0;
			_size = 0;
		}
		
		key_compare key_comp() 
		{
			return _k_cmp;
		}

		key_compare key_comp() const 
		{
			return _k_cmp;
		}

		iterator	find(const key_type& key)
		{
			return (iterator(_root, _tree.find_node(_root, bind(key))));
		}

		const_iterator	find(const key_type& key) const
		{
			return (const_iterator(_root, _tree.find_node(_root, bind(key))));
		}

		size_type count(const key_type& k) const {
			if (_tree.find_node(_root, bind(k)))
				return 1;
			return 0;
		}

		iterator lower_bound(const key_type& k) {
			return (iterator(_root, _tree.lower(_root, bind(k))));
		}

		const_iterator lower_bound(const key_type& k) const {
			return (const_iterator(_root, _tree.lower(_root, bind(k))));
		}

		iterator	upper_bound(const key_type& key)
		{
			node_ptr temp = _tree.lower(_root, bind(key));
			iterator res(_root, temp);
			if (temp && temp->data.first == key)
				++res;
			return iterator(res);
		}

		iterator	upper_bound(const key_type& key) const
		{
			node_ptr temp = _tree.lower(_root, bind(key));
			iterator res(_root, temp);
			if (temp && temp->data.first == key)
				++res;
			return iterator(res);
		}

		ft::pair <iterator, iterator> equal_range(const key_type& k) {
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		ft::pair <const_iterator, const_iterator> equal_range(const key_type& k) const {
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		value_type	bind(const Key &key)
		{
			return ft::make_pair(key, mapped_type());
		}

		value_type	bind(const Key &key) const
		{
			return ft::make_pair(key, mapped_type());
		}

		bool	empty() const { return _size == 0; }
		size_type	size() const  { return _size; }
		size_type	max_size() const { return _tree.max_size(); }

		iterator	begin() { return (iterator(_root, _tree.min_node(_root))); }  
		const_iterator	begin() const  { return const_iterator(_root, _tree.min_node(_root)); }  
		iterator	end() { return (iterator(_root, 0)); }  
		const_iterator	end() const { return (const_iterator(_root, 0)); }  
		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }




		class value_compare: public ft::binary_function<value_type, value_type, bool> {
			friend class map<key_type, mapped_type, key_compare, Allocator>;
		protected:
			Compare comp;
			value_compare(const key_compare & cmp = key_compare()): comp(cmp) {}
//			~value_compare() {}
		public:
			bool operator()( const value_type& lhs, const value_type& rhs )
			const {
				return (comp(lhs.second, rhs.second));
			}
		};

		class pair_compare{
			key_compare comp;
		public:
			pair_compare(const key_compare & cmp = key_compare()): comp(cmp) {}
			bool operator()( const value_type& lhs, const value_type& rhs )
			const {
				return (comp(lhs.first, rhs.first));
			}
		};

		typedef ft::RBT <value_type, pair_compare>							tree_type;
	private:
		size_type		_size;
		allocator_type	_alloc;
		key_compare		_k_cmp;
		value_compare	_v_cmp;
		tree_type 		_tree;
		node_ptr		_root;
	};
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()) && ft::equal(y.begin(), y.end(), x.begin());
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return !(x == y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return ft::lexicographical_compare( x.begin(), x.end(), y.begin(), y.end()) && x != y;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return x < y || x == y;
	}
	template <class Key, class T, class Compare, class Allocator>
	bool operator>(const map<Key, T ,Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return y < x;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y) {
		return x > y || x == y;
	}

	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y) {
		x.swap(y);
	}
}
