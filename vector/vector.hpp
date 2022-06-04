#pragma once
#include <iostream>
#include "../iter/iterator.hpp"
#include "../iter/reverse_iterator.hpp"
#include "../iter/random_access_iterator.hpp"
#include "../utils/utils.hpp"
#include <memory>
#include <vector>
namespace ft{
	template< class T, class Allocator = std::allocator<T> >
	class vector{
	public:
//		Переименовываем переменные согласно стандарту
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename iterator::difference_type				difference_type;
		//Блок конструкторов
//		vector(): _arr(nullptr), _alloc(std::allocator<T>), _size(0), _cap(0) {};
		explicit vector(const allocator_type &allocator = allocator_type()):
		_arr(nullptr), _alloc(allocator), _size(0), _cap(0) {}

		explicit vector (size_type n,
						 const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type())
		{
			if (n == _size)
				return;
			_alloc = alloc;
			_arr = _alloc.allocate(n);
			_cap = n;
			_size = n;
//			value_type *tmp = _arr;
			for (size_t i = 0; i < n; i++)
				_alloc.construct(_arr + i, val);
		}

		template<class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()){
			_alloc = alloc;
			_size = 0;
			for (InputIterator it = first; it != last; it++)
				_size++;
			_cap = _size;
			_arr = _alloc.allocate(_size);
			value_type *tmp = _arr;
			for (InputIterator it = first; it != last; it++)
				_alloc.construct(tmp++, *it);
		}

		vector (const vector& x): _alloc(x._alloc), _size(x._size), _cap(x
		._cap){
			_arr = _alloc.allocate(_cap);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_arr + i, x[i]);
		}

		~vector()
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);
		}

		vector& operator= (const vector& ar){
			_alloc = ar._alloc;
			_size = ar._size;
			_cap = ar._cap;
			_arr = _alloc.allocate(_size);
			value_type *tmp = _arr;
			for (const_iterator it = ar.begin(); it != ar.end(); it++)
				_alloc.construct(tmp++, *it);
			return *this;
		}
//		template <class InputIterator>
//		void assign (InputIterator first, InputIterator last){
//			clear();
//			insert(begin(), first, last);
//		}
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			size_type distance = ft::distance(first, last);

			if (_cap < distance)
			{
				if (_cap * 2 >= distance)
					reserve(_cap * 2);
				else
					reserve(distance);
			}
			for (; first < last; _size++, first++)
				_alloc.construct(&(*(begin() + _size)), *first);
		}
