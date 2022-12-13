#pragma once
#include <utility>

template <typename ForwardIter, typename Iter>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Iter &key)
{
    for (; beg != end; beg++)
    {
        if (*beg == key)
        {
            return beg;
        }
    }
    return beg;
}

template <typename ForwardIter, typename Iter>
ForwardIter auIfFind(ForwardIter beg, ForwardIter end, Iter pred)
{
    for (; beg != end; beg++)
    {
        if (pred(*beg))
        {
            return beg;
        }
    }
    return beg;
}

template <typename Iter>
Iter auMinElement(Iter beg, Iter end)
{
    if (beg == end)
    {
        return end;
    }

    Iter res = beg++;
    while (beg != end)
    {
        if (*beg < *res)
        {
            res = beg;
        }
        beg++;
    }
    return res;
}

template <typename Iter, typename Predicator>
Iter auMinElement(Iter beg, Iter end, Predicator pred)
{
    if (beg == end)
    {
        return end;
    }

    Iter res = beg++;
    while (beg != end)
    {
        if (pred(*beg, *res))
        {
            res = beg;
        }
        beg++;
    }
    return res;
}

template <typename ForwardIter, class T>
bool auBinarySearch(ForwardIter beg, ForwardIter end, T &value)
{
    while (beg != end)
    {

        ForwardIter middle = beg;
        advance(middle, (end - beg) / 2);

        if (value > *middle)
        {
            beg = middle;
        }
        else if (value < *middle)
        {
            end = middle;
        }
        else
        {
            return true;
        }

        if (end - beg == 1 && (value != *end && value != *beg))
        {
            break;
        }
    }
    return false;
}