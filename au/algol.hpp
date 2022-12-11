#pragma once
#include <utility>

template <typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter beg, BidirectionalIter end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }

        --end;

        if (beg == end)
        {
            break;
        }
        auSwap(*beg, *end);

        ++beg;
    }
}

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    for (; beg != end; ++beg)
    {
        if (*beg == key)
        {
            return beg;
        }
    }

    return beg;
}

template <typename ForwardIter, typename UnirayPredicates>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnirayPredicates pred)
{
    for (; beg != end; ++beg)
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

template <typename Iter, typename Predicate>
Iter auMinElement(Iter beg, Iter end, Predicate p)
{
    if (beg == end)
    {
        return end;
    }

    Iter res = beg++;
    while (beg != end)
    {
        if (p(*beg, *res))
        {
            res = beg;
        }
        beg++;
    }
    return res;
}

template <typename Iter, typename T>
Iter auLowerBounded(Iter beg, Iter end, const T &k)
{
    while (beg != end)
    {
        auto mid = beg + (end - beg) / 2;
        if (*mid < k)
        {
            beg = ++mid;
        }
        else
        {
            end = mid;
        }
    }
    return beg;
}

template <typename Iter, typename T>
bool auBinarySearch(Iter beg, Iter end, const T &k)
{
    auto iter = auLowerBounded(beg, end, k);
    return iter != end && *iter == k;
}