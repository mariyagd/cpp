//// setfill example
//#include <iostream>     // std::cout, std::endl
//#include <iomanip>      // std::setfill, std::setw
//
//int main () {
//  std::cout << std::setfill (' ') << std::setw (10);
//  std::cout << 77 << std::endl;
//  return 0;
//}

// setbase example
//#include <iostream>     // std::cout, std::endl
//#include <iomanip>      // std::setbase
//
//int main () {
//	std::cout << std::setbase(16);
//	std::cout << 110 << std::endl;
//	return 0;
//}

#include <iomanip>
#include <iostream>
#include <locale>

int main()
{
	std::cout.imbue(std::locale("en_US.utf8"));

	std::cout << "Default positioning:\n" << std::setfill('*')
			  << std::setw(12) << -1.23  << '\n'
			  << std::setw(12) << std::hex << std::showbase << 42 << '\n'
			  << std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Left positioning:\n" << std::left
			  << std::setw(12) << -1.23  << '\n'
			  << std::setw(12) << 42 << '\n'
			  << std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Internal positioning:\n" << std::internal
			  << std::setw(12) << -1.23  << '\n'
			  << std::setw(12) << 42 << '\n'
			  << std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Right positioning:\n" << std::right
			  << std::setw(12) << -1.23  << '\n'
			  << std::setw(12) << 42 << '\n'
			  << std::setw(12) << std::put_money(123, true) << '\n';
}
