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
	int i;

	i = 0;
	while (i < count_)
	{
		std::cout
			<< i << " "
			<< "[" << contracts_[i].first_name() << "] "
			<< "[" << contracts_[i].last_name() << "] "
			<< "[" << contracts_[i].nickname()  << "]\n";
		i++;
	}
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
