/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:26 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:44 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";" << "created"
			<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount 
		<< ";closed"
		<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0)
	{
		std::cout << "deposit:refused" << std::endl;

		return ;
	}

	this->_amount += deposit;
	this->_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << (this->_amount - deposit)
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;


}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:refused" << std::endl;
		
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << (this->_amount + withdrawal)
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

//----------------------------STATIC FUNCTIONS----------------------------

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}
 
void	Account::_displayTimestamp( void )
{
	time_t		t = time(0);

	char		buff[80];
	strftime(buff, 80, "%Y%m%d_%H%M%S", localtime(&t));
	std::cout << "[" << buff << "] ";
}
