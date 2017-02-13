//
// This part should be completed by yourself
// ps. You can generate the definitions in the header file
// Just click on yellow background functions and use the bulb appeared on the left
//
#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"

BigNumber::BigNumber()
{
    m_symbol=ZERO;
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
    if(len>1) {
        trim();
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
    else if(this->m_symbol==ZERO)
        str="0";
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

// ++BigNumber
BigNumber &BigNumber::operator++()
{
    const BigNumber one("1");
    *this=*this+one;
    return *this;
}

// BigNumber++
const BigNumber BigNumber::operator++(int)
{
    const BigNumber one("1");
    BigNumber c;
    c=*this;
    *this=add(this,&one);
    return c;
}

BigNumber BigNumber::operator-(const BigNumber &that) const
{
    return add(this,&that,NEGATIVE);
}

// --BigNumber
BigNumber &BigNumber::operator--()
{
    BigNumber one("1");
    *this=add(this,&one,NEGATIVE);
    return *this;
}

// BigNumber--
const BigNumber BigNumber::operator--(int)
{
    BigNumber one("1");
    BigNumber c;
    c=*this;
    *this=add(this,&one,NEGATIVE);
    return c;
}

BigNumber BigNumber::operator*(const BigNumber &that) const
{
    BigNumber c("0");
    BigNumber intermediate;
    digit_t flag=0;
    int len_a,len_b;
    len_a=this->length();
    len_b=that.length();
    for(int i=0;i<len_b;++i)
    {
        int multiplier;
        multiplier=that.m_digits[i];
        for(int k=0;k<i;++k)
            intermediate.m_digits.push_back(0);
        for(int j=0;j<len_a;++j)
        {
            digit_t digit;
            digit=this->m_digits[j]*multiplier;
            digit+=flag;
            flag=digit/10;
            digit=digit%10;
            intermediate.m_digits.push_back(digit);
        }
        intermediate.m_digits.push_back(flag);
        c=add(&c,&intermediate);
    }
    return c;
}

void BigNumber::trim()
{
    while((length()>0)&&(m_digits.back()==0))
        m_digits.pop_back();
    if(length()==0)
    {
        m_symbol=ZERO;
    }
}

BigNumber BigNumber::add(const BigNumber *numA, const BigNumber *numB, SYMBOL symbolB)
{
    BigNumber c;
    SYMBOL symbolA=numA->m_symbol;
    if(numB->m_symbol==NEGATIVE) {
        symbolB = SYMBOL((-1) * (int) symbolB);
    }
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
    if (((symbolA!=NEGATIVE)&&(symbolB!=NEGATIVE))||((symbolA==NEGATIVE)&&(symbolB==NEGATIVE)))
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
        else
        {
            c.m_symbol=POSITIVE;
        }
    }
    if ((symbolA==NEGATIVE&&symbolB!=NEGATIVE)||(symbolB==NEGATIVE&&symbolA!=NEGATIVE))
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
            {
                c.m_digits.push_back(digit);
            }
            if (c.m_digits.back() < 0) {
                c.m_digits[0] = 10 - c.m_digits[0];
                for (int i = 1; i < lenm - 1; ++i)
                    c.m_digits[i] = 9 - c.m_digits[i];
                c.m_digits[lenm - 1] = -c.m_digits[lenm - 1] - 1;
                c.m_symbol = NEGATIVE;
            }
            else
            {
                c.m_symbol=POSITIVE;
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
            {
                c.m_digits.push_back(digit);
            }
            if (c.m_digits.back() < 0)
            {
                if(c.m_digits.size()>1) {
                    c.m_digits[0] = 10 - c.m_digits[0];
                    for (int i = 1; i < len - 1; ++i)
                        c.m_digits[i] = 9 - c.m_digits[i];
                    c.m_digits[len - 1] = -c.m_digits[len - 1] - 1;
                    c.m_symbol = NEGATIVE;
                }
                else
                {
                    c.m_digits[len - 1] = -c.m_digits[len - 1] ;
                    c.m_symbol = NEGATIVE;
                }
            }
            else
            {
                c.m_symbol=POSITIVE;
            }

        }
    }
    c.trim();
    return c;
}


