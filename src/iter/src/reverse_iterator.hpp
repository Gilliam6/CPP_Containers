#pragma once
#include <iterator>

namespace ft{
	template<class BidirectionalIterator>
	class reverse_iterator{
	private:
		BidirectionalIterator it;
	public:
		reverse_iterator(const it& it): it(it) {}

		reverse_iterator<it>& operator++()
		{
			--it;
			return *this;
		}

		reverse_iterator<it> operator++(it)
		{
			BidirectionalIterator tmp(it);
			--it;
			return tmp;
		}

		reverse_iterator<it>& operator--()
		{
			++it;
			return *this;
		}

		reverse_iterator<it> operator--(it)
		{
			BidirectionalIterator tmp(it);
			++it;
			return tmp;
		}
	};
}