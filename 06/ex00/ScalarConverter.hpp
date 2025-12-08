#include <string>
/**
 * @file ScalarConverter.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter {
   public:
    static void convert(const std::string &str);

   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);

    static void fromChar(const std::string str);
    static void fromInt(const std::string str);
    static void fromFloat(const std::string str);
    static void fromDouble(const std::string str);
};

#endif