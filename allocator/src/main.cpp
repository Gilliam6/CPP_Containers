#include "allocator.hpp"
#include <vector>

int main()
{
	std::vector<int> std_vector(10, 5);
	std::vector<int, ft::allocator<int>> my_vector(10, 5);
//	std::vector<int, ft::allocator<int>()> my_vector(10);
//---------------------------------------------------SIZE & CAP CHECK
	std::cout << std_vector.size() << " size | " << std_vector.capacity()
	<<" capacity\n";
	std::cout << my_vector.size() <<  " size | " << my_vector.capacity() << " capacity\n";
//-------------------------------------------------------------------
// MAX SIZE CHECK
	std::cout << std_vector.get_allocator().max_size()<< "\n";
	std::cout << my_vector.get_allocator().max_size()<< "\n";
//-------------------------------------------------------------------
// get_allocator and address check
	std::cout << std_vector.get_allocator().address(std_vector.at(0)) << "\n";
	std::cout << my_vector.get_allocator().address(std_vector.at(0))<<"\n";
//-------------------------------------------------------------------
// Another type check
	std::vector<char> charVector(200, 'a');
	std::vector<char, ft::allocator<char>> myCharVector(200, 'a');
//	---------------------------------------------------SIZE & CAP CHECK
	std::cout << charVector.size() << charVector.capacity()<<"\n";
	std::cout << myCharVector.size() << myCharVector.capacity()<<"\n";

	return (0);
}