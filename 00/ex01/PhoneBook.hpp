/**
 * @file PhoneBook.hpp
 * @brief A primitive phone book class that works with three commands
 */

#pragma once
#include "Contract.hpp"
#include <iostream>

class PhoneBook
{
  private:
	static const int kMaxContracts = 8;
	Contract contracts_[kMaxContracts];
	int count_;
	int c_i_;
	void add();
	void search();

  public:
	PhoneBook();
	void prompt();
};
