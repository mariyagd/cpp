#include "phone.h"

void Contact::setIndex(int i) {

	this->_index = i;
	return;
}

std::string& Contact::setFirstName(){

	return this->_firstName;
}

std::string& Contact::setLastName() {

	return this->_lastName;
}

std::string &Contact::setNickName() {

	return this->_nickName;
}

std::string &Contact::setPhoneNumber() {

	return this->_phoneNumber;
}

std::string &Contact::setDarkestSecret() {

	return this->_darkestSecret;
}