#pragma once
#include "iterator.hpp"
namespace ft{
	template<class BidirectionalIterator>
	class reverse_iterator{
	public:
		typedef BidirectionalIterator							iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type
		value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference         reference;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;

		reverse_iterator() {};
		explicit reverse_iterator (iterator_type it) : _it(it) {}
		reverse_iterator(const reverse_iterator &it): _it(it.base()) {}
		~reverse_iterator() {}

		iterator_type base() const {return _it;}
		reference operator*() const {
			BidirectionalIterator tmp;
			tmp = _it;
			return *tmp;
		}
		reverse_iterator operator+ (difference_type n) const {
			return reverse_iterator(_it - n);
		}
		reverse_iterator operator+= (difference_type n) const {
			_it -= n;
			return *this;
		}
		reverse_iterator& operator++(){
			--_it;
			return _it;
		}
		reverse_iterator operator++(int)
		{
			BidirectionalIterator tmp(_it);
			--_it;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++_it;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			BidirectionalIterator tmp(_it);
			++_it;
			return tmp;
		}
		reverse_iterator operator- (difference_type n) const {
			return reverse_iterator(_it + n);
		}
		reverse_iterator operator-= (difference_type n) const {
			_it += n;
			return *this;
		}
		pointer operator->() const{
			return _it.operator->();
		}
		reference operator[] (difference_type n) const{
			return *(_it - n);
		}
	private:
		BidirectionalIterator _it;
	};
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs){
		return lhs.base() <= rhs.base();
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it){
		return rev_it + n;
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return lhs.base() - rhs.base();
	}
}