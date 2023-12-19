#include "phone.h"

int Contact::getIndex( void ) const {

	return this->_index;
}

std::string Contact::getFirstName( void ) const {

	return this->_firstName;
};

std::string Contact::getLastName() const {

	return this->_lastName;
}

std::string Contact::getNickName() const {

	return this->_nickName;
}

std::string Contact::getPhoneNumber() const {

	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {

	return this->_darkestSecret;
}