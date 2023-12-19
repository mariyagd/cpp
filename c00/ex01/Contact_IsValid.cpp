#include "phone.h"

bool	Contact::isValidFirstName() const {

	return !this->_firstName.empty();
}

bool	Contact::isValidLastName() const {

	return !this->_lastName.empty();
}

bool	Contact::isValidNickName() const {

	return !this->_nickName.empty();
}

bool	Contact::isValidPhoneNumber() const {

	int i(0);

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

bool	Contact::isValidDarkestSecret() const {

	return !this->_darkestSecret.empty();
}