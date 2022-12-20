#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        vector<pair<string, unsigned long>> v;
        int n;
        cin >> n;

        // read input
        for (int j = 0; j < n; ++j)
        {
            string name;
            cin >> name;
            name = name.substr(0, name.length() - 1);
            string class_string;
            cin >> class_string;
            string throw_away; // "class"
            cin >> throw_away;

            string class_value = ""; // Empty string to start with
            istringstream ss(class_string);
            string token;
            while (getline(ss, token, '-'))
            { // iterate through class
                if (token == "upper")
                {
                    class_value += '3';
                }
                else if (token == "middle")
                {
                    class_value += '2';
                }
                else if (token == "lower")
                {
                    class_value += '1';
                }
            }
            reverse(class_value.begin(), class_value.end()); // reverse string to get highest class value first
            while (class_value.length() < 10)
            {
                class_value += '2'; // pad with 2:s (middle class) if shorter than 10 classes
            }

            // convert string to unsigned long
            unsigned long value = 0;
            for (char c : class_value)
            {
                value = 10 * value + (c - '0');
            }

            // add to vector
            v.emplace_back(name, value);
        }

        // sort vector using stable_sort and a lambda function
        stable_sort(v.begin(), v.end(),
                    [](const pair<string, unsigned long> &a, const pair<string, unsigned long> &b)
                    {
                        if (a.second != b.second)
                        {
                            return a.second > b.second;
                        }
                        else
                        {
                            return a.first < b.first;
                        }
                    });

        for (const auto &p : v)
        {
            const auto &name = p.first;
            const auto &value = p.second;
            cout << name << endl;
        }
        cout << "==============================" << endl;
    }
    return 0;
}
