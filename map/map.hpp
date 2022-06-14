#pragma once

#include <iostream>
#include "../iter/iterator.hpp"
#include "../iter/reverse_iterator.hpp"
#include <map>
namespace ft{
	template<
			class Key,
			class T,
			class Compare = ft::less<Key>, // сделать less
			class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef	ft::pair<const Key, T>					value_type;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&reference					reference;
		typedef const value_type&						const_reference;
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;
		typedef ft::Bidirectional_iterator<value_type>			iterator;
		typedef ft::Bidirectional_iterator< constvalue_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_iterator;

		map();
		template< class InputIt >
		map( InputIt first, InputIt last,
			 const Compare& comp = Compare(),
			 const Allocator& alloc = Allocator() );
		map( const map& other );
		~map();
		allocator_type get_allocator() const { return allocator_type;}



		class value_compare: public ft::binary_function<value_type, value_type, bool> {
			friend class map<key_type, mapped_type, key_compare, Allocator>;
		protected:
			Compare comp;
			value_compare( Compare c ): comp(c) {}
//			~value_compare() {}
		public:
			bool operator()( const value_type& lhs, const value_type& rhs )
			const {
				return (comp(lhs.first, rhs.first));
			}
		};
	private:
		size_type		_size;
		allocator_type	_alloc;
		key_compare		_cmp;
		RBT				_tree;
//		typedef struct _RBT{
//			value_type	_data;
//			_RBT		*left;
//			_RBT		*right;
//			_RBT		*parent;
//		} _RBT;
	};
}