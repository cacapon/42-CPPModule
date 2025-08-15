/**
 * @file Contract.hpp
 * @brief Data class for managing contact information.
 */

#ifndef CONTRACT_HPP
#define CONTRACT_HPP

#include <string>

class Contract
{
  private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_num_;
	std::string darkest_secret_;

  public:
	Contract();
	Contract(
		std::string& first_name,
		std::string& last_name,
		std::string& nickname,
		std::string& phone_num,
		std::string& darkest_secret
	);
	const std::string& first_name() 	const { return first_name_; 	};
	const std::string& last_name()		const { return last_name_;		};
	const std::string& nickname()		const { return nickname_;		};
	const std::string& phone_num()		const { return phone_num_;		};
	const std::string& darkest_secret() const { return darkest_secret_;	};
};

#endif