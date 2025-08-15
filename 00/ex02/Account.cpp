/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:06:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/15 11:05:03 by ttsubo           ###   ########.fr       */
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
	//TODO
}

Account::Account(int initial_deposit)
{
	_nbDeposits = initial_deposit;
}
Account::~Account() 
{
	//TODO
}

void Account::makeDeposit(int deposit)
{
	//TODO
}

bool Account::makeWithdrawal(int withdrawal)
{
	//TODO
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	//TODO
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