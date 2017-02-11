//
// Created by liu on 17-2-11.
//

#pragma once

#include <vector>
#include <string>
#include <exception>

class BigNumberParseException : public std::exception
{

};

class BigNumber
{
public:
    // Use unsigned char to save digits of BigNumber
    // Be careful that the range of unsigned char is 0-255
    typedef unsigned char digit_t;

    enum SYMBOL
    {
        POSITIVE = 1, NEGATIVE = -1
    };

    // Default Constructor (set default value to zero)
    BigNumber();

    // Constructor from a number expressed by a string (if there exists a parse error, throws BigNumberParseException)
    BigNumber(const std::string &numStr);

    // Copy Constructor
    BigNumber(const BigNumber &that);

    // Destructor
    ~BigNumber();

    // Generate a string to express the number
    std::string toString() const;

    // Return the length of the BigNumber
    size_t length() const;

    // Return true if the BigNumber is positive
    bool isPositive() const;

    // Add two BigNumbers and return a new one
    BigNumber operator+(const BigNumber &that) const;

    // Add two BigNumbers and return the left value
    BigNumber &operator+=(const BigNumber &that);

    // Minus two BigNumbers and return a new one
    BigNumber operator-(const BigNumber &that) const;

    // Minus two BigNumbers and return the left value
    BigNumber &operator-=(const BigNumber &that);


protected:
    // The vector to save the digits of the BigNumber
    std::vector<digit_t> m_digits;

    SYMBOL m_symbol;
};


