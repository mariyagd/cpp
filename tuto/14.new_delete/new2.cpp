#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student() : _login("ldefault")
		{
			std::cout << "Student " << this->_login << " is born." << std::endl;
		}
		~Student()
		{
			std::cout << "Student " << this->_login << " died." << std::endl;
		}
};

int	main()
{
	Student* students = new Student[42]; // students is created on the heap
	
	// do some stuff with students
	
	delete [] students; // students is destroyed

}
