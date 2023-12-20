#include "Account.hpp"
#include <iostream>
#include <iomanip>

#define MAGENTA "\033[0;35m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

/*
 * initialization des variables non-membres
 * chaque variable représente le total
 */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
 * Constructeur: lorsqu'on crée un nouveau compte
 * le constructeur est appelé. Il initialise le
 * somme du compte et incrémente les variables statiques
 */

Account::Account(int initial_deposit) :	_accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
			  <<";amount:" << MAGENTA << ITALIC << this->_amount << RESET
			  << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(){

	_displayTimestamp();
	std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
			  <<";amount:" << MAGENTA << ITALIC << this->_amount << RESET
			  << ";closed" << std::endl;

}

int Account::getNbAccounts() {

	return _nbAccounts;
}

int Account::getTotalAmount() {

	return _totalAmount;
}

int	Account::getNbDeposits() {

	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {

	return _totalNbWithdrawals;
}

int Account::checkAmount() const {

	return this->_amount;
}

void	Account::displayAccountsInfos() {

	_displayTimestamp();
	std::cout 	<< "accounts:" << MAGENTA << ITALIC << getNbAccounts() << RESET
				<< ";total:" << MAGENTA << ITALIC << getTotalAmount() << RESET
				<< ";deposits:" << MAGENTA << ITALIC << getNbDeposits() << RESET
				<< ";withdrawals:" << MAGENTA << ITALIC << getNbWithdrawals() << RESET
				<< std::endl;
}

/*
 * std::cout << "[19920104_091532] ";
 */

void	Account::_displayTimestamp( void ) {

	std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());

	struct std::tm* ptm = std::localtime(&tt);
	std::cout << "[" << std::put_time(ptm,"%Y%m%d")
			  << "_" << std::put_time(ptm,"%H%M%S") << "] ";

}

void	Account::displayStatus() const {

	_displayTimestamp();
	std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
			  << ";amount:" << MAGENTA << ITALIC << this->_amount << RESET
			  << ";deposits:" << MAGENTA << ITALIC << this->_nbDeposits << RESET
			  << ";withdrawals:" << MAGENTA << ITALIC << this->_nbWithdrawals << RESET
			  << std::endl;
}

void	Account::makeDeposit(int deposit) {

	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
			  << ";p_amount:" << MAGENTA << ITALIC << this->_amount << RESET
			  << ";deposit:" << MAGENTA << ITALIC << deposit << RESET
			  << ";amount:" << MAGENTA << ITALIC << this->_amount + deposit << RESET
			  << ";nb_deposits:" << MAGENTA << ITALIC << this->_nbDeposits << RESET
			  << std::endl;

	_totalAmount += deposit;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {

	if (checkAmount() <= 50)
	{
		_displayTimestamp();
		std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
				  << ";p_amount:" << MAGENTA << ITALIC << this->_amount << RESET
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << MAGENTA << ITALIC << this->_accountIndex << RESET
			  << ";p_amount:" << MAGENTA << ITALIC << this->_amount << RESET
			  << ";withdrawal:" << MAGENTA << ITALIC << withdrawal << RESET
			  << ";amount:" << MAGENTA << ITALIC << this->_amount - withdrawal << RESET
			  << ";nb_withdrawals:" << MAGENTA << ITALIC << _nbWithdrawals << RESET
			  << std::endl;
	this->_amount = this->_amount - withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	return true;
}