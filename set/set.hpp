#pragma once

#include "../iter/iterator.hpp"
#include "../iter/reverse_iterator.hpp"
#include "../utils/red_black_tree.hpp"
#include "../iter/BidirectionalMapIterator.hpp"
#include "../utils/pair.hpp"
#include <memory>
namespace ft{
	template<
			class Key,
			class Compare = ft::less<Key>,
			class Allocator = std::allocator<Key> 
	> class set {
	public:
        typedef Key															key_type;
		typedef key_type													value_type;
        typedef size_t														size_type;
		typedef Compare														key_compare;
		typedef key_compare													value_compare;
		typedef Allocator													allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
        typedef std::ptrdiff_t												difference_type;
		typedef ft::BidirectionalmapIterator<const value_type>				iterator;
		typedef ft::BidirectionalmapIterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
        typedef typename Allocator::template rebind<RBT_Node<value_type> >::other	node_allocator_type;
        typedef RBT<value_type , value_compare , ft::RBT_Node<value_type>, node_allocator_type >		tree_type;
        typedef RBT_Node<value_type>* node_ptr;
        
        explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(0), _alloc(alloc), _k_comp(comp), _size(0) {}

        template <class InputIterator>
        set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(0), _alloc(alloc), _k_comp(comp), _size(0) {
            insert(first, last);
        }

        ~set() {
            _tree.clear(_root);
        }

        set(const set& other) : _root(0), _alloc(other._alloc), _k_comp(other._k_comp), _size(0) {
            //_root = _tree.make_node(value_type());
            *this = other;
        }

        set& operator=(const set& other) {
            clear();
            _alloc = other._alloc;
            _k_comp = other._k_comp;
            insert(other.begin(), other.end());
            //_tree.printTree(_root);
            return *this;
        }

		iterator	begin() { return (iterator(_root, _tree.min_node(_root))); }  
		const_iterator	begin() const  { return const_iterator(_root, _tree.min_node(_root)); }  
		iterator	end() { return (iterator(_root, 0)); }  
		const_iterator	end() const { return (const_iterator(_root, 0)); }  
		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

		bool empty() const {
            return _size == 0;
        }

		size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return _tree.max_size();
        }

        ft::pair<iterator, bool> insert(const value_type& val) {
			bool res = _tree.insert(_root, _tree.make_node(val));
            //_tree.printTree(_root);
			_size += res;
			return (ft::pair<iterator, bool>(iterator(_root, _tree.find_node(_root, val)), res));
        }

        iterator insert(iterator, const value_type& val) {
            
            node_ptr ptr = _tree.make_node(val);
            _size += _tree.insert(_root, ptr);
            return iterator(_root, ptr);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; ++first)
                insert(*first);
        }

        void erase(iterator position) {
            bool res = _tree.erase_val(_root, *position);

            if (res)
                --_size;
        }

        size_type erase(const key_type& k) {
            bool res = _tree.erase_val(_root, k);

            if (res)
                --_size;
            return res;
        }

        void erase(iterator first, iterator last) {
            while(first != last)
                erase(first++);
        }

        void swap(set& x) {
			ft::swap(x._root, _root);
			ft::swap(x._alloc, _alloc);
			ft::swap(x._k_comp, _k_comp);
			ft::swap(x._size, _size);
        }

        void clear() {
            _tree.clear(_root);
            _root = 0;
            _size = 0;
        }

        key_compare key_comp() const {
            return _k_comp;
        }

        value_compare value_comp() const {
            return _k_comp;
        }

        iterator find(const key_type& k) {
            node_ptr ptr = _tree.find_node(_root, k);
            return iterator(_root, ptr);
        }

        const_iterator find(const key_type& k) const {
            node_ptr ptr = _tree.find_node(_root, k);
            return const_iterator(_root, ptr);
        }

        size_type count(const key_type& k) const {
            if (_tree.find_node(_root, k))
                return 1;
            return 0;
        }

        iterator lower_bound(const key_type& k) {
            return iterator(_root, _tree.lower(_root, k));
        }

        const_iterator lower_bound(const key_type& k) const {
            return const_iterator(_root, _tree.lower(_root, k));
        }

        iterator upper_bound(const key_type& k) {
            node_ptr tmp = _tree.lower(_root, k);
            iterator res(_root, tmp);

            if (tmp && tmp->data == k)
                ++res;
            return iterator(res);
        }

        const_iterator upper_bound(const key_type& k) const {
            node_ptr tmp = _tree.lower(_root, k);
            iterator res(_root, tmp);

            if (tmp && tmp->data == k)
                ++res;
            return const_iterator(res);
        }

        ft::pair<iterator, iterator> equal_range(const key_type& k) {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }

        allocator_type get_allocator() const {
            return _alloc;
        }

	private:
        tree_type		_tree;
        node_ptr		_root;
        allocator_type	_alloc;
        key_compare		_k_comp;
        size_type		_size;
	};

    template <class Key, class Compare, class Allocator>
    bool operator==(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
        return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()) && ft::equal(y.begin(), y.end(), x.begin());
    }

    template <class Key, class Compare, class Allocator>
    bool operator!=(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
        return !(x == y);
    }

    template <class Key, class Compare, class Allocator>
    bool operator<(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()) && x != y;
    }

	template <class Key, class Compare, class Allocator>
	bool operator<=(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
		return x < y || x == y;
	}

    template <class Key, class Compare, class Allocator>
    bool operator>(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
        return y < x;
    }

    template <class Key, class Compare, class Allocator>
    bool operator>=(const set<Key, Compare, Allocator>& x, const set<Key, Compare, Allocator>& y) {
        return x > y || x == y;
    }

    template <class Key, class Compare, class Allocator>
    void swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y) {
        x.swap(y);
    }
}
