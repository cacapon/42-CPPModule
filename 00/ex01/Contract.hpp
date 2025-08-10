/**
 * @file Contract.hpp
 * @brief Data class for managing contact information.
 */

#pragma once
#include <string>

class Contract
{
  private:
	const std::string first_name_;
	const std::string last_name_;
	const std::string nickname_;
	const std::string phone_num_;
	const std::string darkest_secret_;

  public:
	Contract(
		const std::string& first_name,
		const std::string& last_name,
		const std::string& nickname,
		const std::string& phone_num,
		const std::string& darkest_secret
	);
	const std::string& first_name() 	const { return first_name_; 	};
	const std::string& last_name()		const { return last_name_;		};
	const std::string& nickname()		const { return nickname_;		};
	const std::string& phone_num()		const { return phone_num_;		};
	const std::string& darkest_secret() const { return darkest_secret_;	};
};
