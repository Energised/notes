#include <iostream>

#include <functional>
#include <algorithm>
#include <iterator>

#include <vector>
#include <list>

#include "my_algorithms.h"

int main(int argc, char* argv[]) {
	
	// For each
	{
		auto print_func = [](const int &value) {
			std::cout << value << " ";
		};

		std::vector<int> vec = { 0, 1, 2, 3, 4 };

		std::cout << "std::for_each" << std::endl;
		std::for_each(vec.begin(), vec.end(), print_func);

		std::cout << std::endl;


		std::cout << "my_for_each" << std::endl;
		my_for_each(vec.begin(), vec.end(), print_func);

		std::cout << std::endl;

		std::cout << "std::for_each_n" << std::endl;
		std::for_each_n(vec.begin(), 2, print_func);

		std::cout << std::endl;


		std::cout << "my_for_each_n" << std::endl;
		my_for_each_n(vec.begin(), 2, print_func);

		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Equality
	{
		auto abs_eq = [](const int &a, const int &b) {
			return std::abs(a) == std::abs(b);
		};

		std::vector<int> vec = { 0, 1,  2, 3, 4 };
		std::list<int>   lst = { 0, 1, -2, 3, 4 };

		std::cout << "std::equal" << std::endl;
		if ( std::equal(vec.begin(), vec.end(), lst.begin()) ) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl; // *
		}

		std::cout << "my_equal" << std::endl;
		if ( my_equal(vec.begin(), vec.end(), lst.begin()) ) {
			std::cout << "True" << std::endl;
		}
		else {
			std::cout << "False" << std::endl; // *
		}

		std::cout << "std::equal (abs)" << std::endl;
		if ( std::equal(vec.begin(), vec.end(), lst.begin(), abs_eq) ) {
			std::cout << "True" << std::endl; // *
		}
		else {
			std::cout << "False" << std::endl;
		}


		std::cout << "my_equal (abs)" << std::endl;
		if ( my_equal(vec.begin(), vec.end(), lst.begin(), abs_eq) ) {
			std::cout << "True" << std::endl; // *
		}
		else {
			std::cout << "False" << std::endl;
		}
	}
	std::cout << std::endl;

	// Find
	{
		auto is_odd = [](const int &value) {
			return (value % 2) != 0;
		};

		std::vector<int> vec = { 0, 1, 2, 3, 4 };

		std::cout << "std::find" << std::endl;

		auto it0 = std::find(vec.begin(), vec.end(), 3);
		if ( it0 != vec.end() ) {
			std::cout << "Found at index " << std::distance(vec.begin(), it0) << std::endl;
		}

		std::cout << "my_find" << std::endl;

		auto it1 = my_find(vec.begin(), vec.end(), 3);
		if (it1 != vec.end()) {
			std::cout << "Found at index " << std::distance(vec.begin(), it1) << std::endl;
		}

		std::cout << "std::find_if (is_odd)" << std::endl;
		
		auto it2 = std::find_if(vec.begin(), vec.end(), is_odd);
		if ( it2 != vec.end() ) {
			std::cout << "Found at index " << std::distance(vec.begin(), it2) << std::endl;
		}

		std::cout << "my_find_if (is_odd)" << std::endl;

		auto it3 = my_find_if(vec.begin(), vec.end(), is_odd);
		if (it3 != vec.end()) {
			std::cout << "Found at index " << std::distance(vec.begin(), it3) << std::endl;
		}
	}
	std::cout << std::endl;

	// Copy
	{
		auto is_odd = [](const int &value) {
			return (value % 2) != 0;
		};

		auto print_func = [](const int &value) {
			std::cout << value << " ";
		};

		std::vector<int> vec = { 0, 1, 2, 3, 4 };

		{
			std::cout << "std::copy" << std::endl;

			std::list<int> lst( vec.size() ); // Construct a linked list with 5 nodes

			std::copy(vec.begin(), vec.end(), lst.begin());
			
			std::for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "my_copy" << std::endl;

			std::list<int> lst( vec.size() ); // Construct a linked list with 5 nodes

			my_copy(vec.begin(), vec.end(), lst.begin());
			
			my_for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "std::copy_if (is_odd)" << std::endl;

			std::list<int> lst( vec.size() ); // Construct a linked list with 5 nodes

			std::copy_if(vec.begin(), vec.end(), lst.begin(), is_odd); // Only copies into the first 2 nodes!
			
			std::for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "my_copy_if (is_odd)" << std::endl;

			std::list<int> lst( vec.size() ); // Construct a linked list with 5 nodes

			my_copy_if(vec.begin(), vec.end(), lst.begin(), is_odd); // Only copies into the first 2 nodes!
			
			my_for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	// Copy with push_back iterator
	{
		auto is_odd = [](const int &value) {
			return (value % 2) != 0;
		};

		auto print_func = [](const int &value) {
			std::cout << value << " ";
		};

		std::vector<int> vec = { 0, 1, 2, 3, 4 };

		{
			std::cout << "std::copy" << std::endl;

			std::list<int> lst; // Construct an empty linked list

			std::copy(vec.begin(), vec.end(), std::back_inserter(lst));
			
			std::for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "my_copy" << std::endl;

			std::list<int> lst; // Construct an empty linked list

			my_copy(vec.begin(), vec.end(), my_push_back_iterator(lst));
			
			my_for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "std::copy_if (is_odd)" << std::endl;

			std::list<int> lst; // Construct an empty linked list

			std::copy_if(vec.begin(), vec.end(), std::back_inserter(lst), is_odd);
			
			std::for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
		{
			std::cout << "my_copy_if (is_odd)" << std::endl;

			std::list<int> lst; // Construct an empty linked list

			my_copy_if(vec.begin(), vec.end(), my_push_back_iterator(lst), is_odd);
			
			my_for_each(lst.begin(), lst.end(), print_func);
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	
	std::cin.get();
	return 0;
}