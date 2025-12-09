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
    static void convert(const std::string &s);

   private:
    /* canonical form - private because instantiation is not allowed */
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

   private:
    /* Check whether the provided string can be converted to the type */
    static bool isChar(const std::string &s);
    static bool isInt(const std::string &s);
    static bool isFloat(const std::string &s);
    static bool isDouble(const std::string &s);

   private:
    /* helper methods */
    static bool fitsInInt(const std::string &s);
    static bool regexInt(const std::string &s);
    static bool regexFloat(const std::string &s);
    static bool regexDouble(const std::string &s);
    static bool decimalIsZero(const std::string &s);
    static std::string extractIntegerPart(const std::string &s);

   private:
    /* Output in that format. If not possible, return impossible. */
    static void fromChar(const std::string &s);
    static void fromInt(const std::string &s);
    static void fromFloat(const std::string &s);
    static void fromDouble(const std::string &s);
};

#endif