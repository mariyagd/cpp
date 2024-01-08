/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:21:47 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:21:51 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

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
	std::cout << "index:" << this->_accountIndex
			  <<";amount:" << this->_amount
			  << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(){

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  <<";amount:" << this->_amount
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
	std::cout 	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
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
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void	Account::makeDeposit(int deposit) {

	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount + deposit
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;

	_totalAmount += deposit;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {

	if (checkAmount() <= 50)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount - withdrawal
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	this->_amount = this->_amount - withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	return true;
}
