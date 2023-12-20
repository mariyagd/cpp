#include "phone.h"

bool	Contact::isValidFirstName() {

	if (!this->_firstName.empty())
	{
		_eraseWhiteSpace(this->_firstName);
		if (this->_firstName.empty())
			return false;
	}
	return true;
}

bool	Contact::isValidLastName() {

	if (!this->_lastName.empty())
	{
		_eraseWhiteSpace(this->_lastName);
		if (this->_lastName.empty())
			return false;
	}
	return true;
}

bool	Contact::isValidNickName() {

	if (!this->_nickName.empty())
	{
		_eraseWhiteSpace(this->_nickName);
		if (this->_nickName.empty())
			return false;
	}
	return true;
}

bool	Contact::isValidPhoneNumber() {

	int i(0);

	if (this->_phoneNumber.empty())
		return false;
	_eraseWhiteSpace(this->_phoneNumber);
	if (this->_phoneNumber.empty())
		return false;
	if (this->_phoneNumber[i] == '+')
		i++;
	while (this->_phoneNumber[i])
	{
		if (this->_phoneNumber[i] < '0' || this->_phoneNumber[i] > '9')
			return false;
		i++;
	}
	return true;
}

bool	Contact::isValidDarkestSecret() {

	if (!this->_darkestSecret.empty())
	{
		_eraseWhiteSpace(this->_darkestSecret);
		if (this->_darkestSecret.empty())
			return false;
	}
	return true;
}