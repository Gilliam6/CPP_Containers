#pragma once
//#include "../vector/vector.hpp"
#include "../iter/iterator.hpp"
#include "../iter/random_access_iterator.hpp"
#include "../iter/reverse_iterator.hpp"

namespace ft{
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2<*first1)) return false;
			else if (comp(*first1<*first2)) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate predicate) {
		(void) (predicate);
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template < bool B, class T =  void >
	struct enable_if { } ;

	template < class T >
	struct enable_if < true , T >  {  typedef T type ;  } ;

	template <class T, bool val>
	struct integral_constant {
		static const bool value = val;
		typedef T					value_type;
		typedef integral_constant	type;

		operator value_type() const {
			return value;
		}
	};
	template <class T>
	struct is_integral : public ft::integral_constant<T, false> {};

	template <>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> {};

	template <class T>
	void swap (T& ls, T& rs) {
		T tmp = ls;
		ls = rs;
		rs = tmp;
	}

	template<class Arg1, class Arg2, class Result> struct binary_function {
		typedef Arg1		first_argument_type;
		typedef Arg2		second_argument_type;
		typedef Result		result_type;
	};

	template< class T >
	struct less: public std::binary_function<T, T, bool>{
	public:
		bool operator()( const T& lhs, const T& rhs ) const{
			return lhs < rhs;
		}
	};

	template< class T1,class T2 > struct pair{
	public:
		typedef T1	first_type;
		typedef T2	second_type;
		first_type	first;
		second_type	second;

		pair(): first(0), second(0) {}
		pair( const T1& x, const T2& y ): first(x), second(y) {}
		pair( const pair& p ): first(p.first), second(p.second) {}
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {}//
		// ?? вопросы с возможностью использовать другие типы

		pair& operator=( const pair& other ) {
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u ){
		return (ft::pair<T1,T2>(t, u));
	}

	template <class T>
		struct switch_const {
			typedef T type;
		};

	template <class T>
		struct switch_const<const T> {
			typedef T type;
		};

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return ((lhs.first < rhs.first) && (lhs.second < rhs.second));
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return ((lhs.first > rhs.first) && (lhs.second > rhs.second));
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(lhs < rhs));
	}
//	template <class T, class Alloc>
//	void swap_1 (vector<T,Alloc>& x, vector<T,Alloc>& y) {
//		uintptr_t tmp = reinterpret_cast<uintptr_t>(x);
//		x = y;
//		y = reinterpret_cast<vector<T,Alloc>>(tmp);
//	}
}
