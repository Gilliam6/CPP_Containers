#pragma once
#include "iterator.hpp"

namespace ft
{
	template<typename T>
	class random_access_iterator :
			iterator<ft::random_access_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>
				iterator_type;
		typedef typename iterator_type::iterator_category iterator_category;
		typedef typename iterator_type::value_type value_type;
		typedef typename iterator_type::difference_type difference_type;
		typedef T *pointer;
		typedef T &reference;

		random_access_iterator() : _ptr(0)
		{}

		random_access_iterator(const pointer a) : _ptr(a)
		{}

		random_access_iterator(const random_access_iterator &ar) : _ptr(
				ar.base())
		{}

		random_access_iterator &operator=(const random_access_iterator &ar)
		{
			if (this == &ar)
				return (*this);
			_ptr = ar.base();
			return *this;
		}

		~random_access_iterator()
		{};

		pointer base() const
		{ return _ptr; }

		reference operator*()
		{
			return *_ptr;
		}

		pointer operator->()
		{
			return _ptr;
		}

		random_access_iterator &operator++()
		{
			++_ptr;
			return *this;
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp = *this;
			++_ptr;
			return tmp;
		}

		random_access_iterator &operator--()
		{
			--_ptr;
			return *this;
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp = *this;
			--_ptr;
			return tmp;
		}

		random_access_iterator operator-(difference_type n) const
		{
			return _ptr - n;
		}

		random_access_iterator operator+(difference_type n) const
		{
			return _ptr + n;
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return *this;
		}

		random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return *this;
		}

		reference operator[](difference_type n) const
		{ return *(operator+(n)); }

	private:
		pointer _ptr;
	};

	template<class Iterator>
	bool operator==(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator<=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	bool operator>(const random_access_iterator<Iterator> &lhs,
				   const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}
	template<class Iterator>
	bool operator>=(const random_access_iterator<Iterator> &lhs,
					const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	random_access_iterator<Iterator> operator+(
			typename random_access_iterator<Iterator>::difference_type n,
			const random_access_iterator<Iterator> &_it)
	{
		return _it + n;
	}

	template<class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(
			const random_access_iterator<Iterator> &lhs,
			const random_access_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}