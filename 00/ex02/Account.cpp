/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:06:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/15 10:50:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>

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
	//TODO
}
Account::Account()
{}