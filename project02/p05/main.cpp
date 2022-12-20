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
    string line;
    while (getline(cin, line))
    {
        vector<Pair> frequencies;
        for (char c : line)
        {
            auto it = find_if(frequencies.begin(), frequencies.end(), [c](const Pair &p)
                              { return p.ascii == c; });
            if (it == frequencies.end())
            {
                frequencies.push_back({c, 1});
            }
            else
            {
                it->value++;
            }
        }
        sort(frequencies.begin(), frequencies.end(), [](const Pair &a, const Pair &b)
             { return a.value < b.value; });

        for (const Pair &p : frequencies)
        {
            cout << p.ascii << ' ' << p.value << '\n';
        }

        cout << '\n';
    }

    return 0;
}