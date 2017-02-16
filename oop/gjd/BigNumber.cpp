//
// This part should be completed by yourself
// ps. You can generate the definitions in the header file
// Just click on yellow background functions and use the bulb appeared on the left
//
#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
#include <math.h>

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

BigNumber::BigNumber(int64_t num)
{
    if (num<0)
    {
        m_symbol = NEGATIVE;
        num=-num;
    }
    else
        m_symbol = POSITIVE;
    int len = 1;
    if(num!=0)
        len=log10(num)+1;
    for (int i =0; i<len; ++i)
    {
        digit_t digit;
        digit=num%10;
        num=num/10;
        m_digits.push_back(digit);
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
    {
        str="0";
    }
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

// Return whether two BigNumbers equal
bool BigNumber::operator==(const BigNumber &that) const
{
    int len_a=this->length();
    int len_b=that.length();
    SYMBOL symbolA=this->m_symbol;
    SYMBOL symbolB=that.m_symbol;
    if (len_a!=len_b||symbolA!=symbolB)
        return false;
    else
    {
        for(int i=0;i<len_a;++i)
        {
            if(this->m_digits[i]!=that.m_digits[i])
                return false;
        }
        return true;
    }
}

// Return whether two BigNumbers unequal
bool BigNumber::operator!=(const BigNumber &that) const
{
    return (!(*this==that));
}

// Return whether one BigNumber is smaller than another
bool BigNumber::operator<(const BigNumber &that) const
{
    BigNumber compare;
    compare=*this-that;
    if (compare.m_symbol==NEGATIVE)
        return true;
    else
        return false;
}

// Return whether one BigNumber is not larger than another
bool BigNumber::operator<=(const BigNumber &that) const
{
    BigNumber compare;
    compare=*this-that;
    if (compare.m_symbol==NEGATIVE)
        return true;
    else
    {
        if(*this==that)
            return true;
        else
            return false;
    }
}

// Return whether one BigNumber is larger than another
bool BigNumber::operator>(const BigNumber &that) const
{
    BigNumber compare;
    compare=*this-that;
    if (compare.m_symbol==POSITIVE)
        return true;
    else
        return false;
}

// Return whether one BigNumber is not smaller than another
bool BigNumber::operator>=(const BigNumber &that) const
{
    BigNumber compare;
    compare=*this-that;
    if (compare.m_symbol==POSITIVE)
        return true;
    else
    {
        if(*this==that)
            return true;
        else
            return false;
    }
}
// Reset the BigNumber from a string
const BigNumber &BigNumber::operator=(const std::string &numStr)
{
    *this=numStr;
    return *this;
}

// Reset the BigNumber from an integer
const BigNumber &BigNumber::operator=(const int64_t &num)
{
    *this=num;
    return *this;
}
// Same as copy constructor

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

const BigNumber &BigNumber::operator+=(const BigNumber &that)
{
    *this=*this+that;
    return *this;
}
BigNumber BigNumber::operator-(const BigNumber &that) const
{
    return add(this,&that,NEGATIVE);
}
const BigNumber &BigNumber::operator-=(const BigNumber &that)
{
    *this=*this-that;
    return *this;
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
    BigNumber c;
    digit_t flag=0;
    int len_a,len_b;
    len_a=this->length();
    len_b=that.length();
    for(int i=0;i<len_b;++i)
    {
        BigNumber intermediate;
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
        flag=0;
        c=add(&c,&intermediate);
    }
    SYMBOL symbolA,symbolB;
    symbolA=this->m_symbol;
    symbolB=that.m_symbol;
    if(symbolA==symbolB)
        c.m_symbol=POSITIVE;
    else
        c.m_symbol=NEGATIVE;
    c.trim();
    return c;
}
const BigNumber &BigNumber::operator*=(const BigNumber &that)
{
    *this=*this*that;
    return *this;
}

BigNumber BigNumber::operator/(const BigNumber &that) const
{
    return divide(*this, that).first;
}
BigNumber BigNumber::operator%(const BigNumber &that) const
{
    return divide(*this, that).second;
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
                int s;
                for(s=0;s<lenm-1;++s)
                {
                    if(c.m_digits[s]!=0)
                        break;
                }
                c.m_digits[s] = 10 - c.m_digits[s];
                for (int i = s+1; i < lenm - 1; ++i)
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
                    int s;
                    for(s=0;s<len-1;++s)
                    {
                        if(c.m_digits[s]!=0)
                            break;
                    }
                    c.m_digits[s] = 10 - c.m_digits[s];
                    for (int i = s+1; i < len - 1; ++i)
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
std::pair<BigNumber, BigNumber> BigNumber::divide(const BigNumber &divider, const BigNumber &divisor)
{
    int len_divisor=divisor.length();
    if(len_divisor==1&&divisor.m_digits[0]==0)
        std::cout<<"Error.";
    BigNumber factor;
    BigNumber r;
    factor.m_symbol=POSITIVE;
    r=divider;
    int t=0;
    BigNumber process;
    process.m_symbol=POSITIVE;
    while(r>=divisor)
    {
        ++t;
        if(t==1)
        {
            for (int j = len_divisor - 1; j >= 0; --j)
            {
                process.m_digits.push_back(r.m_digits[r.length() - 1 - j]);
            }
            if (process < divisor)
            {
                for (int j = len_divisor - 1; j >= 0; --j)
                    process.m_digits.pop_back();
                for (int j = len_divisor; j >= 0; --j)
                {
                    process.m_digits.push_back(r.m_digits[r.length() - 1 - j]);
                }
            }
        }
        else
        {
            int l=process.length();
            //std::cout<<process.toString()<<std::endl;
            if(l==0)
            {
                //std::cout<<"00000";
                //process.m_digits.push_back(1);
                process.m_digits.push_back(r.m_digits[r.length()-l-1]);
                //std::cout<<process.length()<<std::endl;
                //std::cout<<(int)process.m_digits[0]<<std::endl;
                //std::cout<<(int)r.m_digits[r.length()-l-1]<<std::endl;
                //process.trim();
                process.m_symbol=POSITIVE;
                std::cout << process.toString()<<std::endl;
            }
            else
            {
                process.m_digits.push_back(1);
                for (int i = l - 1; i >= 0; --i)
                    process.m_digits[i + 1] = process.m_digits[i];
                process.m_digits[0] = r.m_digits[r.length() - l - 1];
                //std::cout<<(int)r.m_digits[r.length()-l-1]<<std::endl;
                //process.m_digits.push_back(r.m_digits[r.length()-l-1]);
                //BigNumber reverse;
                //reverse.m_symbol=POSITIVE;
                //std::cout << process.toString();
                //break;
            }
        }
        std::cout << t<<"     "<<process.toString()<<std::endl;
        int len;
        BigNumber inter,inter2;
        inter.m_symbol=POSITIVE;
        inter2.m_symbol=POSITIVE;
        BigNumber k("0");
        BigNumber limit("9");
        for(k;k<=limit;++k)
        {
            //std::cout<<"---"<<std::endl;
            inter=divisor*k;
            inter2=inter+divisor;
            BigNumber zero("0");
            /*if(process==zero)
            {
                factor.m_digits.push_back(0);
                break;
            }*/
            if((inter<=process)&&(inter2>process))
            {
                digit_t digit;
                digit=k.m_digits[0];
                factor.m_digits.push_back(digit);
                len=inter.length();
                break;
            }
        }
        int l_p=process.length();
        process-=inter;
        BigNumber m;
        m.m_symbol=POSITIVE;
        for(int i=0;i<r.length()-l_p;++i)
        {
            m.m_digits.push_back(0);
        }
        for(int i=0;i<len;++i)
            m.m_digits.push_back(inter.m_digits[i]);
        r=r-m;
        std::cout<<m.toString()<<std::endl;
        std::cout<<r.toString()<<std::endl;

    }
    int len_f;
    len_f=factor.length();
    BigNumber f;
    f.m_symbol=POSITIVE;
    for(int i=0;i<len_f;++i)
    {
        f.m_digits.push_back(factor.m_digits[len_f-1-i]);
    }
    f.trim();
    std::cout<<f.toString();
    return std::pair<BigNumber, BigNumber>(f,r);
};

