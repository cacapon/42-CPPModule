/**
 * @file PhoneBook.cpp
 * @brief 
 */

#include "PhoneBook.hpp"

std::string PhoneBook::formatField(std::string data)
{
	if (data.length() > 10)
		return (data.substr(0,9) + ".");
	return (data);
}

std::string PhoneBook::getPromptStr(std::string prompt)
{
	std::string data = "";

	while(true)
	{
		if (!std::cin.eof())
			std::cout << prompt << ">";
		if (!std::getline(std::cin, data))
		{
			if (std::cin.eof())
				return ("EXIT");
			std::cin.clear();
			continue;
		}
		if (data.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
			continue;
		return (data);
	}
}

void PhoneBook::add()
{
	std::string data[5];

	data[0] = getPromptStr("first name?");
	data[1] = getPromptStr("last name?");
	data[2] = getPromptStr("nickname?");
	data[3] = getPromptStr("phone number?");
	data[4] = getPromptStr("darkest secret?");
	Contract c(data[0],data[1],data[2],data[3],data[4]);
	contracts_[c_i_] = c;
	c_i_ = (c_i_ + 1) % kMaxContracts;
	if(count_ < kMaxContracts) count_++;	
}

void PhoneBook::search()
{
	if (count_ == 0)
	{
		std::cout << "No data.\n";
		return ;
	}
	printHeader();
	printEntry();
	searchPrompt();
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

void PhoneBook::searchPrompt()
{
	int	index;

	std::cout << "index?>";
	std::cin >> index;
	std::cin.ignore(10000, '\n');
	if (0 <= index && index < count_)
		showContractDetails(index);
	else
		std::cout << "Invalid Index\n";
}

void PhoneBook::showContractDetails(int index)
{
	std::cout
		<< "first name"		<< ":" << contracts_[index].first_name() 		<< "\n"
		<< "last name"		<< ":" << contracts_[index].last_name() 		<< "\n"
		<< "nickname"		<< ":" << contracts_[index].nickname() 			<< "\n"
		<< "phone number"	<< ":" << contracts_[index].phone_num() 		<< "\n"
		<< "darkest secret"	<< ":" << contracts_[index].darkest_secret()	<< "\n";
}

PhoneBook::PhoneBook()
{
	count_ = 0;
	c_i_ = 0;
}

void PhoneBook::mainPrompt()
{
	std::string cmd;

	while(true)
	{
		cmd = getPromptStr("cmd?");
		if	   (cmd == "ADD")		add();
		else if(cmd == "SEARCH")	search();
		else if(cmd == "EXIT")		break;
	}
}
