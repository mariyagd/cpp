/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:20:58 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:20:59 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

# include <iostream>

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

	bool			isValidFirstName( void );
	bool			isValidLastName( void );
	bool			isValidNickName( void );
	bool			isValidPhoneNumber( void );
	bool			isValidDarkestSecret( void );

private:
	int 		_index;
	std::string	_firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string	_darkestSecret;

	void		_eraseWhiteSpace(std::string& command);
};

#endif

