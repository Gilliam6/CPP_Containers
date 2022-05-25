#include "allocator.hpp"
#include <vector>

int main()
{
	std::vector<int>(10) std_vector;
	std::vector<int, Alloc<T> = ft::allocator()>(10) my_vector;

	return (0);
}