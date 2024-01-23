#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {

private:
	std::string 			_target;

public:
	ShrubberyCreationForm( void );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const &src );
	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const& src);

	ShrubberyCreationForm( std::string target );

	void	execute( Bureaucrat const& executor ) const; //overrides
	void	drawTree( const Bureaucrat &executor ) const;

	std::string getTarget( void ) const;

	// for testing
	std::string getType( void ) const;
};

std::ostream& operator<<( std::ostream&, ShrubberyCreationForm const& object);

#endif