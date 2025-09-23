/**
 * @file Contract.cpp
 */

#include "Contract.hpp"

Contract::Contract()
	:	first_name_(), 
		last_name_(), 
		nickname_(), 
		phone_num_(), 
		darkest_secret_()
{}

Contract::Contract(
	std::string& first,
	std::string& last,
	std::string& nick,
	std::string& phone, 
	std::string& secret
)
	: first_name_(first),
	  last_name_(last),
	  nickname_(nick),
	  phone_num_(phone),
	  darkest_secret_(secret)
{}
