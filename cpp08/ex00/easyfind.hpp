#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <stdexcept>
# include <iostream>
# include <iomanip>

#define END	"\033[0m"
#define RED	"\033[1;31m"

// easyfind foncteur ---------------------------------------------------------------------------------------------------


template< typename T >
class EasyFind {

public :

	class EasyFindException : public std::exception {

		const char * 	_message;

	public:

		EasyFindException( const char *message) : _message(message) {}
		const char *	what() const throw() {
			return this->_message;
		}
	};

	typename T::iterator operator()( T & container, int i ) {

		if (container.empty())
		throw EasyFindException("Exception thrown: Empty container");

		typename T::iterator it;

		for (it = container.begin(); it != container.end(); ++it)
		{
			if (*it == i)
				return it;
		}
		throw EasyFindException("Exception thrown: No occurrences");
	}
};

// Prints all elements in the containers ( for testing ) ---------------------------------------------------------------

template< typename T >
class PrintElements {

public :

	void operator()( T & container ) const {

		if ( container.empty())
		{
			std::cout << " ( empty )" << std::endl;
			return;
		}
		for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};

// Prints the result of easy_find ( for testing ) ----------------------------------------------------------------------

template< typename T >
class PrintEasyFindResult {

public :

	void operator()( T & container, int i, typename T::iterator & it ) const {

		EasyFind< T > easy_find;

		std::string title = "easy_find( v, " + std::to_string(i) + " )";

		std::cout << std::left << std::setw(20) << title << ": ";

		try
		{
			it = easy_find(container, i);
			std::cout << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << END << std::endl;

		}
	}
};

// Template for testing sequence containers ----------------------------------------------------------------------------

template< typename T >
class TestSequenceContainer {

public :

	void operator()( T & c, size_t size ) const {

			// Add some values -----------------------------------------------
			for ( size_t i = 0; i < size; i++)
				c.push_back(rand() % 10);

			// Print values of the container -----------------------------------

			PrintElements< T > print_elements;
			print_elements(c);


			// Print easy_find result using a template -------------------------

			PrintEasyFindResult< T > print_easy_res;

			typename T::iterator it;

			print_easy_res(c, 5, it);
			print_easy_res(c, 9, it);
			print_easy_res(c, 4, it);
			print_easy_res(c, 8, it);
			print_easy_res(c, 3, it);
			print_easy_res(c, 1, it);
			print_easy_res(c, 0, it);
	}
};

template< typename T >
class TestEmptyContainer {

public :

	void operator()( T & c ) const {

		// Print values of the container -----------------------------------

		PrintElements< T > print_elements;
		print_elements(c);

		// Print easy_find result using a template -------------------------

		PrintEasyFindResult< T > print_easy_res;

		typename T::iterator it;

		print_easy_res(c, 5, it);
		print_easy_res(c, 9, it);
		print_easy_res(c, 4, it);
		print_easy_res(c, 8, it);
		print_easy_res(c, 3, it);
		print_easy_res(c, 1, it);
		print_easy_res(c, 0, it);
	}
};

#endif