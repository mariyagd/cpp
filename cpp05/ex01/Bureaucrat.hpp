#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define DIM		"\033[2m"
# define ITALIC		"\033[3m"
# define END		"\033[0m"
# define BLUE		"\033[1;34m"
# define BOLD		"\033[1m"
# define RED		"\033[1;31m"

class Form;

class Bureaucrat {
	
private:
	std::string const		_name;
	int						_grade;
	static const int 		gradeMin;
	static const int 		gradeMax;

public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat( void );
	Bureaucrat( Bureaucrat const &src );
	Bureaucrat&	operator=( Bureaucrat const &rhs );


	void	testGrade( void ) const;

	class GradeTooHighException : public std::exception
	{

	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{

	public:
		const char* what() const throw();
	};

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		increment( void );
	void		decrement( void );

	void				signForm( Form& form ) const;

};

std::ostream&	operator<< ( std::ostream &stream, Bureaucrat const &object );

#endif



