#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>

struct Pair
{
    int ascii;
    int value;
};

int main()
{
    int tests = 0;
    string line;
    while (getline(cin, line))
    {
        if (tests++ > 0)
        {
            cout << endl;
        }
        vector<Pair> vec;
        for (char c : line)
        {
            auto it = find_if(vec.begin(), vec.end(), [c](const Pair &p)
                              { return p.ascii == c; });
            if (it == vec.end())
            {
                vec.push_back({c, 1});
            }
            else
            {
                it->value++;
            }
        }
        sort(vec.begin(), vec.end(), [](const Pair &a, const Pair &b)
             {
                 if (a.value == b.value)
                 {
                     return a.ascii > b.ascii;
                 }
                 return a.value < b.value; });

        for (auto &p : vec)
        {
            cout << p.ascii << ' ' << p.value << '\n';
        }
    }

    return 0;
}
