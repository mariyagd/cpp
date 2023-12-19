#include "phone.h"

std::string Contact::truncFirstName() const{

	std::string str;

	str = this->_firstName.substr(0,10);
	if (str.length() == 10)
		str[9] = '.';
	return str;
}

std::string Contact::truncLastName() const {

	std::string str;

	str = this->_lastName.substr(0,10);
	if (str.length() == 10)
		str[9] = '.';
	return str;
}

std::string Contact::truncNickName() const {

	std::string str;

	str = this->_nickName.substr(0,10);
	if (str.length() == 10)
		str[9] = '.';
	return str;
}