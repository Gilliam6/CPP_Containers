#include <vector>
#include "vector.hpp"
#include <algorithm>

int main()
{
	try
	{
		std::cout << std::endl;
		std::cout << "----------DEFAULT CONSTRUCTOR | SIZE() | CAPACITY() "
					 "CHECK----------" <<
		std::endl;
		std::cout << std::endl;

		std::cout << "INT vector: " << std::endl;
		std::vector<int> std_vector;
		ft::vector<int> ft_vector;
		size_t std_size = std_vector.size();
		size_t ft_size = ft_vector.size();
		size_t std_capacity = std_vector.capacity();
		size_t ft_capacity = ft_vector.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "STRING vector: " << std::endl;
		std::vector<std::string> std_vector1;
		ft::vector<std::string> ft_vector1;
		std_size = std_vector1.size();
		ft_size = ft_vector1.size();
		std_capacity = std_vector1.capacity();
		ft_capacity = ft_vector1.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "----------PARAMETER CONSTRUCTOR CHECK----------" <<
		std::endl;
		std::cout << std::endl;

		std::cout << "INT vector: " << std::endl;
		std::vector<int> std_vector2(5, 3);
		ft::vector<int> ft_vector2(5, 3);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&(*std_vector2
		.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "STRING vector: " << std::endl;
		std::vector<std::string> std_vector3(5, "bla");
		ft::vector<std::string> ft_vector3(5, "bla");
		std_size = std_vector3.size();
		ft_size = ft_vector3.size();
		std_capacity = std_vector3.capacity();
		ft_capacity = ft_vector3.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector3.size(); ++i)
			std::cout << std_vector3[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector3.size(); ++i)
			std::cout << ft_vector3[i] << " ";
		if (std_vector3.size() == ft_vector3.size() && std::equal(&(*std_vector3
				.begin()), &(*std_vector3.end()), &(*ft_vector3.begin())))
			std::cout << "					OK =)"<< std::endl;
		else
			std::cout << "					NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "INT with no value: " << std::endl;
		std::vector<int> std_vector4(5);
		ft::vector<int> ft_vector4(5);
		std_size = std_vector4.size();
		ft_size = ft_vector4.size();
		std_capacity = std_vector4.capacity();
		ft_capacity = ft_vector4.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector4.size(); ++i)
			std::cout << std_vector4[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector4.size(); ++i)
			std::cout << ft_vector4[i] << " ";
		if (std_vector4.size() == ft_vector4.size() && std::equal(&(*std_vector4
				.begin()), &(*std_vector4.end()), &(*ft_vector4.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "insert str into int vector :" << std::endl;
		std::string str("blabla");
		std_vector2.insert(std_vector2.begin(), str.begin(), str.end());
		ft_vector2.insert(ft_vector2.begin(), str.begin(), str.end());
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&(*std_vector2
				.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "insert long into short vector :" << std::endl;
		std::vector<short> std_short(5, 6);
		ft::vector<short> ft_short(5, 6);
		std::vector<long long> std_long(3, 99999999999);
		ft::vector<long long> ft_long(3, 99999999999);
		std_short.insert(std_short.begin() + 1, std_long.begin(),
						   std_long.end());
		ft_short.insert(ft_short.begin() + 1, ft_long.begin(), ft_long
				.end());
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_short.size(); ++i)
			std::cout << std_short[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_short.size(); ++i)
			std::cout << ft_short[i] << " ";
		if (std_short.size() == ft_short.size() && std::equal(&(*std_short
				.begin()), &(*std_short.end()), &(*ft_short.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

//		std::cout << "Const iterators check :" << std::endl;
//		std::vector<int>::const_iterator std_it = std_vector2.begin();
//		size_t std_it1 = *std_vector2.begin();
//		ft::vector<int>::const_iterator ft_it = ft_vector2.begin();
//		size_t ft_it1 = *ft_vector2.begin();
//		*std_it = 40;
//		*ft_it = 40;
//		std::cout << "std_it = " << *std_it << "	std_it1 = " << std_it1;
//		std::cout << "	ft_it = " << *ft_it << "	ft_it1 = " << ft_it1;
//		if (*ft_it == ft_it1)
//			std::cout << "						OK =)"<< std::endl;
//		else
//			std::cout << "						NOK!"<< std::endl;

//		std::cout << "Negative parameter with no value: " << std::endl;
//		ft::vector<int> ft_vector5(-5);

		std::cout << "----------RANGE CONSTRUCTOR CHECK----------" << std::endl;
		std::cout << std::endl;
		std::vector<int> std_vector6(5, 5);
		ft::vector<int> ft_vector6(&(*std_vector6.begin()), &(*std_vector6.end
		()));
		std_size = std_vector6.size();
		ft_size = ft_vector6.size();
		std_capacity = std_vector6.capacity();
		ft_capacity = ft_vector6.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector6.size(); ++i)
			std::cout << std_vector6[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector6.size(); ++i)
			std::cout << ft_vector6[i] << " ";
		if (std_vector6.size() == ft_vector6.size() && std::equal(&(*std_vector6
				.begin()), &(*std_vector6.end()), &(*ft_vector6.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------COPY CONSTRUCTOR CHECK----------" << std::endl;
		std::cout << std::endl;
		std::vector<int> std_vector7(std_vector4);
		ft::vector<int> ft_vector7(ft_vector4);
		std_size = std_vector7.size();
		ft_size = ft_vector7.size();
		std_capacity = std_vector7.capacity();
		ft_capacity = ft_vector7.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector7.size(); ++i)
			std::cout << std_vector7[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector7.size(); ++i)
			std::cout << ft_vector7[i] << " ";
		if (std_vector7.size() == ft_vector7.size() && std::equal(&(*std_vector7
				.begin()), &(*std_vector7.end()), &(*ft_vector7.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------OPERATOR= CHECK----------" << std::endl;
		std::cout << std::endl;
		std::vector<int> std_vector8 = std_vector4;
		ft::vector<int> ft_vector8 = ft_vector4;
		std_size = std_vector8.size();
		ft_size = ft_vector8.size();
		std_capacity = std_vector8.capacity();
		ft_capacity = ft_vector8.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector8.size(); ++i)
			std::cout << std_vector8[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector8.size(); ++i)
			std::cout << ft_vector8[i] << " ";
		if (std_vector8.size() == ft_vector8.size() && std::equal(&(*std_vector8
				.begin()), &(*std_vector8.end()), &(*ft_vector8.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------BEGIN() | END | RBEGIN() | REND() | MAX_SIZE()"
					 " | PUSH_BACK() | POP_BACK CHECK-----------"
		<< std::endl;
		std::cout << std::endl;
		std::vector<int> std_vector9;
		std_vector9.push_back(1);
		std_vector9.push_back(2);
		std_vector9.push_back(3);
		std_vector9.push_back(4);
		std_vector9.push_back(5);
		std_vector9.pop_back();
		ft::vector<int> ft_vector9;
		ft_vector9.push_back(1);
		ft_vector9.push_back(2);
		ft_vector9.push_back(3);
		ft_vector9.push_back(4);
		ft_vector9.push_back(5);
		ft_vector9.pop_back();
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << "std_vector.begin() = " << *std_vector9.begin() <<
		"	ft_vector.begin() = " << *ft_vector9.begin();
		if (*std_vector9.begin() == *ft_vector9.begin())
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << "std_vector.end() - 1 = " << *(std_vector9.end() - 1) <<
				  "	ft_vector.end() - 1 = " << *(ft_vector9.end() - 1);
		if (*(std_vector9.end() - 1) == *(ft_vector9.end() - 1))
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;;
		std::cout << "std_vector.rbegin() = " << *std_vector9.rbegin() <<
				  "	ft_vector.rbegin() = " << *ft_vector9.rbegin();
		if (*std_vector9.rbegin() == *ft_vector9.rbegin())
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << "std_vector.rend() - 1 = " << *(std_vector9.rend() - 1) <<
				  "	ft_vector.rend() - 1 = " << *(ft_vector9.rend() - 1);
		if (*(std_vector9.rend() - 1) == *(ft_vector9.rend() - 1))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << "std_vector.max_size() = " << std_vector9.max_size() <<
				  "	ft_vector.max_size() = " << ft_vector9.max_size();
		if (std_vector9.max_size() == ft_vector9.max_size())
			std::cout << "		OK =)"<< std::endl;
		else
			std::cout << "		NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------RESIZE() CHECK----------" << std::endl;
		std::cout << std::endl;
		std::cout << "N = SIZE" << std::endl;
		std_vector9.resize(5);
		ft_vector9.resize(5);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N < SIZE" << std::endl;
		std_vector9.resize(3);
		ft_vector9.resize(3);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N = CAPACITY" << std::endl;
		std_vector9.resize(8);
		ft_vector9.resize(8);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N > CAPACITY && N < 2 * CAPACITY" << std::endl;
		std_vector9.resize(9);
		ft_vector9.resize(9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N > 2 * CAPACITY" << std::endl;
		std_vector9.resize(40);
		ft_vector9.resize(40);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "		OK =)"<< std::endl;
		else
			std::cout << "		NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "RESIZE with parameter" << std::endl;
		std::cout << std::endl;

		std::cout << "N < SIZE" << std::endl;
		std_vector9.resize(5, 9);
		ft_vector9.resize(5, 9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N > CAPACITY && N < 2 * CAPACITY" << std::endl;
		std_vector9.resize(41, 9);
		ft_vector9.resize(41, 9);
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << std::endl;
		std::cout << "ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&(*std_vector9
				.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "		OK =)" << std::endl;
		else
			std::cout << "		NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------EMPTY() CHECK----------" << std::endl;
		std::cout << std::endl;
		std::cout << "std_vector is empty ? - " << std_vector9.empty();
		std::cout << "	ft_vector is empty ? - " << ft_vector9.empty();
		if (std_vector9.empty() == ft_vector9.empty())
			std::cout << "						OK =)" << std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------RESERVE() CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "N < CAPACITY" << std::endl;
		std_vector2.reserve(3);
		ft_vector2.reserve(3);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&(*std_vector2
				.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N > CAPACITY && N < MAX_SIZE " << std::endl;
		std_vector2.reserve(100);
		ft_vector2.reserve(100);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&(*std_vector2
				.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------OPERATOR[] CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "First element: " << std::endl;
		std::cout << "std_vector[0] = " << std_vector9[0];
		std::cout << "	ft_vector[0] = " << ft_vector9[0];
		if (std_vector9[0] == ft_vector9[0])
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Last element: " << std::endl;
		std::cout << "std_vector[size - 1] = " << std_vector9[std_vector9.size
		() - 1];
		std::cout << "	ft_vector[size - 1] = " << ft_vector9[ft_vector9.size
		() - 1];
		if (std_vector9[std_vector9.size() - 1] == ft_vector9[ft_vector9.size
		() - 1])
			std::cout << "							OK =)" << std::endl;
		else
			std::cout << "							NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Inner element: " << std::endl;
		std::cout << "std_vector[n] = " << std_vector9[3];
		std::cout << "	ft_vector[n] = " << ft_vector9[3];
		if (std_vector9[3] == ft_vector9[3])
			std::cout << "								OK =)" << std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Change Inner element: " << std::endl;
		std_vector9[3] = 10;
		ft_vector9[3] = 10;
		std::cout << "std_vector[n] = " << std_vector9[3];
		std::cout << "	ft_vector[n] = " << ft_vector9[3];
		if (std_vector9[3] == ft_vector9[3])
			std::cout << "								OK =)" << std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "-----------AT() | FRONT() | BACK() CHECK----------" <<
		std::endl;
		std::cout << std::endl;

		std::cout << "N = front() element: " << std::endl;
		std::cout << "std_vector.at(std_vector.front()) = " << std_vector9.at(std_vector9.front());
		std::cout << "	ft_vector.at(ft_vector.front()) = " << ft_vector9.at
		(ft_vector9.front());
		if (std_vector9.at(std_vector9.front()) == ft_vector9.at(ft_vector9
		.front()))
			std::cout << "				OK =)"<< std::endl;
		else
			std::cout << "				NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "N = back() element: " << std::endl;
		std::cout << "std_vector.at(std_vector.back()) = " << std_vector9.at
		(std_vector9.back());
		std::cout << "	ft_vector.at(ft_vector.back()) = " << ft_vector9.at
		(ft_vector9.back());
		if (std_vector9.at(std_vector9.back()) == ft_vector9.at(ft_vector9
		.back()))
			std::cout << "				OK =)" << std::endl;
		else
			std::cout << "				NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Inner element: " << std::endl;
		std::cout << "std_vector.at(n) = " << std_vector9.at(3);
		std::cout << "	ft_vector.at(n) = " << ft_vector9.at(3);
		if (std_vector9.at(3) == ft_vector9.at(3))
			std::cout << "								OK =)" << std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Change Inner element: " << std::endl;
		std_vector9.at(3) = 50;
		ft_vector9.at(3) = 50;
		std::cout << "std_vector.at(n) = " << std_vector9.at(3);
		std::cout << "	ft_vector.at(n) = " << ft_vector9.at(3);
		if (std_vector9.at(3) == ft_vector9.at(3))
			std::cout << "								OK =)" << std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;

//		std::cout << "Not valid element: " << std::endl;
//		ft_vector9.at(100);
//		std_vector9.at(100);
//		std::cout << "std_vector.at(n) = " << std_vector9.at(100);
//		std::cout << "	ft_vector.at(n) = " << ft_vector9.at(100);
//		if (std_vector9.at(100) == ft_vector9.at(100))
//			std::cout << "								OK =)" << std::endl;
//		else
//			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------ASSIGN() CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "New vectors : " << std::endl;
		std::vector<int> std_vector10;
		std_vector10.assign(10, 6);
		ft::vector<int> ft_vector10;
		ft_vector10.assign(10, 6);
		std_size = std_vector10.size();
		ft_size = ft_vector10.size();
		std_capacity = std_vector10.capacity();
		ft_capacity = ft_vector10.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector10.size(); ++i)
			std::cout << std_vector10[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector10.size(); ++i)
			std::cout << ft_vector10[i] << " ";
		if (std_vector10.size() == ft_vector10.size() && std::equal(&
		(*std_vector10.begin()), &(*std_vector10.end()), &(*ft_vector10.begin
		())))
			std::cout << "					OK =)"<< std::endl;
		else
			std::cout << "					NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Existed vectors : " << std::endl;
		std_vector2.assign(10, 6);
		ft_vector2.assign(10, 6);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "					OK =)"<< std::endl;
		else
			std::cout << "					NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Assigning using the iterators : " << std::endl;
		std_vector2.assign(std_vector4.begin(), std_vector4.end());
		ft_vector2.assign(ft_vector4.begin(), ft_vector4.end());
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------INSERT(position, val) CHECK----------" <<
		std::endl;
		std::cout << std::endl;

		std::cout << "Insert position = 1 element : " << std::endl;
		std_vector2.insert(std_vector2.begin(), 7);
		ft_vector2.insert(ft_vector2.begin(), 7);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = some inner element : " << std::endl;
		std_vector2.insert(std_vector2.begin() + 5, 7);
		ft_vector2.insert(ft_vector2.begin() + 5, 7);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = last element : " << std::endl;
		std_vector2.insert(std_vector2.end(), 7);
		ft_vector2.insert(ft_vector2.end(), 7);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when size = capacity : " << std::endl;
		std_vector2.assign(100, 1);
		std_vector2.insert(std_vector2.end() - 50, 50);
		ft_vector2.assign(100, 1);
		ft_vector2.insert(ft_vector2.end() - 50, 50);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "If std_vector and ft_vector are equal ?  ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when *vector = nullptr: " << std::endl;
		std::vector<int> std_vector11;
		ft::vector<int> ft_vector11;
		std_vector11.insert(std_vector11.begin(), 50);
		ft_vector11.insert(ft_vector11.begin(), 50);
		std_size = std_vector11.size();
		ft_size = ft_vector11.size();
		std_capacity = std_vector11.capacity();
		ft_capacity = ft_vector11.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector11.size(); ++i)
			std::cout << std_vector11[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector11.size(); ++i)
			std::cout << ft_vector11[i] << " ";
		if (std_vector11.size() == ft_vector11.size() && std::equal(&
		(*std_vector11.begin()), &(*std_vector11.end()), &(*ft_vector11.begin())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;

//		std::cout << "Insert when position is bad : " << std::endl;
//		ft_vector11.insert(ft_vector11.begin() - 1, 50);
		std::cout << std::endl;

		std::cout << "----------INSERT(position, n, val) CHECK----------" <<
		std::endl;
		std::cout << std::endl;

		std::cout << "Insert position = 1 element : " << std::endl;
		std_vector2.resize(5);
		ft_vector2.resize(5);
		std_vector2.insert(std_vector2.begin(), 3, 5);
		ft_vector2.insert(ft_vector2.begin(), 3, 5);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = some inner element : " << std::endl;
		std_vector2.insert(std_vector2.begin() + 5, 3, 5);
		ft_vector2.insert(ft_vector2.begin() + 5, 3, 5);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "				OK =)"<< std::endl;
		else
			std::cout << "				NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = last element : " << std::endl;
		std_vector2.insert(std_vector2.end(), 3, 5);
		ft_vector2.insert(ft_vector2.end(), 3, 5);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "			OK =)"<< std::endl;
		else
			std::cout << "			NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when size = capacity : " << std::endl;
		std_vector2.assign(std_vector2.capacity(), 1);
		std_vector2.insert(std_vector2.end() - 50, 3, 50);
		ft_vector2.assign(ft_vector2.capacity(), 1);
		ft_vector2.insert(ft_vector2.end() - 50, 3, 50);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "If std_vector and ft_vector are equal ?  ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when *vector = nullptr: " << std::endl;
		std::vector<int> std_vector12;
		ft::vector<int> ft_vector12;
		std_vector12.insert(std_vector12.begin(), 3,50);
		ft_vector12.insert(ft_vector12.begin(), 3, 50);
		std_size = std_vector12.size();
		ft_size = ft_vector12.size();
		std_capacity = std_vector12.capacity();
		ft_capacity = ft_vector12.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector12.size(); ++i)
			std::cout << std_vector12[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector12.size(); ++i)
			std::cout << ft_vector12[i] << " ";
		if (std_vector12.size() == ft_vector12.size() && std::equal(&
		(*std_vector12.begin()), &(*std_vector12.end()), &(*ft_vector12.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "Test check : " << std::endl;
		std_vector2.assign(1000,1);
		ft_vector2.assign(1000,1);
		std_vector2.insert(std_vector2.end() - 50, 4200 * 10000, 2);
		ft_vector2.insert(ft_vector2.end() - 50, 4200 * 10000, 2);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "If std_vector and ft_vector are equal ?  ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

//		std::cout << "Insert when position is bad : " << std::endl;
//		ft_vector12.insert(ft_vector12.begin() - 1, 3, 50);
		std::cout << std::endl;

		std::cout << "----------INSERT(position, Iterator1, Iterator2) "
					 "CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "Insert position = 1 element : " << std::endl;
		std_vector2.resize(5);
		ft_vector2.resize(5);
		std::vector<int> test;
		test.assign(3,9);
		std::vector<int>::iterator begin;
		std::vector<int>::iterator end;
		begin = test.begin();
		end = test.end();
		std_vector2.insert(std_vector2.begin(), begin, end);
		ft_vector2.insert(ft_vector2.begin(), begin, end);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = some inner element : " << std::endl;
		std_vector2.insert(std_vector2.begin() + 5, begin, end);
		ft_vector2.insert(ft_vector2.begin() + 5, begin, end);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "				OK =)"<< std::endl;
		else
			std::cout << "				NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert position = last element : " << std::endl;
		std_vector2.insert(std_vector2.end(), begin, end);
		ft_vector2.insert(ft_vector2.end(), begin, end);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "			OK =)"<< std::endl;
		else
			std::cout << "			NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when size = capacity : " << std::endl;
		std_vector2.assign(std_vector2.capacity(), 1);
		std_vector2.insert(std_vector2.end() - 50, begin, end);
		ft_vector2.assign(ft_vector2.capacity(), 1);
		ft_vector2.insert(ft_vector2.end() - 50, begin, end);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "If std_vector and ft_vector are equal ?  ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Insert when *vector = nullptr: " << std::endl;
		std::vector<int> std_vector13;
		ft::vector<int> ft_vector13;
		std_vector13.insert(std_vector13.begin(), begin, end);
		ft_vector13.insert(ft_vector13.begin(), begin, end);
		std_size = std_vector13.size();
		ft_size = ft_vector13.size();
		std_capacity = std_vector13.capacity();
		ft_capacity = ft_vector13.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector13.size(); ++i)
			std::cout << std_vector13[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector13.size(); ++i)
			std::cout << ft_vector13[i] << " ";
		if (std_vector13.size() == ft_vector13.size() && std::equal(&
		(*std_vector13.begin()), &(*std_vector13.end()), &(*ft_vector13.begin())))
			std::cout << "								OK =)"
					  << std::endl;
		else
			std::cout << "								NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "Test check : " << std::endl;
		std_vector.assign(2600 * 10000, 1);
		std_vector2.assign(4200 * 10000, 1);
		ft_vector.assign(2600 * 10000, 1);
		ft_vector2.assign(4200 * 10000, 1);
		std_vector2.insert(std_vector2.end() - 1000 * 10000, std_vector
		.begin(), std_vector.end());
		ft_vector2.insert(ft_vector2.end() - 1000 * 10000, ft_vector.begin(), ft_vector.end());
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "If std_vector and ft_vector are equal ?  ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(std_vector2.begin(), std_vector2.end(), ft_vector2.begin()))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

//		std::cout << "Insert when position is bad : " << std::endl;
//		ft_vector13.insert(ft_vector13.begin() - 1, begin, end);
		std::cout << std::endl;

		std::cout << "----------ERASE(position) CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "First element :" << std::endl;
		std_vector2.resize(10);
		ft_vector2.resize(10);
		std_vector2.erase(std_vector2.begin());
		ft_vector2.erase(ft_vector2.begin());
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Last element : " << std::endl;
		std_vector2.erase(std_vector2.end() - 1);
		ft_vector2.erase(ft_vector2.end() - 1);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Some inner element : " << std::endl;
		std_vector2.erase(std_vector2.end() - 3);
		ft_vector2.erase(ft_vector2.end() - 3);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;
		std::cout << std::endl;

		std::cout << "Empty vector : " << std::endl;
		std_vector2.resize(0);
		ft_vector2.resize(0);
//		std_vector2.erase(std_vector2.begin());
		ft_vector2.erase(ft_vector2.begin());
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;
		std::cout << std::endl;

//		std::cout << "Not valid position: " << std::endl;
//		ft_vector2.assign(5, 5);
//		std_vector2.assign(5, 5);
//		ft_vector2.erase(ft_vector2.begin() - 1);

		std::cout << "----------ERASE(Iterator1, Iterator2) CHECK----------"
		<< std::endl;
		std::cout << std::endl;

		std::cout << "First 3 element :" << std::endl;
		std_vector2.assign(10, 5);
		ft_vector2.assign(10, 5);
		std_vector2.erase(std_vector2.begin(), std_vector2.begin() + 3);
		ft_vector2.erase(ft_vector2.begin(), ft_vector2.begin() + 3);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "Last 3 element : " << std::endl;
		std_vector2.erase( std_vector2.end() - 4, std_vector2.end() - 1);
		ft_vector2.erase(ft_vector2.end() - 4, ft_vector2.end() - 1);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
		(*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "3 inner element : " << std::endl;
		std_vector2.assign(10, 5);
		ft_vector2.assign(10, 5);
		std_vector2.erase( std_vector2.end() - 5, std_vector2.end() - 2);
		ft_vector2.erase( ft_vector2.end() - 5, ft_vector2.end() - 2);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "						OK =)"<< std::endl;
		else
			std::cout << "						NOK!"<< std::endl;;
		std::cout << std::endl;

//		std::cout << "Empty vector : " << std::endl;
//		std_vector2.resize(0);
//		ft_vector2.resize(0);
////		std_vector2.erase(std_vector2.begin());
//		ft_vector2.erase(ft_vector2.begin(), ft_vector2.end() - 1);
//		std_size = std_vector2.size();
//		ft_size = ft_vector2.size();
//		std_capacity = std_vector2.capacity();
//		ft_capacity = ft_vector2.capacity();
//		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
//		if (std_size == ft_size)
//			std::cout << "										OK =)" << std::endl;
//		else
//			std::cout << "										NOK!" << std::endl;
//		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
//				  ft_capacity;
//		if (std_capacity == ft_capacity)
//			std::cout << "									OK =)" << std::endl;
//		else
//			std::cout << "									NOK!" << std::endl;
//		std::cout << "std_vector: ";
//		for (size_t i = 0; i < std_vector2.size(); ++i)
//			std::cout << std_vector2[i] << " ";
//		std::cout << "	ft_vector: ";
//		for (size_t i = 0; i < ft_vector2.size(); ++i)
//			std::cout << ft_vector2[i] << " ";
//		if (std_vector2.size() == ft_vector2.size() && std::equal(&
//																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
//			std::cout << "										OK =)" << std::endl;
//		else
//			std::cout << "										NOK!"<< std::endl;;
//		std::cout << std::endl;

//		std::cout << "Not valid position: " << std::endl;
//		ft_vector2.assign(5, 5);
//		std_vector2.assign(5, 5);
//		ft_vector2.erase(ft_vector2.begin() - 1, ft_vector2.begin());

		std::cout << "----------SWAP() CHECK----------" << std::endl;
		std_vector2.swap(std_vector13);
		ft_vector2.swap(ft_vector13);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;

		std_vector9.assign(10, 0);
		ft_vector9.assign(10, 0);
		std_vector2.swap(std_vector9);
		ft_vector2.swap(ft_vector9);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "					OK =)"<< std::endl;
		else
			std::cout << "					NOK!"<< std::endl;;

		std_vector2.swap(std_vector4);
		ft_vector2.swap(ft_vector4);
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "								OK =)"<< std::endl;
		else
			std::cout << "								NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------CLEAR() CHECK----------" << std::endl;
		std_vector2.clear();
		ft_vector2.clear();
		std_size = std_vector2.size();
		ft_size = ft_vector2.size();
		std_capacity = std_vector2.capacity();
		ft_capacity = ft_vector2.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector2.size(); ++i)
			std::cout << std_vector2[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector2.size(); ++i)
			std::cout << ft_vector2[i] << " ";
		if (std_vector2.size() == ft_vector2.size() && std::equal(&
																		  (*std_vector2.begin()), &(*std_vector2.end()), &(*ft_vector2.begin())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;

		std_vector9.clear();
		ft_vector9.clear();
		std_size = std_vector9.size();
		ft_size = ft_vector9.size();
		std_capacity = std_vector9.capacity();
		ft_capacity = ft_vector9.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector9.size(); ++i)
			std::cout << std_vector9[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector9.size(); ++i)
			std::cout << ft_vector9[i] << " ";
		if (std_vector9.size() == ft_vector9.size() && std::equal(&
		(*std_vector9.begin()), &(*std_vector9.end()), &(*ft_vector9.begin())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;

		std_vector4.clear();
		ft_vector4.clear();
		std_size = std_vector4.size();
		ft_size = ft_vector4.size();
		std_capacity = std_vector4.capacity();
		ft_capacity = ft_vector4.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "									OK =)"<< std::endl;
		else
			std::cout << "									NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector4.size(); ++i)
			std::cout << std_vector4[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector4.size(); ++i)
			std::cout << ft_vector4[i] << " ";
		if (std_vector4.size() == ft_vector4.size() && std::equal(&
		(*std_vector4.begin()), &(*std_vector4.end()), &(*ft_vector4.begin())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;

		std_vector13.clear();
		ft_vector13.clear();
		std_size = std_vector13.size();
		ft_size = ft_vector13.size();
		std_capacity = std_vector13.capacity();
		ft_capacity = ft_vector13.capacity();
		std::cout << "std_size = " << std_size << "   ft_size = " << ft_size;
		if (std_size == ft_size)
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;
		std::cout << "std_capacity = " << std_capacity << "   ft_capacity = " <<
				  ft_capacity;
		if (std_capacity == ft_capacity)
			std::cout << "							OK =)"<< std::endl;
		else
			std::cout << "							NOK!"<< std::endl;
		std::cout << "std_vector: ";
		for (size_t i = 0; i < std_vector13.size(); ++i)
			std::cout << std_vector13[i] << " ";
		std::cout << "	ft_vector: ";
		for (size_t i = 0; i < ft_vector13.size(); ++i)
			std::cout << ft_vector13[i] << " ";
		if (std_vector13.size() == ft_vector13.size() && std::equal(&
		(*std_vector13.begin()), &(*std_vector13.end()), &(*ft_vector13.begin
		())))
			std::cout << "										OK =)"<< std::endl;
		else
			std::cout << "										NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "----------BOOL OPERATORS CHECK----------" << std::endl;
		std::cout << std::endl;

		std::cout << "STD and FT vectors are equal :" << std::endl;
		std_vector2.assign(10, 5);
		std_vector4.assign(10, 5);
		ft_vector2.assign(10, 5);
		ft_vector4.assign(10, 5);
		std::cout << "Operator== ";
		if (std_vector2 == std_vector4 && ft_vector2 == ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator!= ";
		if (!(std_vector2 != std_vector4) && !(ft_vector2 != ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator< ";
		if (!(std_vector2 < std_vector4) && !(ft_vector2 < ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator<= ";
		if (std_vector2 <= std_vector4 && ft_vector2 <= ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator> ";
		if (!(std_vector2 > std_vector4) && !(ft_vector2 > ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator>= ";
		if (std_vector2 >= std_vector4 && ft_vector2 >= ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "STD and FT vectors are NOT equal :" << std::endl;
		std_vector2.assign(10, 5);
		std_vector4.assign(5, 3);
		ft_vector2.assign(10, 5);
		ft_vector4.assign(5, 3);
		std::cout << "Operator== ";
		if (!(std_vector2 == std_vector4) && !(ft_vector2 == ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator!= ";
		if (std_vector2 != std_vector4 && ft_vector2 != ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator< ";
		if (!(std_vector2 < std_vector4) && !(ft_vector2 < ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator<= ";
		if (!(std_vector2 <= std_vector4) && !(ft_vector2 <= ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator> ";
		if (std_vector2 > std_vector4 && ft_vector2 > ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator>= ";
		if (std_vector2 >= std_vector4 && ft_vector2 >= ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << std::endl;

		std::cout << "STD and FT vectors are NOT equal by val, but equal by "
					 "size:"	<< std::endl;
		std_vector2.assign(10, 5);
		std_vector4.assign(10, 3);
		ft_vector2.assign(10, 5);
		ft_vector4.assign(10, 3);
		std::cout << "Operator== ";
		if (!(std_vector2 == std_vector4) && !(ft_vector2 == ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator!= ";
		if (std_vector2 != std_vector4 && ft_vector2 != ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator< ";
		if (!(std_vector2 < std_vector4) && !(ft_vector2 < ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator<= ";
		if (!(std_vector2 <= std_vector4) && !(ft_vector2 <= ft_vector4))
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator> ";
		if (std_vector2 > std_vector4 && ft_vector2 > ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;
		std::cout << "Operator>= ";
		if (std_vector2 >= std_vector4 && ft_vector2 >= ft_vector4)
			std::cout << "												OK =)"<< std::endl;
		else
			std::cout << "												NOK!"<< std::endl;;

	}
	catch (std::exception &x)
	{
		std::cerr << "Error: " << x.what() << std::endl;
	}
	return (0);
}