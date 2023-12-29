#include <iostream>
#include <string>

class Student 
{
	private:
		std::string _login;

	public:
		Student(std::string login) : _login(login)
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
	Student		bob = Student("bfubar"); // bob is created on the stack
	Student*	jim = new Student("jfubar"); // jim is created on the heap

	// do some stuff with bob and jim

	delete jim; //jim is destroyed
	return (0); //bob is destroyed
}
