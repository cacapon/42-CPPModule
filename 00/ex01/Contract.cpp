/**
 * @file Contract.cpp
 * @brief 
 */

#include "Contract.hpp"

Contract::Contract(
	const std::string& first_name,
	const std::string& last_name,
	const std::string& nickname,
	const std::string& phone_num, 
	const std::string& darkest_secret
)
	: first_name_(first_name),
	  last_name_(last_name),
	  nickname_(nickname),
	  phone_num_(phone_num),
	  darkest_secret_(darkest_secret)
{
}
