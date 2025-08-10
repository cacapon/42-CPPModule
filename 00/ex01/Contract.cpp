/**
 * @file Contract.cpp
 * @brief 
 */

#include "Contract.hpp"

Contract::Contract()
{}

Contract::Contract(
	std::string first,
	std::string last,
	std::string nick,
	std::string phone, 
	std::string secret
)
	: first_name_(first),
	  last_name_(last),
	  nickname_(nick),
	  phone_num_(phone),
	  darkest_secret_(secret)
{}
