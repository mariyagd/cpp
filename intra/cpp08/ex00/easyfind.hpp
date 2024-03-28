#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <stdexcept>
# include <iostream>
# include <iomanip>

#define END	"\033[0m"
#define RED	"\033[1;31m"

// easyfind foncteur ---------------------------------------------------------------------------------------------------

template< typename T >
int	easyfind( T & container, int i ) {

	if (container.empty())
		throw std::runtime_error("Exception thrown: Empty container");

	typename T::iterator it;

	for (it = container.begin(); it != container.end(); ++it)
	{
		if (*it == i)
		{
			std::cout << "found " << *it << std::endl;
			return *it;
		}
	}
	throw std::runtime_error("Exception thrown: No occurrences");
}

#endif