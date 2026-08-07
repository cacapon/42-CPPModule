/**
 * @file BitcoinExchange.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-07
 *
 *
 */

#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

std::string BitcoinExchange::_trim(const std::string& str) const {
    size_t frontPos = str.find_first_not_of(" ");
    if (frontPos == std::string::npos) return "";
    size_t endPos = str.find_last_not_of(" ");
    return str.substr(frontPos, endPos - frontPos + 1);
}

bool BitcoinExchange::_isValidDate(const std::string& dateStr) const {
    // length
    if (dateStr.size() != 10) return false;

    // year
    for (int i = 0; i < 4; i++) {
        if (!std::isdigit(dateStr[i])) return false;
    }
    int year = (dateStr[0] - '0') * 1000 + (dateStr[1] - '0') * 100 +
               (dateStr[2] - '0') * 10 + (dateStr[3] - '0');
    if (dateStr[4] != '-') return false;
    // month
    for (int i = 5; i < 7; i++) {
        if (!std::isdigit(dateStr[i])) return false;
    }
    int month = (dateStr[5] - '0') * 10 + (dateStr[6] - '0');
    if (!(1 <= month and month <= 12)) return false;
    if (dateStr[7] != '-') return false;
    // day
    for (int i = 8; i < 10; i++) {
        if (!std::isdigit(dateStr[i])) return false;
    }
    int day = (dateStr[8] - '0') * 10 + (dateStr[9] - '0');
    if (!(1 <= day and day <= _getLastDayOfMonth(year, month))) return false;
    return true;
}

int BitcoinExchange::_getLastDayOfMonth(int year, int month) const {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) return daysInMonth[month - 1];
    if (year % 400 == 0)
        return 29;
    else if (year % 100 == 0)
        return 28;
    else if (year % 4 == 0)
        return 29;
    else
        return 28;
}

float BitcoinExchange::_getRate(const std::string& dateStr) const {
    std::map<std::string, float>::const_iterator it =
        _bitCoinTable.lower_bound(dateStr);
    if (it == _bitCoinTable.end() || it->first != dateStr) {
        if (it == _bitCoinTable.begin())
            throw std::runtime_error("no data available for this date.");
        --it;
    }
    return it->second;
}

BitcoinExchange::BitcoinExchange(const std::string& path) {
    loadDatabase(path);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _bitCoinTable(other._bitCoinTable) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (&other != this) {
        _bitCoinTable = other._bitCoinTable;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file.is_open()) throw std::runtime_error(path + " is not open.");
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) continue;
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        std::stringstream ss(rateStr);
        float rate;
        ss >> rate;
        if (ss.fail()) continue;
        _bitCoinTable[date] = rate;
    }
}

void BitcoinExchange::loadInputText(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file.is_open()) throw std::runtime_error(path + " is not open.");
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t separatePos = line.find('|');
        if (separatePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = _trim(line.substr(0, separatePos));
        std::string valueStr = _trim(line.substr(separatePos + 1));
        if (!_isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::stringstream ss(valueStr);
        float value;
        ss >> value;
        if (ss.fail()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }
        float calc = value * _getRate(date);
        std::cout << date << " => " << value << " = " << calc << std::endl;
    }
}
