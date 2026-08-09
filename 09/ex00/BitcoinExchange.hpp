/**
 * @file BitcoinExchange.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-07
 *
 *
 */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _bitCoinTable;
    BitcoinExchange();
    std::string _trim(const std::string&) const;
    bool _isValidDate(const std::string&) const;
    int _getLastDayOfMonth(int, int) const;
    float _getRate(const std::string&) const;

public:
    BitcoinExchange(const std::string&);
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);
    ~BitcoinExchange();

    void loadDatabase(const std::string& path);
    void loadInputText(const std::string& path);
};

#endif
