/**
 * @file Account.cpp
 * @brief 
 */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* static functions */
int 	Account::getNbAccounts()	{ return _nbAccounts; }
int 	Account::getTotalAmount()	{ return _totalAmount; }
int 	Account::getNbDeposits()	{ return _totalNbDeposits; }
int		Account::getNbWithdrawals()	{ return _totalNbWithdrawals; }
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << "\n";
}

/* constracotor and destractor */
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
	_totalAmount -= _amount;
	_nbAccounts--;
}

/* public functions */

/**
 * @brief Add funds to the deposit account.
 * 
 * @param deposit 
 */
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

/**
 * @brief Withdraw money from the savings account.
 * 
 * @param withdrawal 
 * @return true : The withdrawal from the deposit account was successful.
 * @return false: Insufficient funds caused the withdrawal to fail.
 */
bool Account::makeWithdrawal(int withdrawal)
{
	int amount = checkAmount();

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << amount << ";"
		<< "withdrawal:";
	if (amount < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	else
		std::cout
			<< withdrawal << ";"
			<< "amount:" << amount - withdrawal << ";"
			<< "nb_withdrawals:" << ++_nbWithdrawals << "\n";
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

/**
 * @brief Ammont getter.
 * 
 * @return int : amount
 */
int Account::checkAmount() const
{
	return (_amount);
}

/**
 * @brief Outputs the account 
 * status (index, amount, deposits, withdrawals) to the console.
 * 
 */
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << "\n";
}

/* private functions */

/**
 * @brief Outputs the current time to the console in [YYYMMDD_hhmmss] format.
 * 
 */
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

/* @hint Account(void) is an uncalled constructor, so implementation is unnecessary. */
