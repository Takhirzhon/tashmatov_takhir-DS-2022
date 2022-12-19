#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <algorithm>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, BigInt &x);
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);

    std::vector<int> mDigits;
    bool mIsNegative;

    static int cmpAbsValues(const BigInt &x, const BigInt &y)
    { //
        if (x.mDigits.size() < y.mDigits.size())
        {
            return -1;
        }
        if (x.mDigits.size() > y.mDigits.size())
        {
            return 1;
        }

        for (size_t i = 0; i < x.mDigits.size(); ++i)
        {
            if (x.mDigits[i] != y.mDigits[i])
            {
                return x.mDigits[i] - y.mDigits[i];
            }
        }
        return 0;
    }

    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;

        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if (itX != x.mDigits.rend())
            {
                s += *itX;
                ++itX;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                ++itY;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }
        if (carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }

    static BigInt subAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(x.mDigits.size());
        auto itZ = z.mDigits.rbegin();

        int borrow = 0;
        for (auto itY = y.mDigits.rbegin(); itY != y.mDigits.rend(); ++itX, ++itY, ++itZ)
        {
            int d = *itX - borrow - *itY;
            if (d < 0)
            {
                d += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            *itZ = d;
        }

        for (; borrow != 0; ++itX, ++itZ)
        {
            int d = *itX - borrow;
            if (d < 0)
            {
                d += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            *itZ = d;
        }

        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }

        return z;
    }

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        size_t i = 0;
        //
        if (!s.empty() && (s[i] == '-' || s[i] == '+'))
        {
            mIsNegative = s[i] == '-';
            ++i;
        }
        // removing leading zeros
        while (i + 1 < s.size() && s[i] == '0')
        {
            ++i;
        }
        //
        for (; i < s.size() && isdigit(s[i]); ++i)
        {
            mDigits.push_back(s[i] - '0');
        }
        // checking if not digit entered
        if (i < s.size() || mDigits.empty())
        {
            throw std::runtime_error("BigInt: incorrect string representation");
        }
        // checking that here is not -0
        if (mDigits.size() == 1 && mDigits[0] == 0)
        {
            mIsNegative = false;
        }
    }

    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }
};

// creating out flow
inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << "-";
    }
    for (auto digit : x.mDigits)
    {
        out << digit;
    }

    return out;
}
inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    char ch;
    // ne poluchilos'
    if (!(inp >> ch))
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    if (!(std::isdigit(ch) || ch == '+' || ch == '-'))
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    std::string s;
    bool isNegetive = false;
    if (ch == '+' || ch == '-')
    {
        isNegetive = ch == '-';
    }
    else
    {
        s += ch;
    }

    while (inp.get(ch) && std::isdigit(ch))
    {
        s += ch;
    }

    if (inp)
    {
        inp.putback(ch);
    }

    if (s.empty())
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    x = BigInt(s);
    x.mIsNegative = isNegetive;

    return inp;
}

inline bool operator==(const BigInt &a, const BigInt &b)
{
    return a.mIsNegative == b.mIsNegative && a.mDigits == b.mDigits;
}

inline bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

inline bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative && !b.mIsNegative)
    {
        return true;
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        return false;
    }

    if (!a.mIsNegative && !b.mIsNegative)
    {
        return a.mDigits.size() < b.mDigits.size() || (a.mDigits.size() == b.mDigits.size() && a.mDigits < b.mDigits);
    }

    return a.mDigits.size() > b.mDigits.size() || (a.mDigits.size() == b.mDigits.size() && a.mDigits > b.mDigits);
}
inline bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}
inline bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}
inline bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(b < a);
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{

    if (x.mIsNegative == y.mIsNegative)
    {
        BigInt res = BigInt::addAbsValues(x, y);
        res.mIsNegative = x.mIsNegative;
        return res;
    }

    // x < 0 and y > 0 return y - x
    if (x.mIsNegative == !y.mIsNegative)
    {
        BigInt res = x;
        res.mIsNegative = false;
        return (y - x);
    }
    // x > 0 and y < 0 return x - y
    if (!x.mIsNegative == y.mIsNegative)
    {
        BigInt res = y;
        res.mIsNegative = false;
        return (x - y);
    }
    throw std::runtime_error("not implemented yet");
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{
    // x > 0 and y < 0 x - abs(y) = x + y
    if (!x.mIsNegative && y.mIsNegative)
    {
        return BigInt::addAbsValues(x, y);
    }
    // x < 0 and y > 0 x - y = -x - y = - (x+y)
    if (x.mIsNegative && !y.mIsNegative)
    {
        BigInt res = BigInt::addAbsValues(x, y);
        res.mIsNegative = true;
        return res;
    }
    // 0 + y = y,
    if (x == 0)
    {
        BigInt res = y;
        res.mIsNegative = !(res.mIsNegative);
        return res;
    }
    // x - y (x ^ y) cmp >= 0 (x >= y) cmp < 0 (x < y) x - y = - (y - x)
    if (!x.mIsNegative && !y.mIsNegative)
    {
        int cmp = BigInt::cmpAbsValues(x, y);
        if (cmp >= 0)
        {
            return BigInt::subAbsValues(x, y);
        }
        if (cmp < 0)
        {
            BigInt res = BigInt::subAbsValues(y, x);
            res.mIsNegative = true;
            return res;
        }
    }

    if (x.mIsNegative && y.mIsNegative)
    {
        int cmp = BigInt::cmpAbsValues(x, y);
        // abs(x) > abs(y)
        if (cmp >= 0)
        {
            // x - y
            BigInt res = BigInt::subAbsValues(x, y);
            // - (x - y)
            res.mIsNegative = true;
            return res;
        }
        // abs(x) < abs(y)
        if (cmp < 0)
        {
            // y - x
            BigInt res = BigInt::subAbsValues(y, x);
            // y - x
            res.mIsNegative = false;
            return res;
        }
    }

    throw std::runtime_error("not implemented yet");
}
