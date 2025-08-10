/**
 * @file PhoneBook.hpp
 * @brief A primitive phone book class that works with three commands
 */

#pragma once
#include "Contract.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook
{
  private:
	static const int kMaxContracts = 8;
	Contract contracts_[kMaxContracts];
	int count_;
	int c_i_;
	void add();
	void search();
	
	std::string formatField(std::string data);
	std::string getPromptStr(std::string prompt);
	void	printHeader();
	void	printEntry();
	void	searchPrompt();
	void 	showContractDetails(int index);

  public:
	PhoneBook();
	void mainPrompt();
};
