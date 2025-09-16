/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:06:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/16 10:55:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()	{ return _nbAccounts; }
int Account::getTotalAmount()	{ return _totalAmount; }
int Account::getNbDeposits()	{ return _totalNbDeposits; }
int	Account::getNbWithdrawals()	{ return _totalNbWithdrawals; }

/**
 * @brief display,acounts,total, deposits and withdrawals.
 * 
 */
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout 
		<< "index:"	 << _accountIndex << ";" 
		<< "amount:" << _amount << ";created\n";
	_nbAccounts++;
}
Account::~Account() 
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << checkAmount() << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount + deposit << ";"
		<< "nb_deposits:" << ++_nbDeposits << "\n";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << checkAmount() << ";"
		<< "withdrawal:";
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	else
		std::cout
			<< withdrawal << ";"
			<< "amount:" << checkAmount() - withdrawal << ";"
			<< "nb_withdrawals:" << ++_nbWithdrawals << "\n";
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << "\n";
}

/* private */

void Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);

    std::cout << "[";
    std::cout << (lt->tm_year + 1900);
    if (lt->tm_mon + 1 < 10) std::cout << "0";
    std::cout << (lt->tm_mon + 1);
    if (lt->tm_mday < 10) std::cout << "0";
    std::cout << lt->tm_mday << "_";
    if (lt->tm_hour < 10) std::cout << "0";
    std::cout << lt->tm_hour;
    if (lt->tm_min < 10) std::cout << "0";
    std::cout << lt->tm_min;
    if (lt->tm_sec < 10) std::cout << "0";
    std::cout << lt->tm_sec;
    std::cout << "] ";
}
Account::Account()
{}