/**
 * @file PhoneBook.hpp
 * @brief A primitive phone book class that works with three commands.
 */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contract.hpp"

class PhoneBook
{
  private:
	enum { kMaxContracts = 8 };
	enum { kColWidth = 10 };

	Contract contracts_[kMaxContracts];
	int count_;
	int c_i_;
	
	// I/O helper
	bool promptLine(const char* prompt, std::string& out);
	bool promptIndex(int& out_index);

	// Display helper
	std::string formatField(const std::string& s);
	void	printHeader();
	void	printSummaryList();
	void	searchPrompt();
	void 	showContractDetails(unsigned int index);

	// main method
	void add();
	void search();

  public:
	PhoneBook();
	void mainPrompt();
};

#endif