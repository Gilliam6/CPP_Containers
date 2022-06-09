#pragma once
//#include <iostream>
//#include "../utils/utils.hpp"
#include "../vector/vector.hpp"
//#include <iterator>
//#include <deque>
//#include <map>
namespace ft{

	template <class T, class Container = ft::vector<T> >
		class stack{
	public:
		typedef T value_type;
		typedef Container 					container_type;
//		typedef typename Container::value_type 		value_type;
		typedef typename Container::size_type 		size_type;
		typedef typename Container::reference 		reference;
		typedef	typename Container::const_reference	const_reference;

		explicit stack( const container_type& cont = container_type() ):
		Cont(cont) {}
		stack( const stack& other ) { Cont.operator=(other.Cont); }
		~stack() {}

		stack& operator=( const stack& other ) {
			Cont.operator=(other.Cont);
			return *this;
		}

		reference top() { return Cont.back(); }
		const_reference top() const { return Cont.back(); }
		bool empty() const { return Cont.empty(); }
		size_type size() const { return Cont.size(); }
		void push( const value_type& value ) { Cont.push_back(value); }
		void pop() { Cont.pop_back(); }

		template< class Tn, class Containern >
		friend bool operator==( const ft::stack<Tn,Containern>& lhs,
				const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator!= ( const ft::stack<Tn,Containern>& lhs,
							const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator< ( const ft::stack<Tn,Containern>& lhs,
				const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator<= ( const ft::stack<Tn,Containern>& lhs,
				const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator> ( const ft::stack<Tn,Containern>& lhs,
				const ft::stack<Tn, Containern>& rhs );

		template< class Tn, class Containern >
		friend bool operator>= ( const ft::stack<Tn,Containern>& lhs,
				const ft::stack<Tn, Containern>& rhs );

	protected:
		container_type Cont;
	};
	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return lhs.Cont == rhs.Cont;
	}
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.Cont != rhs.Cont);
	}
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.Cont < rhs.Cont);
	}
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.Cont <= rhs.Cont);
	}
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,
					Container>& rhs )
	{
		return (lhs.Cont > rhs.Cont);
	}
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,
			Container>& rhs )
	{
		return (lhs.Cont >= rhs.Cont);
	}

}