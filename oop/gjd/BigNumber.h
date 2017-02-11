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

class BigNumberBoundaryException : public std::exception
{

};

class BigNumberDivideZeroException : public std::exception
{

};

class BigNumber
{
public:
    // Use unsigned char to save digits of BigNumber
    // Be careful that the range of unsigned char is -128~127
    typedef char digit_t;

    enum SYMBOL
    {
        POSITIVE = 1, ZERO = 0, NEGATIVE = -1
    };

    // Default Constructor (set default value to zero)
    BigNumber();

    // Constructor from a number expressed by a string (if there exists a parse error, throws BigNumberParseException)
    BigNumber(const std::string &numStr);

    // Constructor from an integer
    BigNumber(int64_t num);

    // Copy Constructor
    BigNumber(const BigNumber &that);

    // Destructor
    virtual ~BigNumber();

    // Generate a string to express the number
    std::string toString() const;

    // Return the length of the BigNumber
    size_t length() const;

    // Return the symbol of the BigNumber
    SYMBOL symbol() const;

    // Return the digit on the index (from left to right, excluding the symbol)
    digit_t operator[](size_t index) const;

    // Return whether two BigNumbers equal
    bool operator==(const BigNumber &that) const;

    // Return whether two BigNumbers unequal
    bool operator!=(const BigNumber &that) const;

    // Return whether one BigNumber is smaller than another
    bool operator<(const BigNumber &that) const;

    // Return whether one BigNumber is not larger than another
    bool operator<=(const BigNumber &that) const;

    // Return whether one BigNumber is larger than another
    bool operator>(const BigNumber &that) const;

    // Return whether one BigNumber is not smaller than another
    bool operator>=(const BigNumber &that) const;

    // Reset the BigNumber from a string
    const BigNumber &operator=(const std::string &numStr);

    // Reset the BigNumber from an integer
    const BigNumber &operator=(const int64_t &num);

    // Same as copy constructor
    BigNumber operator+() const;

    // Add two BigNumbers and return a new one
    BigNumber operator+(const BigNumber &that) const;

    // Add two BigNumbers and return the left value
    const BigNumber &operator+=(const BigNumber &that);

    // ++BigNumber
    BigNumber &operator++();

    // BigNumber++
    const BigNumber operator++(int);

    // Change the symbol of the BigNumber
    BigNumber operator-() const;

    // Minus two BigNumbers and return a new one
    BigNumber operator-(const BigNumber &that) const;

    // Minus two BigNumbers and return the left value
    const BigNumber &operator-=(const BigNumber &that);

    // --BigNumber
    BigNumber &operator--();

    // BigNumber--
    const BigNumber operator--(int);

    // Multiple two BigNumbers and return a new one
    BigNumber operator*(const BigNumber &that) const;

    // Multiple two BigNumbers and return the left value
    const BigNumber &operator*=(const BigNumber &that);

    // Divide two BigNumbers and return a new one
    BigNumber operator/(const BigNumber &that) const;

    // Divide two BigNumbers and return the left value
    const BigNumber &operator/=(const BigNumber &that);

    // Mod two BigNumbers and return a new one
    BigNumber operator%(const BigNumber &that) const;

    // Mod two BigNumbers and return the left value
    const BigNumber &operator%=(const BigNumber &that);

protected:
    // The vector to save the digits of the BigNumber
    std::vector<digit_t> m_digits;

    SYMBOL m_symbol;

    // Remove zeros on the left
    void trim();

    static BigNumber add(const BigNumber *numA, const BigNumber *numB, const SYMBOL symbolB = POSITIVE);

    static std::pair<BigNumber, BigNumber> divide(const BigNumber &divider, const BigNumber &divisor);
};


