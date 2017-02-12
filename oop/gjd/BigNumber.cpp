//
// This part should be completed by yourself
// ps. You can generate the definitions in the header file
// Just click on yellow background functions and use the bulb appeared on the left
//
#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"

BigNumber::BigNumber() {

}

// Constructor from a number expressed by a string (if there exists a parse error, throws BigNumberParseException)
BigNumber::BigNumber(const std::string &numStr) {
    if (numStr[0] == '-')
        m_symbol = NEGATIVE;
    else
        m_symbol = POSITIVE;
    int len = numStr.length();
    for (int i = len - 1; i >= 0; --i) {
        if (isdigit(numStr[i])) {
            m_digits.push_back((unsigned char) numStr[i] - '0');
        }
    }
}

// Copy Constructor
BigNumber::BigNumber(const BigNumber &that) {

}

// Destructor
BigNumber::~BigNumber() {

}

// Generate a string to express the number
std::string BigNumber::toString() const {
    std::string str;
    if (this->m_symbol == NEGATIVE)
        str = "-";
    else
        str = "";
    int len = m_digits.size();
    std::vector<digit_t> digits = m_digits;
    for (int i = 0; i < len; ++i) {
        char ch = (char) digits.back() + '0';
        digits.pop_back();
        str.push_back(ch);
    }
    return str;
}

// Return the length of the BigNumber
size_t BigNumber::length() const
{
    return this->m_digits.size();
}

BigNumber BigNumber::operator+(const BigNumber &that) const
{
     return add(this,&that);
}

BigNumber BigNumber::operator-(const BigNumber &that) const
{
    return add(this,&that,NEGATIVE);
}

BigNumber BigNumber::operator*(const BigNumber &that) const
{
    int flag;
    int len_a,len_b,len,lenm;
    len_a=this->length();

}

void BigNumber::trim()
{
    while((length()>0)&&(m_digits.back()==0))
        m_digits.pop_back();
    if(length()==0)
        m_symbol=ZERO;
}

BigNumber BigNumber::add(const BigNumber *numA, const BigNumber *numB, SYMBOL symbolB)
{
    BigNumber c;
    SYMBOL symbolA=numA->m_symbol;
    if(numB->m_symbol==NEGATIVE)
        symbolB=SYMBOL ((-1)*(int)symbolB);
    else
        symbolB=numB->m_symbol;
    int len_a, len_b, len, lenm;
    len_a = (numA->m_digits).size();
    len_b = (numB->m_digits).size();
    len = (len_a > len_b) ? len_b : len_a;
    lenm = (len_a > len_b) ? len_a : len_b;
    const BigNumber *num;
    SYMBOL symbol;
    if (len_a<len_b)
    {
        num=numB;
        numB=numA;
        numA=num;
        symbol=symbolB;
        symbolB=symbolA;
        symbolA=symbol;
    }
    bool flag = false;
    bool flag0=false;
    digit_t digit;
    if (((symbolA==POSITIVE)&&(symbolB==POSITIVE))||((symbolA==NEGATIVE)&&(symbolB==NEGATIVE)))
    {
        for (int i = 0; i < len; ++i)
        {
            digit = numA->m_digits[i] + numB->m_digits[i];
            if (flag)
                digit += 1;
            if (digit > 9)
            {
                digit -= 10;
                flag = true;
            }
            else
                flag = false;
            c.m_digits.push_back(digit);
        }
        for (int i = len; i < lenm; ++i)
        {
            digit = numA->m_digits[i];
            if (flag)
                digit += 1;
            if (digit > 9)
            {
                digit -= 10;
                flag = true;
            }
            else
                flag = false;
            c.m_digits.push_back(digit);
        }
        if(flag)
            c.m_digits.push_back(1);
        if((symbolA==NEGATIVE)&&(symbolB==NEGATIVE))
            c.m_symbol=NEGATIVE;
    }
    if ((int)symbolA+(int)symbolB==0)
    {
        if(len!=lenm) {
            for (int i = 0; i < len; ++i) {
                digit = ((digit_t) symbolA) * (numA->m_digits[i]) + ((digit_t) symbolB) * (numB->m_digits[i]);
                if (flag0) {
                    digit -= 1;
                }
                if (digit < 0) {
                    flag0 = true;
                    digit += 10;
                } else
                    flag0 = false;
                c.m_digits.push_back(digit);
            }
            for (int i = len; i < lenm - 1; ++i) {
                digit = ((digit_t) symbolA) * (numA->m_digits[i]);
                if (flag0)
                    digit -= 1;
                if (digit < 0) {
                    flag0 = true;
                    digit += 10;
                } else
                    flag0 = false;
                c.m_digits.push_back(digit);
            }
            digit = ((digit_t) symbolA) * (numA->m_digits[lenm - 1]);
            if (flag0)
            {
                digit -= 1;
                c.m_digits.push_back(digit);
            }
            else
                c.m_digits.push_back(digit);
            if (c.m_digits.back() < 0) {
                c.m_digits[0] = 10 - c.m_digits[0];
                for (int i = 1; i < lenm - 1; ++i)
                    c.m_digits[i] = 9 - c.m_digits[i];
                c.m_digits[lenm - 1] = -c.m_digits[lenm - 1] - 1;
                c.m_symbol = NEGATIVE;
            }
        }
        else
        {
            for (int i = 0; i < len-1; ++i)
            {
                digit = ((digit_t) symbolA) * (numA->m_digits[i]) + ((digit_t) symbolB) * (numB->m_digits[i]);
                if (flag0) {
                    digit -= 1;
                }
                if (digit < 0) {
                    flag0 = true;
                    digit += 10;
                } else
                    flag0 = false;
                c.m_digits.push_back(digit);
            }
            digit = ((digit_t) symbolA) * (numA->m_digits[len-1]) + ((digit_t) symbolB) * (numB->m_digits[len-1]);
            if (flag0)
            {
                digit -= 1;
                c.m_digits.push_back(digit);
            }
            else
                c.m_digits.push_back(digit);
            if (c.m_digits.back() < 0)
            {
                c.m_digits[0] = 10 - c.m_digits[0];
                for (int i = 1; i < len- 1; ++i)
                    c.m_digits[i] = 9 - c.m_digits[i];
                c.m_digits[len - 1] = -c.m_digits[len - 1] - 1;
                c.m_symbol = NEGATIVE;
            }
        }
    }
    c.trim();
    return c;
}


