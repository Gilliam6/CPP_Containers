#pragma once
#include <iostream>

namespace ft
{
	template<typename T>
	class allocator
	{
	public:

		T				value_type;
		T*				value;
		T&				reference;
		const T*		const_pointer;
		const T&		const_reference;
		size_t			size_type;
		difference_type	ptrdiff_t;
//		мембер переменные стандартного аллокатора для переименовывания
		//______________________________________________________________
		allocator() throw();
		allocator (const allocator& alloc) throw();
		template <class T>
		allocator (const allocator<T>& alloc) throw(); //стандартные
		// конструкторы с cpp reference
		//______________________________________________________________
		~allocator ( ) throw; // стандартный деструктор с срр reference
		//______________________________________________________________
		T* allocate(size_t n) const {
			return ::operator new(n * sizeof(T));
		}; // Функция принимает колличество штук объектов

		void deallocate(T *ptr){
			return ::operator delete(ptr);
		}; // Ф-ция уничтожает выделенное

		template<typename ...Args>
		void construct(T *ptr, Args&... args){
			new(ptr) T(args...);
		}; // Запуск конструкторов с переменным количеством аргументов

		void destroy(T* ptr){
			ptr->~T();
		}; // Запуск деконструкторов
		//______________________________________________________________
		pointer			address( reference ref ) const {return (&ref);};
		const_pointer	address( const_reference ref ) const {return &ref;};
		// Функции возвращающие адрес объекта в параметрах аллиасы
		// прописанные в мембер переменных
		//______________________________________________________________
		size_type		max_size() const {
			return (pow(2, sizeof(void *) * 8)/ size_of(T) - 1);
		}
		// Экспериментальная реализация max_size
	};
}

