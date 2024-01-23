#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string 			_target;

public:
	RobotomyRequestForm( void );
	~RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const &src );
	RobotomyRequestForm&	operator=( RobotomyRequestForm const& src);

	RobotomyRequestForm( std::string target );

	void	execute( Bureaucrat const& executor ) const; //overrides

	std::string getTarget( void ) const;
};

std::ostream& operator<<( std::ostream&, RobotomyRequestForm const& object);

#endif