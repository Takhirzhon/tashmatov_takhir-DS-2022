#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct Skill
{
    string word;
    int value;
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<Skill> wordValues;
    for (int i = 0; i < m; ++i)
    {
        string word;
        int value;
        cin >> word >> value;
        wordValues.push_back({word, value});
    }

    sort(wordValues.begin(), wordValues.end(),
         [](const Skill &a, const Skill &b)
         { return a.value < b.value; });

    for (int i = 0; i < n; ++i)
    {
        string word;
        int salary = 0;
        while (cin >> word, word != ".")
        {
            for (const Skill &pair : wordValues)
            {
                if (pair.word == word)
                {
                    salary += pair.value;
                    break;
                }
            }
        }

        cout << salary << endl;
    }
    return 0;
}
