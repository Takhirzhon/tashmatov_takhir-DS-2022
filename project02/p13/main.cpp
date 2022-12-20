#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    string word;
    int length = 0;
    vector<pair<string, string>> dyslection;
    while (getline(cin, word))
    {
        if (word.empty())
        {
            sort(dyslection.begin(), dyslection.end(),
                 [](const pair<string, string> &a, const pair<string, string> &b)
                 { return a.first < b.first; });
            for (auto x : dyslection)
            {
                cout << setw(length) << x.second << "\n";
            }
            dyslection.clear();
            length = 0;
            cout << "\n";
        }

        else
        {
            string s = word;
            reverse(s.begin(), s.end());
            length = max(length, int(s.size()));
            dyslection.push_back({s, word});
        }
    }
    sort(dyslection.begin(), dyslection.end());
    for (auto x : dyslection)
    {
        cout << setw(length) << x.second << "\n";
    }
    dyslection.clear();
}