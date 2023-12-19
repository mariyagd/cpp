#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class PhoneBook {

public :
	PhoneBook( void );
	~PhoneBook( void );

private:
	Contact		_contact[8];
	int 		_realIndex;
	int 		_index;
	int 		_tableSize;
	void 		_userInput( void ) ;
	void		_addContact( void ) ;
	void		_searchContact( void ) const ;
	int 		_isNumber( std::string str, int tableSize ) const;
	void		_addFirstName ( void );
	void		_addLastName ( void );
	void		_addNickName ( void );
	void		_addPhoneNumber ( void );
	void		_addDarkestSecret ( void );
};

#endif