#pragma once
#include <iostream>

namespace ft
{
	template<typename T>
	class allocator
	{
	public:
		typedef T			value_type;
		typedef T			*pointer;
		typedef T			&reference;
		typedef const T*	const_pointer;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t 	difference_type;
//		мембер переменные стандартного аллокатора для переименовывания
		//______________________________________________________________
		allocator(){};
		allocator(const allocator& alloc){ *this = alloc; }; //стандартные

		template <typename U>
		allocator(const allocator<U>& alloc){ *this = alloc; }; //стандартные
		// конструкторы с cpp reference
		//______________________________________________________________
		~allocator() {}; // стандартный деструктор с срр reference
		//______________________________________________________________
		T* allocate(size_t n) const {
			return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
		}; // Функция принимает колличество штук объектов

		void deallocate(T *ptr, size_t){
			return ::operator delete(ptr);
		}; // Ф-ция уничтожает выделенное

		template<typename ...Args>
		void construct(T *ptr, Args&... args){
			new(ptr) T(args...);
		}; // Запуск конструкторов с переменным количеством аргументов

		void destroy(T& ptr){
			ptr->~T();}
		 // Запуск деконструкторов
		//______________________________________________________________
		pointer			address( reference ref ) const {return (&ref);};
		const_pointer	address( const_reference ref ) const {return &ref;};
		// Функции возвращающие адрес объекта в параметрах аллиасы
		// прописанные в мембер переменных
		//______________________________________________________________
		size_type		max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}
		// Экспериментальная реализация max_size

	};
	template <class T, class U>
	bool operator==(const allocator<T>&, const allocator<U>&) { return true; }
	template <class T, class U>
	bool operator!=(const allocator<T>&, const allocator<U>&) { return false; }
}

