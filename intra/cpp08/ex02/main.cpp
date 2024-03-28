#include "MutantStack.hpp"




void	print_small_line( void ) {

	std::cout << BLUE << std::setw(25) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');

}

void	print_line( void ) {

	std::cout << BLUE << std::setw(100) << std::setfill('-') << "" << END << std::endl;
	std::cout << std::setfill(' ');
}

int main() {

	print_line();
	{
		std::cout << BLUE << "Subject test. Test on stack: T = int, Container = default deque" << END << std::endl;
		print_line();

		MutantStack<int> s;

		for (int i = 0; i < 10; i++)
			s.push(i + 1);

		// Print MutantStack and top of MutantStack-------------------------------------------------------------------------------------

		print_mutant_stack(s);
		std::cout << BLUE << std::left << std::setw(25) << "MutantStack Top: " << END << s.top() << std::endl;

		// Print deque -------------------------------------------------------------------------------------------------

		std::deque<int> deque(s.begin(), s.end());
		print_sequence_container(deque, "deque");

		// Print top of std::stack---------------------------------------------------------------------------------------

		std::stack<int> stack(s);
		print_stack(stack);

	}
	print_line();
	{
		std::cout << BLUE << "Test on stack: T = char, Container = vector" << END << std::endl;
		print_line();

		MutantStack<char, std::vector< char > > s;

		for (char i = 0; i < 26; i++)
			s.push(65 + i);

		// Print MutantStack and top of MutantStack-------------------------------------------------------------------------------------

		print_mutant_stack(s);
		std::cout << BLUE << std::left << std::setw(25) << "MutankStack Top" << END << s.top() << std::endl;

		// Print vector -------------------------------------------------------------------------------------------------

		std::vector<char> vector(s.begin(), s.end());
		print_sequence_container(vector, "vector");

		// Print top of std::stack---------------------------------------------------------------------------------------

		std::stack<char, std::vector < char > > stack(s);
		print_stack(stack);
	}
	print_line();
	{
		std::cout << BLUE << "Test on CONST stack: T = double, Container = list, CONST_iterator" << END << std::endl;
		print_line();

		MutantStack<double, std::list< double > > s1;

		for (double i = 0.0; i < 10.0; i++)
			s1.push(i + 0.5);

		const MutantStack<double, std::list< double > > s(s1);

		// Print  -------------------------------------------------------

		std::cout << BLUE << std::left << std::setw(25) << "MutankStack iteration" << END;

		MutantStack<double, std::list< double > >::const_iterator it = s.begin();
		MutantStack<double, std::list< double > >::const_iterator ite = s.end();

		while (it != ite)
		{
			std::cout << *it << "  ";
			++it;
		}
		std::cout << std::endl;

		// Print top of MutantStack-------------------------------------------------------------------------------------

		std::cout << BLUE << std::left << std::setw(25) << "MutantStack Top: " << END << s.top() << std::endl;

		// Print list -------------------------------------------------------------------------------------------------

		std::list<double> list(s.begin(), s.end());
		print_sequence_container(list, "list");

		// Print top of std::stack---------------------------------------------------------------------------------------

		std::stack< double, std::list< double > > stack(s);
		print_stack(stack);
	}
	print_line();
	return 0;
}
