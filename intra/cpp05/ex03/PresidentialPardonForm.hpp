#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class  PresidentialPardonForm : public AForm {

private:
	std::string 			_target;

public:
	 PresidentialPardonForm( void );
	~ PresidentialPardonForm( void );
	 PresidentialPardonForm(  PresidentialPardonForm const &src );
	 PresidentialPardonForm&	operator=(  PresidentialPardonForm const& src);

	 PresidentialPardonForm( std::string target );

	void	execute( Bureaucrat const& executor ) const; //overrides

	std::string getTarget( void ) const;

	// for testing
	std::string getType( void ) const;

};

std::ostream& operator<<( std::ostream&,  PresidentialPardonForm const& object);

#endif