//		void assign (size_type n, const value_type& val) {
//			clear();
//			insert(begin(), n, val);
//		}
		void assign(size_type n, const value_type &val)
		{
			clear();
			if (_cap < n)
			{
				if (_cap * 2 >= n)
					reserve(_cap + n);
				else
					reserve(n);
			}
			for (; _size < n; _size++)
				_alloc.construct(&(*(begin() + _size)), val);
		}
		//Iterators
		iterator begin() {return iterator(_arr);}
		const_iterator begin() const {return const_iterator(_arr);}
		iterator end() {return iterator(_arr + _size);}
		const_iterator end() const {return const_iterator(_arr + _size);}

		reverse_iterator rbegin() {return reverse_iterator(_arr + _size - 1);}
		const_reverse_iterator rbegin() const {return reverse_iterator(_arr + _size - 1);}
		reverse_iterator rend() {return reverse_iterator(_arr - 1);}
		const_reverse_iterator rend() const {return reverse_iterator(_arr - 1);}

		//Capacity
		size_type size() const {return (_size);}
		size_type max_size() const {return (_alloc.max_size());}
		size_type capacity() const {return (_cap);}
		bool empty() const { return size() == 0;}

		void resize (size_type n, value_type val = value_type())
		{
//			if (!val)
//				val = 0;
//			if (n < 0)
//				throw std::logic_error("Error: Incorrect size!");
			if (n == _size)
				return;
			if (n < _size)
			{
				erase(&_arr[n], end());
				_size = n;
			}
			else if (n > _cap && n <= _cap * 2)
			{
				reserve(_cap * 2);
				for (size_type i = _size; i < n; ++i) //?????
					_alloc.construct(_arr + i, val);
				_size = n;
			}
			else if (n > _cap && n > _cap * 2)
			{
				reserve(n);
				for (size_type i = _size; i < n; ++i) //?????
					_alloc.construct(_arr + i, val);
				_size = n;
			}
			else
			{
				for (size_type i = _size; i < n; ++i)
					_alloc.construct(_arr + i, val);
				_size = n;
			}
		}

		void reserve(size_t n)
		{
			if (n <= _cap) return;

			value_type *new_arr = _alloc.allocate(n);
			try{
				std::uninitialized_copy(_arr, _arr + _size, new_arr);
			}
			catch (...) {
				_alloc.deallocate(new_arr, _cap);
				throw;
			}
			_alloc.deallocate(_arr, _cap);
			_arr = new_arr;
			_cap = n;
		}

		void push_back(const T& value)
		{
			if (_size == _cap) reserve(_cap * 2);
			_alloc.construct(_arr + _size, value);
			++_size;
//			++_size;

		}

		void pop_back()
		{
			_alloc.destroy(_arr + (--_size));
		}

		iterator insert( iterator pos, const T& value )
		{
			if (pos > end() || pos < begin())
				throw std::logic_error("Error: Bad position index!/n");
			value_type *new_arr, *tmp;
			if (_size == _cap)
			{
				new_arr = _alloc.allocate(_cap * 2);
				_cap *= 2;
			}
			else
				new_arr = _alloc.allocate(_cap);
			tmp = new_arr;
			for (iterator it = begin(); it != end(); it++)
			{
				if (it == pos) _alloc.construct(tmp++, value);
				_alloc.construct(tmp++, *it);
				_alloc.destroy(it.base());
			}
			if (pos == end()) _alloc.construct(tmp, value);

			_alloc.deallocate(_arr, _cap);
			_arr = new_arr;
			_size++;
			return (pos);
		}
