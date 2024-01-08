/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:21:09 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/08 19:47:24 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

# include "Contact.hpp"

class PhoneBook {

public :
	PhoneBook( void );
	~PhoneBook( void );

	void 		userInput( void ) ;

private:
	Contact		_contact[8];
	int 		_realIndex;
	int 		_index;
	int 		_tableSize;
	void		_addContact( void ) ;
	void		_addFirstName ( void );
	void		_addLastName ( void );
	void		_addNickName ( void );
	void		_addPhoneNumber ( void );
	void		_addDarkestSecrdet ( void );
	void		_searchContact( void ) const ;
	int 		_isNumber( std::string& str, int tableSize ) const;
	void		_eraseWhiteSpaces(std::string& command) const;
	void		_transformToUpper(std::string& command) const;

};

#endif
