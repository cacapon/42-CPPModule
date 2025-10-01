/**
 * @file PhoneBook.cpp
 * @brief A primitive phone book class that works with three commands.
 */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count_(0), c_i_(0)
{
}

/**
 * @brief Open the prompt screen.
 * 
 * Only ADD, SEARCH, and EXIT are accepted.
 * 
 */
void PhoneBook::mainPrompt()
{
	std::string cmd;
	while (true)
	{
		if (!promptLine("cmd?", cmd))
			break ;

		if 		(cmd == "ADD")		add();
		else if (cmd == "SEARCH")	search();
		else if (cmd == "EXIT")		break ;
	}
}

/* I/O helper */

/**
 * @brief Write the prompt input to out.
 * 
 * @param prompt 
 * @param out 
 * @return true	:Write successful
 * @return false:Write failure (e.g., EOF due to interrupt signal) 
 */
bool PhoneBook::promptLine(const char *prompt, std::string &out)
{
	out.clear();
	while (true)
	{
		if (!std::cin.eof())
			std::cout << prompt << ">";
		if (!std::getline(std::cin, out))
		{
			if (std::cin.eof())
				return (false);
			std::cin.clear();
				continue ;
		}
		if (out.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
			continue ;
		return (true);
	}
}
/**
 * @brief Safely stores the index entered from the prompt in an int type array.
 * 
 * @param out_index 
 * @return true :Successful write to out_index
 * @return false:Failed to write to out_index
 */
bool PhoneBook::promptIndex(int &out_index)
{
	int	v;
	std::string line;

	if (!promptLine("index?", line))
		return (false);
	std::istringstream iss(line);
	if (!(iss >> v))
		return (false);
	out_index = v;
	return (true);
}

/* Display helper */

/**
 * @brief If the text exceeds the column width, 
 * 
 * add a period at the end to make it fit within the column width.
 * 
 * @param s 
 * @return std::string 
 */
std::string PhoneBook::formatField(const std::string& s)
{
	if (s.length() > kColWidth)
		return (s.substr(0, kColWidth - 1) + ".");
	return (s);
}

/**
 * @brief Display the header.
 * 
 */
void PhoneBook::printHeader()
{
	std::cout  
			   << std::setw(kColWidth) << "Index"
		<< "|" << std::setw(kColWidth) << "FirstName"
		<< "|" << std::setw(kColWidth) << "LastName"
		<< "|" << std::setw(kColWidth) << "NickName"
		<< "\n";
}

/**
 * @brief Displays contact information in a simplified format. 
 * 
 */
void PhoneBook::printSummaryList()
{
	for (int i = 0; i < count_; i++)
	{
		std::cout 
				   << std::setw(kColWidth) << i 
			<< "|" << std::setw(kColWidth) << formatField(contracts_[i].first_name())
			<< "|" << std::setw(kColWidth) << formatField(contracts_[i].last_name()) 
			<< "|" << std::setw(kColWidth) << formatField(contracts_[i].nickname())
			<< "\n";
	}
}

/**
 * @brief Displays detailed information about the contact specified in the index.
 * 
 * @param index
 * @note pre: index < _count -1
 */
void PhoneBook::showContractDetails(unsigned int index)
{
	std::cout
		<< "first name"		<< ":" << contracts_[index].first_name()		<< "\n"
		<< "last name"		<< ":" << contracts_[index].last_name()			<< "\n"
		<< "nickname"		<< ":" << contracts_[index].nickname() 			<< "\n"
		<< "phone number"	<< ":" << contracts_[index].phone_num() 		<< "\n"
		<< "darkest secret"	<< ":" << contracts_[index].darkest_secret()	<< "\n";
}

/* main method. */

/**
 * @brief Add contact information.
 * 
 */
void PhoneBook::add()
{
	std::string data[5];

	if (!promptLine("first name?", data[0]))		return;
	if (!promptLine("last name?", data[1]))			return;
	if (!promptLine("nickname?", data[2]))			return;
	if (!promptLine("phone number?", data[3]))		return;
	if (!promptLine("darkest secret?", data[4]))	return;
	
	contracts_[c_i_] = Contract(data[0], data[1], data[2], data[3], data[4]);
	c_i_ = (c_i_ + 1) % kMaxContracts;
	if (count_ < kMaxContracts)
		count_++;
}

/**
 * @brief Display saved contacts in a simplified format, 
 * 
 * then display the specified index in detail.
 * 
 */
void PhoneBook::search()
{
	int index;

	if (count_ == 0)
	{
		std::cout << "No data.\n";
		return ;
	}
	printHeader();
	printSummaryList();

	if (promptIndex(index) && 0 <= index && index < count_)
		showContractDetails(index);
	else
		std::cout << "Invalid Index\n";
}
