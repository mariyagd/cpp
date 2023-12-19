#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>

class Contact {

public:
	Contact ( void );
	~Contact ( void );

	void			setIndex(int i);
	std::string&	setFirstName( void );
	std::string&	setLastName( void );
	std::string&	setNickName( void );
	std::string&	setPhoneNumber( void );
	std::string&	setDarkestSecret( void );

	int				getIndex( void ) const;
	std::string		getFirstName( void ) const;
	std::string		getLastName( void ) const;
	std::string		getNickName( void ) const;
	std::string		getPhoneNumber( void ) const;
	std::string		getDarkestSecret( void ) const;

	std::string		truncFirstName( void ) const;
	std::string		truncLastName( void ) const;
	std::string		truncNickName( void ) const;

	bool			isValidFirstName( void ) const;
	bool			isValidLastName( void ) const;
	bool			isValidNickName( void ) const;
	bool			isValidPhoneNumber( void ) const;
	bool			isValidDarkestSecret( void ) const;

private:
	int 		_index;
	std::string	_firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string	_darkestSecret;
};

#endif

