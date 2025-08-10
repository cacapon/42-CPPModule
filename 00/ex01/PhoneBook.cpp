/**
 * @file PhoneBook.cpp
 * @brief 
 */

#include "PhoneBook.hpp"

void PhoneBook::add()
{
	std::string data[5];

	std::cout << "first name?:";
	std::cin >> data[0];
	std::cout << "last name?:";
	std::cin >> data[1];
	std::cout << "nickname?:";
	std::cin >> data[2];
	std::cout << "phone number?:";
	std::cin >> data[3];
	std::cout << "darkest secret?:";
	std::cin >> data[4];

	Contract c(data[0],data[1],data[2],data[3],data[4]);
	contracts_[c_i_] = c;
	c_i_ = (c_i_ + 1) % kMaxContracts;
	if(count_ < kMaxContracts) count_++;	
}
void PhoneBook::search()
{
	printHeader();
	printEntry();
}

void PhoneBook::printHeader()
{
	std::cout
		<< std::setw(10) << "Index" 	<< "|"
		<< std::setw(10) << "FirstName" << "|"
		<< std::setw(10) << "LastName" 	<< "|"
		<< std::setw(10) << "NickName" 	<< "\n";
}

void PhoneBook::printEntry()
{
	int i;

	i = 0;
	while (i < count_)
	{
		std::cout
			<< std::setw(10) << i 										<< "|"
			<< std::setw(10) << formatField(contracts_[i].first_name()) << "|"
			<< std::setw(10) << formatField(contracts_[i].last_name())	<< "|"
			<< std::setw(10) << formatField(contracts_[i].nickname())	<< "\n";
		i++;
	}
}

std::string PhoneBook::formatField(std::string data)
{
	if (data.length() > 10)
		return (data.substr(0,9) + ".");
	return (data);
}

PhoneBook::PhoneBook()
{
	count_ = 0;
	c_i_ = 0;
}

void PhoneBook::prompt()
{
	std::string cmd;

	while(1)
	{
		std::cout << "cmd?>";
		std::cin >> cmd;
		if	   (cmd == "ADD")		this->add();
		else if(cmd == "SEARCH")	this->search();
		else if(cmd == "EXIT")		break;
		std::cout << "\n";
	}
}
