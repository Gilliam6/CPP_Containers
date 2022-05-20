#pragma once
#include <iostream>

namespace ft
{
	template<typename T>
	class allocator
	{
	public:
		T* allocate(size_t n) const {
			return ::operator new(n * sizeof(T));
		}; // Функция принимает колличество штук объектов

		void deallocate(T *ptr){
			return ::operator delete(ptr);
		}; // Ф-ция уничтожает выделенное

		template<typename ...Args>
		void construct(T *ptr, Args&... args){
			new(ptr) T(args...);
		}

		void destroy(T* ptr){
			ptr->~T();
		}
	};
}

