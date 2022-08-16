#pragma once

namespace ft{

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

	template <class T1, class T2>
	bool operator==(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair <T1, T2>& lhs, const pair <T1, T2>& rhs) {
		return !(lhs < rhs);
	}

}