//		void insert( iterator pos, size_type count, const T& value )
//		{
//			if (pos > end() || pos < begin())
//				throw std::logic_error("Error: Bad position index!/n");
//			value_type *new_arr, *tmp;
//			size_type new_cap = _cap;
//			if (_size + count > _cap)
//			{
//				new_arr = _alloc.allocate(_size + count);
//				new_cap = _size + count;
//			}
//			else
//				new_arr = _alloc.allocate(_cap);
//			tmp = new_arr;
//			_size += count;
//			size_type i = 0;
//			for (iterator it = begin(); it != end(); it++)
//			{
//				if (it == pos)
//				{
//					while(count--)
//						_alloc.construct(tmp + i, value);
//					i++;
//				}
//				_alloc.construct(tmp + i, *it);
//				i++;
//				_alloc.destroy(it.base());
//			}
//			_alloc.deallocate(_arr, _cap);
//			_arr = new_arr;
//			_cap = new_cap;
//		}
		void insert(iterator position, size_type n, const value_type &val)
		{
			if (_size + n > _cap)
			{
				if (_size + n >= _cap * 2)
					_cap = _size + n;
				else
					_cap *= 2;
			}
			value_type *temp_data = _alloc.allocate(_cap);
			value_type *p = temp_data;
			for (int i = 0; begin() + i < position; i++)
			{
				_alloc.construct(temp_data, *(begin() + i));
				temp_data++;
				_alloc.destroy(&(*(begin() + i)));
			}
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(temp_data, val);
				temp_data++;
			}
			for (int i = 0; position + i < end(); i++)
			{
				_alloc.construct(temp_data, *(position + i));
				temp_data++;
				_alloc.destroy(&(*(position + i)));
			}
			_alloc.deallocate(&(*begin()), _size);
			_arr = p;
			_size += n;
		}
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last )
		{
			if (pos > end() || pos < begin())
				throw std::logic_error("Error: Bad position index!/n");
			size_type count = 0, new_cap = _cap;
			value_type *new_arr, *tmp;
			for (InputIt it = first; it != last; it++)
				count++;
			if (_size + count > _cap)
			{
				new_arr = _alloc.allocate(_cap * 2);
				new_cap = _cap * 2;
			}
			else
				new_arr = _alloc.allocate(_cap);
			tmp = new_arr;
			for (iterator it = begin(); it != end(); it++)
			{
				if (it == pos)
				{
					while(first != last)
					{
						_alloc.construct(tmp++, *first);
						first++;
					}
				}
				_alloc.construct(tmp++, *it);
				_alloc.destroy(it.base());
			}
			_alloc.deallocate(_arr, _cap);
			_arr = new_arr;
			_size += count;
			_cap = new_cap;
		}

		reference operator[](size_type n) {return _arr[n];}
		const_reference operator[](size_type n) const {return _arr[n];}

		reference at (size_type n) {
			if (n >= _size || n < 0)
				throw std::out_of_range("Error: Out of range");
			return _arr[n];
		}
		const_reference at (size_type n) const {
			if (n >= _size || n < 0)
				throw std::out_of_range("Error: Out of range");
			return _arr[n];
		}

		iterator erase( iterator pos )
		{
			if (pos > end() || pos < begin())
				throw std::logic_error("Error: Bad position index!/n");
			if (!_arr)
				return insert(begin(), *pos);
			value_type *tmp = _alloc.allocate(_cap);
			size_type i = 0;
			for (iterator it = begin(); it != end(); it++)
			{
				if (it == pos)
					continue;
				tmp[i++] = *it;
			}
			--_size;
			_alloc.deallocate(_arr, _cap);
			_arr = tmp;
			return pos;
		}
		iterator erase( iterator first, iterator last )
		{
			if (first > end() || first < begin() || last > end() || last <
			begin())
				throw std::logic_error("Error: Bad position index!/n");
			if (!_arr)
			{
				insert(begin(), first, last);
				return (begin());
			}
			value_type *tmp = _alloc.allocate(_cap);
			size_type i = 0;
			for (iterator it = begin(); it != end(); it++)
			{
				if (it >= first && it < last)
					continue;
				tmp[i++] = *it;
			}
			_alloc.deallocate(_arr, _cap);
			_arr = tmp;
			_size -= ft::distance(first, last);
			return last;
		}

		void clear() {
			for (size_type i = 0; i != _size; ++i)
				_alloc.destroy(_arr + i);
			_size = 0;
		}
		void swap (vector& x) {
			allocator_type tmp_alloc = _alloc;
			value_type* tmp_arr = _arr;
			size_type tmp_size = _size;
			size_type tmp_cap = _cap;
			_alloc = x._alloc;
			_arr = x._arr;
			_size = x._size;
			_cap = x._cap;
			x._alloc = tmp_alloc;
			x._arr = tmp_arr;
			x._size = tmp_size;
			x._cap = tmp_cap;
		}

		allocator_type get_allocator() const { return _alloc; }
		reference front() {return (&_arr[0]);}
		const_reference front() const {return (&_arr[0]);}
		reference back() {return (&_arr[_size - 1]);}
		const_reference back() const {return (&_arr[_size - 1]);}
		pointer data() {return _arr;}
		const pointer data() const {return _arr;}

	private:
		value_type		*_arr;
		allocator_type	_alloc;
		size_type		_size;
		size_type 		_cap;

	};
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator l_it = lhs.begin();
		typename ft::vector<T>::const_iterator r_it = rhs.begin();
		while (l_it == r_it && (l_it != lhs.end() || r_it != rhs.end()))
		{
			l_it++;
			r_it++;
		}
		if (l_it == lhs.end() && r_it == rhs.end())
			return true;
		else
			return false;
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}