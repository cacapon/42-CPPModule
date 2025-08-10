/**
 * @file Contract.cpp
 * @brief 
 */

#include "Contract.hpp"

Contract::Contract(
	std::string first,
	std::string last,
	std::string nick,
	std::string phone, 
	std::string secret
)
	: first_name_(std::move(first)),
	  last_name_(std::move(last)),
	  nickname_(std::move(nick)),
	  phone_num_(std::move(phone)),
	  darkest_secret_(std::move(secret))
{}
